#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

double A,B,H,M;

double calc(){
    double m = 2.0*M_PI * M / 60.0;
    double h = 2.0*M_PI * H / 12.0 + 2*M_PI * M / 60.0 / 12.0;
    double d = abs(m-h);
    return min(d,2*M_PI-d);
}

int main(){
    cin >> A >> B >> H >> M;
    double t = calc();
    double rr = 2*A*B*cos(t) - A*A - B*B;
    cout << fixed << setprecision(15) << sqrt(abs(rr)) << endl;
    return 0;
}