#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

ll N;
ll A[200000];

int main(){
    cin >> N;
    for(int i=0;i<N;i++) cin >> A[i];
    ll X = 0;
    for(int i=0;i<N;i++) X ^= A[i];
    for(int i=0;i<N;i++){
        cout << (X^A[i]);
        if(i != N-1) cout << " ";
    }
    cout << endl;
    return 0;
}