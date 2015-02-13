#include<bits/stdc++.h>
using namespace std;

string Plus(string a,string b){
	string res="";
	int l1=a.size();
	int l2=b.size();
	
	int l=max(l1,l2);
	
	for(int i=0;i<l-l1;i++) a='0'+a;
	for(int i=0;i<l-l2;i++) b='0'+b;
	
	int memo=0;
	
	for(int i=l-1;i>=0;--i){
		int x=a[i]-'0';
		int y=b[i]-'0';
		
		int z=x+y+memo;
		memo=0;
		
		if(z>9){
			z-=10;
			memo=1;
		}
		
		char c='0'+z;
		res=c+res;
	}
	
	if(memo==1) res='1'+res;
	
	return res;
}

int main(){
	string s;
	string ans="0";
	
	while(cin>>s){
		if(s=="0") break;
		ans=Plus(ans,s);
	}
	
	cout<<ans<<endl;
	return 0;
	
}
