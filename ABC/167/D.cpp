#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N,K;
ll A[200000];
vector<ll> v;
int check[200000];

int main(){
    cin >> N >> K;
    for(int i=0;i<N;i++){
        cin >> A[i];
        A[i]--;
    }
    int p = 0;
    while(check[p] == 0){
        check[p]++;
        v.push_back(p);
        p = A[p];
    }
    ll q;
    for(int i=0;i<v.size();i++){
        if(p == v[i]) q = i;
    }
    if(K <= q){
        cout << v[K] + 1 << endl;
        return 0;
    }
    K -= q;
    ll ind = K % (v.size() - q);
    cout << v[q + ind]+1 << endl;
    return 0;
}