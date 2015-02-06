#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define N_ 102
#define INF 1e9


int main(){
    int a,b,d,res;
    int dist[N_][N_];
    int t=0;
    while(cin>>a>>b){
        if(a==0 && b==0) break;
        d=0;
        res=0;
        for(int i=1;i<N_;i++){
            for(int j=1;j<N_;j++){=
                dist[i][j]=INF;
                if(i==j) dist[i][j]=0;
            }
        }

        dist[a][b]=1;
        //cout<<a<<b<<endl;
        while(cin>>a>>b){
            if(a==0 && b==0) break;
            dist[a][b]=1;
        }

        for(int k=1;k<N_;k++){
            for(int u=1;u<N_;u++){
                for(int v=1;v<N_;v++){
                    dist[u][v]=min(dist[u][v],dist[u][k]+dist[k][v]);
                }
            }
        }

        for(int i=1;i<N_;i++){
            for(int j=1;j<N_;j++){
                if(i!=j){
                    if(dist[i][j]!=INF){
                        d++;
                        res+=dist[i][j];
                        //cout<<i<<" "<<j<<" "<<dist[i][j]<<endl;
                    }
                }
            }
        }
    //cout<<dist[1][2]<<endl;
        printf("Case %d: average length between pages = %.3lf clicks\n",++t,double(res)/double(d));

    }
}

