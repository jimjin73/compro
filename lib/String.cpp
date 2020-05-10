#include <bits/stdc++.h>

using namespace std;

void toLower(string& s){
    for(int i=0;i<s.size();i++){
        if(s[i] >='A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
    }
}

void toUpper(string& s){
    for(int i=0;i<s.size();i++){
        if(s[i] >='a' && s[i] <= 'z') s[i] = s[i] - 'a' + 'A';
    }
}

int main(){
    string s = "sd3jDKsi2fDL";
    toLower(s);
    cout << s << endl;
    toUpper(s);
    cout << s << endl;
}