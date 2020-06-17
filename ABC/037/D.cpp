#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> Q;

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

ll H,W;
ll A[1000][1000];
mint M[1000][1000];
bool f[1000][1000];
priority_queue<Q,vector<Q>,greater<Q>> pq; 
int d[5] = {0,-1,0,1,0};

void dfs(ll x, ll y){
    if(f[x][y]) return;
    M[x][y] = mint(1);
    for(int i=0;i<4;i++){
        ll dx = x + d[i];
        ll dy = y + d[i+1];
        if(dx < 0 || dx >= H) continue;
        if(dy < 0 || dy >= W) continue;
        if(A[dx][dy] <= A[x][y]) continue;
        dfs(dx,dy);
        M[x][y] += M[dx][dy];
    }
    f[x][y] = true;
}

int main(){
    cin >> H >> W;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin >> A[i][j];
            pq.push({A[i][j],{i,j}});
        }
    }
    mint ans(0);
    while(!pq.empty()){
        auto t = pq.top();
        ll x = t.second.first;
        ll y = t.second.second;
        pq.pop();
        if(f[x][y]) continue;
        dfs(x,y);
    }
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            ans += M[i][j];
        }
    }
    cout << ans << endl;
    return 0;
}