#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll H,W;
ll A[80][80];
ll B[80][80];
bool dp[80][80][30000];
int BASE = 15000;

int main(){
    cin >> H >> W;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin >> A[i][j];
        }
    }
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin >> B[i][j];
        }
    }
    for(int i=0;i<30000;i++) dp[0][0][i] = false;
    dp[0][0][A[0][0] - B[0][0] + BASE] = true;
    dp[0][0][B[0][0] - A[0][0] + BASE] = true;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(i==0 && j==0) continue;
            for(int k=0;k<30000;k++) dp[i][j][k] = false;
            ll diff1 = A[i][j] - B[i][j];
            ll diff2 = B[i][j] - A[i][j];
            if(j==0){
                for(int k=0;k<30000;k++){
                    if(k-diff1 > 0 && k-diff1 < 30000) dp[i][j][k] = dp[i][j][k] || dp[i-1][j][k-diff1];
                    if(k-diff2 > 0 && k-diff2 < 30000) dp[i][j][k] = dp[i][j][k] || dp[i-1][j][k-diff2];
                }
                continue;
            }
            if(i==0){
                for(int k=0;k<30000;k++){
                    if(k-diff1 > 0 && k-diff1 < 30000) dp[i][j][k] = dp[i][j][k] || dp[i][j-1][k-diff1];
                    if(k-diff2 > 0 && k-diff2 < 30000) dp[i][j][k] = dp[i][j][k] || dp[i][j-1][k-diff2];
                }
                continue;
            }
            for(int k=0;k<30000;k++){
                if(k-diff1 > 0 && k-diff1 < 30000) dp[i][j][k] = dp[i][j][k] || dp[i-1][j][k-diff1];
                if(k-diff2 > 0 && k-diff2 < 30000) dp[i][j][k] = dp[i][j][k] || dp[i-1][j][k-diff2];
                if(k-diff1 > 0 && k-diff1 < 30000) dp[i][j][k] = dp[i][j][k] || dp[i][j-1][k-diff1];
                if(k-diff2 > 0 && k-diff2 < 30000) dp[i][j][k] = dp[i][j][k] || dp[i][j-1][k-diff2];
            }
        }
    }
    ll min_l = 1e15;
    for(int i=0;i<30000;i++){
        if(dp[H-1][W-1][i]) min_l = min(min_l, (ll)abs(BASE - i));
    }
    cout << min_l << endl;
    return 0;
}