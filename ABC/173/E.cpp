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
        if((t & 1) == 1) m *= *this;
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
ll A[300000];

bool isPos(){
    ll c = 0;
    for(int i=0;i<N;i++){
        if(A[i] < 0) c++;
    }
    if(N > c){
        if(N==K) return c%2 == 0;
        return true;
    }
    return K%2 == 0;
}

int main(){
    cin >> N >> K;
    for(int i=0;i<N;i++) cin >> A[i];
    if(isPos()){
        vector<ll> P;
        vector<ll> M;
        for(int i=0;i<N;i++){
            if(A[i]>=0) P.push_back(A[i]);
            else M.push_back(abs(A[i]));
        }
        sort(P.rbegin(),P.rend());
        sort(M.rbegin(),M.rend());
        mint ans(1);
        int s = 0;
        if(K % 2 == 1){
            ans *= mint(P[0]);
            s++;
        }
        vector<ll> t;
        for(int i=0;i+1<M.size();i+=2) t.push_back(M[i]*M[i+1]);
        for(int i=s;i+1<P.size();i+=2) t.push_back(P[i]*P[i+1]);
        sort(t.rbegin(),t.rend());
        for(int i=0;i<(K-s)/2;i++) ans *= t[i];
        cout << ans << endl;
    }else{
        vector<ll> v;
        for(int i=0;i<N;i++) v.push_back(abs(A[i]));
        sort(v.begin(),v.end());
        mint ans(1);
        for(int i=0;i<K;i++) ans *= mint(v[i]);
        cout << mint(0) - ans << endl;
    }
    return 0;
}