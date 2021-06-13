#include<iostream>
using namespace std;

int main(){
	int n, l=1, r=1, now=1, ans=0; 
	cin>>n;
	if(n==1){
		cout<<1; return 0;
	}
	while(1){
		if(now<=n){
			r++; now+=r;
		}
		else{
			now-=l; l++;
		}
		if(now==n){
			ans++;
			if(l==n) break;
		}
	}
	cout<<ans<<endl;
}