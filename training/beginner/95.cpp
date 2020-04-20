#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll A,B,K;

int main(){
    cin >> A >> B >> K;
    if(A >= K){
        cout << A-K << " " << B << endl;
        return 0;
    }
    if(A + B >= K){
        cout << 0 << " " << A+B-K << endl;
        return 0;
    }
    cout << 0 << " " <<  0 << endl;
    return 0;
}