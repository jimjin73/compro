#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

int N;
int B[100];
vector<int> v;

int main(){
    cin >> N;
    for(int i=0;i<N;i++) cin >> B[i];
    for(int i=0;i<N;i++){
        int p = -1;
        int z = N-i;
        for(int j=N-1;j>=0;j--){
            if(B[j] == -1) continue;
            if(B[j] != z){
                z--;
                continue;
            }
            p = j;
            break;
        }
        if(p==-1){
            cout << -1 << endl;
            return 0;
        }
        v.push_back(B[p]);
        B[p] = -1;
    }
    reverse(v.begin(),v.end());
    for(auto &e : v) cout << e << endl;
    return 0;
}