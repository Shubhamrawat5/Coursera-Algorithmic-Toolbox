//3 Partition Quick Sort
#include <iostream>

using namespace std; 

void swap(int *x,int *y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
}

//taking 1st element as pivot then moving smaller value to left side of m1 and greater value to right side of m2 and equal element btw m1 & m2

/*Logic:-
Taking first element as pivot..
throwing greater than pivot value to the end..
small than pivot value to the left side of m1..
*/
int Partition(int a[],int l,int r,int &m1,int &m2)
{
	int pivot=a[l];
	m1=l,m2=l+1;
	while(m2<=r)
	{

		if(pivot==a[m2]){
		++m2;
			}
		
		else if(pivot>a[m2]) {
			swap(&a[m1],&a[m2]);
			++m1;
		}
		
		else{
			swap(&a[m2],&a[r]);
			--r;
		}
		
	}
--m2;
}

//here passing m1,m2 through reference
int quicksort(int a[],int l,int r)
{
	if(l<r){
		int m1,m2;
	Partition(a,l,r,m1,m2);
	quicksort(a,l,m1-1);
	quicksort(a,m2+1,r); 
	}
	return 0;
}

int main() {
  int n;
  std::cin >> n;
  int a[n];
  for (size_t i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  quicksort(a, 0, n - 1);
  for (size_t i = 0; i < n; ++i) {
    std::cout << a[i] << ' ';
  }
}
