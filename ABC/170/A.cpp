#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

bool b[6];

int main(){
    for(int i=0;i<5;i++){
        int n;
        cin >> n;
        b[n] = true;
    }
    for(int i=1;i<=5;i++){
        if(!b[i]) cout << i << endl;
    }
    return 0;
}