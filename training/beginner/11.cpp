#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bitset<10> bts[10];
int p[10];

int main(){
    int N,M;
    cin >> N >> M;
    for(int i=0;i<M;i++){
        int k;
        cin >> k;
        bts[i] = 0;
        for(int j=0;j<k;j++){
            int b;
            cin >> b;
            bts[i].set(b-1);
        }
    }
    for(int i=0;i<M;i++){
        cin >> p[i];
    }
    ll c = 0;
    for(int i=0;i<(1<<N);i++){
        bitset<10> n(i);
        bool f = true;
        for(int j=0;j<M;j++){
            bitset<10> btt = n & bts[j];
            if(btt.count()%2 != p[j]){
                f = false;
                break;
            }
        }
        if(f) c++;
    }
    cout << c << endl;
    return 0;
}