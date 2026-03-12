/*
 * An integer is an integral type that can represent +ve and -ve whole numbers, including 0 eg. (-2, -1, 0, 1, 2)
 * C++ has 4 primary fundamental integer types available for use;
 * Type             Minimum size
 *
 * short int        16 bits
 * int              16 bits
 * long int         32 bits
 * long long int    64 bits
 *
 * By default integers in C++ are singed i.e short s, int i, long l, long long ll; are defaulted to signed integers
 * You can do singed short s, singed int i, singed long l, singed long long ll; but its essentially the same as above
 */

#include <iostream>
int main () {
    int x {2147483647}; //maximum value of a 4-byte integer signed integer
    std::cout << "value of x at initialization : " << x << '\n';
    x = x + 1;
    std::cout << "value of x after x + 1 : " << x << '\n';
    return 0;
}

/*
 * In the above example the output was 
 * 2147483647
 *-2147483648
 * Now the output depends on your machine/compiler. WHY?
 * Because in C++20 standard if during an evaluation of an expression, the result is not mathematically defined or not
 * in range of representable values for its type, the behaviour is undefined. This is better know as an overflow.
 * In the case listed above in the code block that is an arithematic overflow. When you assign a number greater than what a singed integer can hold its called
 * integer overflow. In each case the behaviour is undefined
 */


