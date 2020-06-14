#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

ll N,M;
ll A[300][300];
ll c[300];
bool f[300];

int main(){
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> A[i][j];
            A[i][j]--;
        }
    }
    for(int i=0;i<M;i++) f[i] = true;
    ll min_q = 1e9;
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++) c[j] = 0;
        for(int n=0;n<N;n++){
            for(int m=0;m<M;m++){
                if(f[A[n][m]]){
                    c[A[n][m]]++;
                    break;
                }
            }
        }
        ll q = 0;
        ll arg_q = -1;
        for(int m=0;m<M;m++){
            if(q < c[m]){
                q = c[m];
                arg_q = m;
            }
        }
        min_q = min(min_q, q);
        f[arg_q] = false;
    }
    cout << min_q << endl;
    return 0;
}