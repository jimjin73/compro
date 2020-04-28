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
ll a[100];
mint dp[100][100001];

int main(){
    cin >> N >> K;
    for(int i=0;i<N;i++) cin >> a[i];
    for(int j=0;j<=K;j++){
        if(j <= a[0]) dp[0][j] = mint(1);
        else mint(0);
    }
    for(int i=1;i<N;i++){
        for(int j=0;j<=K;j++){
            if(j == 0){
                dp[i][j] = mint(1);
                continue;
            }
            dp[i][j] = dp[i][j-1] + dp[i-1][j];
            if(j-a[i]-1 >= 0) dp[i][j] -= dp[i-1][j-a[i]-1];
        }
    }
    cout << dp[N-1][K] << endl;
    return 0;
}