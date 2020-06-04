#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

ll N;
string s[200];
ll t[200];
ll m[200][200];
vector<vector<ll>> G;

bool dfs(ll n){
    ll count = 0;
    for(auto &e : G[n]){
        if(t[e] == 0) count++;
        if(t[e] == t[n]) return false;
    }
    if(count == 0) return true;
    for(auto &e : G[n]){
        if(t[e] != 0) continue;
        t[e] = (t[n] == 1) ? 2 : 1;
        if(!dfs(e)) return false;
    }
    return true;
}

int main(){
    cin >> N;
    G.resize(N);
    for(int i=0;i<N;i++) cin >> s[i];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(s[i][j] == '0') m[i][j] = 1e9;
            else{
                m[i][j] = 1;
                G[i].push_back(j);
                G[j].push_back(i);
            }
        }
    }
    t[0] = 1;
    if(!dfs(0)){
        cout << -1 << endl;
        return 0;
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(s[i][j] == '0') m[i][j] = 1e9;
            else m[i][j] = 1;
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                m[j][k] = min(m[j][k], m[j][i] + m[i][k]);
            }
        }
    }
    ll l = 0;
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            l = max(l,m[i][j]);
        }
    }
    cout << l+1 << endl;
    return 0;
}