#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

ll M,K;

int main(){
    cin >> M >> K;
    if(K >= (1<<M)){
        cout << -1 << endl;
        return 0;
    }
    if(K==0){
        for(int i=(1<<M)-1;i>=0;i--){
            cout << i << " ";
        }
        for(int i=0;i<(1<<M);i++){
            if(i != (1<<M)-1) cout << i << " ";
            else cout << i << endl;
        }
        return 0;
    }
    if(M == 1 && K == 1){
        cout << -1 << endl;
        return 0;
    }
    for(int i=(1<<M)-1;i>=0;i--){
        if(i == K) continue;
        cout << i << " ";
    }
    cout << K << " ";
    for(int i=0;i<(1<<M);i++){
        if(i == K) continue;
        cout << i << " ";
    }
    cout << K << endl;
    return 0;
}