#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

ll N;
vector<ll> v;

int main(){
    cin >> N;
    for(ll i=1;i*i<=N;i++){
        if(N%i==0){
            v.push_back(i);
            if(i*i != N) v.push_back(N/i);
        }
    }
    ll ans = 0;
    for(auto &e : v){
        if(e==1) continue;
        if(N % (e-1) == 0) continue;
        if(N / (e-1) == N % (e-1)) ans += (e-1);
    }
    cout << ans << endl;
    return 0;
}