#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N,K;
ll h[100001];
ll dp[100001];

int main(){
    cin >> N >> K;
    for(int i=0;i<N;i++) cin >> h[i];
    for(int i=0;i<N;i++) dp[i] = 1e12;
    dp[0] = 0;
    for(int i=0;i<N-1;i++){
        for(int j=1;j<=K && i+j<N;j++){
            dp[i+j] = min(dp[i+j], dp[i] + abs(h[i]-h[i+j]));
        }
    }
    cout << dp[N-1] << endl;
    return 0;
}