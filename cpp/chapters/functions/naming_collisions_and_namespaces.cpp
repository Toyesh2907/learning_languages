//Lets say we have two .cpp files


//a.cpp
#include <iostream>
void foo(){
    std::cout<<"foo left";
}


//main.cpp
#include <iostream>
void foo(){
    std::cout<<"foo entered";
}

int main () {
    foo();
    return 0;
}

/*
 * Now we have two .cpp files a.cpp and main.cpp; when the compiler compiles it's goint to throw an error
 * an ambigiouty(I know I butchered that) error because foo has been declared twice and the compiler can't
 * differenciate between these two.
 * Compiler will compile both individually however issue arises when the linker comes into play.
 *
 * So ho do we soleve this? We use namespaces
 * Namespaces provide scope to a function, class, variable so that they are defined inside that namespace without
 * any conflicts.
 */

/*
 * In C++, any name that is not defined inside a class, function, or a namespace is considered to be part of an implicitly-defined 
 * namespace called the global namespace (sometimes also called the global scope).
 * In the example at the top of the lesson, functions main() and both versions of myFcn() are defined inside the global namespace. 
 * The naming collision encountered in the example happens because both versions of myFcn() end up inside the global namespace, 
 * which violates the rule that all names in the scope region must be unique.
 */


