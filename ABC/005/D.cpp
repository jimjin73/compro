#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N,Q;
ll m[60][60];
ll q[3000];

int main(){
    cin >> N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> m[i][j];
        }
    }
    cin >> Q;
    for(int i=0;i<Q;i++) cin >> q[i];
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            m[i][j] += m[i-1][j] + m[i][j-1] - m[i-1][j-1];
        }
    }
    for(int i=0;i<Q;i++){
        ll max_v = 0;
        for(int t=q[i]-q[i]%N;t<=q[i];t++){
            if(t==0) continue;
            for(int j=1;j*j<=t;j++){
                if(t % j != 0) continue;
                ll h = j - 1;
                ll w = t / j - 1;
                for(int x=1;x+h<=N;x++){
                    for(int y=1;y+w<=N;y++){
                        max_v = max(max_v, m[x+h][y+w] - m[x+h][y-1] - m[x-1][y+w] + m[x-1][y-1]);
                    }
                }
                swap(h,w);
                for(int x=1;x+h<=N;x++){
                    for(int y=1;y+w<=N;y++){
                        max_v = max(max_v, m[x+h][y+w] - m[x+h][y-1] - m[x-1][y+w] + m[x-1][y-1]);
                    }
                }
            }
        }
        cout << max_v << endl;
    }
    return 0;
}