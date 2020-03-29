#include <iostream>
#include <string>

using namespace std;
typedef long long ll;

ll N, K;
ll A[200009];

int main(){
    cin >> K >> N;
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    ll max = (K-A[N-1]) + A[0];
    for(int i=1;i<N;i++){
        ll d = A[i] - A[i-1];
        if(d > max) max = d;
    }
    cout << K - max << endl;
    return 0;
}