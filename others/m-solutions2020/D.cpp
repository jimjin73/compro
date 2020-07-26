#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

ll N;
ll A[100];

int main(){
    cin >> N;
    for(int i=0;i<N;i++) cin >> A[i];
    ll K,M;
    K = 0;
    M = 1000;
    for(int i=0;i<N-1;i++){
        if(A[i+1] > A[i]){
            K += M / A[i];
            M = M % A[i];
        }
        if(A[i+1] < A[i]){
            M += K * A[i];
            K = 0;
        }
    }
    M += K * A[N-1];
    cout << M << endl;
    return 0;
}