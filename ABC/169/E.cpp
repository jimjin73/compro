#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

vector<ll> A,B;
ll N;

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        ll a,b;
        cin >> a >> b;
        A.push_back(a);
        B.push_back(b);
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    if(N % 2 == 1){
        cout << B[N/2] - A[N/2] + 1 << endl;
    }else{
        cout << (B[N/2]+B[N/2-1]) - (A[N/2]+A[N/2-1]) + 1 << endl;
    }
    return 0;
}