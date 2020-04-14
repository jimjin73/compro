#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll H,W;
ll m[10][10];
ll A[210][210];

int main(){
    cin >> H >> W;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cin >> m[i][j];
        }
    }
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin >> A[i][j];
        }
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            for(int k=0;k<10;k++){
                m[j][k] = min(m[j][k], m[j][i] + m[i][k]);
            }
        }
    }
    ll sum = 0;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(A[i][j] == -1) continue;
            sum += m[A[i][j]][1];
        }
    }
    cout << sum << endl;
    return 0;
}