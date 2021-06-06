#include<iostream>
using namespace std;

int w,h,p,q,t,xd,yd;

int main(){
	cin>>w>>h>>p>>q>>t;
	xd=t%(2*w);
	yd=t%(2*h);
	
	p+=xd;
	q+=yd;
	
	if(p>w) p=2*w-p;
	if(q>h) q=2*h-q;
	if(q<0) q=-q;
	if(p<0) p=-p;
	
	cout<<p<<' '<<q<<endl;
}
