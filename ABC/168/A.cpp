#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N;

int main(){
    cin >> N;
    if(N%10 == 3){
        cout << "bon" << endl;
    }else if(N%10 == 0 || N%10==1 || N%10==6 || N%10==8){
        cout << "pon" << endl;
    }else{
        cout << "hon" << endl;
    }
    return 0;
}