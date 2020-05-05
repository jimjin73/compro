#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N;
ll A[200000];

int main(){
    cin >> N;
    for(int i=0;i<N;i++) cin >> A[i];
    ll memo = 0;
    for(int i=0;i<N;i++){
        if(A[i] != memo+1) continue;
        memo++;
    }
    if(memo == 0) cout << -1 << endl;
    else cout << N - memo << endl;
    return 0;
}