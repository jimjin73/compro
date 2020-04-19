#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N;
ll A[100001];
vector<ll> v;

int main(){
    cin >> N;
    for(int i=0;i<N;i++) cin >> A[i];
    ll n = A[0];
    ll l = 1;
    for(int i=1;i<N;i++){
        if(n == A[i]){
            v.push_back(l);
            l = 1;
        }else{
            l++;
        }
        n = A[i];
    }
    v.push_back(l);
    ll max_v = 0;
    if(v.size() == 1){
        cout << v[0] << endl;
        return 0;
    } 
    if(v.size() == 2){
        cout << v[0] + v[1] << endl;
        return 0;
    }
    for(int i=2;i<v.size();i++){
        max_v = max(max_v, v[i] + v[i-1] + v[i-2]);
    }
    cout << max_v << endl;
    return 0;
}