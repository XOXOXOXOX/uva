#include<iostream>
#include<vector>
#include<queue>
#include<math.h>
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
#define N_ 102

int a[N_][N_];
int n,r,s,d,t,tc=0;

int main(){
	int x,y,z;
	
	while(cin>>n>>r){
		if(n==0 || r==0) break;
		
		ff(i,1,n) ff(j,1,n) a[i][j]=0;
		
		ff(i,1,r){
			cin>>x>>y>>z;
			a[x][y]=a[y][x]=z-1;
		}
		
		cin>>s>>d>>t;
		
		ff(k,1,n){
			ff(i,1,n){
				ff(j,1,n){
					a[i][j]=max(a[i][j],min(a[i][k],a[k][j]));
				}
			}
		}
		
		int res=ceil((double)t/a[s][d]);
		
		cout<<"Scenario #"<<++tc<<endl;
		cout<<"Minimum Number of Trips = "<<res<<endl<<endl;
		
	}
	return 0;
	
}
