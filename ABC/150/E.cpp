#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N;
vector<ll> C;
ll MOD = 1e9+7;

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        ll c;
        cin >> c;
        C.push_back(c);
    }
    sort(C.rbegin(), C.rend());
    ll ans = 0;
    ll t = 1;
    for(int i=0;i<N-1;i++){
        t *= 2;
        t %= MOD;
    }
    for(int i=0;i<N;i++){
        ll p = t * t;
        p %= MOD;
        p *= ll(i+2);
        p %= MOD;
        ans += p * C[i];
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}