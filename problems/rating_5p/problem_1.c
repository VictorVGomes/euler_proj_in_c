#include <stdio.h>


// Although there may be no benefit
// (actually, it might be prejudicial)
// to use pointers in these functions
// (passing by reference instead of by value)
// I will keep it like this simply to show
// that pointers can be used in such a problem.
// This solution should be O(1), since it avoids
// the use of loops and such.


int sum_linearf(int value, int *n){
    // This function sums all integer values up to
    // a value n in a function of the form
    // f(x) = value * x, where `value` is a constant
    // e.g.: n=3, value=2, => 2*1 + 2*2 + 2*3
    // we use Gauss' sum to make this O(1):
    // S_n = (a_1 + a_n) * n / 2
    int a_n = value * (*n);
    int out = (value + a_n) * (*n) / 2;
    return out;
}


void get_summation(int *n){
    // the function will be purposefully verbose
    // i will count appearances of multiples of 3
    // n-1 is used to avoid counting the n-th term
    int i = ((*n) - 1) / 3;
    // j will count appearances of multiples of 5
    int j = ((*n) - 1) / 5;
    // k  will count appearances of multiples of 15
    //  (3*5) (these will be subtracted from the final answer)
    int k = ((*n) - 1) / 15;
    // get sums of 3, 5, 15
    int sum3 = sum_linearf(3, &i);
    int sum5 = sum_linearf(5, &j);
    int sum15 = sum_linearf(15, &k);
    int result = sum3 + sum5 - sum15;
    printf("The sum of multiples of 3 and 5 up to %d is %d\n", (*n), result);
}


void main(){
    // gets the cumulative sum up to 1000, included.
    // The answer to Project Euler's problem #1
    // will be the last output of this loop.
    for(int i = 10; i <= 1000; i++){
        get_summation(&i);
    };
}
