#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N;
vector<ll> v[5001];
ll x[5000];
ll y[5000];

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> x[i] >> y[i];
        v[x[i]].push_back(y[i]);
    }
    for(int i=0;i<=5000;i++) sort(v[i].begin(),v[i].end());
    ll max_s = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==j) continue;
            ll diff_x = x[j] - x[i];
            ll diff_y = y[j] - y[i];
            ll xx = x[j] + diff_y;
            ll yy = y[j] - diff_x;
            if(xx < 0 || xx > 5000 || yy < 0 || yy > 5000) continue;
            if(!binary_search(v[xx].begin(),v[xx].end(),yy)) continue;
            xx -= diff_x;
            yy -= diff_y;
            if(xx < 0 || xx > 5000 || yy < 0 || yy > 5000) continue;
            if(!binary_search(v[xx].begin(),v[xx].end(),yy)) continue;
            ll s = (abs(diff_x) + abs(diff_y)) * (abs(diff_x) + abs(diff_y)) - 2 * abs(diff_x) * abs(diff_y);
            max_s = max(max_s, s);
        }
    }
    cout << max_s << endl;
    return 0;
}