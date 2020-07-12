#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

ll N;
string X;
ll g[400001];
ll f[400001];

ll calc(ll m){
    if(m == 0) return 0;
    ll ret = 0;
    for(auto &x : X){
        ret *= 2;
        ret += x - '0';
        ret %= m;
    }
    return ret;
}

int main(){
    cin >> N;
    cin >> X;
    vector<ll> ans;
    for(int i=1;i<=400000;i++){
        bitset<32> bt(i);
        g[i] = i % bt.count();
    }
    for(int i=1;i<=400000;i++){
        if(g[i] == 0){
            f[i] = 1;
            continue;
        }
        f[i] = f[g[i]] + 1;
    }
    bitset<200000> btX(X);
    ll x_count = btX.count();
    ll mod_p = x_count + 1;
    ll mod_m = x_count - 1;
    ll X_mod_p = calc(mod_p);
    ll X_mod_m = calc(mod_m);
    ll pp, mp;
    pp = mp = 1;
    for(int i=N-1;i>=0;i--){
        pp %= mod_p;
        if(mod_m != 0) mp %= mod_m;
        if(X[i] == '0'){
            ll t = pp + X_mod_p;
            t %= mod_p;
            ans.push_back(f[t] + 1);
        }else{
            if(mod_m == 0){
                ans.push_back(0);
                continue;
            }
            ll t = X_mod_m - mp;
            t += mod_m;
            t %= mod_m;
            ans.push_back(f[t] + 1);
        }
        pp *= 2;
        mp *= 2;
    }
    for(int i=N-1;i>=0;i--) cout << ans[i] << endl;
    return 0;
}