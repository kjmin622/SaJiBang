#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

int map[50][50], dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}}, n, m, minn = 2e7; bool lab[50][50];
queue<pair<int,int> > bfs;
vector<int> ord;
vector<vector<int> > order;
vector<pair<int,int> > birus;

void combi(int N, int r){
	if(r==0){
		memset(lab,false,sizeof(lab));
		int anss=0;
		for(int i : ord){
			int x=birus[i].first,y=birus[i].second;
			bfs.push({x,y});
			lab[x][y]=true; 
		}
		
		while(!bfs.empty()){
			int si = bfs.size();
			while(si--){
				int fn=bfs.front().first, sn=bfs.front().second;
				bfs.pop();
				for(int i=0; i<4; i++){
					int nfn=fn+dir[i][0],nsn=sn+dir[i][1];
					if(nfn<0 || nsn<0 || nfn>=n || nsn>=n || lab[nfn][nsn] || map[nfn][nsn]==1) continue;
					lab[nfn][nsn]=true;
					bfs.push({nfn,nsn});
				}
			}
			if(!bfs.empty()) anss++;
		}
		bool flag = true;
		for(int i=0; i<n; i++){
			if(!flag) break;
			for(int j=0; j<n; j++){
				if(map[i][j]==1) continue;
				if(!lab[i][j]){
					flag=false;
					break;
				}
			}
		}
		if(flag){
			if(minn>anss) minn=anss;
		}
		return;
	}
	
	int last = ord.empty() ? -1 : ord.back();
	for(int i=last+1;i<N;i++){
		ord.push_back(i);
		combi(N,r-1);
		ord.pop_back();
	}
}
	
int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	cin>>n>>m;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>map[i][j];
			if(map[i][j]==2){
				map[i][j]=0;
				birus.push_back({i,j});
			}
		}
	}
	combi(birus.size(),m);
	
	if(minn==2e7) cout<<"-1\n";
	else cout<<minn<<'\n';
}