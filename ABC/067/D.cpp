#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

vector<vector<ll>> G;
ll N;
ll c[100000];

int main(){
    cin >> N;
    G.resize(N);
    for(int i=0;i<N-1;i++){
        ll a,b;
        cin >> a >> b;
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
    }

    return 0;
}