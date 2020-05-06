#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

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
vector<ll> v;
mint fact[100001];
mint inv_fact[100001];

mint comb(ll a, ll b){
    if(a == b) return mint(1);
    if(b==0) return mint(1);
    return fact[a] * inv_fact[b] * inv_fact[a-b];
}

int main(){
    cin >> N >> K;
    for(int i=0;i<N;i++){
        ll a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.rbegin(),v.rend());
    mint ans(0);
    fact[0] = mint(1);
    inv_fact[0] = mint(1);
    for(int i=1;i<=N;i++) fact[i] = fact[i-1] * mint(i);
    for(int i=1;i<=N;i++) inv_fact[i] = fact[i].inv();
    for(int i=0;i<N;i++){
        if(N-i-1 < K-1) break;
        ans += mint(v[i]) * comb(N-i-1, K-1);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<N;i++){
        if(N-i-1 < K-1) break;
        ans -= mint(v[i]) * comb(N-i-1, K-1);
    }
    cout << ans << endl;
    return 0;
}