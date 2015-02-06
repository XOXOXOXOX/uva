#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef pair<ll,ii> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;

#define INF -1
#define X first
#define Y second
#define ff(i,a,b) for(ll i=a;i<=b;++i)
#define FF(i,a,b) for(ll i=a;i>=b;--i)
#define N_ 205

int main(){
	int n,m,t=0;
	int x[N_],y[N_];
	map<string,int > index;
	
	while(cin>>n>>m){
		if(n==0 && m==0) break;
		
		index.clear();
		int id=1;
		
		string a,b,start,destination;
		int c;
		
		int dist[N_][N_];
		/*
		ff(i,0,N_-1) ff(j,0,N_-1){
			dist[i][j]=INF;
			if(i==j) dist[i][j]=0;
		} 
		8=*/
		ff(i,1,m){
			cin>>a>>b>>c;
			
			if(index[a]==0){
				index[a]=id;
				id++;
			}
			if(index[b]==0){
				index[b]=id;
				id++;
			}
			
			int x=index[a];
			int y=index[b];
			
			dist[x][y]=dist[y][x]=c;
		}
		
		cin>>start>>destination;
		
		ff(k,1,n) 
		ff(u,1,n)
		ff(v,1,n){
			dist[u][v]=max(dist[u][v],min(dist[u][k],dist[k][v]));
		}
		
		printf("Scenario #%d\n%d tons\n\n",++t,dist[index[start]][index[destination]]);
		
	}
	return 0;
}
