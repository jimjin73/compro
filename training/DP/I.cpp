#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N;
double dp[3000][3000];
double p[3000];

int main(){
    cin >> N;
    for(int i=0;i<N;i++) cin >> p[i];
    dp[0][0] = 1;
    for(int i=1;i<=N;i++){
        for(int j=0;j<=i;j++){
            dp[i][j] = dp[i-1][j-1] * p[i-1];
            if(j < i) dp[i][j] += dp[i-1][j] * (1.0 - p[i-1]);
        }
    }
    double ans = 0;
    for(int i=N/2+1;i<=N;i++) ans += dp[N][i];
    cout << fixed << setprecision(15) << ans << endl;
    return 0;
}