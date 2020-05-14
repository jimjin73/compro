#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N,K;
ll A[200000][64];

int main(){
    cin >> N >> K;
    for(int i=0;i<N;i++){
        cin >> A[i][0];
        A[i][0]--;
    }
    for(int i=1;i<=63;i++){
        for(int j=0;j<N;j++){
            A[j][i] = A[A[j][i-1]][i-1];
        }
    }
    int p = 0;
    for(int i=0;i<64;i++){
        if((K>>i)&1) p = A[p][i];
    }
    cout << p+1 << endl;
    return 0;
}