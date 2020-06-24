#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
using std::vector;
using std::string;

//checks two digits concatenation max value
//like for 2 and 21 , 2'21 > 21'2 means 2 is greater than 21 here
//stoi converts string to int
bool IsGreaterOrEqual(string digit,string maxDigit)
{
	return(stoi(maxDigit+digit)<stoi(digit+maxDigit));
}

string largest_number(vector<string> a) {
  std::stringstream ret;
  
  while(!a.empty())
   {
    string max="0";
    int indexMax=-1;
    for(size_t j=0;j<a.size();++j)
    {
    	if(IsGreaterOrEqual((a[j]),max)){
    	indexMax=j;
    	max=a[j]; }
    }
    
    ret << max;
    a.erase(a.begin()+indexMax);
  }
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
 std::cin >> n;
  vector<string> a(n);
   for (size_t i = 0; i < a.size(); i++) {
   std::cin >> a[i];
 }
   std::cout << largest_number(a);
//cout<<IsGreaterOrEqual("989","98");
}
