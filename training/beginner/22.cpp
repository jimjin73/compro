#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

double P;

double func(double x){
    return x + (double)P / pow(2,x/1.5);
}

int main(){
    cin >> P;
    double sp = 0.0;
    double ep = 100.0;
    while(ep - sp > 1e-8){
        double a = sp + (ep-sp) / 3;
        double b = sp + (ep-sp) * 2 / 3;
        double aa = func(a);
        double bb = func(b);
        if(aa < bb){
            ep = b;
        }else{
            sp = a;
        }
    }
    double p = func(ep);
    cout << fixed << setprecision(15) << p << endl;
    return 0;
}