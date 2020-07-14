#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

ll N,K;
ll A[1001];
ll C[64];
bool ng[1000000];

int main(){
    cin >> N >> K;
    for(int i=1;i<=N;i++) cin >> A[i];
    for(int i=0;i<N;i++) A[i+1] += A[i];
    vector<ll> v;
    for(int i=0;i<N;i++){
        for(int j=i+1;j<=N;j++){
            v.push_back(A[j]-A[i]);
        }
    }
    for(int i=0;i<v.size();i++) ng[i] = true;
    ll ans = 0;
    for(int i=63;i>=0;i--){
        vector<ll> idx;
        ll c = 0;
        for(int j=0;j<v.size();j++){
            if(!ng[j]) continue;
            bitset<64> bt(v[j]);
            if(!bt[i]) idx.push_back(j);
            else c++;
        }
        if(c < K) continue;
        ans += (ll)1 << (ll)i;
        for(auto &e : idx) ng[e] = false;
    }
    cout << ans << endl;
    return 0;
}