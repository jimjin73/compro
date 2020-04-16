#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll MOD = 1e9 + 7;

ll N,Q;
ll a[150000];
ll c[150000];
vector<ll> v;

ll powmod(ll a, ll b){
    ll ans = 1;
    bitset<64> bt(b);
    for(int i=0;i<64;i++){
        if(bt[i] == 1) ans *= a;
        ans %= MOD;
        a *= a;
        a %= MOD;
    }
    return ans;
}

int main(){
    cin >> N >> Q;
    for(int i=0;i<N;i++) cin >> a[i];
    c[0] = 1;
    for(int i=1;i<=Q;i++) cin >> c[i];
    c[Q+1] = 1;
    v.push_back(0);
    for(int i=1;i<N;i++) v.push_back(powmod(a[i-1],a[i]));
    for(int i=1;i<N;i++){
        v[i] += v[i-1];
        v[i] %= MOD;
    }
    ll sum = 0;
    for(int i=1;i<=Q+1;i++){
        sum += (v[max(c[i],c[i-1])-1] - v[min(c[i],c[i-1])-1]) + MOD;
        sum %= MOD;
    }
    cout << sum << endl;
    return 0;
}