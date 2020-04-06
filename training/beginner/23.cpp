#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N,M;
ll p[1001];

int main(){
    cin >> N >> M;
    ll t;
    for(int i=0;i<N;i++) cin >> p[i];
    vector<ll> v;
    v.push_back(0);
    for(int i=0;i<N;i++){
        v.push_back(p[i]);
        for(int j=i;j<N;j++){
            v.push_back(p[i]+p[j]);
        }
    }
    sort(v.begin(),v.end());
    ll max_m = 0;
    for(int i=0;i<v.size();i++){
        auto itr = upper_bound(v.begin(), v.end(), M - v[i]);
        if(itr != v.begin()){
            max_m = max(max_m, v[i] + *(itr - 1));
        }
    }
    cout << max_m << endl;
    return 0;
}