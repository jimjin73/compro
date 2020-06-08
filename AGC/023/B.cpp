#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

ll N;
string s[300];
char t[300][300];

bool check(){
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(t[i][j] != t[j][i]) return false;
        }
    }
    return true;
}

int main(){
    ll ans = 0;
    cin >> N;
    for(int i=0;i<N;i++) cin >> s[i];
    for(int z=0;z<N;z++){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                t[i][(j+z)%N] = s[i][j];
            }
        }
        if(check()) ans += N;
    }
    cout << ans << endl;
    return 0;
}