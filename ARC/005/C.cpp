#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int H,W;
string s[510];
int sh,sw,gh,gw;
priority_queue<pair<ll,pair<ll,ll>>, vector<pair<ll,pair<ll,ll>>>, greater<pair<ll,pair<ll,ll>>>> pq;
ll m[510][510];
ll d[5] = {0,1,0,-1,0};

int main(){
    cin >> H >> W;
    for(int i=0;i<H;i++) cin >> s[i];
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            m[i][j] = 1e15;
            if(s[i][j] == 's'){
                sh = i, sw = j;
                s[i][j] = '.';
            }
            if(s[i][j] == 'g'){
                gh = i, gw = j;
                s[i][j] = '.';
            }
        }
    }
    pq.push(make_pair(0,make_pair(sh,sw)));
    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();
        ll cost = p.first;
        ll h = p.second.first;
        ll w = p.second.second;
        if(m[h][w] != 1e15) continue;
        m[h][w] = cost;
        if(h == gh && w == gw) break;
        for(int i=0;i<4;i++){
            ll hh = h + d[i];
            ll ww = w + d[i+1];
            if(hh < 0 || hh >= H || ww < 0 || ww >= W) continue;
            if(m[hh][ww] != 1e15) continue;
            ll c = 1;
            if(s[hh][ww] == '#') c = 1e8;
            pq.push(make_pair(cost+c,make_pair(hh,ww)));
        }
    }
    if(m[gh][gw] < 3e8) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}