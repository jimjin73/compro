#include <bits/stdc++.h>

using namespace std;

int N,Q;
string s;
set<int> v[26];

int main(){
    cin >> N;
    cin >> s;
    cin >> Q;
    for(int i=0;i<N;i++) v[s[i]-'a'].insert(i);
    for(int i=0;i<26;i++) v[i].insert(N+1);
    vector<int> ans;
    for(int i=0;i<Q;i++){
        int C = 0;
        int a;
        cin >> a;
        if(a == 1){
            int b;
            char c;
            cin >> b >> c;
            v[s[b-1]-'a'].erase(b-1);
            s[b-1] = c;
            v[s[b-1]-'a'].insert(b-1);
        }else{
            int b,c;
            cin >> b >> c;
            for(int j=0;j<26;j++){
                if(c > *(v[j].lower_bound(b-1))){
                    C++;
                }
            }
            ans.push_back(C);
        }
    }
    for(auto &e : ans) cout << e << endl;
    return 0;
}