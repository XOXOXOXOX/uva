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

#define pb push_back
#define INF 1e9
#define X first
#define Y second
#define ff(i,a,b) for(ll i=a;i<=b;++i)
#define FF(i,a,b) for(ll i=a;i>=b;--i)
#define f0(i,n) for(ll i=0;i<n;++i)
#define f_all(i,a) for(ll i=0;i<a.size();++i)
#define N_ 4004
#define all(a) a.begin(),a.end()
#define IOS ios_base::sync_with_stdio(false);

double dp[1<<16];
ll x[20],y[20];
ll n;

double F(ll mask){
	if(mask==(1<<n)-1) return 0;
	else if(dp[mask]!=0) return dp[mask];
	
	double res=1e9;
	ll p1,p2;
	
	for(p1=0;p1<n;p1++){
		if(((mask>>p1)&1)==0) break;
	}
	
	for(p2=p1+1;p2<n;p2++){
		if(((mask>>p2)&1)==0){
			res=min(res,hypot(abs(x[p1]-x[p2]),abs(y[p1]-y[p2]))+F(mask|(1<<p1)|(1<<p2)) );
		}
	}
	
	return dp[mask]=res;
}



int main(){
    char c[102];
    int t=0;
    while(scanf("%lld",&n)==1){
    	if(n==0) break;
		n*=2;
    	for(int i=0;i<n;i++){
    		scanf("%s %lld %lld",c,&x[i],&y[i]);
    	}
    	memset(dp,0,sizeof(dp));
    	double res=F(0);
    	
    	printf("Case %d: %.2lf\n",++t,res);
    }
    return 0;
}
