#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> Q;
typedef pair<ll,Q> R;
priority_queue<R,vector<R>,greater<R>> pq;
ll H,W,K;
ll x_1,y_1,x_2,y_2;
string s[1000000];
unordered_map<ll,ll> um;

ll ind(ll a,ll b){
    return a*1e7 + b;
}

int main(){
    cin >> H >> W >> K;
    cin >> x_1 >> y_1 >> x_2 >> y_2;
    for(int i=0;i<H;i++) cin >> s[i];
    x_1--,y_1--,x_2--,y_2--;
    pq.push({0,{-1,{x_1,y_1}}});
    while(um.find(ind(x_2,y_2)) == um.end() && !pq.empty()){
        auto t = pq.top();
        pq.pop();
        ll cost = t.first;
        ll dir = t.second.first;
        ll x = t.second.second.first;
        ll y = t.second.second.second;
        cout << cost << " " << dir << " " << x << " " << y << endl;
        if(um.find(ind(x,y))!=um.end()) continue;
        um[ind(x,y)] = cost;
        for(ll d=1;d<=K;d++){
            if(x+d >= H) break;
            if(s[x+d][y] == '@') break;
            pq.push({cost+1,{0,{x+d,y}}});
            d++;
        }
        for(ll d=1;d<=K;d++){
            if(x-d < 0) break;
            if(s[x-d][y] == '@') break;
            pq.push({cost+1,{0,{x-d,y}}});
            d++;
        }

        for(ll d=1;d<=K;d++){
            if(y+d >= W) break;
            if(s[x][y+d] == '@') break;
            pq.push({cost+1,{1,{x,y+d}}});
            d++;
        }
        for(ll d=1;d<=K;d++){
            if(y-d < 0) break;
            if(s[x][y-d] == '@') break;
            pq.push({cost+1,{1,{x,y-d}}});
            d++;
        }
    }
    if(um.find(ind(x_2,y_2))!=um.end()) cout << um[ind(x_2,y_2)] << endl;
    else cout << -1 << endl;
    return 0;
}