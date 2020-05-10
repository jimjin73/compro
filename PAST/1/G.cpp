#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int g[10];
int m[10][10];
int N;

ll dfs(ll d){
    if(d == N){
        vector<ll> v[3];
        for(int i=0;i<N;i++){
            v[g[i]].push_back(i);
        }
        ll score = 0;
        for(int i=0;i<3;i++){
            for(int j=0;j<v[i].size();j++){
                for(int k=j+1;k<v[i].size();k++){
                    score += m[v[i][j]][v[i][k]];
                }
            }
        }
        return score;
    }
    ll score = -1e15;
    for(int i=0;i<3;i++){
        g[d] = i;
        score = max(score,dfs(d+1));
    }
    return score;
}

int main(){
    cin >> N;
    for(int i=0;i<N-1;i++){
        for(int j=i+1;j<N;j++){
            cin >> m[i][j];
        }
    }
    cout << dfs(0) << endl;
    return 0;
}