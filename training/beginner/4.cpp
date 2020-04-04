#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll A[110][110];
ll N,M;

int main(){
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> A[i][j];
        }
    }
    ll maxp = 0;
    for(int i=0;i<M;i++){
        for(int j=i+1;j<M;j++){
            ll p = 0;
            for(int k=0;k<N;k++){
                p += max(A[k][i], A[k][j]);
            }
            if(p > maxp){
                maxp = p;
            }
        }
    }
    cout << maxp << endl;
    return 0;
}