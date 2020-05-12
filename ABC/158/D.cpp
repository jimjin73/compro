#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

deque<char> d;
string s;
ll Q;
bool f;

int main(){
    cin >> s;
    cin >> Q;
    f = true;
    for(auto &e : s) d.push_back(e);
    for(int i=0;i<Q;i++){
        int a;
        cin >> a;
        if(a == 1){
            if(f) f = false;
            else f = true;
        }else{
            int b;
            char c;
            cin >> b >> c;
            if((b == 1 && f) || (b == 2 && !f)) d.push_front(c);
            else d.push_back(c);
        }
    }
    if(!f) reverse(d.begin(),d.end());
    for(auto &e : d) cout << e;
    cout << endl;
    return 0;
}