#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

ll N,L;
ll A[100000];

int main(){
    cin >> N >> L;
    for(int i=0;i<N;i++) cin >> A[i];
    ll ind = -1;
    for(int i=0;i<N-1;i++){
        if(A[i] + A[i+1] >= L) ind = i+1;
    }
    if(ind < 0){
        cout << "Impossible" << endl;
    }else{
        cout << "Possible" << endl;
        for(int i=1;i<ind;i++){
            cout << i << endl;
        }
        for(int i=N-1;i>=ind;i--){
            cout << i << endl;
        }
    }
    return 0;
}