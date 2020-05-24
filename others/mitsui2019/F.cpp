#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

ll T1,T2;
ll A1,A2,B1,B2;

int main(){
    cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;
    if(A1>B1 && A2>B2){
        cout << 0 << endl;
        return 0;
    }
    if(A1<B1 && A2<B2){
        cout << 0 << endl;
        return 0;
    }
    if(A1 < B1){
        swap(A1,B1);
        swap(A2,B2);
    }
    ll D1 = (A1-B1) * T1;
    ll D2 = (B2-A2) * T2;
    if(D1 > D2){
        cout << 0 << endl;
        return 0;
    } 
    if(D1 == D2){
        cout << "infinity" << endl;
        return 0;
    }
    ll dd = D2 - D1;
    ll r = D1 / dd;
    if(D1 % dd == 0) r = r*2;
    else r = r*2 + 1;
    cout << r << endl;
    return 0;
}