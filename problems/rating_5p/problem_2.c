#include <stdio.h>


int fib(int n){
    // implements Fibonacci seq. using
    // recursion and some tricks
    // w/o memoization. should be O(mlogn)
    // to compute a single fib number.
    // "k" will be the middle of the interval,
    // ensuring it is halving the remaining
    // space.
    int k = n / 2;
    if(n < 2){ // recursion stopping criteria
        return 1;
    }
    int fibn = fib(k) * fib(n - k) + fib(k - 1) * fib(n - k - 1);
    return fibn;
}


int get_sum(int max){
    int s = 0;
    int iter = 2;
    int i = 0;
    int f = fib(iter);
    while(f <= max){
        printf("Fib. #%d = %d\n", iter, f);
        s += f;
        i++;
        iter = 3 * i + 2;
        f = fib(iter);
    }
    return s;
}


void main(){
    int MAX = 4000000;
    int s = get_sum(MAX);
    printf("Sum of even fib. <= %d = %d\n", MAX, s);
}
