#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N;
ll A[200001];

int main(){
    cin >> N;
    for(int i=1;i<=N;i++) A[i] = 0;
    for(int i=2;i<=N;i++){
        ll a;
        cin >> a;
        A[a]++;
    }
    for(int i=1;i<=N;i++) cout << A[i] << endl;
    return 0;
}