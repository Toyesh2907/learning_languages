/*
 * A function is a piece of code that can be reused via a function call
 * During a function call the compiler stops the current execution and starts execution of that function(in case of a sync function)
 *
 * returnType func_name(**kwargs){
 * returnType foo = some_calc;
 * return foo;
 *     }
 *
 * In above is a definition of a function
 * in C/C++ you have to define the return type of the function; it can not return something other than its return type
 * **kwargs are function parameters i.e values fed to the function in standard C++ boilerplate
 * int main (int argc, char *argv[]) {
        
        return 0;
    }
 * main is the function name is main, int is return type and it returns 0
 *
 * Why do we need functions so that we follow DRY(DO NOT REPEAT YOURSELF) a practice that tells programmers if a piece of code is
 * getting repeated its better to create a function(imo depeneding on how many time its repeated and how big of a code block is repeated
 * should call for making a function for it) so this function is called anytime you need that piece of code
 */

#include <iostream>
void print_fuckwit(std::string name){
    std::cout << name << "is a fuckwit" ;
}

int main(){
    print_fuckwit("Bill Gates"); //Intended!!
    return 0;
}

/*
 * In the code block function fuckwit takes in std::string in function param and retruns nothing and prints name followed by "is a fuckwit"
 * My sense of humour is questinable I know, anyways.
 * Below is an example of a codeblock of a function that takes a name a returns a std::string foo
 */

std::string return_fuckwit(std::string name){
    std::string foo = name + "is a fuckwit";
    return foo;
}

int main1(){
    std::string foo_bar = return_fuckwit("Bill Gates again!");
    return 0;
}

/*
 * You guessed it right functions can call other functions aswell
 * If you had print_fuckwit called inside return_fuckwit it would print name + "is a fuckwit" return the std::string
 */


int main2()
{
    void foo() // Illegal: this function is nested inside function main()
    {
        std::cout << "foo!\n";
    }

    foo(); // function call to foo()

    return 0;
}

/*
 * The above code block is not legal C/C++ does not allow you to have nested functions
 * A blessing is disguise preventing people from writing horrible code
 *
 * in C++ we usually return 0 in the main function because 0 indicates that function your program ran and exited withough any errors
 * in C++ you can also use exit statuses for better readability since return 0 looks like a magic number and its hard to tell at an initial
 * glance what 0 entails
 * Below is an example
 */

#include <cstdlib> // for EXIT_SUCCESS and EXIT_FAILUR
int main3(){
    return EXIT_SUCCESS;
}

int foo_bar1(int a){
    int b = a;
    //return nothing
}

int main4(){
    foo_bar1(5);
    return EXIT_SUCCESS;
}

/*
 * The code block has UB since the function is supposed to return int and returns nothing
 * and the behaviour depends on the compiler that is being used to compile the code above
 */
