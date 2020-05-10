#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int b[101][101];
int N,Q;
int tmp[101];

int main(){
    cin >> N >> Q;
    for(int i=0;i<Q;i++){
        int t;
        cin >> t;
        if(t==1){
            int a,c;
            cin >> a >> c;
            b[a][c]++;
            continue;
        }
        if(t==2){
            int a;
            cin >> a;
            for(int i=1;i<=N;i++){
                if(b[i][a] == 0) continue;
                b[a][i]++;
            }
            continue;
        }
        if(t==3){
            int a;
            cin >> a;
            for(int i=1;i<=N;i++) tmp[i]=0;
            for(int i=1;i<=N;i++){
                if(b[a][i] == 0) continue;
                for(int j=1;j<=N;j++){
                    if(j==a) continue;
                    if(b[i][j] == 0) continue;
                    tmp[j]++;
                }
            }
            for(int i=1;i<=N;i++) b[a][i] += tmp[i];
        }
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(b[i][j]==0) cout << 'N';
            else cout << 'Y';
        }
        cout << endl;
    }
    return 0;
}