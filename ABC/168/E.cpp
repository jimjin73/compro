#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

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

ll N;
vector< pair<ld,pair<ll,ll>> > v;
ld eps = 1e-8;

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        ll a,b;
        cin >> a >> b;
        if(b < 0){
            a *= -1;
            b *= -1;
        }
        ld ad,bd;
        ad = a;
        bd = b;
        ld rad = atan2l(bd,ad);
        v.push_back(make_pair(rad, make_pair(a,b)));
    } 
    sort(v.begin(),v.end());
    ll g[200000];
    for(int i=0;i<N;i++) g[i] = 1e15;
    for(int i=0;i<N;i++){
        if(g[i] == 1e15) g[i] = i+1;
        ld rad = v[i].first;
        ll x = v[i].second.first;
        ll y = v[i].second.second;
        auto sp = lower_bound(v.begin(),v.end(),make_pair(rad+M_PI/2.0-eps,make_pair((ll)0,(ll)0)));
        auto ep = upper_bound(v.begin(),v.end(),make_pair(rad+M_PI/2.0+eps,make_pair((ll)0,(ll)0)));
        for(auto itr=sp;itr!=ep;itr++){
            ll xx = (*itr).second.first;
            ll yy = (*itr).second.second;
            if(x*xx + y*yy == 0) {
                if(g[itr-v.begin()] != 1e15) g[i] = -g[itr-v.begin()];
                else g[itr-v.begin()] = -g[i];
            }
        }
    }
    unordered_map<ll,ll> um;
    for(int i=0;i<N;i++){
        if(um.find(g[i]) == um.end()) um[g[i]] = 1;
        else{
            um[g[i]] = 1 + um[g[i]];
        }
    }
    mint ans(1);
    for(auto p=um.begin(); p!=um.end(); p++){
        ll t = p->first;
        ll s = p->second;
        if(p->first < 0) continue;
        if(um.find(-t) == um.end()){
            ans *= mint(2).pow(s);
            ans *= (mint(2).pow(s) + mint(2).pow(um[-t]));
        }
    }
    cout << ans - 1 << endl;
    return 0;
}