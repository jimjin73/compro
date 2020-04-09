#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N;
ll a[110];
ll dp[110][22];
ll d[2] = {-1,1};

int main(){
    cin >> N;
    for(int i=0;i<N;i++) cin >> a[i];
    for(int i=0;i<N;i++){
        for(int j=0;j<=20;j++){
            dp[i][j] = 0;
        }
    }
    dp[0][a[0]]++;
    for(int i=1;i<N-1;i++){
        for(int j=0;j<=20;j++){
            for(int k=0;k<2;k++){
                int t = j + d[k] * a[i];
                if(t < 0 || t > 20) continue;
                dp[i][t] += dp[i-1][j];
            }
        }
    }
    cout << dp[N-2][a[N-1]] << endl;
    return 0;
}