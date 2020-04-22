#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N;
ll h[100001];
ll dp[100001];

int main(){
    cin >> N;
    for(int i=0;i<N;i++) cin >> h[i];
    dp[0] = 0;
    dp[1] = abs(h[0]-h[1]);
    for(int i=2;i<N;i++) dp[i] = min(dp[i-2] + abs(h[i]-h[i-2]), dp[i-1] + abs(h[i]-h[i-1]));
    cout << dp[N-1] << endl;
    return 0;
}