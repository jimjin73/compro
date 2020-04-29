#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<ll>> G;
ll N;
ll dp[100000][2];
ll MOD = 1e9+7;

ll dfs(ll n, ll col, ll par){
    if(dp[n][col] != -1) return dp[n][col];
    if((G[n].size() == 1 && par != -1) || (G[n].size() == 0 && par == -1)){
        if(col == 0) return dp[n][col] = 2;
        else return dp[n][col] = 1;
    }
    ll ans_w = 1;
    for(auto &e : G[n]){
        if(e == par) continue;
        ans_w *= dfs(e, 0, n);
        ans_w %= MOD;
    }
    if(col == 0){
        ll ans_b = 1;
        for(auto &e : G[n]){
            if(e == par) continue;
            ans_b *= dfs(e, 1, n);
            ans_b %= MOD;
        }
        ans_w += ans_b;
    }
    return  dp[n][col] = ans_w % MOD;
}

int main(){
    cin >> N;
    G.resize(N);
    for(int i=0;i<N-1;i++){
        ll a,b;
        cin >> a >> b;
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
    }
    for(int i=0;i<100000;i++) dp[i][0] = dp[i][1] = -1;
    cout << dfs(0,0,-1) << endl;
    return 0;
}