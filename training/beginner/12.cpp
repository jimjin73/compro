#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int b[13][13];
int N,M;

int main(){
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            b[i][j] = 0;
        }
    }
    for(int i=0;i<M;i++){
        int x,y;
        cin >> x >> y;
        b[x-1][y-1] = b[y-1][x-1] = 1;
    }
    int max_c = 0;
    for(int i=1;i<(1<<N);i++){
        bitset<12> bt(i);
        int bb = 1;
        vector<int> v;
        for(int j=0;j<N;j++){
            if(bt[j] == 1) v.push_back(j);
        }
        int t = 1;
        for(int x=0;x<v.size();x++){
            for(int y=x+1;y<v.size();y++){
                t &= b[v[x]][v[y]];
            }
        }
        if(t==1 && max_c < bt.count()){
            max_c = bt.count();
        }
    }
    cout << max_c << endl;
    return 0;
}