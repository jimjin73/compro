#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<pair<ll,ll>> ms;
vector<pair<ll,ll>> ns;

int main(){
    ll x,y;
    ll n,m;
    cin >> m;
    for(int i=0;i<m;i++){
        cin >> x >> y;
        ms.push_back(make_pair(x,y));
    }
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x >> y;
        ns.push_back(make_pair(x,y));
    }
    sort(ns.begin(),ns.end());
    for(int i=0;i<n;i++){
        ll dx = ns[i].first - ms[0].first;
        ll dy = ns[i].second - ms[0].second;
        bool f = true;
        for(int j=1;j<m;j++){
            if(!binary_search(ns.begin(),ns.end(),make_pair(ms[j].first + dx, ms[j].second + dy))){
                f = false;
                break;
            }
        }
        if(f){
            cout << dx << " " << dy << endl;
            return 0;
        }
    }
    cout << "error" << endl;
    return 0;
}