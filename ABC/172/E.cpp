#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

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


ll N,M;
mint fac[600000];
mint inv[600000];

mint comb(ll a, ll b){
    return fac[a] * inv[a-b] * inv[b];
}

mint pat(ll a, ll b){
    return fac[a] * inv[a-b];
}

int main(){
    cin >> N >> M;
    fac[0] = inv[0] = mint(1);
    for(int i=1;i<=M;i++){
        fac[i] = mint(i) * fac[i-1];
        inv[i] = fac[i].inv();
    }
    mint ans(0);
    for(int k=0;k<=N;k++){
        mint t = comb(N,k) * pat(M-k,N-k);
        if(k%2 == 0) ans += t;
        else ans -= t;
    }
    cout << ans * pat(M,N) << endl;
    return 0;
}