#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N,K;
ll M[110][110];

ll dijk(ll sp, ll ep){
    ll m[110];
    for(int i=0;i<=N;i++) m[i] = -1;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> q;
    q.push(make_pair(0,sp));
    while(!q.empty()){
        pair<ll,ll> p = q.top();
        q.pop();
        ll l = p.first;
        ll t = p.second;
        if(t == ep) return l;
        m[t] = l;
        for(int i=0;i<=N;i++){
            if(M[t][i] == 1e12) continue;
            if(m[i] != -1) continue;
            q.push(make_pair(l+M[t][i],i));
        }
    }
    return -1;
}

int main(){
    cin >> N >> K;
    for(int i=0;i<=N;i++){
        for(int j=0;j<=N;j++){
            M[i][j] = 1e12;
        }
    }
    for(int i=0;i<K;i++){
        ll a,b,c,d;
        cin >> a;
        if(a == 0){
            cin >> b >> c;
            cout << dijk(b,c) << endl;
        }else{
            cin >> b >> c >> d;
            M[b][c] = M[c][b] = min(d,M[b][c]);
        }
    }
    return 0;
}