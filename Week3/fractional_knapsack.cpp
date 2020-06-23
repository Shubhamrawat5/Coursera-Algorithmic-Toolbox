#include <iostream>
#include <vector>
using std::vector;

//Getting index of max value
int maxIndex(const vector<double>& ppw)
{
	int max=0;
	for(int j=1;j<ppw.size();++j)
	{
	//	std::cout<<ppw[max]<<" "<<ppw[j]<<"\n";
		if(ppw[j]>ppw[max])
		max=j;
	}
	return max;
}

double get_optimal_value(int capacity, int n, vector<int> weights, vector<int> values) {
  double value = 0.0;
  vector<double> ppw(n);
  int i,max,lastMax=-1;
  for(i=0;i<n;++i) //calculating value per weight
  ppw[i]=(double)values[i]/weights[i];
    //for(i=0;i<n;++i)
  //std::cout<<ppw[i]<<" ";
 // std::cout<<"\n";
  while(capacity>0)
  {
  max=(maxIndex(ppw)); //getting index of highest value per weight
  if(max==lastMax)
  break;
  ppw[max]=0; //making that index of max value per weight to be 0 so that next time, same index will not come
  
  if(capacity>weights[max]) 
  {
  	value+=(double)values[max];
  	capacity-=weights[max];
  }
  else //for fractional part
  {
  	value+=((double)capacity/weights[max])*values[max];
  	break;
  }
  lastMax=max;
  }

 //std::cout<<"\n"<<value;
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
 for (int i = 0; i < n; i++) {
   std::cin >> values[i] >> weights[i];
 }

  double optimal_value = get_optimal_value(capacity,n, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
