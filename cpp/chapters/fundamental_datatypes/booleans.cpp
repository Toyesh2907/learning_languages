//Booleans are values that only have two values true or false

#include <immintrin.h>
#include <ios>
#include <iostream>
int main () {
    bool b1;
    bool b2;
    b1 = false;
    bool b3 {};
    std::cout << b1 << '\n';
    std::cout << b2 << '\n';
    std::cout << b3 << '\n';

    bool b4 {!false};
    bool b5 {!true};
    std::cout << b4 << '\n';
    std::cout << b5 << '\n';

    std::cout << std::boolalpha;
    bool b6 {false};
    std::cout << b6 << '\n';

    std::cout << std::noboolalpha;
    bool b7 {true};
    std::cout << b6 << '\n';

    return 0;
}

/*
 * In the code block above b1, b2, b3 are three booleans
 * For the code block above it prints
 *
 * 0
 * 27
 * 0
 * 1
 * 0
 * false
 * 0
 * 
 * since b1 is declared and initialized as false and false == 0 in C
 * b2 is not initialized and prints 26 which has the be value stored at the variables location(garbage)
 * b3 prints 0 because that declaration defaults to false initialization
 *
 * b4 get's initialized as true whereas b5 get's initialized as false so it prints
 * 1
 * 0
 *
 * If we want to print true or false instead of 1 and 0 for true and false respectively
 * use std::boolalpha
 *
 * Use std::noboolalpha to turn it back off.
 */

#include <iostream>
int main () {
    bool bFalse {0};
    bool bTrue {1};
    bool bNo {2};
    std::cout << bFalse << bTrue << bNo << '\n';
    
    return 0;
}

/*
 * The code block above prints the following
 * 011
 * You can type convert integers into booleans as shown above during initialization
 * however its preffered to use true and false for obvious reasons.
 * But in case of type conversions 0 is conveted to false and any other integer is converted to true
 * 
 * For other compilers you might get an error for bool bNo {2} since its a narrowing conversion
 */

#include <iostream>
int main () {
    bool b {};
    std::cout << "Enter a boolean value: ";
    std::cin >> b;
    std::cout << "You entered : " << b << '\n';

    return 0;
}

/*
 * The above code block bamboozles programmers but not me
 * becuase I am him
 * so you would enter something like true or false
 * so the terminal would look like
 * Enter a boolean value: true
 * You entered : 0
 *
 * This happens because we entered true and it got converted to 1
 *
 * Yeah I am indeed not him I didnt realize true in integers 1 not 0 so what's happening is given below -_-.
 *
 * This happens because std::cin accepts only numeric input for boolean variables: 0 is false 1 is true
 * any other numeric value will be treated as true and will cause std::cin to enter failure mode.Any
 * non-numeric value will interpreted as false
 *
 * So what to do?
 */

#include <iostream>
int main () {
    bool b { };
    std::cout << "Enter a boolean value: " << '\n';
    std::cin >> std::boolalpha;
    std::cin >> b;

    std::cout << std::boolalpha;
    std::cout << "You entered :" << b << '\n';

    return 0;
}

/*
 * For the code block above the input is case-sensitive
 * so if you enter true and false it prints true and false respectively
 * however if you try to enter True or False or TRUE or FALSE
 * it prints false which is the fallback I guess.
 *
 * And enabling std::boolalpha for std::cin won't accept 0 and 1 as inputs unless turned
 * off by std::noboolalpha
 */


