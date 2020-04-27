#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N,K;
ll a[100];
ll b[100001];

int main(){
    cin >> N >> K;
    for(int i=0;i<N;i++) cin >> a[i];
    ll min_a = 1e12;
    for(int i=0;i<N;i++) min_a = min(min_a, a[i]);
    for(int i=0;i<=K;i++) b[i] = 0;
    for(int i=0;i<=K;i++){
        for(int j=0;j<N;j++){
            if(i-a[j] < 0) continue;
            if(b[i-a[j]] == 0){
                b[i] = 1;
                break;
            }
        }
    }
    if(b[K] == 0){
        cout << "Second" << endl;
    }else{
        cout << "First" << endl;
    }
    return 0;
}