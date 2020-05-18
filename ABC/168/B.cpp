#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string s;
ll K;

int main(){
    cin >> K;
    cin >> s;
    if(s.size() <= K){
        cout << s << endl;
    }else{
        for(int i=0;i<K;i++) cout << s[i];
        cout << "...";
        cout << endl;
    }
    return 0;
}