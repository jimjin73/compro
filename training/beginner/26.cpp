#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

unordered_set<ll> s[200010];
ll N,Q;
ll x[200010];
bool y[200010];

void dfs(ll n){
    y[n] = false;
    for(const auto& e : s[n]){
        if(!y[e]) continue;
        x[e] += x[n];
        dfs(e);
    }
}

int main(){
    cin >> N >> Q;
    ll a,b;
    for(int i=0;i<N-1;i++){
        cin >> a >> b;
        s[a-1].insert(b-1);
        s[b-1].insert(a-1);
    }
    for(int i=0;i<N;i++) x[i] = 0;
    for(int i=0;i<N;i++) y[i] = true;
    for(int i=0;i<Q;i++){
        cin >> a >> b;
        x[a-1] += b;
    }
    dfs(0);
    for(int i=0;i<N;i++){
        cout << x[i];
        if(i != N-1) cout << " "; 
    }
    cout << endl;
    return 0;
}