#include <iostream>
#include <string>

using namespace std;
typedef long long ll;

string s;

int isCheck(string S, int s, int e){
    while(s < e){
        if(S[s] != S[e]){
            return 1;
        }
        s++;
        e--;
    }
    return 0;
}

int main(){
    cin >> s;
    int N = s.length();
    if(isCheck(s,0,N-1) == 1){
        cout << "No" << endl;
        return 0;
    }
    if(isCheck(s,0,(N-1)/2-1) == 1){
        cout << "No" << endl;
        return 0;
    }
    if(isCheck(s,(N+3)/2-1,N-1) == 1){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}