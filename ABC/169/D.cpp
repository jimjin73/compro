#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

ll N;
unordered_map<ll,ll> um;

int main(){
    cin >> N;
    ll M = N;
    for(ll i=2;i*i<=N;i++){
        if(M % i != 0) continue;
        ll c = 0;
        while(M % i == 0){
            M /= i;
            c++;
        }
        um[i] = c;
    }
    if(M != 1) um[M] = 1;
    ll ans = 0;
    for(auto &e : um){
        ll t = e.second;
        for(int i=1;i<=t;i++){
            t -= i;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}