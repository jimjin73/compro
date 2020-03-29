#include <iostream>
#include <string>

using namespace std;
typedef long long ll;

ll m;

int main(){
    cin >> m;
    ll n1 = m / 500;
    ll n2 = (m -  n1 * 500) / 5;
    cout << n1 * 1000 + n2 * 5 << endl;
    return 0;
}