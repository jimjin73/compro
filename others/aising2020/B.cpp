#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

ll N;
ll A[500];

int main(){
    cin >> N;
    for(int i=0;i<N;i++) cin >> A[i];
    ll c = 0;
    for(int i=0;i<N;i++){
        if(i%2==0 && A[i]%2==1) c++;
    }
    cout << c << endl;
    return 0;
}