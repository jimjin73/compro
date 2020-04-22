#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N;
vector<ll> v[1000];

int main(){
    cin >> N;
    if(N < 1){
        cout << "No" << endl;
        return 0;
    }
    N *= 2;
    ll n = -1;
    for(int i=1;i*i<=N;i++){
        if(N % i != 0) continue;
        if(N / i != i+1) continue;
        n = i;
        break;
    }
    if(n == -1){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    cout << n+1 << endl;
    for(int i=0;i<n;i++) v[0].push_back(i+1);
    ll count = n+1;
    for(int i=1;i<n+1;i++){
        for(int j=0;j<i;j++) v[i].push_back(v[j][i-1]);
        for(int j=i;j<n;j++) v[i].push_back(count++);
    }
    for(int i=0;i<n+1;i++){
        cout << n;
        for(int j=0;j<n;j++) cout << " " << v[i][j];
        cout << endl;
    }
    return 0;
}