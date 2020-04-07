#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int H,W,N;
string s[1010];
int m[1010][1010];
int p[15][2];
queue<pair<int,int>> q;
int d[5] = {0,-1,0,1,0};

int main(){
    cin >> H >> W >> N;
    for(int i=0;i<H;i++) cin >> s[i];
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(s[i][j] >= '0' && s[i][j] <= '9'){
                p[s[i][j] - '0'][0] = i;
                p[s[i][j] - '0'][1] = j;
                s[i][j] = '.';
            }
            if(s[i][j] == 'S'){
                p[0][0] = i;
                p[0][1] = j;
                s[i][j] = '.';
            }
        }
    }
    ll sum = 0;
    for(int i=1;i<=N;i++){
        int sx = p[i-1][0];
        int sy = p[i-1][1];
        int ex = p[i][0];
        int ey = p[i][1];
        for(int j=0;j<H;j++){
            for(int k=0;k<W;k++){
                m[j][k] = -1;
            }
        }
        m[sx][sy] = 0;
        q.push(make_pair(sx,sy));
        while(true){
            pair<int,int> p = q.front();
            int x = p.first;
            int y = p.second;
            if(x == ex && y == ey){
                sum += (ll)m[x][y];
                break;
            }
            q.pop();
            for(int j=0;j<4;j++){
                int dx = x + d[j];
                int dy = y + d[j+1];
                if(dx < 0 || dx >= H) continue;
                if(dy < 0 || dy >= W) continue;
                if(m[dx][dy] != -1) continue;
                if(s[dx][dy] != '.') continue;
                m[dx][dy] = m[x][y] + 1;
                q.push(make_pair(dx,dy));
            }
        }
        queue<pair<int,int>> tmp;
        swap(q,tmp);
    }
    cout << sum << endl;
    return 0;
}