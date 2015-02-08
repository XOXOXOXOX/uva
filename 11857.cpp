#include<iostream>
#include<vector>
#include<queue>
#include<math.h>
#include<algorithm>
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
#define N_ 1000010

// Union_find Disjoint Sets
int N,M;
int pset[N_];
int set_size;
void initset(int n){
	set_size=N;
	for(int i=0;i<n;i++) pset[i]=i;
}

int findset(int x){
	if(x==pset[x]) return x;
	else return pset[x]=findset(pset[x]);
}

void unionset(int x,int y){
	int rx=findset(x);
	int ry=findset(y);
	
	pset[rx]=ry;
	set_size--;
}

bool sameset(int x,int y){
	return findset(x)==findset(y);
}


// Dijkstra algorithm
vector<iii> edge;
int res;

void dijkstra(){
	
	sort(edge.begin(),edge.end());
	
	for(int i=0;i<edge.size();i++){
		iii front=edge[i];
		
		int u=front.second.first;
		int v=front.second.second;
		int w=front.first;
		
		if(!sameset(u,v)){
			res=max(res,w);
			unionset(u,v);
		}
	}
	
}


int main(){
	while(cin>>N>>M){
		if(N==0 && M==0) break;
		
		// Init:
		int x,y,z;
		
		edge.clear();
		initset(N);
		res=0;
		
		for(int i=0;i<M;i++){
			cin>>x>>y>>z;
			edge.push_back(iii(z,ii(x,y)));
		}
		
		// Process:
		dijkstra();
		
		if(set_size>1) cout<<"IMPOSSIBLE"<<endl;
		else cout<<res<<endl;
		
	}
}
