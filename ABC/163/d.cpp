#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N,K;
ll MOD = 1e9+7;

int main(){
    cin >> N >> K;
    ll sum = 0;
    for(ll i=K;i<=N+1;i++){
        ll a = N * i;
        a %= MOD;
        ll b = i * (i-1);
        b %= MOD;
        sum += a - b + 1;
        sum %= MOD;
        sum += MOD;
        sum %= MOD;
    }
    cout << sum << endl;
    return 0;
}