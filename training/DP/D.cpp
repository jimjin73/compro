#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N,W;
ll w[101];
ll v[101];
ll dp[101][100001];

int main(){
    cin >> N >> W;
    for(int i=0;i<N;i++) cin >> w[i] >> v[i];
    for(int i=0;i<=N;i++) dp[i][0] = 0;
    for(int i=0;i<=W;i++) dp[0][i] = 0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=W;j++){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if(j - w[i-1] >= 0){
                dp[i][j] = max(dp[i][j], dp[i-1][j-w[i-1]] + v[i-1]);
            }
        }
    }
    cout << dp[N][W] << endl;
    return 0;
}