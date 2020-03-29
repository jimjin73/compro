#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll X,Y,A,B,C;
vector<ll> p;
vector<ll> q;
vector<ll> r;

int main(){
    p.resize(100010);
    q.resize(100010);
    r.resize(100010);
    cin >> X >> Y >> A >> B >> C;
    for(int i=0;i<A;i++) cin >> p[i];
    for(int i=0;i<B;i++) cin >> q[i];
    for(int i=0;i<C;i++) cin >> r[i];
    sort(p.begin(),p.end(),greater<ll>());
    sort(q.begin(),q.end(),greater<ll>());
    sort(r.begin(),r.end(),greater<ll>());
    int ap = X-1;
    int bp = Y-1;
    int cp = 0;
    while(true){
        if(ap < 0 && bp < 0) break;
        if(cp >= C) break;
        if(ap < 0){
            if(q[bp] >= r[cp]) break;
            bp--;
            cp++;
            continue;
        }
        if(bp < 0){
            if(p[ap] >= r[cp]) break;
            ap--;
            cp++;
            continue;
        }
        if(p[ap] < q[bp]){
            if(p[ap] >= r[cp]) break;
            ap--;
            cp++;
        }else{
            if(q[bp] >= r[cp]) break;
            bp--;
            cp++;
        }
    }
    ll sum = 0;
    for(int i=0;i<=ap;i++) sum += p[i];
    for(int i=0;i<=bp;i++) sum += q[i];
    for(int i=0;i<cp;i++) sum += r[i];
    cout << sum << endl;
    return 0;
}