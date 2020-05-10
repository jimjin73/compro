#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<int>> G;
vector<int> chs[150000];
int N;
int root;
int a[100000];
int b[100000];

void dfs(int p){
    if(G[p].size()==0) return;
    for(auto &e : G[p]){
        dfs(e);
        chs[p].push_back(e);
        for(auto &g : chs[e]){
            chs[p].push_back(g);
        }
    }
    sort(chs[p].begin(),chs[p].end());
}

int main(){
    cin >> N;
    G.resize(N);
    for(int i=0;i<N;i++){
        int p;
        cin >> p;
        if(p==-1) root = i;
        else G[p-1].push_back(i);
    }
    int Q;
    cin >> Q;
    for(int i=0;i<Q;i++){
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
    }
    dfs(root);
    for(int i=0;i<Q;i++){
        if(binary_search(chs[b[i]].begin(), chs[b[i]].end(), a[i])) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}