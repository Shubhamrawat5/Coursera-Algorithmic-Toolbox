#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using namespace std;

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  sort(a.begin(),a.end()); //sorting the vector
  int ele=a[(right+left)/2]; //getting mid element
  int count=0;
  for(int i=0;i<a.size();++i) //checking till out count becomes greater than half the size of vector
  {
  	if(a[i]==ele)
  	++count;
  	if(count>a.size()/2)
  	return 1;  	
  }
  
  return -1;
}

int main() {
  int n;
   std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
   std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size())!=-1) << '\n';
}
