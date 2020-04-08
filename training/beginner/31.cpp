#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int W,H;
int m[110][110];
queue<pair<int,int>> q;
int ody[6] = {0,1,-1,1,0,1};
int edy[6] = {-1,0,-1,1,-1,0};
int dx[6] = {-1,-1,0,0,1,1};

int main(){
    cin >> W >> H;
    for(int i=0;i<H+2;i++){
        for(int j=0;j<W+2;j++){
            m[i][j] = 0;
        }
    }
    int t;
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            cin >> t;
            m[i][j] = t;
        }
    }
    q.push(make_pair(0,0));
    m[0][0] = 2;
    while(!q.empty()){
        pair<int,int> p = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;
        for(int i=0;i<6;i++){
            int xx = x;
            int yy = y;
            xx += dx[i];
            if(x % 2 == 0){
                yy += edy[i];
            }else{
                yy += ody[i];
            }
            if(xx < 0 || xx > H+1) continue;
            if(yy < 0 || yy > W+1) continue;
            if(m[xx][yy] == 0){
                m[xx][yy] = 2;
                q.push(make_pair(xx,yy));
            }
            if(m[xx][yy] == 1){
                m[xx][yy] = 3;
            }
        }
    }
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            if(m[i][j] < 2) m[i][j] = 3;
        }
    }
    int c = 0;
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            if(m[i][j] == 2) continue;
            for(int k=0;k<6;k++){
                int xx = i;
                int yy = j;
                xx += dx[k];
                if(i % 2 == 0){
                    yy += edy[k];
                }else{
                    yy += ody[k];
                }
                if(m[xx][yy] == 2) c++;
            }
        }
    }
    cout << c << endl;
    return 0;
}