#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1<<29;
#define X first
#define Y second
#define ff(i,a,b) for(ll i=a;i<=b;++i)
#define FF(i,a,b) for(ll i=a;i>=b;--i)
#define N_ 1000000

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

int weight[1010][1010];
int R,C;

int dijkstra(){
	priority_queue<iii,vector<iii>,greater<iii> > pq; 
	
	int distance[1010][1010];
	
	for(int i=0;i<R;i++)
	for(int j=0;j<C;j++){
		distance[i][j]=INF;
	}
	
	distance[0][0]=weight[0][0];
	
	pq.push(iii(distance[0][0],ii(0,0)));
	
	while(!pq.empty()){
		iii front=pq.top();
		pq.pop();
		
		int d=front.X;
		int r=front.Y.X;
		int c=front.Y.Y;
		
		for(int i=0;i<4;i++){
			int nr=r+dx[i];
			int nc=c+dy[i];
			
			if(nr>=0 && nc>=0 && nr<R && nc<C){
				if(d+weight[nr][nc]<distance[nr][nc]){
					distance[nr][nc]=d+weight[nr][nc];
					pq.push(iii(distance[nr][nc],ii(nr,nc)));
				}
				
			}
			
		}
		
	}
	
	return distance[R-1][C-1];
}

int main(){
	int t;cin>>t;
	
	while(t--){
		cin>>R>>C;
		
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++){
				cin>>weight[i][j];
			}
		}
		cout<<dijkstra()<<endl;
	}
	
}
