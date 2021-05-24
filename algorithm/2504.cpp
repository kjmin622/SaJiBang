#include<iostream>
#include<cstring>
#include<stack>
#include<vector>
using namespace std;

string s; 
int order[31]={};
bool visit[31]={};

int nextIdx(int idx){
	while(visit[idx]){
		idx++;
		if(s.size()<=idx) return -1;
	}
	return idx;
}
int prevIdx(int idx){
	while(visit[idx]){
		idx--;
		if(idx<0) return -1;
	}
}

int main(){
	int idx=0;
	cin>>s;
	stack<char> st, st2;
	stack<int> nst;
	int ans = 0, target=0, visitnum=0;
	
	while(s[idx]!='\0'){
		if(s[idx]=='(' || s[idx]=='['){
			st.push(s[idx]);
			order[idx]=st.size();
			if(target<st.size()) target=st.size();
		}
		else{
			if(st.empty() || s[idx]==')'&&st.top()!='(' || s[idx]==']'&&st.top()!='['){
				cout<<"0\n"; return 0;
			}
			order[idx]=-st.size();
			st.pop();
		}
		idx++;
	}
	if(!st.empty()){
		cout<<"0\n"; return 0;
	}
	vector<char> vs;
	for(int i=0; i<s.size()-1; i++){
		if(order[i]>0){
			if(order[i]+order[i+1]==0){ // n, -n
				if(s[i]=='(') vs.push_back('2');
				else vs.push_back('3');
			}
			else if(order[i+1]>0&&order[i+1]>order[i]){ // n, m
				if(s[i]=='(') vs.push_back('2');
				else vs.push_back('3');
				vs.push_back('*');
				vs.push_back('(');
			}
		}
		else{
			if(order[i+1]>0){
				vs.push_back('+');
			}
			if(order[i+1]<0){
				vs.push_back(')');
			}
		}
	}
	
	vector<char> ves;
	for(char c:vs){
		if(c=='2' || c=='3') ves.push_back(c);
		if(c=='+'){
			while(!st2.empty() && (st2.top()=='+' || st2.top()=='*')){
				ves.push_back(st2.top()); st2.pop();
			}
			st2.push(c);
		}
		if(c=='*'){
			while(!st2.empty() && st2.top()=='*'){
				ves.push_back(st2.top()); st2.pop();
			}
			st2.push(c);
		}
		if(c=='(') st2.push(c);
		if(c==')'){
			while(st2.top()!='('){
				ves.push_back(st2.top()); st2.pop();
			}
			st2.pop();
		}
	}
	while(!st2.empty()){
		ves.push_back(st2.top()); st2.pop();
	}
	
	for(char cc:ves){
		if(cc=='2' || cc=='3'){
			nst.push(cc-'0');
		}
		else{
			int b = nst.top(); nst.pop();
			int a = nst.top(); nst.pop();
			if(cc=='+') nst.push(a+b);
			else nst.push(a*b);
		}
	}
	cout<<nst.top();
}

/*
2*(2+3*(3))+2*(3)

/ 2 2 3 3 * + * 2 3 * +

*/
/* n<m,
 n, -n
 n,  m
-n,  n
-m, -n

 

*/