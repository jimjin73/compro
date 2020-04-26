#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N,M;
vector<vector<ll>> G;
ll dp[100000];

void dfs(ll n){
    if(dp[n] != -1) return;
    ll d = 0;
    for(auto &e : G[n]){
        dfs(e);
        d = max(d, dp[e]+1);
    }
    dp[n] = d;
    return;
}

int main(){
    cin >> N >> M;
    G.resize(N);
    for(int i=0;i<M;i++){
        ll a,b;
        cin >> a >> b;
        G[a-1].push_back(b-1);
    }
    for(int i=0;i<N;i++) dp[i] = -1;
    for(int i=0;i<N;i++) dfs(i);
    ll max_l = 0;
    for(int i=0;i<N;i++) max_l = max(max_l, dp[i]);
    cout << max_l << endl;
    return 0;
}