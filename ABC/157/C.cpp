#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N,M;
int d[5];

int main(){
    cin >> N >> M;
    for(int i=0;i<N;i++) d[i] = -1;
    for(int i=0;i<M;i++){
        int a,b;
        cin >> a >> b;
        if(d[a-1] != -1 && d[a-1] != b){
            cout << -1 << endl;
            return 0;
        }
        d[a-1] = b;
    }
    if(d[0] == 0 && N > 1){
        cout << -1 << endl;
        return 0;
    }
    for(int i=0;i<N;i++){
        if(d[i] == -1){
            if(i == N-1 || i != 0) cout << 0;
            else cout << 1;
        }else{
            cout << d[i];
        }
    }
    cout << endl;
    return 0;
}