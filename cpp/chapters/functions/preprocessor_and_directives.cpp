/*
 * Before a C++ program is compiled it goes through a preprocessing step. The code logic is not changed
 * the changes are usually done in memory or in temp files.
 * So what does this preprocessor do?
 * It stripts out comments and ensures each file ends in a newline
 * It also processes the include directive i.e "#include <iostream>"
 * So the preprocessor replaces "#include <iostream>" with the contents of iostream
 */

#include <iostream>
#include <ostream>

#define IDENTIFIER
#define INDENTIFIER substituion_text

int main () {
    std::cout<<"sample";
    return 0;
}

/*
 * The code block above shows an example for macros
 * A macro is a rule that denines certain piece of texts are suppoed to be interpreted and replaced
 * There are two types of macros: object-like-macros, function-like-macros
 * It is generall a good practice to keep macros in all upercases
 */

#define MY_NAME "baazyman"

int main1 () {
    std::cout << "My name is :" << MY_NAME << std::endl;
    return 0;
}

/*
 * In the code block above MY_NAME is a macro so every time MY_NAME is used it is replaced by
 * "baazyman"
 */

#include <iostream>

#define PRINT_JOE

int main2 () {

    #ifdef PRINT_JOE
    std::cout << " JOE"; //prints JOE because PRINT_JOE has been defined
    #endif // PRINT_JOE
    
    #ifdef PRINT_BOB
    std::cout << "BOB"; //does not print BOB because ALEX has not been defineP
    #endif // PRINT_BOB

    #ifndef PRINT_ALEX
    std::cout << "ALEX"; //prints ALEX because ALEX has not been defined
    #endif // !PRINT_ALEX
    return 0;
}

/*
 * The code block above have macro called PRINT_JOE 
 * #ifdef directive checks whether an identifer has been previosly defined via #define
 * If so the code between the #ifdef and matching #endif is compiled. If not the code is ignored.
 *
 * #ifndef is the opposite of #ifdef it checks whether an identifer has been defined if not it executes the code
 * inside #ifndef and #endif
 */


#include <iostream>
int main3 () {
#if 0
std::cout << "what ever is kept in this code block";
#endif // 0
    return 0;
}

/*
 * Another way of checking whether a codeblock is supposed to compiled or not #if 0
 * sort of works as commenting and uncommenting a block of code so while testing
 * if something is needed/not needed repeatidly it the 1 and 0 can be changed in #if
 */

void foo(){
#define FOO 9
}

int main4 () {
    std::cout << "FOO: " << FOO;
    return 0;
}

/*
 * The codeblock even though looks like it won't compile
 * It does. Why :D?
 * Because preprocessor has does not understand concepts like functions and scope unlike compiler so the above codeblock compiles
 * So its a better to keep all define directives outside any functions and at a glboal level for better readability(does not make
 * a difference but a good practice)
 */


//let's say this is a file called something.cpp
#include <iostream>

void doSomething()
{
#ifdef PRINT
    std::cout << "Printing!\n";
#endif
#ifndef PRINT
    std::cout << "Not printing!\n";
#endif
}


//let's say this is a file called main.cpp
void doSomething(); // forward declaration for function doSomething()

#define PRINT

int main5()
{
    doSomething();

    return 0;
}
