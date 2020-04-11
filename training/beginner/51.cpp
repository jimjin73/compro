#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N;
string s;
ll dp[1010][8];

int c2i(char c){
    if(c == 'J') return 0;
    if(c == 'O') return 1;
    if(c == 'I') return 2;
    return -1;
}

int main(){
    cin >> N;
    cin >> s;
    for(int i=0;i<N;i++){
        for(int j=0;j<8;j++){
            dp[i][j] = 0;
        }
    }
    dp[0][1] = 1;
    for(int i=1;i<=N;i++){
        for(int j=0;j<8;j++){
            for(int k=0;k<8;k++){
                if((j&k) == 0) continue;
                if((j&(1<<c2i(s[i-1]))) == 0) continue;
                dp[i][j] += dp[i-1][k];
                dp[i][j] %= 10007; 
            }
        }
    }
    ll sum = 0;
    for(int i=0;i<8;i++) sum += dp[N][i];
    cout << sum % 10007 << endl;
    return 0;
}