#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    
    stops.push_back(dist); //adding destination to our vector in the end
     int count=0,cp=0,ct=tank,i=1; //cp is current position & ct is current tank fuel, i to iterate through vector
    if(stops[0]<=ct) //checking for 1st stop
    {
    	ct=ct-stops[0];
    	cp=stops[0];
    }
    else return -1;
 
    while(cp<dist) //checking for remaining stops
    {
    	if(stops[i]-stops[i-1]<=ct) //if next stop is within current fuel range
    	{
    		cp=stops[i];
    		ct=ct-(stops[i]-stops[i-1]);
    		++i;
    	}
    	else //if we dont have enough fuel 
    	{
    		++count;
    		ct=tank;
    		if(ct<stops[i]-stops[i-1])
    		return -1;
    	}
    
}
return count;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (int i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
