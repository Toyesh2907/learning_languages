#include <iostream>
int main () {
    std::cout << 5;
    int x{5};
    std::cout << x;
    return 0;
}

/*
 * In the code block above the difference between the first and second cout statement is that
 * 5 is a literal(5's value does not change it remains constant) whereas
 * x's is a variable i.e its value can be changed later
 * So for the first statement 5 is directly printed where as x is fetched from memory and then its value is printed
 */

int main2(){
    std::cout << 1 + 2 << '\n';
    return 0;
}
/*
 * For the code block above '+' is the addition operator
 * Any operator in C/C++ gives a return value which is the result of that operation
 */

int main3(){
    int a = 5;
    a = -a;
    return 0;
}

/*
 * The code block above uses a UNARY operator that flips the sign the character making it negative
 * Unary operators only take one operand
 */


int main4(){
    int a = 5;
    int b = 6;
    std::cout << a + b;
    return 0;
}

/*
 * The code block above shows '+' which is a binary operator
 * Binary operator takes two operand
 * Binary operators are: +,-,*,/
 * The insertion (<<) and extraction (>>) operators are binary operators, taking std::cout or std::cin on the left side, 
 * and the value to output or variable to input to on the right side.
 * 
 * And there's ternary that takes 3 operands and nullary that takes 0 operands
 */


int main5(){
    int a = 5;
    std::cout << a + 5 - 6 * 2;
    return 0;
}

/*
 * Operators can be changed together and for the above arthematic operation the precedence is handled by BODMAS(PEMDAS is not real)
 */
