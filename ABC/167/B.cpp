#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll A,B,C,K;

int main(){
    cin >> A >> B >> C >> K;
    if(A >= K){
        cout << K << endl;
        return 0;
    }
    if(A+B >= K){
        cout << A << endl;
        return 0;
    }
    cout << A - (K - A - B) << endl;
    return 0;
}