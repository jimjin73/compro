#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

int main(){
    ll a,b,c,k;
    cin >> a >> b >> c;
    cin >> k;
    for(int i=0;i<k;i++){
        if(a >= b){
            b *= 2;
        }else{
            c *= 2;
        }
    }
    if(c > b && b > a) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}