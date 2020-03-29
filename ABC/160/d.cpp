#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;

int m[2010][2010];
int N,X,Y;
int c[2010];

int main(){
    cin >> N >> X >> Y;
    for(int i=0;i<N;i++) c[i] = 0;
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            c[min(j-i,abs(X-i-1) + abs(Y-1-j)+ 1)]++;
        }
    }
    for(int i=1;i<N;i++){
        cout << c[i] << endl;
    }
    return 0;
}