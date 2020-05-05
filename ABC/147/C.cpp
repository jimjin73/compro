#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
int m[15][15];

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            m[i][j] = -1;
        }
    }
    for(int i=0;i<N;i++){
        int A;
        cin >> A;
        for(int j=0;j<A;j++){
            int x,y;
            cin >> x >> y;
            m[i][x-1] = y;
        }
    }
    int max_s = 0;
    for(int i=0;i<(1<<N);i++){
        bitset<15> bt(i);
        bool f = true;
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                if(m[j][k] == -1) continue;
                if(m[j][k] == 1){
                    if(bt[j] == 1 && bt[k] == 0) f = false;
                }else{
                    if(bt[j] == 1 && bt[k] == 1) f = false;
                }
            }
        }
        if(f) max_s = max(max_s, (int)bt.count());
    }
    cout << max_s << endl;
    return 0;
}