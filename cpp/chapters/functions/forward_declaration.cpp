#include <iostream>

int main () {
    std::cout << foo(5 , 4);
    return 0;
}

int foo(int a, int b){
    return a + b;
}

/*
 * The code block above will throw an error because a C++ program is compiled top to bottom
 * so when main tries to call foo it has not encountered the function yet so it throws an error
 * Something like this would work in Python
 * Love the way C++ is unapologetic about a programmers incompetence :D
 * So can you have functions defined below? Yes.
 * Forward declaration happens when we define a function before defining what it is suppose to do
 * Below is an example for that
 */

int foo1(int a, int b);

int main1 () {
    std::cout << foo1(5 , 4);
    return 0;
}

int foo1(int a, int b){
    return a + b;
}
