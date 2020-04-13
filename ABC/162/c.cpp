#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ll K;
    ll sum = 0;
    cin >> K;
    for(int i=1;i<=K;i++){
        for(int j=1;j<=K;j++){
            for(int k=1;k<=K;k++){
                sum += gcd(gcd(i,j),k);
            }
        }
    }
    cout << sum << endl;
    return 0;
}