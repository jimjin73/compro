#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

ll N,M;
string A[50];
string B[50];

int main(){
    cin >> N >> M;
    for(int i=0;i<N;i++) cin >> A[i];
    for(int i=0;i<M;i++) cin >> B[i];
    for(int i=0;i+M-1<N;i++){
        for(int j=0;j+M-1<N;j++){
            bool f = true;
            for(int x=0;x<M && f;x++){
                for(int y=0;y<M && f;y++){
                    if(B[x][y] != A[i+x][j+y]) f = false;
                }
            }
            if(f){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}