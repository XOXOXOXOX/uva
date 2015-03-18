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
#define N_ 10002
#define all(a) a.begin(),a.end()

map<string,int> mp;
vector<string> V;
int main(){
    int t,cnt;
    scanf("%d\n",&t);
    char a[10001];

    while(t--){
        cnt=0;
        mp.clear();
        V.clear();

        while(gets(a)){
            if(strlen(a)==0) break;
            cnt++;
            if(!mp.count(string(a))){
                mp[string(a)]=1;
                V.push_back(string(a));
            }
            else mp[string(a)]++;
        }

        sort(all(V));
        f_all(i,V){
            cout<<V[i];
            printf(" %.4lf\n",(1.0*mp[V[i]]/cnt)*100.0);
        }

        if(t!=0) printf("\n");
    }
}
