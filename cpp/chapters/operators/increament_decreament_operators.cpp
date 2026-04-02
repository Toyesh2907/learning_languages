/*
 * Use of these operators is pretty much no surprise to me
 * however uncle alex has suggested to mostly use ++x over x++ as ++x is more performant and
 * has less surprises
 *
 * Take a look at peice of code below
 */

#include <iostream>

int add(int x, int y){
    return x + y;
}

int main () {
    int x { 5 };
    int value { add(x, ++x) };
    std::cout << value << '\n';
    return 0;
}

/*
 * The code block above has UB it depends on how the expression is evaluated
 * It can either print 11 or 12 because the statement int value { add(x, ++x) }; can either evalute
 * with func being fed (5,6) or (6,6) depending on how the compiler evalutes it.
 *
 * So C++ standard does not define the behaviour for above so be careful when dealing with such cases (*￣m￣).
 */
