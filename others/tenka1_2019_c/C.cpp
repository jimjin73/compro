#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

template <typename T>
struct cumsum{
    vector<T> V;
    ll L;
    cumsum(vector<T> &v) : V(v){     
        L = V.size();
        for(int i=1;i<L;i++) V[i] += V[i-1];
    } 
    T query(int a, int b){
        if(a == b) return 0;
        T ret = V[b-1];
        if(a > 0) ret -= V[a-1];
        return ret;
    }
};

int N;
string S;

int main(){
    cin >> N;
    cin >> S;
    vector<int> v(N,0);
    for(int i=0;i<N;i++) if(S[i] == '.') v[i]=1;
    cumsum<int> cs(v);
    int ans = 1e8;
    for(int i=0;i<=N;i++){
        int b = i - cs.query(0,i);
        int w = cs.query(i,N);
        ans = min(ans, b+w);
    }
    cout << ans << endl;
    return 0;
}