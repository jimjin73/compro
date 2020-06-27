#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

int main(){
    ll N;
    cin >> N;
    ll ans = 0;
    for(ll k=1;k<=N;k++){
        ll n = N / k;
        ans += (k + n*k) * n / 2;
    }
    cout << ans << endl;
    return 0;
}