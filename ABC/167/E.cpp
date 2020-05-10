#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;

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

ll N,M,K;
mint fact[200010];
mint fact_inv[200010];
mint mpow[200010];

mint comb(ll a,ll b){
    return fact[a] * fact_inv[b] * fact_inv[a-b];
}

int main(){
    cin >> N >> M >> K;
    fact[0] = mint(1);
    mpow[0] = mint(1);
    for(int i=1;i<=N;i++){
        fact[i] = fact[i-1] * mint(i);
        mpow[i] = mpow[i-1] * mint(M-1);
    }
    for(int i=0;i<=N;i++) fact_inv[i] = fact[i].inv();
    mint ans = mint(0);
    for(int i=0;i<=K;i++){
        ans += comb(N-1, i) * mint(M) * mpow[N - (i+1)];
    }
    cout << ans << endl;
    return 0;
}