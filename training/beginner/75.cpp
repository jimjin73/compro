#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll MOD = 1e9+7;

class mint{
    ll n;
public:
    mint(ll m = 0){
        n = ((m % MOD) + MOD) % MOD;
    }
    mint operator-() const {
        return mint(-n);
    }
    mint& operator+=(const mint& m){
        n += m.n;
        if(n >= MOD) n -= MOD;
        return *this;
    }
    mint& operator-=(const mint& m){
        n += MOD - m.n;
        if(n >= MOD) n -= MOD;
        return *this;
    }
    mint& operator*=(const  mint& m){
        n *= m.n;
        n %= MOD;
        return *this;
    }
    mint operator+(const mint& m) const{
        mint res(*this);
        res += m;
        return res;
    }
    mint operator-(const mint& m) const{
        mint res(*this);
        res -= m;
        return res;
    }
    mint operator*(const mint& m) const{
        mint res(*this);
        res *= m;
        return res;
    }
    mint pow(ll t) const{
        if(t == 0) return mint(1);
        mint m = pow(t>>1);
        m *= m;
        if(t & 1 == 1) m *= *this;
        return m;
    }
    // for prime modulo
    mint inv() const{
        return pow(MOD-2);
    }
    mint& operator/=(const mint& m){
        (*this) *= m.inv();
        n %= MOD;
        return *this;
    }
    mint operator/(const mint& m) const{
        mint res(*this);
        res /= m;
        return res;
    }
    friend ostream& operator<<(ostream& os, const mint& m){
        os << m.n;
        return os;
    }
};

vector<vector<ll>> G;
ll N;
ll a[200000];
ll b[200000];
mint ans(0);

ll dfs(ll n, ll p = -1){
    ll chs = 1;
    vector<ll> v;
    for(auto &e : G[n]){
        if(e==p) continue;
        ll c = dfs(e,n);
        chs += c;
        v.push_back(c);
    }
    if(p != -1) v.push_back(N - chs);
    mint all = mint(2).pow(N-1) - 1;
    for(auto &t : v){
        all -= mint(2).pow(t) - 1;
    }
    ans += all;
    return chs;
}

int main(){
    cin >> N;
    G.resize(N);
    for(int i=0;i<N-1;i++){
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
    }
    dfs(0);
    cout << ans / mint(2).pow(N) << endl;
    return 0;
}