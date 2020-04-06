#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int m[100][100];
int N,M;
int max_l = 0;
int d[5] = {0,1,0,-1,0};

void dfs(int x, int y, int l){
    if(m[x][y] == 0){
        max_l = max(l,max_l);
        return;
    }
    m[x][y] = 0;
    for(int i=0;i<4;i++){
        dfs(x+d[i],y+d[i+1],l+1);
    }
    m[x][y] = 1;
    return;
}

int main(){
    cin >> N >> M;
    for(int i=0;i<=N+1;i++){
        for(int j=0;j<=M+1;j++){
            m[i][j] = 0;
        }
    }
    int t;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> t;
            m[i+1][j+1] = t;
        }
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            dfs(i,j,0);
        }
    }
    cout << max_l << endl;
    return 0;
}