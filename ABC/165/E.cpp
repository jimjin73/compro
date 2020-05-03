#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
ll N,M;
 
int main(){
    cin >> N >> M;
    if(N%2 == 1){
        for(int i=0;i<M;i++){
            cout << 1+i << " " << N-i << endl;
        }
        return 0;
    }
    int p = 0;
    for(int i=0;i<M;i++){
        if((N-i)-(1+i) <= N / 2){
            break;
        }
        cout << 1+i << " " << N-i << endl;
        p++;
    }
    for(int i=p;i<M;i++){
        cout << 1+i << " " << N-i-1 << endl;
    }
    return 0;
}