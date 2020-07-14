#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

ll n,m,d;

int main(){
    cin >> n >> m >> d;
    ll a = (n - d) * (m-1);
    if(d != 0) a *= 2.0;
    long double ans = (long double)a / (n*n);
    cout << fixed << setprecision(15) << ans << endl;
    return 0;
}