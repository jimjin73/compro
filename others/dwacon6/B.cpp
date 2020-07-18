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
    bool operator==(const mint& m){
        return n == m.n;
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
        if((t & 1) == 1) m *= *this;
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

ll N;
ll X[100000];
mint f[100000];
mint g[100000];

int main(){
    cin >> N;
    for(int i=0;i<N;i++) cin >> X[i];
    f[0] = mint(1);
    for(int i=1;i<N;i++) f[i] = f[i-1] * mint(i);
    f[0] = f[N-1];
    for(int i=1;i<N;i++) f[i] = f[0] / mint(i);
    for(int i=2;i<N;i++) f[i] += f[i-1];
    vector<ll> v;
    for(int i=1;i<N;i++) v.push_back(X[i]-X[i-1]);
    mint ans(0);
    for(int i=1;i<N;i++){
        ans += f[i] * v[i-1];
    }
    cout << ans << endl;
    return 0;
}