#include <iostream>
#include <cassert>

//recursive algo (slower in fibonacci case)
int fibonacci_naive(int n) {
    if (n <= 1)
        return n;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

//faster simple func
int fibonacci_fast(int n) {
    int a=0,f;
    if(n==0) return(0);
    int b=1;
    if(n==1) return(1);
    for(int i=2;i<=n;++i){
    	f=a+b;
    	a=b;
    	b=f;
    }
    return(f);
}

//test both the algo
void test_solution() {
    assert(fibonacci_fast(3) == 2);
    assert(fibonacci_fast(10) == 55);
    for (int n = 0; n < 20; ++n)
        assert(fibonacci_fast(n) == fibonacci_naive(n));
}

int main() {
    int n = 0;
    std::cin >> n;
    //std::cout << fibonacci_naive(n) << '\n';
    //test_solution();
    std::cout << fibonacci_fast(n) << '\n';
    return 0;
}
