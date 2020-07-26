#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

ll N;

int main(){
    cin >> N;
    deque<ll> A(N);
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    sort(A.begin(),A.end());
    vector<ll> B;
    B.push_back(1);
    for(int i=1;i<N;i++){
        if(i % 2 == 1){
            if(i < N-1) B.push_back(-2);
            else B.push_back(-1);
        }else{
            if(i < N-1) B.push_back(2);
            else B.push_back(1);
        }
    }
    sort(B.begin(),B.end());
    ll f = 0;
    for(int i=0;i<N;i++) f += A[i] * B[i];
    ll b = 0;
    for(int i=0;i<N;i++) b += -1 * A[i] * B[N-1-i];
    cout << max(f,b) << endl;
    return 0;
}