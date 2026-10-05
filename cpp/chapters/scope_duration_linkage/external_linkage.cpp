/*
 * Identifiers that have external linkage are truly considered global i.e. they can be acccessed outside the file aswell. It allows the linker
 * to connect indentifer from one translation unit to another translation unit
 */

/*
 * Intially we learned that functions can be called from one file to another they have external linkage by default until explicitly static is mentioned.
 * In order to use a function in other files use a forward declaration of the function and call it from a header file. The forward declaration
 * tells the compiler about the existance of the function and the linker connects the function calls to the actual function definition.
 * A small recap example:
 */

//a.cpp
#include <iostream>

void say_hi(){
    std::cout << "HI" << '\n';
}

//main.cpp
void say_hi(); // forward declaration of the function makes say_hi accessible.
int main () {
    say_hi();  // call to the actual function in another file which is connected via linker.
    
    return 0;
}

/*
 * Global variables can be provided external linkage via "extern" keyword and are often reffered as external variables.
 */

int g_x { 2 };                      //non const variables are external by default(no need for extern)

extern const int g_y { 3 };         // const variable now has external linkage
extern constexpr int g_z { 3 };     // constexpr globals can be defined as extern, making them external(deemed useless according to uncle Alex)
int main () {
    std::cout << g_x << g_y << g_z << '\n';
    
    return 0;
}

/*
 * In order to actually use an external keyword you need to forward declare the keyword with extern, similar to what we do with a function
 */

#include <iostream>
extern int g_x;             // forward declaration of variable g_x defined somewhere else
extern const int g_y;       // forward declaration of constant g_y defined somewhere else

int main () {
    std::cout << g_x << g_y << '\n'; // prints 2 3
    
    return 0;
}

/*
 * Incase you are trying to define an uninitialized non const variable, do not use extern keyword, C++ will think you are trying to
 * make a forward declaration for the variable.
 *
 * Although constexpr variables can be given external linkage via the extern keyword, they can not be forward declared as constexpr. This is because the compiler
 * needs to know the value of the constexpr variable (at compile time). If that value is defined in some other file, the compiler has no visibility on what value 
 * was defined in that other file.
 * However, you can forward declare a constexpr variable as const, which the compiler will treat as a runtime const. This isn’t particularly useful.
 *
 * So according to uncle Alex:
 * Only use extern for global variable forward declaration or const global variable forward declaration.
 * Don't use extern for non-const global variables they are implicitly extern.
 */
