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

ll N,M;
vector<ll> A,B;

int main(){
    cin >> N >> M;
    for(int i=0;i<N;i++){
        ll tmp;
        cin >> tmp;
        A.push_back(tmp);
    }
    for(int j=0;j<M;j++){
        ll tmp;
        cin >> tmp;
        B.push_back(tmp);
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    A.erase(unique(A.begin(),A.end()), A.end());
    B.erase(unique(B.begin(),B.end()), B.end());
    if(A.size() != N || B.size() != M){
        cout << 0 << endl;
        return 0;
    }
    mint ans(1);
    for(int i=N*M;i>=1;i--){
        if(binary_search(A.begin(),A.end(),i) && binary_search(B.begin(),B.end(),i)) continue;
        if(binary_search(A.begin(),A.end(),i)){
            ll ind = B.end() - upper_bound(B.begin(),B.end(),i);
            ans *= mint(ind);
            continue;
        }
        if(binary_search(B.begin(),B.end(),i)){
            ll ind = A.end() - upper_bound(A.begin(),A.end(),i);
            ans *= mint(ind);
            continue;
        }
        ll ind_a = A.end() - upper_bound(A.begin(),A.end(),i);
        ll ind_b = B.end() - upper_bound(B.begin(),B.end(),i);
        ans *= mint(ind_a) * mint(ind_b) - mint(N*M-i);
    }
    cout << ans << endl;
    return 0;
}