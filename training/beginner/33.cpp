#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int H,W;
string s[55];
queue<pair<int,int>> q;
int m[55][55];
int d[5] = {0,-1,0,1,0};

int main(){
    cin >> H >> W;
    for(int i=0;i<H;i++) cin >> s[i];
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            m[i][j] = -1;
        }
    }
    q.push(make_pair(0,0));
    m[0][0] = 1;
    while(!q.empty()){
        pair<int,int> p = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;
        if(x == H-1 && y == W-1) break;
        for(int i=0;i<4;i++){
            int xx = x + d[i];
            int yy = y + d[i+1];
            if(xx < 0 && xx >= H) continue;
            if(yy < 0 && yy >= W) continue;
            if(m[xx][yy] != -1) continue;
            if(s[xx][yy] == '#') continue;
            m[xx][yy] = m[x][y] + 1;
            q.push(make_pair(xx,yy)); 
        }
    }
    if(m[H-1][W-1] == -1){
        cout << -1 << endl;
        return 0;
    }
    int c = 0;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(s[i][j] == '#') c++;
        }
    }
    cout << H*W - c - m[H-1][W-1] << endl;
    return 0;
}