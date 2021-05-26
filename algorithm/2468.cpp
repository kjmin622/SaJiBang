#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

int main(){
	int n,maxi=0,map[101][101],height[101]={}; cin>>n;
	int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
	bool visited[101][101]={};
	queue<pair<int,int> > bfs;
	vector<pair<int,int> > place[101];
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>map[i][j];
			height[map[i][j]]++;
			place[map[i][j]].push_back({i,j});
		}
	}
	for(int i=99; i>=1; i--){
		height[i]=height[i]+height[i+1];
		for(pair<int,int> p : place[i+1]){
			place[i].push_back(p);
		}
	}
	for(int i=1; i<=100; i++){
		if(height[i]==n*n) maxi = maxi<1 ? 1 : maxi;
		if(height[i]==0) break;
		
		memset(visited,false,sizeof(visited));
		int count=0, nmax=0, pi=0;
		while(count<height[i]){
			nmax++;
			while(visited[place[i][pi].first][place[i][pi].second]) pi++;
			bfs.push(place[i][pi]);
			visited[place[i][pi].first][place[i][pi].second]=true;
			count++;
			while(!bfs.empty()){
				int fn=bfs.front().first, sn=bfs.front().second;
				bfs.pop();
				for(int x=0; x<4; x++){
					int nfn=fn+dir[x][0], nsn=sn+dir[x][1];
					if(nfn<0 || nsn<0 || nfn>=n || nsn>=n || visited[nfn][nsn] || map[nfn][nsn]<i) continue;
					visited[nfn][nsn]=true;
					count++;
					bfs.push({nfn,nsn});
				}
			}
		}
		maxi = maxi<nmax ? nmax : maxi;
	}
	
	cout<<maxi<<endl;
}