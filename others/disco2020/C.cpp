#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

ll H,W,K;
string s[500];
ll m[500][500];

int main(){
    cin >> H >> W >> K;
    for(int i=0;i<H;i++) cin >> s[i];
    ll p = 0;
    for(int i=0;i<H;i++){
        bool f = false;
        for(int j=0;j<W;j++){
            if(s[i][j] == '#'){
                f = true;
                p++;
            }
            if(!f) continue;
            m[i][j] = p;
        }
    }
    for(int i=0;i<H;i++){
        for(int j=W-2;j>=0;j--){
            if(m[i][j]==0) m[i][j] = m[i][j+1];
        }
    }
    for(int i=1;i<H;i++){
        for(int j=0;j<W;j++){
            if(m[i][j] == 0) m[i][j] = m[i-1][j];
        }
    }
    for(int i=H-2;i>=0;i--){
        for(int j=0;j<W;j++){
            if(m[i][j] == 0) m[i][j] = m[i+1][j];
        }
    }
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cout << m[i][j];
            if(j != W-1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}