#include<iostream>
using namespace std;
typedef long long int lli;
int main(){
	int n; cin>>n;
	lli dp[100][10][6]={};
	for(int i=0; i<10; i++){
		dp[1][i][3]=1;
		dp[2][i][4]=i;
		dp[2][i][2]=9-i;
	}
	for(int i=3; i<=100; i++){
		for(int j=0; j<10; j++){
			for(int k=2; k<=4; k++){
				dp[i][j][k-1];
				dp[i][j][k+1];
			}
		}
	}
}