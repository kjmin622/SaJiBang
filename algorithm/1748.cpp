#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int n,tmp,d=9,de=1,len=0; cin>>n;
	tmp = n;
	if(n<10){cout<<n<<endl;return 0;}
	
	while(tmp>9){
		len+=d*de;
		d*=10;
		de++;
		tmp/=10;
	}
	
	d+=pow(10,de-1)-1;
	d/=10;
	len+=(n-d)*de;
	cout<<len<<endl;
}