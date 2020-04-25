#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N,W;
ll w[101];
ll v[101];
ll dp[101][100002];

int main(){
    cin >> N >> W;
    ll V = N * 1000 + 1;
    for(int i=0;i<N;i++) cin >> w[i] >> v[i];
    for(int i=0;i<=V;i++) dp[0][i] = 1e15;
    for(int i=1;i<=N;i++) dp[i][V] = 1e15;
    dp[0][0] = 0;
    for(int i=1;i<=N;i++){
        for(int j=V-1;j>=0;j--){
            dp[i][j] = min(dp[i-1][j], dp[i][j+1]);
            if(j - v[i-1] >= 0){
                dp[i][j] = min(dp[i][j], dp[i-1][j-v[i-1]] + w[i-1]);
            }
        }
    }
    for(int i=V;i>=0;i--){
        if(dp[N][i] <= W){
            cout << i << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}