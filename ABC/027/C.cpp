#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N;

int main(){
    cin >> N;
    bool f = false;
    while(N > 1){
        if(f){
            if(N%2==0) N--;
            N /= 2;
            f = false;
        }else{
            N /= 2;
            f = true;
        }
    }
    if(N == 0){
        if(f) f = false;
        else f = true;
    }
    if(f){
        cout << "Takahashi" << endl;
    }else{
        cout << "Aoki" << endl;
    }
    return 0;
}