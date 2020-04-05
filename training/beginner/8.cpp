#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N;
vector<ll> A,B;

int main(){
    cin >> N;
    ll a,b;
    for(int i=0;i<N;i++){
        cin >> a >> b;
        A.push_back(a);
        B.push_back(b);
    }
    vector<ll> AA = A;
    vector<ll> BB = B;
    sort(AA.begin(), AA.end());
    sort(BB.begin(), BB.end());
    ll ca = AA[N/2];
    ll cb = BB[N/2];
    ll dista = 0;
    ll distm = 0;
    ll distb = 0;
    for(int i=0;i<N;i++){
        dista += abs(ca - A[i]);
        distb += abs(cb - B[i]);
        distm += abs(B[i]-A[i]);
    }
    /*
    if(N % 2 == 0){
        ca = AA[N/2-1];
        cb = BB[N/2-1];
        ll distaa = 0;
        ll distbb = 0;
        for(int i=0;i<N;i++){
            distaa += abs(ca - A[i]);
            distbb += abs(B[i]-cb);
        }
        dista = min(dista, distaa);
        distb = min(distb, distbb);
    }
    */
    cout << dista + distb + distm << endl;
    return 0;
}