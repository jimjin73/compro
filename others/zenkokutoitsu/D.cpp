#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

vector<vector<int>> G;
int N,M;
bool f[100000];
int c[100000];
int par[100000];

int bfs(int n,int d){

}

int main(){
    cin >> N >> M;
    G.resize(N);
    for(int i=0;i<N+M-1;i++){
        int a,b;
        cin >> a >> b;
        G[a-1].push_back(b-1);
        c[b-1]++;
    }
    int root = -1;
    for(int i=0;i<N;i++) if(c[i]==0) root = i;
    queue<P> q;
    q.push({root,0});
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        int n = p.first;
        int d = p.second;
        for(auto &e : G[n]){
            c[e]--;
            if(c[e] > 0) continue;
            par[e] = n+1;
            q.push({e,d+1});
        }
    }
    for(int i=0;i<N;i++) cout << par[i] << endl;
    return 0;
}