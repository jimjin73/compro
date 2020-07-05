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

ll N,K;
vector<ll> P,M;

bool check(ll pn,ll mn){
    if(pn == 0 && K%2==1) return false;
    return true;
}


int main(){
    cin >> N >> K;
    for(int i=0;i<N;i++){
        ll a;
        cin >> a;
        if(a>0) P.push_back(a);
        if(a<0) M.push_back(a);
    }
    ll pn,mn,zn;
    pn = P.size();
    mn = M.size();
    zn = N - pn - mn;
    if(pn > 0) sort(P.rbegin(),P.rend());
    if(mn > 0) sort(M.begin(),M.end());
    if(check(pn,mn)){
        vector<ll> p,m;
        for(int i=0;i+1<pn;i+=2){
            p.push_back(P[i]*P[i+1]);
        }
        for(int i=0;i+1<mn;i+=2){
            m.push_back(M[i]*M[i+1]);
        }
        mint ans(1);
        ll k = 0;
        ll pp,mp;
        pp = mp = 0;
        while(k < (K/2)*2){
            if(pp < p.size() && mp < m.size()){
                if(p[pp] > m[mp]){
                    ans *= mint(p[pp]);
                    pp++;
                }else{
                    ans *= mint(m[mp]);
                    mp++;
                }
                k += 2;
                continue;
            }
            if(pp < p.size()){
                ans *= mint(p[pp]);
                pp++;
            }else{
                ans *= mint(m[mp]);
                mp++;
            }
            k += 2; 
        }
        if(k < K){
            ans *= P[pp*2];
        }
        cout << ans << endl;
    }else if(zn >= 1){
        cout << 0 << endl;
    }else{
        vector<ll> t;
        for(auto &e : P) t.push_back(e);
        for(auto &e : M) t.push_back(-1 * e);
        sort(t.begin(),t.end());
        mint ans(1);
        for(int i=0;i<K;i++) ans *= mint(t[i]);
        ans *= mint(-1);
        cout << ans << endl;
    }
    return 0;
}