#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N;
ll A[100000];

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    for(int i=1;i<N;i++){
        if(A[i] > A[i-1]){
            cout << "up " << A[i]-A[i-1] << endl;
            continue;
        }
        if(A[i] < A[i-1]){
            cout << "down " << A[i-1]-A[i] << endl;
            continue;
        }
        cout << "stay" << endl;
    }
    return 0;
}