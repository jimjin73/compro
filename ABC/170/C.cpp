#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

ll X,N;
unordered_set<ll> us;

int main(){
    cin >> X >> N;
    for(int i=0;i<N;i++){
        ll a;
        cin >> a;
        us.insert(a);
    }
    ll ans = 1e9;
    ll diff = 1e9;
    for(int i=-10;i<110;i++){
        if(us.find(i) != us.end()) continue;
        if(diff < abs(X-i)) continue;
        if(diff == abs(X-i) && i > ans) continue;
        ans = i;
        diff = abs(X-i);
    }
    cout << ans << endl;
    return 0;
}