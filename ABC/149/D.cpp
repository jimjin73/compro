#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N,K;
ll R,S,P;
string T;
ll dp[100000][3];

int main(){
    cin >> N >> K;
    cin >> R >> S >> P;
    cin >> T;
    for(int i=0;i<N;i++){
        for(int j=0;j<3;j++){
            dp[i][j] = 0;
        }
    }
    for(int base=0;base<K;base++){
        if(T[base] == 'r'){
            dp[base][2] += P;
        }
        if(T[base] == 's'){
            dp[base][0] += R;
        }
        if(T[base] == 'p'){
            dp[base][1] += S;
        }
        for(int i=1;base+i*K<N;i++){
            if(T[base+i*K] == 'r'){
                dp[base+i*K][2] = P + max(dp[base+(i-1)*K][0],dp[base+(i-1)*K][1]);
                dp[base+i*K][0] = max(dp[base+(i-1)*K][1],dp[base+(i-1)*K][2]);
                dp[base+i*K][1] = max(dp[base+(i-1)*K][0],dp[base+(i-1)*K][2]);
            }
            if(T[base+i*K] == 's'){
                dp[base+i*K][0] = R + max(dp[base+(i-1)*K][1],dp[base+(i-1)*K][2]);
                dp[base+i*K][1] = max(dp[base+(i-1)*K][0],dp[base+(i-1)*K][2]);
                dp[base+i*K][2] = max(dp[base+(i-1)*K][0],dp[base+(i-1)*K][1]);
            }
            if(T[base+i*K] == 'p'){
                dp[base+i*K][1] = S + max(dp[base+(i-1)*K][0],dp[base+(i-1)*K][2]);
                dp[base+i*K][0] = max(dp[base+(i-1)*K][1],dp[base+(i-1)*K][2]);
                dp[base+i*K][2] = max(dp[base+(i-1)*K][0],dp[base+(i-1)*K][1]);
            }
        }
    }
    ll score = 0;
    for(int i=0;i<K;i++){
        score += max(dp[N-1-i][0],max(dp[N-1-i][1],dp[N-1-i][2]));
    }
    cout << score << endl;
    return 0;
}