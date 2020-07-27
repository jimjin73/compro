#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

string S;

bool check(){
    for(auto &c : S){
        if(c != '_') return false;
    }
    return true;
}

ll pCount(){
    for(int i=0;i<S.size();i++){
        if(S[i] != '_') return i;
    }
    return -1;
}

ll sCount(){
    for(int i=0;i<S.size();i++){
        if(S[S.size()-1-i] != '_') return i;
    }
    return -1;
}

int main(){
    cin >> S;
    if(check()){
        cout << S << endl;
        return 0;
    }
    ll pre = pCount();
    ll suf = sCount();
    string subS = S.substr(pre,S.size()-suf-pre);
    bool is_cam, is_und;
    is_cam = is_und = false;
    for(auto &c : subS){
        if(c == '_') is_und = true;
        if(c >= 'A' && c <= 'Z') is_cam = true;
    }
    if(subS[0] >= 'A' && subS[0] <='Z'){
        cout << S << endl;
        return 0;
    }
    if(subS[0] >= '0' && subS[0] <= '9'){
        cout << S << endl;
        return 0;
    }
    if(is_und && is_cam){
        cout << S << endl;
        return 0;
    }
    if((!is_und) && (!is_cam)){
        cout << S << endl;
        return 0;
    }
    for(int i=1;i<subS.size();i++){
        if(subS[i] == '_' && subS[i-1] == '_'){
            cout << S << endl;
            return 0;
        }
    }
    string T;
    if(is_cam){
        for(int i=0;i<pre;i++) T.push_back('_');
        for(int i=0;i<subS.size();i++){
            if(subS[i] >= 'A' && subS[i] <= 'Z'){
                T.push_back('_');
                T.push_back(subS[i] - 'A' + 'a');
            }else{
                T.push_back(subS[i]);
            }
        }
        for(int i=0;i<suf;i++) T.push_back('_');
    }
    if(is_und){
        for(int i=0;i<pre;i++) T.push_back('_');
        for(int i=0;i<subS.size();i++){
            if(subS[i] == '_'){
                i++;
                if(subS[i] >= '0' && subS[i] <= '9'){
                    cout << S << endl;
                    return 0;
                }
                T.push_back(subS[i]-'a'+'A');
            }else{
                T.push_back(subS[i]);
            }
        }
        for(int i=0;i<suf;i++) T.push_back('_');
    }
    cout << T << endl;
    return 0;
}