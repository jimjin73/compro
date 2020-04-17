#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll MOD = 1e9 + 7;
ll W,H;

ll powmod(ll a, ll b){
    ll ans = 1;
    bitset<64> bt(b);
    for(int i=0;i<64;i++){
        if(bt[i] == 1) ans *= a;
        a *= a;
        ans %= MOD;
        a %= MOD;
    }
    return ans;
}

ll inv(ll n){
    return powmod(n, MOD-2);
}

ll fact(ll n){
    ll ans = 1;
    for(int i=2;i<=n;i++){
        ans *= i;
        ans %= MOD;
    }
    return ans;
}

ll comb(ll n, ll l){
    ll a = fact(n);
    ll b = fact(l) * fact(n-l);
    b %= MOD;
    b = inv(b);
    return (a * b) % MOD;
}

int main(){
    cin >> W >> H;
    cout << comb(W+H-2, min(W-1,H-1)) << endl;
    return 0;
}