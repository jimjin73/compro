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
ll x[100000];
ll y[100000];
mint X;

int main(){
    cin >> N >> M;
    for(int i=0;i<N;i++) cin >> x[i];
    for(int i=0;i<M;i++) cin >> y[i];
    X = mint(0);
    ll n = N-1;
    ll m = M-1;
    for(ll i=0;i<n;i++){
        X += (mint(x[i+1] - x[i]) * (mint(i+1) * mint(n-i)));
    }
    mint S(0);
    for(ll i=0;i<m;i++){
        S += (mint(y[i+1] - y[i]) * (mint(i+1) * mint(m-i))) * X;
    }
    cout << S << endl;
    return 0;
}