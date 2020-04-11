#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N;
string s[5];
ll R[1000];
ll B[1000];
ll W[1000];
ll dp[1000][3];
ll C[1000][3];

int main(){
    cin >> N;
    for(int i=0;i<5;i++){
        cin >> s[i];
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<3;j++) C[i][j] = 0; 
        for(int j=0;j<5;j++){
            if(s[j][i] == 'R') C[i][0]++;
            if(s[j][i] == 'B') C[i][1]++;
            if(s[j][i] == 'W') C[i][2]++;
        }
    }
    for(int i=0;i<3;i++) dp[0][i] = 5 - C[0][i];
    for(int i=1;i<N;i++){
        for(int j=0;j<3;j++){
            dp[i][j] = 5 - C[i][j];
            ll min_v = 1e12;
            for(int k=0;k<3;k++){
                if(j==k) continue;
                min_v = min(min_v, dp[i-1][k]);
            }
            dp[i][j] += min_v;
        }
    }
    ll min_a = 1e12;
    for(int i=0;i<3;i++) min_a = min(min_a, dp[N-1][i]);
    cout << min_a << endl;
    return 0;
}