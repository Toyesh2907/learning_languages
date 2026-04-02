// comma operator i.e ',' let's you evaluate multiple expressions where a single expression is allowed.

#include <iostream>
int main () {
    int x { 1 };
    int y { 2 };
    std::cout << (++x, ++y) << '\n';
    
    return 0;
}

/*
 * The code block above:
 * First the left operand is evaluated i.e ++x which increaments the value
 * of x -> 2 and then the right operand is evaluated which increaments the value
 * of y -> 3 the comma operator returns the value of the right operand in this case
 * it would be 3 so the cout expression prints 3
 */

/*
 * Given that , operator has the lowest precendance even lower than assignment operator
 * so take a look at an example below
 *
 * z = (a, b);
 * z = a, b;
 * for above the first expression evaluates (a, b) first to get the result b, and assigns the value b to z
 * for second expression since precendance of , < = it is evaluated as (z = a), b; so z get's assigned the
 * value a and b get's evaluaed and discarded
 */

/*
 * Major takeaway from this and according to uncle Alex avoid using comma operator unless you are using it
 * in loops
 */

