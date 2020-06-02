#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

ll N,M;
ll d[100][100];
ll l[100][100];

int main(){
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            d[i][j] = 1e9;
        }
    }
    for(int i=0;i<M;i++){
        ll a,b,c;
        cin >> a >> b >> c;
        d[a-1][b-1] = d[b-1][a-1] = c;
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            l[i][j] = d[i][j];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                l[j][k] = min(l[j][k], l[j][i] + l[i][k]);
            }
        }
    }
    ll count = 0;
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(d[i][j] == 1e9) continue;
            if(d[i][j] > l[i][j]) count++;
        }
    }
    cout << count << endl;
    return 0;
}