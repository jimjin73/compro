#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N,K;

int main(){
    cin >> N >> K;
    if(K > (N-1)*(N-2)/2){
        cout << -1 << endl;
        return 0;
    }
    ll c = (N-1)*(N-2)/2 - K;
    cout << N-1 + c << endl;
    for(int i=2;i<=N;i++) cout << 1 << " " << i << endl;
    for(int i=2;i<=N;i++){
        for(int j=i+1;j<=N;j++){
            if(c == 0) break;
            cout << i << " " << j << endl;
            c--;
        }
        if(c == 0) break;
    }
    return 0;
}