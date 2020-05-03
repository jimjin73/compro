#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll A,B,N;

int main(){
    cin >> A >> B >> N;
    if(N >= B) N = B-1;
    cout << (A*N/B) - A*(N/B) << endl;
    return 0;
}