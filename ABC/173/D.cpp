#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

int main(){
    ll N;
    cin >> N;
    vector<ll> v(N);
    for(int i=0;i<N;i++) cin >> v[i];
    ll sum = 0;
    sort(v.rbegin(),v.rend());
    ll n=N-2;
    sum += v[0];
    for(int i=1;i<N-1;i++){
        if(n >= 2){
            sum += v[i]*2;
            n-=2;
        }else if(n >= 1){
            sum += v[i];
            n--;
        }
    }
    cout << sum << endl;
    return 0;
}