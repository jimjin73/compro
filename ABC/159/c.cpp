#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
typedef long long ll;

int main(){
    ll L;
    cin >> L;
    L = L * L * L;
    cout << fixed << setprecision(15) << (double)L / 27.0 << endl;
    return 0;
}