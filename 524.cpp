#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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

vector<bool> prime(1000,true);
vector<int> res[10001];
long long n,a[102],k;
bool b[102];

void backtrack(int pos){
    if(pos==n){
        if(prime[a[0]+a[n-1]]){
            cout<<a[0];
            for(int i=1;i<n;i++){
                cout<<" "<<a[i];
            }
            cout<<endl;
        }
    }
    else{
        for(int i=2;i<=n;i++){
            if(b[i]){
                if(prime[a[pos-1]+i]){
                    a[pos]=i;
                    b[i]=false;
                    backtrack(pos+1);
                    backtrack(pos+1);
                    b[i]=true;
                }
            }

        }
    }
}

int main(){
    for(int i=2;i<1000;i++){
        if(prime[i]){
            int j=2*i;
            while(j<1000){
                prime[j]=false;
                j+=i;
            }
        }
    }
    int t=0;

    while(cin>>n){
        for(int i=0;i<=n;i++) b[i]=true;
        b[1]=false;
        a[0]=1;
        ///for(int i=2;i<50;i++) if(prime[i]) cout<<i<<" ";
        if(t!=0) cout<<endl;
        cout<<"Case "<<++t<<":\n";
        backtrack(1);
    }

}
