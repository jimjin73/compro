#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bitset<10000> bts[10];

int main(){
    int R,C;
    int a;
    cin >> R >> C;
    for(int i=0;i<R;i++){
        bts[i] = 0;
        for(int j=0;j<C;j++){
            cin >> a;
            if(a == 1) bts[i].set(j);
        }
    }
    ll max_m = 0;
    for(int i=0;i<(1<<R);i++){
        bitset<10> bt(i);
        ll m = 0;
        for(int j=0;j<C;j++){
            ll c = 0;
            for(int k=0;k<R;k++){
                if(bt[k] == 1){
                    c += 1 - bts[k][j];
                }else{
                    c += bts[k][j];
                }
            }
            c = max(c, R-c);
            m += c;
        }
        max_m = max(max_m,m);
    }
    cout << max_m << endl;
    return 0;
}