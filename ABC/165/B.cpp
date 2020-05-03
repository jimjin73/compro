#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

double X;

int main(){
    cin >> X;
    ll x = 100.0;
    for(int i=1;i<4000;i++){
        x *= 1.01;
        if(x >= X){
            cout << i << endl;
            break;
        }
    }
    return 0;
}