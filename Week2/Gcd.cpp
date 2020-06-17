#include<iostream>
using namespace std;

//By euclid method
int GCD(int a,int b)
{
	int c;
	//cout<<a<<" "<<b<<endl;
	if(b%a==0) return a;
	else c=GCD(b%a,a);
	return(c);
}

int main()
{
	int a,b;
	cin>>a>>b;
	int ans=GCD(a,b);
	cout<<ans;
	
}
