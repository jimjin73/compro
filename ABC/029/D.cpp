#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

ll N;

int main(){
    cin >> N;
    ll l = 10;
    ll ans = 0;
    for(int i=0;i<10;i++){
        ll s = (N+1) / l;
        ll t = (N+1) % l;
        ans += s * l / 10;
        if(t > l / 10 * 2) ans += l / 10;
        else if(t >= l / 10) ans += t - l / 10;
        l *= 10;
    }
    cout << ans << endl;
    return 0;
}