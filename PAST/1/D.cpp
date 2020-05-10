#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N;
ll A[200001];
ll c[200001];

int main(){
    cin >> N;
    for(int i=0;i<N;i++) cin >> A[i];
    for(int i=0;i<N;i++) c[A[i]]++;
    int a,b;
    a=b=-1;
    for(int i=1;i<=N;i++){
        if(c[i] == 0) a = i;
        if(c[i] == 2) b = i;
    }
    if(a == -1){
        cout << "Correct" << endl;
    }else{
        cout << b << " " << a << endl;
    }
    return 0;
}