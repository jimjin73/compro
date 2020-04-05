#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N,K;
ll A[20];

int main(){
    cin >> N >> K;
    for(int i=0;i<N;i++) cin >> A[i];
    ll min_cost = 1e12;
    for(int i=0;i<(1<<N);i++){
        ll cost = 0;
        bitset<15> bt(i);
        if(bt.count() != K) continue;
        ll h = 0;
        for(int j=0;j<N;j++){
            if(bt[j] == 1){
                if(A[j] <= h){
                    cost += h - A[j] + 1;
                    h++;
                }else{
                    h = A[j];
                }
            }else{
                h = max(A[j], h);
            }
        }
        min_cost = min(cost, min_cost);
    }
    cout << min_cost << endl;
    return 0;
}