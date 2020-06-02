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

mint dp[110][10];
ll H,W,K;
mint p[10][3];

int main(){
    cin >> H >> W >> K;
    dp[0][0] = mint(1);
    for(int i=0;i<(1<<(W-1));i++){
        bitset<10> bt(i);
        bool f = true;
        for(int j=1;j<(W-1);j++){
            if(bt[j-1] == 1 && bt[j] == 1) f = false;
        }
        if(!f) continue;
        for(int j=0;j<W;j++){
            if(j == 0){
                if(bt[0] == 1) p[0][2] += mint(1);
                else p[0][0] += mint(1);
                continue;
            }
            if(j == W-1){
                if(bt[W-2] == 1) p[W-1][1] += mint(1);
                else p[W-1][0] += mint(1);
                continue;
            }
            if(bt[j-1] == 0 && bt[j] == 0){
                p[j][0] += mint(1);
                continue;
            }
            if(bt[j-1] == 1) p[j][1] += mint(1);
            else p[j][2] += mint(1);
        }
    }
    for(int i=1;i<W;i++) dp[0][i] = mint(0);
    for(int h=1;h<=H;h++){
        for(int w=0;w<W;w++){
            dp[h][w] = dp[h-1][w] * p[w][0];
            if(w > 0) dp[h][w] += dp[h-1][w-1] * p[w][1];
            if(w < W-1) dp[h][w] += dp[h-1][w+1] * p[w][2];
        }
    }
    cout << dp[H][K-1] << endl;
    return 0;
}