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
#define N_ 1000000

int main(){
	ll tc,a,b,c;
	ll n,m,S,T;
	vector<vii> adjlist;
	priority_queue<ii, vector<ii>,greater<ii> > pq;
	vector<ll> dist;
	
	cin>>tc;
	ll t=0;
	
	while(tc--){		
		cin>>n>>m>>S>>T;
		adjlist.assign(n,vii());
		dist.assign(n,INF);
		
		for(ll i=0;i<m;i++){
			cin>>a>>b>>c;
			adjlist[a].push_back(ii(c,b));
			adjlist[b].push_back(ii(c,a));
		}
		
		dist[S]=0;
		pq.push(ii(0,S));
		
		while(!pq.empty()){
			ii front=pq.top();
			pq.pop();
			
			int u=front.Y;
			int d=front.X;
			
			for(ll i=0;i<adjlist[u].size();i++){
				ii v=adjlist[u][i];
				
				if(d+v.X<dist[v.Y]){
					dist[v.Y]=d+v.X;
					
					pq.push(ii(dist[v.Y],v.Y));
				}
			}
			
		}
		cout<<"Case #"<<++t<<": ";
		if(dist[T]==INF) cout<<"unreachable"<<endl;
		else cout<<dist[T]<<endl;
		
	}
	
}
