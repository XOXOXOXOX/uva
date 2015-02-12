#include<bits/stdc++.h>
using namespace std;

string s1,s2;
///DBACEGF ABCDEFG -> ACBFGED
///BCAD CBAD -> CDAB

string F(int n,int m,int p,int q){
    int a=s2.find(s1[n]);
    int b=-1;

    string res="";

    if(a!=p){
        b=n;
        while(b<=m && s2.find(s1[b+1])<a) b++;
        if(b!=n) res+=F(n+1,b,p,a-1);
    }

    if(a!=q){
        if(b!=-1) res+=F(b+1,m,a+1,q);
        else res+=F(n+1,m,a+1,q);
    }

    res+=s1[n];

    return res;
}


int main(){
    while(cin>>s1>>s2){
        cout<<F(0,s1.size()-1,0,s2.size()-1)<<endl;
    }
    return 0;
}
