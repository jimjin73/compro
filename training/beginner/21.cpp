#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N;
ll H[100010];
ll S[100010];

int main(){
    cin >> N;
    for(int i=0;i<N;i++) cin >> H[i] >> S[i];
    ll sp = 0;
    ll ep = 1e15;
    vector<ll> v(N);
    while(1 < ep-sp){
        ll p = (sp + ep) / 2;
        bool f = true;
        for(int i=0;i<N;i++) v[i] = 0;
        for(int i=0;i<N;i++){
            if(p - H[i] < 0) f = false;
            ll max_i = (p - H[i]) / S[i];
            if(max_i < 0){
                f = false;
                break;
            }
            v[min(max_i, N-1)]++;
        }
        for(int i=1;i<N;i++) v[i] += v[i-1];
        for(int i=0;i<N;i++){
            if(v[i] > i+1) f = false;
        }
        if(f){
            ep = p;
        }else{
            sp = p;
        }
    }
    cout << ep << endl;
    return 0;
}