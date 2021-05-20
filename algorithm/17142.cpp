#include<iostream>
#include<queue>
#include<vector>
using namespace std;

//  21/5/20 시간초과의 늪에 빠짐

vector<vector<int> > ve;
void pick(int n, vector<int> &picked, int topick) {
    if(topick == 0) {
		vector<int> tmp;
        for (int i = 0; i < picked.size(); ++i) {
            tmp.push_back(picked[i]);
        }
        ve.push_back(tmp);
        return;
    }

    int smallest = picked.empty() ? 0 : picked.back() + 1;

    for (int j = smallest; j < n; ++j) {
        picked.push_back(j);
        pick(n, picked, topick-1);
        picked.pop_back();
    }
}

int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	int n,m, dic[4][2]={{1,0},{0,1},{-1,0},{0,-1}}, birus=0;
	cin>>n>>m;
	queue<pair<int,int> > bfs;
	vector<pair<int,int> > vbirus;
	int map[51][51]={}, tmp;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>tmp;
			if(tmp==2){
				vbirus.push_back({i,j});
				map[i][j]=1;
				birus++;
			}
			else if(tmp==1){
				map[i][j]=-1;
			}
		}
	}
	vector<int> tmpv;
	pick(birus,tmpv,m);
	
	int minn = 2e7;
	for(vector<int> li : ve){
		int mapt[51][51]={};
		for(pair<int,int> ll : vbirus){
			mapt[ll.first][ll.second] = 1;
		}
		for(int ll : li){
			int fn=vbirus[ll].first,sn=vbirus[ll].second;
			bfs.push({fn,sn});	
		}
		
		while(!bfs.empty()){
			int fn=bfs.front().first ,sn=bfs.front().second;
			bfs.pop();
			for(int i=0; i<4; i++){
				int nfn=fn+dic[i][0], nsn=sn+dic[i][1];
				if(nfn<0 || nsn<0 || nfn>=n || nsn>=n || map[nfn][nsn]==-1) continue;
				if(mapt[nfn][nsn]!=0 && mapt[nfn][nsn]<mapt[fn][sn]+1) continue;
				mapt[nfn][nsn]=mapt[fn][sn]+1;
				bfs.push({nfn,nsn});
			}
		}
		
		bool flager=false;
		int maxi=0;
		for(int i=0; i<n; i++){
			if(flager)break;
			for(int j=0; j<n; j++){
				if(map[i][j]!=-1 && mapt[i][j]==0){
					flager=true;break;
				}
				if(mapt[i][j]>maxi) {maxi=mapt[i][j];}
			}
		}
		if(flager) continue;
		if(maxi<minn) minn=maxi;
	}
	
	
	
	
	if(minn!=2e7) cout<<minn-1<<'\n';
	else cout<<-1<<'\n';
}