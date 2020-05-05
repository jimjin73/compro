#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N;

int main(){
    cin >> N;
    if(N%2==1){
        cout << 0 << endl;
        return 0;
    }
    ll c = 0;
    ll t = 5;
    N /= 2;
    while(N >= t){
        c += N/t;
        t*=5;
    }
    cout << c << endl;
    return 0;
}