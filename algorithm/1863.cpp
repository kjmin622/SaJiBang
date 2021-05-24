#include<iostream>
#include<stack>
using namespace std;

int main(){
	int n,x,y,count=0; cin>>n;
	stack<int> skyline;
	
	for(int i=0; i<n; i++){
		cin>>x>>y;
		if(skyline.empty()){
			if(y) skyline.push(y);
		}
		else{
			if(y>skyline.top()){
				skyline.push(y);
			}
			else{
				while(!skyline.empty() && y<skyline.top()){
					skyline.pop(); count++;
				}
				if(y && (skyline.empty() || y>skyline.top())){
					skyline.push(y);
				}
			}
		}
	}
	while(!skyline.empty()){
		skyline.pop(); count++;
	}
	
	cout<<count<<endl;
}
// 
// 6
/*
..........................
.....XX.........XXX.......
.XXX.XX.......XXXXXXX.....
XXXXXXXXXX....XXXXXXXXXXXX

1 
*/