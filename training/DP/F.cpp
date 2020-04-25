#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
string dp[3000][2];
string s,t;
 
int main(){
    cin >> s >> t;
    ll sl = s.size();
    ll tl = t.size();
    if(s[0]==t[0]) dp[0][0] = s[0];
    else dp[0][0] = "";
    for(int i=1;i<sl;i++){
        if(dp[i][0].size() > 0) dp[i][0] = dp[i-1][0];
        else{
            if(s[i] == t[0]) dp[i][0] = s[i];
            else dp[i][0] = "";
        }
    }
    for(int j=1;j<tl;j++){
        for(int i=0;i<sl;i++){
            if(i == 0){
                if(s[0]==t[j]){
                    dp[0][1] = s[0];
                    continue;
                }
                if(dp[0][0].size() > 0){
                    dp[0][1] = dp[0][0];
                    continue;
                }
                dp[0][1] = "";
                continue;
            }
            if(dp[i][0].size() > dp[i-1][1].size()) dp[i][1] = dp[i][0];
            else dp[i][1] = dp[i-1][1]; 
            if(s[i]!=t[j]) continue;
            if(dp[i][1].size() <= dp[i-1][0].size()) dp[i][1] = dp[i-1][0] + s[i];
        }
        for(int i=0;i<sl;i++) dp[i][0] = dp[i][1];
    }
    cout << dp[sl-1][0] << endl;
    return 0;
}