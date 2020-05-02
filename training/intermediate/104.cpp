#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll W,H;
ll N;
ll a[1000],b[1000],c[1000],d[1000];
vector<ll> X,Y;
ll m[2050][2050];
ll col;
int dd[5] = {0,-1,0,1,0};

void bfs(ll x,ll y){
    queue<pair<ll,ll>> q;
    q.push(make_pair(x,y));
    while(!q.empty()){
        pair<ll,ll> p = q.front();
        q.pop();
        ll s = p.first;
        ll t = p.second;
        if(m[s][t] != 0) continue;
        m[s][t] = col;
        for(int i=0;i<4;i++){
            if(m[s+dd[i]][t+dd[i+1]] != 0) continue;
            q.push(make_pair(s+dd[i],t+dd[i+1]));
        }
    }
}

int main(){
    col = 0;
    cin >> W >> H;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        X.push_back(a[i]);
        X.push_back(c[i]);
        Y.push_back(b[i]);
        Y.push_back(d[i]);
    }
    X.push_back(0);
    X.push_back(W);
    X.push_back(-1);
    Y.push_back(0);
    Y.push_back(H);
    Y.push_back(-1);
    sort(X.begin(),X.end());
    sort(Y.begin(),Y.end());
    X.erase(unique(X.begin(),X.end()), X.end());
    Y.erase(unique(Y.begin(),Y.end()), Y.end());
    for(int i=0;i<X.size();i++){
        for(int j=0;j<Y.size();j++){
            m[i][j] = 0;
        }
    }
    for(int i=0;i<N;i++){
        ll ia = lower_bound(X.begin(),X.end(),a[i]) - X.begin();
        ll ic = lower_bound(X.begin(),X.end(),c[i]) - X.begin();
        ll ib = lower_bound(Y.begin(),Y.end(),b[i]) - Y.begin();
        ll id = lower_bound(Y.begin(),Y.end(),d[i]) - Y.begin();
        m[ia][ib]++;
        m[ia][id]--;
        m[ic][ib]--;
        m[ic][id]++;
    }
    for(int i=1;i<X.size();i++){
        for(int j=1;j<Y.size();j++){
            m[i][j] += m[i-1][j] + m[i][j-1] - m[i-1][j-1];
        }
    }
    for(int i=0;i<X.size();i++){
        m[i][0] = m[i][Y.size()-1] = -1;
    }
    for(int i=0;i<Y.size();i++){
        m[0][i] = m[X.size()-1][i] = -1;
    }
    for(int i=1;i<X.size();i++){
        for(int j=1;j<Y.size();j++){
            if(m[i][j] != 0) m[i][j] = -1;
        }
    }
    for(int i=1;i<X.size()-1;i++){
        for(int j=1;j<Y.size()-1;j++){
            if(m[i][j] != 0) continue;
            col++;
            bfs(i,j);
        }
    }
    cout << col << endl;
    return 0;
}