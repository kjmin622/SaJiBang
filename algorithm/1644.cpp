#include<iostream>
#include<vector>
using namespace std;

vector<int> sosu;
bool visit[4000001]={true,true};
int n, now=2, ans, l, r;

void save_sosu(){
	for(int i=2; i<=n; i++){
		if(!visit[i]){
			sosu.push_back(i);
			for(int j=i+i; j<=n; j+=i){
				visit[j]=true;
			}
		}
	}
}

int main(){
	cin>>n;
	save_sosu();
	if(n==1){
		cout<<0<<endl;
	}
	else if(n==2){
		cout<<1<<endl;
	}
	else{
		while(sosu[l]<=n){
			if(now>=n){
				now-=sosu[l++];
			}
			else{
				if(r+1>=sosu.size()) break;
				now+=sosu[++r];
			}
			if(now==n) ans++;
		}
		cout<<ans<<endl;
	}
	
}