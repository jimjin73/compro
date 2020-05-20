#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

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


ll N,L;
string S;
string T[1000];
mint dp[1001];
vector<ll> v[1000];

void search(int ind){
    ll l = T[ind].size();
    for(int i=0;i<=L-l;i++){
        for(int j=0;j<l;j++){
            if(S[i+j] != T[ind][j]) break;
            if(j == l-1) v[i].push_back(l);
        }
    }
}

int main(){
    cin >> N;
    cin >> S;
    L = S.size();
    for(int i=0;i<N;i++) cin >> T[i];
    for(int i=0;i<N;i++) search(i);
    dp[0] = mint(1);
    for(int i=0;i<L;i++){
        for(auto &e : v[i]){
            dp[i+e] += dp[i];
        }
    }
    cout << dp[L] << endl;
    return 0;
}