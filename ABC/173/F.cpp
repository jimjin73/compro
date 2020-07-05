#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

ll N;
vector<P> v;

int main(){
    cin >> N;
    for(int i=0;i<N-1;i++){
        ll s,t;
        cin >> s >> t;
        v.push_back({min(s,t),max(s,t)});
    }
    ll ans = 0;
    for(ll i=1;i<=N;i++){
        ans += i * (N-i+1);
    }
    for(auto &e : v){
        ans -= e.first * (N-e.second+1);
    }
    cout << ans << endl;
    return 0;
}