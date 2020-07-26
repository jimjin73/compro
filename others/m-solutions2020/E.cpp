#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,ll> Q;

ll N;
vector<Q> v;

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        ll x,y,p;
        cin >> x >> y >> p;
        v.push_back({{x,y},p});
    }
    ll dist = 0;
    for(int i=0;i<N;i++) dist += v[i].second * min(v[i].first.first, v[i].first.second);
    cout << dist << endl;
    for(int K=1;K<N;K++){
        dist = 1e18;
        for(int i=0;i<(1<<N);i++){
            ll tmp_dist = 1e18;
            bitset<15> bt(i);
            
        }
        cout << dist << endl;
    }
    cout << 0 << endl;
    return 0;
}