#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using namespace std;

vector<int> dp(int n)
{
	vector<int> seq(n+1,1000);
	int i;
	seq[0]=0;
 	seq[1]=0;
	for(i=2;i<=n;++i) //making table 
	{
		for(int j=2;j<=3;++j) //for *2 and *3
		{
			if(i%j==0 && seq[i]>1+seq[i/j])	{
				seq[i]=1+seq[i/j];	}
    	}
    	if(seq[i]>seq[i-1]) //for +1
    	   seq[i]=1+seq[i-1];
	}
	
	int min,value;
	vector<int> ans;
	ans.push_back(n);
	
	for(i=n;i>=2;i=value) //now getting the values by help of table
	{
		min=1000;
		for(int j=2;j<=3;++j)
		{
			if(i%j==0 && min>seq[i/j]) 
			{
				min=seq[i/j];
				value=i/j;
     		}
   		if(min>seq[i-1]) 
    		{
 			min=seq[i-1];
 			value=i-1;
     		}
		}
		ans.push_back(value);
	}
	reverse(ans.begin(),ans.end()); //reverse the vector
	 return ans;
}

/* greedy approach already given function:-
vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}*/

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence=dp(n);
 //vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
     std::cout << sequence[i] << " "; }
}
