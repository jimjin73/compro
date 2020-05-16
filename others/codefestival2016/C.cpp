#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<ll>> G;
ll N,M; 
ll d[200000];

void dfs(ll p){
    d[p]++;
    for(auto &e : G[p]){
        if(d[e] > 0) continue;
        dfs(e);
    }
}

bool check(){
    for(int i=0;i<N;i++){
        if(d[i] == 0) return false;
    }
    return true;
}

int main(){
    cin >> N >> M;
    G.resize(N+M);
    for(int i=0;i<N;i++){
        ll K;
        cin >> K;
        for(int j=0;j<K;j++){
            ll L;
            cin >> L;
            L--;
            G[i].push_back(N+L);
            G[N+L].push_back(i);
        }
    }
    dfs(0);
    if(check()) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}