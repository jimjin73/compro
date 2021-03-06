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

vector<ll> v;
mint fact[2000000];
mint inv_fact[2000000];

mint comb(ll a, ll b){
    return fact[a] * inv_fact[b] * inv_fact[a-b];
}

int main(){
    ll N,M;
    cin >> N >> M;
    fact[0] = mint(1);
    for(int i=1;i<2000000;i++) fact[i] = mint(i) * fact[i-1];
    for(int i=0;i<2000000;i++) inv_fact[i] = fact[i].inv();
    ll m = M;
    for(int i=2;i*i<=M;i++){
        ll c = 0;
        while(m % i == 0){
            m /= i;
            c++;
        }
        if(c>0) v.push_back(c);
    }
    if(m > 1) v.push_back(1);
    mint ans(1);
    for(auto &e : v){
        ans *= comb(N+e-1,e);
    }
    cout << ans << endl;
    return 0;
}