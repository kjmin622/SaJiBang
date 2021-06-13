#include<iostream>
using namespace std;

int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	long long int n, t, dp[65][10], ans[65]={0,10,55};
	
	for(int i=0; i<10; i++){
		dp[1][i]=1;
		dp[2][i]=10-i;
	}
	
	for(int i=3; i<=64; i++){
		dp[i][0] = ans[i-1];
		ans[i]+=dp[i][0];
		for(int j=1; j<10; j++){
			dp[i][j] = dp[i][j-1]-dp[i-1][j-1];
			ans[i]+=dp[i][j];
		}
	}
	cin>>t;
	while(t--){
		cin>>n; cout<<ans[n]<<'\n';
	}
}