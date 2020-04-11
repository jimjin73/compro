#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll D[1010];
ll C[1010];
ll dp[1010][1010];
ll N,M;

int main(){
    cin >> N >> M;
    for(int i=0;i<N;i++){
        cin >> D[i];
    }
    for(int i=0;i<M;i++){
        cin >> C[i];
    }
    for(int i=1;i<=N;i++) dp[0][i] = 1e9;
    for(int i=0;i<=M;i++) dp[i][0] = 0;
    for(int i=1;i<=M;i++){
        for(int j=1;j<=N;j++){
            dp[i][j] = min(dp[i-1][j], dp[i-1][j-1] + D[j-1] * C[i-1]);
        }
    }
    cout << dp[M][N] << endl;
    return 0;
}