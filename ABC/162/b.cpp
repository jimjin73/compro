#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N;

int main(){
    cin >> N;
    ll sum = 0;
    for(int i=1;i<=N;i++){
        if(i%3!=0 && i%5!=0) sum += i;
    }
    cout << sum << endl;
    return 0;
}