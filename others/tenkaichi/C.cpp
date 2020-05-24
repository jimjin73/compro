#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

ll N;

int main(){
    cin >> N;
    for(int i=1;i<=3500;i++){
        for(int j=1;j<=3500;j++){
            ll a = N*i*j;
            ll b = 4*i*j - i*N - j*N;
            if(b <= 0) continue;
            if(a % b != 0) continue;
            cout << i << " " << j << " " << a / b << endl;
            return 0;
        }
    }
    return 0;
}