#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int n, maxi=0, already=0; cin>>n;
	vector<int> v(n+1), se, ans;
	vector<bool> visited(n+1);
	for(int i=1; i<=n; i++){
		cin>>v[i];
		if(i==v[i]){
			already++;
			se.push_back(i);
			ans.push_back(i);
			visited[i]=true;
		}
	}
	maxi+=already;
	/*
	1 2 3 4 5 6 7
	3 1 1 5 5 4 6
	*/
	for(int i=1; i<=n; i++){
		int counter = 0, idx=i;
		vector<int> tmp;
		vector<bool> vis(n+1);
		while(!visited[idx] && !vis[idx]){
			counter++;
			tmp.push_back(idx);
			vis[idx]=true;
			idx=v[idx];
			if(idx==i) break;
		}
		if(idx!=i) continue;
		
		maxi += counter;
		for(int j : tmp){
			visited[j]=true;
			ans.push_back(j);	
		}
		
	}
	sort(ans.begin(),ans.end());
	
	cout<<maxi<<'\n';
	for(int i=0; i<ans.size(); i++){
		cout<<ans[i]<<'\n';
	}
	
}

/*
1 2 3 4 5 6 7
2 6 5 4 3 2 7


*/