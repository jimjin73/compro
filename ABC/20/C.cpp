#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll H,W,T;
string s[10];
ll INF = 1e15;
ll sx,sy,gx,gy;
ll dd[5] = {0,1,0,-1,0};

bool check(ll C){
    ll m[10][10];
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            m[i][j] = INF;
        }
    }
    priority_queue<pair<ll,pair<ll,ll>>, vector<pair<ll,pair<ll,ll>>>, greater<pair<ll,pair<ll,ll>>>> pq;
    pq.push(make_pair(0,make_pair(sx,sy)));
    while(m[gx][gy] == INF){
        pair<ll,pair<ll,ll>> p = pq.top();
        pq.pop();
        ll l = p.first;
        ll x = p.second.first;
        ll y = p.second.second;
        if(m[x][y] != INF) continue;
        m[x][y] = l;
        for(int i=0;i<4;i++){
            ll xx = x + dd[i];
            ll yy = y + dd[i+1];
            if(xx >= 0 && xx < H && yy >= 0 && yy < W){
                if(m[xx][yy] != INF) continue;
                ll cost = 1;
                if(s[xx][yy] == '#') cost = C;
                pq.push(make_pair(l+cost,make_pair(xx,yy)));
            }
        }
    }
    return m[gx][gy] <= T;
}

int main(){
    cin >> H >> W >> T;
    for(int i=0;i<H;i++) cin >> s[i];
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(s[i][j] == 'S'){
                sx = i;
                sy = j;
                s[i][j] = '.';
            }
            if(s[i][j] == 'G'){
                gx = i;
                gy = j;
                s[i][j] = '.';
            }
        }
    }
    ll sp = 1;
    ll ep = 1e9;
    while(ep - sp > 1){
        ll p = (ep+sp) / 2;
        if(check(p)) sp = p;
        else ep = p;
    }
    cout << sp << endl;
    return 0;
}