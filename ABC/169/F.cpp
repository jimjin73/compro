#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

ll MOD = 998244353;

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

ll N,S;
ll A[3000];
mint dp[3050][3050];

int main(){
    cin >> N >> S;
    mint t = mint(1) / mint(2);
    for(int i=0;i<N;i++) cin >> A[i];
    dp[0][0] = mint(2).pow(N);
    for(int i=0;i<N;i++){
        for(int j=0;j<=S;j++){
            if(dp[i][j] == mint(0)) continue;
            dp[i+1][j] += dp[i][j];
            if(j+A[i]<=S){
                dp[i+1][j+A[i]] += dp[i][j] * t;
            }
        }
    }
    cout << dp[N][S] << endl;
    return 0;
}