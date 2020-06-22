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

ll K;
string S;

mint fact[2000001];
mint v25[1000001];
mint v26[1000001];

mint comb(ll a, ll b){
    return fact[a] / fact[a-b] / fact[b];
}

int main(){
    cin >> K;
    cin >> S;
    ll L = S.size();
    fact[0] = mint(1);
    for(int i=1;i<=2000000;i++) fact[i] = mint(i) * fact[i-1];
    v26[0] = v25[0] = mint(1);
    for(int i=1;i<=1000000;i++){
        v26[i] = mint(26) * v26[i-1];
        v25[i] = mint(25) * v25[i-1];
    }
    mint ans(0);
    for(int i=0;i<=K;i++){
        ans += comb(K-i+L-1,L-1) * v26[i] * v25[K-i];
    }
    cout << ans << endl;
    return 0;
}