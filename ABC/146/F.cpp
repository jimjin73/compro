#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N,M;
string s;
ll d[200000];
ll f[200000];

int main(){
    cin >> N >> M;
    cin >> s;
    ll c = 0;
    for(int i=0;i<N+1;i++){
        if(s[i] == '1') c++;
        else c=0;
        if(c >= M){
            cout << -1 << endl;
            return 0;
        }
    }
    d[0] = 0;
    f[0] = -1;
    for(int i=1;i<=N;i++) d[i] = -1;
    queue<ll> q;
    q.push(0);
    ll min_v = 0;
    while(!q.empty() && d[N] == -1){
        ll n = q.front();
        q.pop();
        for(int i=min_v-n+1;i<=M;i++){
            if(n+i>N) break;
            if(s[i+n] == '1') continue;
            d[i+n] = d[n] + 1;
            f[i+n] = n;
            q.push(i+n);
        }
        min_v = n + M;
        if(min_v > N) break;
    }
    vector<ll> v;
    ll n = N;
    v.push_back(n);
    while(n != 0){
        n = f[n];
        v.push_back(n);
    }
    reverse(v.begin(),v.end());
    for(int i=1;i<v.size();i++){
        cout << v[i] - v[i-1];
        if(i == v.size()-1) cout << endl;
        else cout << " ";
    }
    return 0;
}