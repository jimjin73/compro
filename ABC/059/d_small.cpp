#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define M 10

ll INF = 1e18;
ll d[M][M];

int main(){
    queue<P> q;
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            d[i][j] = INF;
        }
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            q.push({i,j});
            d[i][j] = 0;
        }
    }
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        ll x = p.first;
        ll y = p.second;
        for(int i=1;i<=x;i++){
            ll xx = x-i;
            ll yy = y+2*i;
            if(yy >= M) break;
            if(d[xx][yy] != INF) continue;
            d[xx][yy] = d[x][y] + 1;
            q.push({xx,yy});
        }
        for(int i=1;i<=y;i++){
            ll xx = x+2*i;
            ll yy = y-i;
            if(xx >= M) break;
            if(d[xx][yy] != INF) continue;
            d[xx][yy] = d[x][y] + 1;
            q.push({xx,yy});
        }
    }
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            cout << d[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}