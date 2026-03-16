/*
 * Pretty straight forward
* if,
* if else
* if else if else
 */

#include <iostream>
int main () {
    int x { 4 };
    if (x) // this is dumb but for an example
        std::cout << "hi\n";
    else
        std::cout << "byee\n";
    return 0;
}

/*
 * The above piece of code prints hi because 4 gets type converted to true
 * any integer that is not 0 is interpreted as false.
 */
