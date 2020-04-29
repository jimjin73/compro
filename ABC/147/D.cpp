#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N;
ll b[64];
ll MOD = 1e9+7;

int main(){
    cin >> N;
    for(int i=0;i<64;i++) b[i] = 0;
    for(int i=0;i<N;i++){
        ll a;
        cin >> a;
        for(int j=0;j<64;j++){
            b[j] += ((a>>j)&1);
        }
    }
    ll ans = 0;
    for(int i=0;i<64;i++){
        ll t = (b[i] * (N-b[i])) % MOD;
        ll s = ((ll)1 << i) % MOD;
        ans += t * s;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}