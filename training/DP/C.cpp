#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N;
ll a[100000][3];
ll dp[100000][3];

int main(){
    cin >> N;
    for(int i=0;i<N;i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
    for(int i=0;i<N;i++){
        for(int j=0;j<3;j++){
            dp[i][j] = 0;
        }
    }
    for(int i=0;i<3;i++) dp[0][i] = a[0][i];
    for(int i=1;i<N;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if(j==k) continue;
                dp[i][j] = max(dp[i-1][k]+a[i][j], dp[i][j]);
            }
        }
    }
    cout << max(max(dp[N-1][0],dp[N-1][1]),dp[N-1][2]) << endl;
    return 0;
}