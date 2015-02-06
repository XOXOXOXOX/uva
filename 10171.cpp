#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define N_ 27
#define INF 1<<30

ll Y[N_][N_];
ll M[N_][N_];

int main(){
    ll n,t;
    char a,b,c,d,X_,Y_;

    while(scanf("%lld",&n)==1){
        if(n==0) break;

        for(int i=0;i<N_;i++){
            for(int j=0;j<N_;j++){
                Y[i][j]=M[i][j]=INF;
                if(i==j) Y[i][j]=M[i][j]=0;
            }
        }

        for(int i=0;i<n;i++){
            cin>>a>>b>>c>>d>>t;
            int x=c-'A';
            int y=d-'A';
            if(a=='Y'){
                if(b=='B'){
                    Y[x][y]=min(Y[x][y] ,t);
                    Y[y][x]=min(Y[y][x],t);
                }
                else{
                    Y[x][y]=min(Y[x][y],t);
                }
            }
            else{
                if(b=='B'){
                    M[x][y]=min(M[x][y],t);
                    M[y][x]=min(M[y][x],t);
                }
                else{
                    M[x][y]=min(M[x][y],t);
                }
            }

        }
        cin>>X_>>Y_;
        int x_=X_-'A';
        int y_=Y_-'A';
        ll res=INF;
        vector<char> ress;

        for(int k=0;k<26;k++){
            for(int u=0;u<26;u++){
                for(int v=0;v<26;v++){
                    Y[u][v]=min(Y[u][v],Y[u][k]+Y[k][v]);
                    M[u][v]=min(M[u][v],M[u][k]+M[k][v]);
                }
            }
        }

        for(int i=0;i<26;i++){
            if(Y[x_][i]+M[y_][i]<res && Y[x_][i]!=INF && M[y_][i]!=INF){
                ress.clear();
                ress.push_back('A'+i);

                res=Y[x_][i]+M[y_][i];
            }

            else if(Y[x_][i]+M[y_][i]==res && Y[x_][i]!=INF && M[y_][i]!=INF){
                ress.push_back('A'+i);
            }
        }

        if(res!=INF){
            //sort(ress.begin(),ress.end());
            cout<<res;
            for(int i=0;i<ress.size();i++) cout<<" "<<ress[i];
            cout<<endl;
        }
        else cout<<"You will never meet.\n";
    }
    return 0;
}
