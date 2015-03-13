#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cassert>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef pair<ll,ii> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;

#define INF 1e9
#define X first
#define Y second
#define ff(i,a,b) for(ll i=a;i<=b;++i)
#define FF(i,a,b) for(ll i=a;i>=b;--i)
#define N_ 1002

int dr[]={0,1,0,-1};
int dc[]={1,0,-1,0};

int a[N_][N_];
int d[N_][N_];
int r,c;
queue<ii> Q;
int main(){
    ios_base::sync_with_stdio(false);

    while(cin>>r>>c){
        if(r==0 && c==0) break;

        for(int i=0;i<=r;i++){
            for(int j=0;j<=c;j++){
                d[i][j]=INF;
                a[i][j]=0;
            }
        }

        int n; cin>>n;
        for(int i=0;i<n;i++){
            int x,m; cin>>x>>m;
            for(int j=0;j<m;j++){
                int y;cin>>y;
                a[x][y]=1;
                d[x][y]=-1;
            }
        }
        int sx,sy,dx,dy;
        cin>>sx>>sy>>dx>>dy;
        d[sx][sy]=0;
        Q.push(ii(sx,sy));

        while(!Q.empty()){
            int cx=Q.front().first;
            int cy=Q.front().second;
            Q.pop();
            for(int i=0;i<4;i++){
                int nx=cx+dr[i];
                int ny=cy+dc[i];
                if(nx>=0 && ny>=0 && nx<=r && ny<=c){
                    if(a[nx][ny]==0 && d[nx][ny]==INF){
                        d[nx][ny]=d[cx][cy]+1;
                        Q.push(ii(nx,ny));
                    }
                }
            }
        }
        cout<<d[dx][dy]<<endl;
    }
    return 0;
}

