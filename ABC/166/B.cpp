#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll A[100];
ll N,K;

int main(){
    cin >> N >> K;
    for(int i=0;i<N;i++) A[i] = 0;
    for(int i=0;i<K;i++){
        ll d;
        cin >> d;
        for(int j=0;j<d;j++){
            ll a;
            cin >> a;
            A[a-1]++;
        }
    }
    ll c = 0;
    for(int i=0;i<N;i++){
        if(A[i] == 0) c++;
    }
    cout << c << endl;
    return 0;
}