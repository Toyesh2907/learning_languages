/*
 * This is a poor mans implementation of how multi file programs are supposed to work
 * start of every code block the comment indicates "supposed" filename it would have been kept in
 *
 * So why is there a need to do this?
 * If you have to sit back and ask that question, your program file contains over 5000 lines of code.
 * Get to refactoring!
 */

#include <iostream>
int add(int a, int b){
    return a + b;
}

int main () {
    std::cout << "addition of 1, 2 is: " << add(1, 2);
    return 0;
}

/*
 * Looking at the codeblocks above lets say you have two files
 * File 1 called add.cpp contains the function add
 * File 2 contains the main function that calls add function from file 2
 * Above behaviour is UB depending how the compiler compiles
 * If File 1 i.e app.cpp gets compiled first you don't get an error
 * Else you will get an error
 * The reason for the second is because once it reaches the line where it wants the func add;
 * it does not exist for the compiler
 *
 * So how to handle this? This can be handled by forward declaration
 */
int add1 (int a, int b);

int main1 () {
    std::cout << "addition of 1, 2 is: " << add1(1, 2);
    return 0;
}

/*
 * Now when the compiler compiles it knows that func add1 exists and won't throw an error
 */
