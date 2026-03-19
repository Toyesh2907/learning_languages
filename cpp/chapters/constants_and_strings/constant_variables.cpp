/*
 * So what is a constant?
 * A value that can not be changed during execution of a program
 */

int main () {
    const double gravity { 9.8 };
    int const side_in_square { 4 };
    return 0;
}

/*
 * Above code block shows two ways of declaring a constant even though both are valid syntax
 * I would consider it a declaration of war if I see somebody declare a const like
 * const_type const const_name { const_value };
 *
 * A const must be initialized with a value otherwise it will throw an error
 * const double gravity {};
 * gravity = 9.8;
 * above syntax is invalid
 *
 * The naming conventions followed for naming a const is usually all uppercase
 * because in a code base if you see something like EARTH_GRAVITY you most likely know
 * its a constant
 */ 

#include <iostream>

void foo(){
#define gravity 9.8;
}

void print_gravity(double gravity){
    std::cout << gravity << '\n';
}

int main () {
    print_gravity(9.8);
    return 0;
}

/*
 * For the code block everything in the file above will be replaced by 9.8 incase gravity is encountered
 * so foo becomes void print_gravity(9.8)
 * So it is usually better to preffer constants over #define directive
 *
 * Something Extra:
 * volatile qualifier is used to tell compiler that an object may have its value changed at any time.
 */

