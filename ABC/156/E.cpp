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

ll N,K;
mint f[200001];
mint f_inv[200001];

mint comb(ll a, ll b){
    return f[a] * f_inv[b] * f_inv[a-b];
}

int main(){
    cin >> N >> K;
    f[0] = f_inv[0] = mint(1);
    for(int i=1;i<=200000;i++) f[i] = f[i-1] * mint(i), f_inv[i] = f[i].inv();
    mint ans(0);
    for(int i=0;i<=K&&i<N;i++){
        ans += comb(N,i) * comb(N-1,N-i-1);
    }
    cout << ans << endl;
    return 0;
}