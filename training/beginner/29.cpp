#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int R,C;
int sx,sy;
int ex,ey;
string m[60];
int l[60][60];
queue<pair<int, int>> q;
int d[5] = {0,-1,0,1,0};

int main(){
    cin >> R >> C;
    cin >> sx >> sy;
    cin >> ex >> ey;
    sx--;
    sy--;
    ex--;
    ey--;
    for(int i=0;i<R;i++) cin >> m[i];
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            l[i][j] = -1;
        }
    }
    q.push(make_pair(sx,sy));
    l[sx][sy] = 0;
    while(true){
        pair<int,int> p = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;
        if(x == ex && y == ey) break;
        for(int i=0;i<4;i++){
            int dx = x+d[i];
            int dy = y+d[i+1];
            if(m[dx][dy] == '#' || l[dx][dy] >= 0) continue;
            l[dx][dy] = l[x][y] + 1;
            q.push(make_pair(dx,dy));
        }
    }
    cout << l[ex][ey] << endl;
    return 0;
}