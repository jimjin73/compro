#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

ll N,Q;
vector<ll> v[500000];
vector<P> q;
vector<ll> L,R;


int main(){
    cin >> N >> Q;
    for(int i=0;i<N;i++){
        ll t;
        cin >> t;
        v[t-1].push_back(i+1);
    }
    for(int i=0;i<Q;i++){
        ll l,r;
        cin >> l >> r;
        q.push_back({l,r});
    }
    for(int i=0;i<N;i++){
        if(v[i].size()<2) continue;
        for(int j=1;j<v[i].size();j++){
            L.push_back(v[i][j-1]);
            R.push_back(v[i][j]);
        }
    }
    sort(L.begin(),L.end());
    sort(R.begin(),R.end());
    for(auto &e : L) cout << e << " ";
    cout << endl;
    for(auto &e : R) cout << e << " ";
    cout << endl;
    for(auto &e : q){
        ll l = e.first;
        ll r = e.second;
        auto rR = upper_bound(R.begin(),R.end(),r);
        auto lR = upper_bound(R.begin(),R.end(),l);
        auto lL = lower_bound(L.begin(),L.end(),l);
        ll r_count = 0;
        if(rR != R.begin()) r_count += (rR-1) - R.begin() + 1;
        if(lR != R.begin()) r_count -= ((lR-1) - R.begin()) + 1;
        ll rl_diff = 0;
        if(lL != L.begin()) rl_diff += (lL-1) - L.begin() + 1;
        if(lR != R.begin()) rl_diff -= (lR-1) - R.begin() + 1;
        cout << l << " " << r << " " << r_count << " " << rl_diff << endl; 
        cout << r - l - (r_count - rl_diff) + 1 << endl;
    }
    return 0;
}