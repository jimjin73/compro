#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, M;
int A[110];

int main(){
    cin >> N >> M;
    for(int i=0;i<N;i++) cin >> A[i];
    int sum = 0;
    for(int i=0;i<N;i++) sum += A[i];
    int c = 0;
    for(int i=0;i<N;i++){
        if(sum <= A[i] * 4 * M) c++;
    }
    if(c >= M) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}