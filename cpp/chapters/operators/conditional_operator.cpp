/* ? is know as the conditional operator
 * c ? x:y
 * if c is true evaluate x else evaluate y
 */

#include <iostream>
int main () {
    int x { 2 };
    int y { 8 };

    int max {};
    if (x > y)
        max = x;
    else
        max = y;
    return 0;
}

/*
 * Take a look at the piece of code above seems a bit lengthy in order to find the max between x and y
 * it can be done with conditional operator aswell take a look below
 */


#include <iostream>
int main () {
    int x { 2 };
    int y { 8 };

    int max = ((x > y) ? x : y);
    return 0;
}

#include <iostream>
int main () {
    constexpr bool in_big_classroom { false };
    constexpr int class_size { in_big_classroom ? 30 : 20};
    std::cout << "The class size is: " << class_size << '\n';

    return 0;
}

/*
 * since ? operator is evaluated as a part of an expression, it can be used anywhere an expression is accepted
 */
