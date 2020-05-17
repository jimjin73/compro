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

const int MAX_N = 1000001;
bool isP[MAX_N];
vector<ll> p_vec;
ll N;
ll A[10000];

int main(){
    cin >> N;
    for(int i=0;i<N;i++) cin >> A[i];
    isP[0] = isP[1] = true;
    for(int i=2;i<MAX_N;i++){
        if(isP[i]) continue;
        p_vec.push_back(i);
        for(int j=2;i*j<MAX_N;j++) isP[i*j] = true;
    }
    vector<ll> p_count(p_vec.size(),0);
    for(int i=0;i<N;i++){
        ll ai = A[i];
        for(int j=0;j<p_vec.size()&&p_vec[j]*p_vec[j]<=A[i];j++){
            ll c = 0;
            while(ai % p_vec[j] == 0){
                ai /= p_vec[j];
                c++;
            }
            p_count[j] = max(p_count[j], c);
            if(ai == 1){
                break;
            }
        }
        if(ai != 1){
            ll ind = lower_bound(p_vec.begin(),p_vec.end(),ai) - p_vec.begin();
            p_count[ind] = max(p_count[ind],(ll)1);
        }
    }
    mint lcm = 1;
    for(int j=0;j<p_vec.size();j++) lcm *= (mint(p_vec[j])).pow(p_count[j]);
    mint ans = 0;
    for(int i=0;i<N;i++) ans += lcm / A[i];
    cout << ans << endl;
    return 0;
}