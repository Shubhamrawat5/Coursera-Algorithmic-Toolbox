#include <iostream>
#include <vector>

using namespace std;

int lcs2(vector<int> &a, vector<int> &b) {
  
	int n=a.size();
	int m=b.size();
	int c[n+1][m+1];
	int i,j;
	
	for(i=0;i<n+1;++i)
	{
		for(j=0;j<m+1;++j)
		{
			if(i==0 || j==0)
			c[i][j]=0;
			
			else if(a[i-1]==b[j-1])
			c[i][j] = 1+c[i-1][j-1];
			
			else
			c[i][j]=max(c[i-1][j],c[i][j-1]);
		}
	}
/*for(i=0;i<s1+1;++i)
{
	for(j=0;j<s2+1;++j)
	cout<<a[i][j]<<" ";
	cout<<endl;
*/
     return(c[n][m]);
     }

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
