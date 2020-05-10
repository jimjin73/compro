#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N;
ll C[200000];
ll min_even, min_odd;
ll even_m, odd_m;

int main(){
    cin >> N;
    for(int i=0;i<N;i++) cin >> C[i];
    min_even = min_odd = 1e15;
    for(int i=0;i<N;i++){
        if(i % 2 == 0) min_odd = min(min_odd, C[i]);
        else min_even = min(min_even, C[i]);
    }
    ll Q;
    cin >> Q;
    ll c = 0;
    ll odd_n = N / 2 + N % 2;
    even_m = odd_m = 0;
    for(int i=0;i<Q;i++){
        ll t,x,a;
        cin >> t;
        if(t==1){
            cin >> x >> a;
            if(x % 2 == 1){
                if(C[x-1] - even_m - odd_m < a) continue;
                C[x-1] -= a;
                min_odd = min(min_odd, C[x-1]);
            }else{
                if(C[x-1] - even_m < a) continue;
                C[x-1] -= a;
                min_even = min(min_even, C[x-1]);
            }
            c += a;
            continue;
        }
        if(t==2){
            cin >> a;
            if(min_odd - even_m - odd_m < a) continue;
            odd_m += a;
            c += odd_n * a;
            continue;
        }
        if(t==3){
            cin >> a;
            if(min_even - even_m < a) continue;
            if(min_odd - even_m - odd_m < a) continue;
            even_m += a;
            c += N * a;
            continue;
        }
    }
    cout << c << endl;
    return 0;
}