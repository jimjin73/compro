#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N,M,X;
ll C[20];
ll A[20][20];
ll r[12];

int main(){
    cin >> N >> M >> X;
    for(int i=0;i<N;i++){
        cin >> C[i];
        for(int j=0;j<M;j++) cin >> A[i][j];
    }
    ll min_c = 1e15;
    for(int i=1;i<(1<<N);i++){
        bitset<12> bt(i);
        ll c = 0;
        for(int j=0;j<M;j++) r[j] = 0;
        for(int j=0;j<N;j++){
            if(bt[j] == 0) continue;
            c += C[j];
            for(int k=0;k<M;k++) r[k] += A[j][k];
        }
        bool f = true;
        for(int j=0;j<M;j++){
            if(r[j] < X) f = false;
        }
        if(f){
            min_c = min(min_c, c);
        }
    }
    if(min_c == 1e15) cout << -1 << endl;
    else cout << min_c << endl;
    return 0;
}