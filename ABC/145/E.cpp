#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N,T;
ll dp[6000][3001];
vector<pair<ll,ll>> v;

int main(){
    cin >> N >> T;
    for(int i=0;i<N;i++){
        ll a,b;
        cin >> a >> b;
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(),v.end());
    for(int i=0;i<2*T;i++){
        for(int j=0;j<=N;j++) dp[i][j] = -1e15;
    }
    dp[0][0] = 0;
    for(int i=0;i<T;i++){
        for(int j=0;j<=N;j++){
            dp[i+1][j] = max(dp[i][j], dp[i+1][j]);
            if(j < N){
                dp[i][j+1] = max(dp[i][j], dp[i][j+1]);
                dp[i+v[j].first][j+1] = max(dp[i][j]+v[j].second, dp[i+v[j].first][j+1]);
            }
        }
    }
    ll max_b = -1;
    for(int i=T;i<T+3000;i++){
        for(int j=0;j<=N;j++){
            max_b = max(max_b, dp[i][j]);
        }
    }
    cout << max_b << endl;
    return 0;
}