#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll MOD = 1e9+7;
ll N;
ll m[30][30];
ll check;
ll dp[21][1<<21];

ll dfs(ll d){
    ll ans = 0;
    if(dp[d][check] != -1) return dp[d][check];
    if(d == N-1){
        for(int i=0;i<N;i++){
            if(m[N-1][i] == 1 && ((check>>i)&1) == 0) ans++;
        }
        ans %= MOD;
        return dp[d][check] = ans;
    }
    for(int i=0;i<N;i++){
        if(m[d][i] == 1 && ((check>>i)&1) == 0){
            check += (1<<i);
            ans += dfs(d+1);
            check -= (1<<i);
        }
    }
    ans %= MOD;
    return dp[d][check] = ans;
}

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> m[i][j];
        }
    }
    check = 0;
    for(int i=0;i<21;i++){
        for(int j=0;j<1<<21;j++){
            dp[i][j] = -1;
        }
    }
    cout << dfs(0) << endl;
    return 0;
}