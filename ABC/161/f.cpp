#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N;
vector<ll> v;

int main(){
    cin >> N;
    if(N==2){
        cout << 1 << endl;
        return 0;
    }
    ll ans = 1;
    for(ll i=2;(i*i)<=(N-1);i++){
        if((N-1) % i != 0) continue;
        ans++;
        if(i*i != N-1) ans++;
    }
    v.push_back(N);
    for(ll i=2;i*i<=N;i++){
        if(N%i != 0) continue;
        v.push_back(i);
        if(i*i != N) v.push_back(N/i);
    }
    for(auto &e : v){
        ll n = N;
        while(n % e == 0) n /= e;
        if(n%e == 1) ans++; 
    }
    cout << ans << endl;
    return 0;
}