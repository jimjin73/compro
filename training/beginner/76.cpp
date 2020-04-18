#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N;
ll A[4000];

int main(){
    cin >> N;
    A[0] = 0;
    for(int i=1;i<=N;i++) cin >> A[i];
    for(int i=1;i<=N;i++) A[i] += A[i-1];
    for(int k=1;k<=N;k++){
        ll max_v = 0;
        for(int j=0;j<=N-k;j++){
            max_v = max(max_v, A[j+k] - A[j]);
        }
        cout << max_v << endl;
    }
    return 0;
}