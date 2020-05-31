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
vector<pair<ll,ll>> dp[3001][3001];
unordered_map<ll,mint> um;

ll ind(ll a, ll b, ll c){
    return ((a*3000)+b)*3000+c;
}

mint dfs(ll n,ll s,ll c){
    if(um.find(ind(n,s,c)) != um.end()) return um[ind(n,s,c)];
    if(s == 0){
        return um[ind(n,s,c)] = mint(2).pow(N-c);
    }
    mint ret(0);
    for(auto &e : dp[n][s]){
        ll d = c;
        if(s != e.second) d++;
        ret += dfs(e.first,e.second,d);
    }
    return um[ind(n,s,c)] = ret;
}

int main(){
    cin >> N >> S;
    for(int i=0;i<N;i++) cin >> A[i];
    dp[0][0].push_back({-1,-1});
    for(int i=0;i<N;i++){
        for(int j=0;j<=S;j++){
            if(dp[i][j].size()==0) continue;
            dp[i+1][j].push_back({i,j});
            if(j+A[i] > S) continue;
            dp[i+1][j+A[i]].push_back({i,j});
        }
    }
    cout << dfs(N,S,0) << endl;
    return 0;
}