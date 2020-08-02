#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

/*
query(a,b) : aからb-1番目の要素までの総和
*/

template <typename T>
struct cumsum{
    vector<T> V;
    ll L;
    cumsum(vector<T> &v) : V(v){     
        L = V.size();
        for(int i=1;i<L;i++) V[i] += V[i-1];
    } 
    T query(int a, int b){
        if(a == b) return 0;
        T ret = V[b-1];
        if(a > 0) ret -= V[a-1];
        return ret;
    }
};


int main(){
    vector<ll> v = {1,3,5,4,6,2};
    cumsum<ll> cs(v);
    cout << cs.query(2,5) << endl;
    return 0;
}