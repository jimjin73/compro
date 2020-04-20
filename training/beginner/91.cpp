#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

double a,b,x;

double deg(double g){
    return g * 180 / M_PI;
}

int main(){
    cin >> a >> b >> x;
    if(a*a*b/2 >= x){
        cout << fixed << setprecision(15) << 90.0 - deg(atan(2 * x / a/b/b)) << endl;
    }else{
        cout << fixed << setprecision(15) << deg(atan(2*(a*a*b-x)/a/a/a)) << endl;
    }
    return 0;
}