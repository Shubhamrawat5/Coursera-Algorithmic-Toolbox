#include <iostream>

int get_change(int m) {
  int n=0;
  while(m>0)
  {
  	if(m>=10) //firstly checking for 10 coin
  	{
  	++n;
  	m=m-10;
  	continue; }
  	else if(m>=5) //now for 5 coin
  	{
  	++n;
  	m=m-5;
  	continue; }
  	else //now remaining for 1 coin
  	{
  		n=n+m;
  		break;	
  	
  }
  }
  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
