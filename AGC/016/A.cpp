#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

string t;

int main(){
    cin >> t;
    int L = t.size();
    int min_v = 1e9;
    for(int i=0;i<26;i++){
        string s = t;
        char c = 'a' + i;
        bool f = false;
        for(int j=0;j<L;j++) if(s[j] == c) f = true;
        if(!f) continue;
        for(int j=0;j<L;j++){
            f = true;
            for(int l=0;l<L-j;l++){
                if(s[l] != c) f = false;
            }
            for(int l=0;l<L-j-1;l++){
                if(s[l] == c || s[l+1] == c) s[l] = c;
            }
            if(f){
                min_v = min(min_v, j);
                break;
            }
        } 
    }
    cout << min_v << endl;
    return 0;
}