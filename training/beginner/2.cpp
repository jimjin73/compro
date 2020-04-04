#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    int N;
    cin >> N;
    int count = 0;
    for(int i=3;i<=N;i+=2){
        int n = 0;
        for(int j=1;j*j<i;j+=2){
            if(i % j == 0) n += 1;
        }
        if(n==4){
            count++;
        }
    }
    cout << count << endl;
    return 0;
}