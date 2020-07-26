#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

ll A[200000];

int main(){
    ll N,K;
    cin >> N >> K;
    for(int i=0;i<N;i++) cin >> A[i];
    for(int i=K;i<N;i++){
        if(A[i] > A[i-K]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}