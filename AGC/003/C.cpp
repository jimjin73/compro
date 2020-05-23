#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

ll N;
vector<ll> a;
unordered_map<ll,ll> um;

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        ll c;
        cin >> c;
        a.push_back(c);
        um[c] = i%2;
    }
    sort(a.begin(),a.end());
    ll ans = 0;
    for(int i=0;i<N;i+=2){
        if(i%2 != um[a[i]]) ans++;
    }
    cout << ans << endl;
    return 0;
}