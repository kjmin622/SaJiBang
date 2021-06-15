#include<iostream>
using namespace std;
#define A int
#define B -2147483648

int main(){
	A x = B;
	if(x!=0 && x==-x) cout<<true<<endl;
	else cout<<false<<endl;
}