#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<ll>> G;
ll N,M;
ll H[100000];

int main(){
    cin >> N >> M;
    G.resize(N);
    for(int i=0;i<N;i++){
        cin >> H[i];
    }
    for(int i=0;i<M;i++){
        ll a,b;
        cin >> a >> b;
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
    }
    ll C = 0;
    for(int i=0;i<N;i++){
        bool f = true;
        for(auto &e : G[i]){
            if(H[i] <= H[e]){
                f = false;
                break;
            }
        }
        if(f) C++;
    }
    cout << C << endl;
    return 0;
}