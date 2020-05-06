#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll H,W;
string s[30];
ll m[30][30];
ll dd[5] = {0,-1,0,1,0};

ll dist(ll a, ll b, ll c, ll d){
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            m[i][j] = 1e15;
        }
    }
    m[a][b] = 0;
    queue<pair<ll,ll>> q;
    q.push(make_pair(a,b));
    while(m[c][d] == 1e15){
        pair<ll,ll> p = q.front();
        q.pop();
        ll x = p.first;
        ll y = p.second;
        for(int i=0;i<4;i++){
            ll xx = x + dd[i];
            ll yy = y + dd[i+1];
            if(xx < 0 || xx >= H || yy < 0 || yy >= W) continue;
            if(m[xx][yy] != 1e15) continue;
            if(s[xx][yy] == '#') continue;
            m[xx][yy] = m[x][y] + 1;
            q.push(make_pair(xx,yy));
        }
    }
    return m[c][d];
}


int main(){
    cin >> H >> W;
    ll max_d = 0;
    for(int i=0;i<H;i++) cin >> s[i];
    for(int sx=0;sx<H;sx++){
        for(int sy=0;sy<W;sy++){
            for(int gx=0;gx<H;gx++){
                for(int gy=0;gy<W;gy++){
                    if(s[sx][sy] == '#' || s[gx][gy] == '#') continue;
                    max_d = max(max_d, dist(sx,sy,gx,gy));
                }
            }
        }
    }
    cout << max_d << endl;
    return 0;
}