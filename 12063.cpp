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

ll dp[35][35][102]; // dp[i][j][k]:: i bit 0, j bit 1, mod==k
int N,K;
int main(){
    int t;scanf("%d",&t);
    int tc=0;
    while(t--){
    	printf("Case %d: ",++tc);
    	
		scanf("%d%d",&N,&K);
    	
		if(N%2==1|| K==0){
    		printf("0\n");
    	}
    	else{
    		N/=2;
    		memset(dp,0,sizeof(dp));
    		dp[0][1][1%K]=1;
    		
			for(int i=0;i<=N;i++){
    			for(int j=0;j<=N;j++){
    				for(int k=0;k<K;k++){
    					dp[i][j+1][((k<<1)+1)%K]+=dp[i][j][k];
    					dp[i+1][j][(k<<1)%K]+=dp[i][j][k];
    				}
    			}
    		}
    		
    		printf("%lld\n",dp[N][N][0]);
    	}
    }
    return 0;
}
