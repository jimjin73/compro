#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

ll X,Y;

int main(){
    cin >> X >> Y;
    if(X*2 > Y || X*4 < Y){
        cout << "No" << endl;
        return 0;
    }
    if(Y % 2 != 0){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}