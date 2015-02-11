#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<cstdio>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;

string input;
int N;
bool flag;

int make_tree(int start,int sum){
	if(input[start+1]==')') return -1;
	
	int number=0;
	bool negative=false;
	start++;
	if(input[start]=='-'){
		negative=true;
		start++;	
	} 
	while(input[start]!='('){
		number*=10;
		int x=input[start]-'0';
		number+=x;
		start++;
	}
	
	if(negative) number=-number;
	
	//cout<<number<<endl;
	
	int start1,start2,left,right; // the position of children 
	// left child
	start1=start++;
	left=1;
	right=0;
	while(left!=right){
		if(input[start]=='(') left++;
		if(input[start]==')') right++;
		start++;
	}
	// right child
	start2=start++;
	left=1;
	right=0;
	while(left!=right){
		if(input[start]=='(') left++;
		if(input[start]==')') right++;
		start++;
	}
	
	int X=make_tree(start1,sum+number);
	int Y=make_tree(start2,sum+number);
	
	if(X==-1 && Y==-1 && sum+number==N) flag=true;
	
	return 0;
}

int main(){
	while(scanf("%d",&N)!=EOF){
		flag=false;
		
		// read the input:
		char c;
		while(scanf("%c",&c) && c!='(');
		input="(";
		
		int left_Parenthesis = 1;
        int right_Parenthesis = 0;
		
		while(left_Parenthesis!=right_Parenthesis){
			cin>>c;
			if(c=='(') left_Parenthesis++;
			if(c==')') right_Parenthesis++;
			
			if(c!=' ') input+=c;
		}
		
		make_tree(0,0);
		
		if(flag) printf("yes\n");
		else printf("no\n");
		
	}
}
