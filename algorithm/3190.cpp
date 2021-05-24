#include<iostream>
#include<queue>
#include<deque>
using namespace std;


int fn,sn,n,k,l,x,y,map[101][101],darr[4][2]={{-1,0},{0,1},{1,0},{0,-1}},times=0,d=1; // 0 up-right-down-left 3
char c;
deque<pair<int,int> > snake;
queue<pair<int,char> > dir;

int startGame(){
	snake.push_front({1,1});
	map[1][1]=1;
	while(1){
		// cout<<endl<<times<<endl;
		// for(int i=0; i<n; i++){
		// 	for(int j=0; j<n; j++){
		// 		cout<<map[i][j];
		// 	}cout<<endl;
		// }
		// cout<<endl;
		
		if(!dir.empty() && dir.front().first == times){
			if(dir.front().second == 'L') d--;
			else d++;
			if(d==-1) d=3;
			if(d==4) d=0;
			dir.pop();
		}
		fn = snake.front().first+darr[d][0]; sn = snake.front().second+darr[d][1];
		if(fn<=0 || sn<=0 || fn>n || sn>n || map[fn][sn]==1) return times+1;
		snake.push_front({fn,sn});
		if(map[fn][sn]==0){
			map[snake.back().first][snake.back().second]=0;
			snake.pop_back();
		}
		map[fn][sn]=1;
		times++;
	}
}

int main(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	cin>>n>>k;
	for(int i=0; i<k; i++){
		cin>>x>>y;
		map[x][y]=2;
	}
	cin>>l;
	for(int i=0; i<l; i++){
		cin>>x>>c;
		dir.push({x,c});
	}
	cout<<startGame()<<endl;
}

/*
10
5
1 5
1 3
1 2
1 6
1 7
4
8 D
10 D
11 D
13 L
*/