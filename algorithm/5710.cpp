#include<iostream>
#include<algorithm>
using namespace std;

int a,b,awh;

int get_price(int wh){
	if(wh<100){
		return wh*2;
	}
	else if(wh<10000){
		return 200+(wh-100)*3;
	}
	else if(wh<1000000){
		return 29900+(wh-10000)*5;
	}
	else{
		return 4979900+(wh-1000000)*7;
	}
}

int get_wh(int price){
	int wh=0;
	wh+=min(price,200)/2;
	price-=200;
	if(price>0){
		wh+=min(price,29700)/3;
		price-=29700;
		if(price>0){
			wh+=min(price,4950000)/5;
			price-=990000*5;
			if(price>0){
				wh+=price/7;
			}
		}
	}
	return wh;
}

int bsearch(int l, int r){
	int mid = (l+r)/2;
	int sg = get_price(mid);
	int neigh = get_price(awh-mid);
	
	if(neigh-sg==b){
		return sg;
	}
	if(l==r){
		return 0;
	}
	if(neigh-sg>b){
		return bsearch(mid+1,r);
	}
	else{
		return bsearch(l,mid-1);
	}
}

int main(){
	while(1){
		cin>>a>>b;
		if(a==b && a==0){
			return 0;
		}
		awh = get_wh(a);
		cout<<bsearch(0,awh)<<endl;
	}
}