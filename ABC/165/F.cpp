#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N;
vector<vector<ll>> G;
ll A[200000];
ll L[200000];
vector<ll> v;
ll INF = 1e15;

void dfs(ll n){
    ll ind = lower_bound(v.begin(),v.end(),A[n]) - v.begin();
    ll backup = v[ind];
    v[ind] = A[n];
    L[n] = lower_bound(v.begin(),v.end(),INF) - v.begin();
    for(auto &e : G[n]){
        if(L[e] != 0) continue;
        dfs(e);
    }
    v[ind] = backup;
}

int main(){
    cin >> N;
    G.resize(N);
    v.resize(N);
    for(int i=0;i<N;i++) cin >> A[i];
    for(int i=0;i<N-1;i++){
        ll a,b;
        cin >> a >> b;
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
    }
    for(int i=0;i<N;i++) v[i] = INF;
    dfs(0);
    for(int i=0;i<N;i++) cout << L[i] << endl;
    return 0;
}