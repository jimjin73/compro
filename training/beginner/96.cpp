#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N;

int main(){
    cin >> N;
    ll sum = 0;
    for(int i=0;i<N;i++) sum += i;
    cout << sum << endl;
    return 0;
}