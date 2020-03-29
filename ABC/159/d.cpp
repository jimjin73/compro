#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

int main(){
    ll v[200010];
    ll w[200010];
    ll input[200010];
    ll N;
    cin >> N;
    for(int i=0;i<=N;i++) v[i] = 0;
    for(int i=0;i<N;i++){
        cin >> input[i];
        v[input[i]]++;
    }
    ll sum = 0;
    for(int i=1;i<=N;i++){
        w[i] = v[i]*(v[i]-1)/2;
        sum += w[i];
    }
    for(int i=0;i<N;i++){
        cout << sum - w[input[i]] + (v[input[i]]-1)*(v[input[i]]-2)/2 << endl;
    }
    return 0;
}