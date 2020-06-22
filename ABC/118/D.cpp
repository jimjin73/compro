#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

ll N,M;
char dp_c[20000];
ll dp_l[20000];
ll dp_b[20000];
ll A[10];
ll n[10] = {0,2,5,5,4,5,6,3,7,6};

int main(){
    cin >> N >> M;
    for(int i=0;i<M;i++) cin >> A[i];
    dp_c[0] = '\n';
    for(int i=0;i<N;i++){
        if(dp_c[i] == 0) continue;
        for(int m=0;m<M;m++){
            if(dp_c[i+n[A[m]]]==0){
                dp_c[i+n[A[m]]] = '0' + A[m];
                dp_b[i+n[A[m]]] = i;
                dp_l[i+n[A[m]]] = dp_l[i] + 1;
                continue;
            }
            if(dp_l[i] + 1 > dp_l[i+n[A[m]]]){
                dp_c[i+n[A[m]]] = '0' + A[m];
                dp_b[i+n[A[m]]] = i;
                dp_l[i+n[A[m]]] = dp_l[i] + 1;
                continue;
            }
            if(dp_l[i] + 1 == dp_l[i+n[A[m]]] && A[m] > dp_c[i+n[A[m]]]-'0'){
                dp_c[i+n[A[m]]] = '0' + A[m];
                dp_b[i+n[A[m]]] = i;
                dp_l[i+n[A[m]]] = dp_l[i] + 1;
            }
        }
    }
    vector<char> v;
    ll p = N;
    while(p > 0){
        v.push_back(dp_c[p]);
        p = dp_b[p];
    }
    for(auto &e : v) cout << e;
    cout << endl;
    return 0;
}