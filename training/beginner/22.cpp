#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

ld P;

ld dT(ld x){
    return 1.0 + (-2.0/3) * P * log(2.0) * pow(2.0, (-2.0/3)*x);
}

ld T(ld x){
    return x + pow(2.0, (-2.0/3)*x) * P;
}

int main(){
    cin >> P;
    ld x = 100.0;
    ld lr = 1.0;
    ld decay = 1.0;
    for(int i=0;i<5000000;i++){
        x -= lr * dT(x);
        lr *= decay;
    }
    ld ans = T(x);
    if(x < 0){
        cout << fixed << setprecision(15) << P << endl;
    }else{
        cout << fixed << setprecision(15) << T(x) << endl;
    }
    return 0;
}