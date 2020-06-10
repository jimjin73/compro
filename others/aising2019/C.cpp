#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

ll H,W;
string s[400];
ll m[400][400];
ll dh[4] = {0,1,0,-1};
ll dw[4] = {1,0,-1,0};

P dfs(ll h, ll w){
    ll A = 0;
    ll B = 0;
    m[h][w] = 1;
    for(int i=0;i<4;i++){
        ll nh = h + dh[i];
        ll nw = w + dw[i];
        if(nh < 0 || nh >= H) continue;
        if(nw < 0 || nw >= W) continue;
        if(s[h][w] == s[nh][nw]) continue;
        if(m[nh][nw] != 0) continue;
        P p = dfs(nh, nw);
        A += p.first;
        B += p.second;
    }
    if(s[h][w] == '#') A++;
    else B++;
    return {A,B};
}

int main(){
    cin >> H >> W;
    for(int i=0;i<H;i++) cin >> s[i];
    ll ans = 0;
    for(int h=0;h<H;h++){
        for(int w=0;w<W;w++){
            if(m[h][w] == 0){
                P p = dfs(h,w);
                ans += p.first * p.second;
            }
        }
    }
    cout << ans << endl;
    return 0;
}