#include <iostream>
#include <vector>

using namespace std;

int optimal_weight(int W, const vector<int> &w)
{
	vector<vector<int>> v(w.size()+1,vector<int>(W+1,0)); //created 2D vector
    int i,j;
    
   for(i=1;i<=w.size();++i) //for available weights
    {
    	for(j=1;j<=W;++j) //for 0 to W weight
    	{
    		if(w[i-1]>j) v[i][j]=v[i-1][j]; //current weight is high than total weight so put previous value
    		else if(w[i-1]==j) v[i][j]=w[i-1]; //total weight & current weight is equal so directly put value
    		else //current weight is bigger than total weight so 2 possibilities, whether last was higher or using current weight will get more higher value
    		{
    			v[i][j]=max(v[i-1][j],w[i-1]+v[i-1][j-w[i-1]]);
    		}
    	}
    }
  /*  for(i=0;i<=w.size();++i)
    {
    	for(j=0;j<=W;++j)
    	cout<<v[i][j];
       cout<<endl;
    }*/
    return(v[w.size()][W]);
}

int main() {
  int n,W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
 	  std::cin >> w[i];  }

  std::cout << optimal_weight(W, w) << '\n';
}
