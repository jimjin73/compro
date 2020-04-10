#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll D,N;
ll T[250];
ll A[250][3];
ll dp[250][250];

int main(){
    cin >> D >> N;
    for(int i=0;i<D;i++) cin >> T[i];
    for(int i=0;i<N;i++){
        for(int j=0;j<3;j++){
            cin >> A[i][j];
        }
    }
    for(int i=0;i<D;i++){
        for(int j=0;j<N;j++){
            dp[i][j] = -1e9;
        }
    }
    for(int i=0;i<N;i++){
        if(T[0] >= A[i][0] && T[0] <= A[i][1]) dp[0][i] = 0;
    }
    for(int i=1;i<D;i++){
        for(int j=0;j<N;j++){
            if(T[i] < A[j][0] || T[i] > A[j][1]) continue;
            for(int k=0;k<N;k++){
                dp[i][j] = max(dp[i][j], dp[i-1][k] + abs(A[k][2] - A[j][2]));
            }
        }
    }
    ll ans = -1e9;
    for(int i=0;i<N;i++) ans = max(ans, dp[D-1][i]);
    cout << ans << endl;
    return 0;
}