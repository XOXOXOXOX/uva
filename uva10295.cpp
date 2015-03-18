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
ll m,n;
map<string,ll> dict;
int main(){
    string s;
    ll cost;
    cin>>m>>n;
    f0(i,m){
        cin>>s>>cost;
        dict[s]=cost;
    }
    f0(i,n){
        ll res=0;

        while(cin>>s){
            if(s==".") break;
            if(dict.count(s))res+=dict[s];
        }
        cout<<res<<endl;
    }

}

