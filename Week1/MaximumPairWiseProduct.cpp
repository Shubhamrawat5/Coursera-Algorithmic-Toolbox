//max multiply of 2 numbers of an array
#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

//brute force approach
long long maxmul(const vector<int>& v,int n)
{
	int i,j;
	long long highestmul=0;
	for(i=0;i<n-1;++i){
		for(j=i+1;j<n;++j){
			if(highestmul<(long long)v[i]*v[j])
			highestmul=(long long)v[i]*v[j];
		}		
	}
	return(highestmul);
}

//better faster algo: finding top two highest values
long long maxmulfaster(const vector<int>& v,int n)
{
	int max1=-1; //max1,max2 are top index of highest value numbers
	int i;
	for(i=0;i<n;i++){
		if(max1==-1 || v[max1]<v[i]) max1=i;
	}
	int max2=-1;
	for(i=0;i<n;i++){
		if(i!=max1 && (max2==-1 || v[max2]<v[i])) max2=i;
    }
 	//cout<<max1<<" "<<max2<<"\n";
     return((long long)v[max1]*v[max2]);
}


int main()
{
/*	int i, test=0;
	//40 stress test -------
	while(test<40){
		int n=rand()%4 + 2;
		cout<<n<<"\n";
		vector<int> v(n);
		for(i=0;i<n;i++){
			v[i]=rand()%8+1;
		}
		for(i=0;i<n;i++)
		cout<<v[i]<<" ";
		cout<<"\n";
		int a1=maxmul(v,n);
		int a2=maxmulfaster(v,n);
		if(a1!=a2){
		cout<<"Test failed:"<<a1<<" "<<a2<<"\n";
		break; }
		cout<<"Sucess! \n";
		test++;
	}*/
	
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;++i)
	{
		cin>>v[i];
	}
	cout<<maxmulfaster(v,n);
}
