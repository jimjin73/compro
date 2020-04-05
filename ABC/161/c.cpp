#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ll N ,K;
    cin >> N >> K;
    cout << min(N%K, K-N%K) << endl;
    return 0;
}