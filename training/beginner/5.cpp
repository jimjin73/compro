#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ll A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;
    ll x = A*X+B*Y;
    ll y = max(X,Y) * 2 * C;
    if(X > Y){
        swap(X,Y);
        swap(A,B);
    }
    ll z = X*2*C + (Y-X)*B;
    cout << min(x,min(y,z)) << endl;
    return 0;
}