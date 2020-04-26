#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll H,W,K,V;
ll m[130][130];

int main(){
    ll max_s = 0;
    cin >> H >> W >> K >> V;
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            cin >> m[i][j];
            m[i][j] += K;
        }
    }
    for(int i=0;i<=H;i++) m[i][0] = 0;
    for(int i=0;i<=W;i++) m[0][i] = 0;
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            m[i][j] += m[i-1][j] + m[i][j-1] - m[i-1][j-1];
        }
    }
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            for(int x=i+1;x<=H;x++){
                for(int y=j+1;y<=W;y++){
                    if(m[x][y] - m[x][j] - m[i][y] + m[i][j]> V) continue;
                    max_s = max(max_s, (ll)(x-i)*(y-j));
                }
            }
        }
    }
    cout << max_s << endl;
    return 0;
}