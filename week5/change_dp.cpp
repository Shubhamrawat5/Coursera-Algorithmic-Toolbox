#include <iostream>
#include<vector>
using namespace std;

//coins are 1,3,4 
int get_change(int m) {
  int i,j; 
  int c[3]={1,3,4};
  vector<int> v(m+1,250); //fill all index with 250 value
  v[0]=0;
  for(i=1;i<=m;++i)
  {
  	for(j=0;j<3;++j)
  	{
  		if(i-c[j]==0) //for 1,3,4 index
  		{
  			v[i] = 1;
  			break;
  		}
  		else if(i-c[j]<0) continue; //for negative
  		else if(v[i]>1+v[i-c[j]]) 
  		{
  			v[i]=1+v[i-c[j]];
  		}
  		
  	}
//  	for(auto k:v)
//	  cout<<k<<" ";
//  	cout<<"\n";
  }
  return(v[m]);
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
