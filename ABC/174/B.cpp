#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

int main(){
    ll N,D;
    ll ans = 0;
    cin >> N >> D;
    for(int i=0;i<N;i++){
        ll x,y;
        cin >> x >> y;
        if(D*D >= x*x + y*y) ans++;
    }
    cout << ans << endl;
    return 0;
}