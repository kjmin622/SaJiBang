#include<iostream>
using namespace std;

int main(){
	int n,k,output=0; long long int arr[201][201]={};
	cin>>n>>k;
	for(int i=1; i<=200; i++){
		arr[i][1]=i;
		arr[1][i]=1;
	}
	for(int j=2; j<=n; j++){
		for(int i=2; i<=k; i++){
			arr[i][j]=(arr[i][j-1]+arr[i-1][j])%1000000000;
			// cout<<arr[i][j]<<' ';
			
		}
	}
	cout<<arr[k][n]<<endl;
}
/* 
   1  2  3  4  5  6  7  8
1  1  1  1  1  1  1  1  1
2  2  3  4  5  6  7  8  9
3  3  6  9 12 15 18 21 24
4  4 10 16
5  5 15
6  6
7  7
8  8

0
1
3
6
10
*/
