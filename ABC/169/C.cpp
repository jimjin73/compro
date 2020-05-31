#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

ll A;
long double B;

int main(){
    cin >> A >> B;
    long double C = B * A;
    cout << fixed << setprecision(0) << floor(C) << endl;
    return 0;
}