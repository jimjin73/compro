#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
priority_queue<ll, vector<ll>, greater<ll>> q;

int main(){
    ll K;
    cin >> K;
    for(int i=1;i<10;i++) q.push(i);
    for(int i=1;i<=K;i++){
        ll s = q.top();
        q.pop();
        if(i==K){
            cout << s << endl;
            break;
        }
        int n = s % 10;
        for(int j=-1;j<=1;j++){
            if(n + j >= 0 && n + j <= 9){
                q.push(n+j + s*10);
            }
        }
    }
    return 0;
}