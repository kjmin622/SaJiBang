#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

typedef long long int lli;

int n;
string s;
vector<int> comt;
vector<vector<int> > com;

void combi(int c){
	vector<int> tmp; bool flag = true;
	for(int i : comt){
		if(!tmp.empty() && i-tmp.back()==2){
			return; 
			flag=false;
		}
		tmp.push_back(i);
	}
	if(flag){
		com.push_back(tmp);
	}
	
	for(int i=c; i<n; i+=2){
		comt.push_back(i);
		combi(i+2);
		comt.pop_back();
	}
} 

int main(){
	cin>>n>>s;
	combi(1);
	lli maxi = -2e31;
	
	for(vector<int> comb : com){
		queue<lli> num;
		queue<char> calq;
		int idx = 0;
		bool flag = false;	
		for(int i=1; i<n; i+=2){
			if(!comb.empty() && !(comb.size()<=idx) && comb[idx]==i){
				char cal = s[i];
				if(cal == '+') num.push((s[i-1]-'0')+(s[i+1]-'0'));
				if(cal == '-') num.push((s[i-1]-'0')-(s[i+1]-'0'));
				if(cal == '*') num.push((s[i-1]-'0')*(s[i+1]-'0'));
				idx++;
				flag = true;
			}
			else{
				if(!flag) num.push(s[i-1]-'0');
				calq.push(s[i]);
				flag = false;
				
			}
		}
		if(!flag) num.push(s[n-1]-'0');
		
		idx = 0;
		int x = num.front(); num.pop(); 
		while(!calq.empty()){
			char ca = calq.front(); calq.pop();
			int y = num.front(); num.pop();
			if(ca == '+') x+=y;
			if(ca == '-') x-=y;
			if(ca == '*') x*=y;
		}
		maxi = maxi<x ? x : maxi;
	}
	cout<<maxi<<endl;
}