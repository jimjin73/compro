#include <iostream>

using namespace std;
typedef long long ll;


int main(){
    ll a,b,c;
    cin >> a >> b >> c;
    ll r = (c-a-b) * (c-a-b);
    ll l = 4 * a * b;
    if(c-a-b < 0){
        cout << "No" << endl;
        return 0;
    }
    if(l < r){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}