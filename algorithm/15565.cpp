#include<iostream>
using namespace std;

int main(){
	int n,k,arr[1000001],l=0,r=0,now=0,ans=2e8;
	cin>>n>>k;
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	now=(arr[0]==1?1:0);
	if(now==k) ans++;
	
	while(1){
		if(now<k){
			r++; now+=(arr[r]==1?1:0);
		}
		else{
			now-=(arr[l]==1?1:0); l++;
		}
		if(!(l<=n && r<=n)) break;
		if(now>=k) ans = r-l+1<ans?r-l+1:ans;
	}
	cout<<(ans==2e8?-1:ans)<<endl;
}