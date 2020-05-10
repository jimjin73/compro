#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string s;
vector<string> v;

int main(){
    cin >> s;
    int sp,ep;
    sp=0;ep=1;
    while(true){
        if(s[ep] >= 'a' && s[ep] <= 'z'){
            ep++;
            continue;
        }
        string ss = s.substr(sp,ep-sp+1);
        ss[0] += ('a' - 'A');
        ss[ss.size()-1] += ('a'-'A');
        v.push_back(ss);
        if(ep == s.size()-1) break;
        sp = ep+1;
        ep = ep+2;
    }
    sort(v.begin(),v.end());
    for(auto &e : v){
        e[0] += ('A' - 'a');
        e[e.size()-1] += ('A' - 'a');
        cout << e;
    }
    cout << endl;
    return 0;
}