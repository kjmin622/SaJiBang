#include<iostream>
#include<cstring>
using namespace std;

int main(){
	string s; cin>>s;
	int count = 1;
	for(int i=0; i<s.size(); i++) if(s[i]==',') count++;
	cout<<count<<endl;
}