#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N;
ll P[200000];

int main(){
    cin >> N;
    for(int i=0;i<N;i++) cin >> P[i];
    ll min_v = 1e10;
    ll c = 0;
    for(int i=0;i<N;i++){
        if(min_v <= P[i]) continue;
        min_v = P[i];
        c++;
    }
    cout << c << endl;
    return 0;
}