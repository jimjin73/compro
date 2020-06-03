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

ll N;
ll T[100000];
ll A[100000];
bool t[100000];
bool a[100000];

int main(){
    cin >> N;
    for(int i=0;i<N;i++) cin >> T[i];
    for(int i=0;i<N;i++) cin >> A[i];
    t[0] = true;
    for(int i=1;i<N;i++){
        t[i] = (T[i] > T[i-1]);
    }
    a[N-1] = true;
    for(int i=N-2;i>=0;i--){
        a[i] = (A[i] > A[i+1]);
    }
    mint ans = mint(1);
    for(int i=0;i<N;i++){
        if(a[i] && t[i]){
            if(A[i] != T[i]) ans *= mint(0);
        }else if(a[i]){
            if(A[i] > T[i]) ans *=  mint(0);
        }else if(t[i]){
            if(T[i] > A[i]) ans *= mint(0);
        }else{
            ans *= mint(min(A[i],T[i]));
        }
    }
    cout << ans << endl;
    return 0;
}