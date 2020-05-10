#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N,M;
int sinfo[1000];
ll scost[1000];
ll dp[1024];

int getinfo(string &s){
    int ans = 0;
    for(int i=0;i<N;i++){
        ans *= 2;
        if(s[i] == 'Y') ans++;
    }
    return ans;
}

int main(){
    cin >> N >> M;
    for(int i=0;i<M;i++){
        string s;
        cin >> s >> scost[i];
        sinfo[i] = getinfo(s);
    }
    for(int i=0;i<(1<<N);i++) dp[i] = 1e15;
    dp[0] = 0;
    for(int i=0;i<N;i++){
        vector<int> v;
        for(int j=0;j<N-i;j++) v.push_back(0);
        for(int j=N-i;j<N;j++) v.push_back(1);
        do{
            int vn = 0;
            for(auto &e : v){
                vn *= 2;
                vn += e;
            }
            for(int j=0;j<M;j++){
                if((vn | sinfo[j]) == vn) continue;
                dp[vn | sinfo[j]] = min(dp[vn | sinfo[j]], dp[vn] + scost[j]);
            }
        }while(next_permutation(v.begin(), v.end()));
    }
    if(dp[(1<<N)-1] == 1e15) cout << -1 << endl;
    else cout << dp[(1<<N)-1] << endl;
    return 0;
}