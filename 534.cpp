#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef pair<ll,ii> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;

#define INF 1<<29
#define X first
#define Y second
#define ff(i,a,b) for(ll i=a;i<=b;++i)
#define FF(i,a,b) for(ll i=a;i>=b;--i)
#define N_ 205

int main(){
	int n,t=0;
	int x[N_],y[N_];
	
	while(cin>>n){
		if(n==0) break;
		ff(i,0,n-1){
			cin>>x[i]>>y[i];
		}
		
		double dist[N_][N_];
		
		ff(i,0,n-2) ff(j,i+1,n-1){
			dist[i][j]=dist[j][i]=sqrt(1.0*(x[i]-x[j])*(x[i]-x[j])+1.0*(y[i]-y[j])*(y[i]-y[j]));
		}
		
		ff(k,0,n-1) 
		ff(u,0,n-1)
		ff(v,0,n-1){
			dist[u][v]=min(dist[u][v],max(dist[u][k],dist[k][v]));
		}
		
		printf("Scenario #%d\nFrog Distance = %.3lf\n\n",++t,dist[0][n-1]);
		
	}
	return 0;
}
