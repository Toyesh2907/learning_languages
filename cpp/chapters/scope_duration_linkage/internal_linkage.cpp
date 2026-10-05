/*
 * Global variables and functions can have either internal or external linkage.
 *
 * An identifier with internal linkage can be seen and used in a single translational unit, but it is not accessible from other
 * translational units. This means that if there are two source files that have identically named identifiers with internal linkage, those
 * identifiers will be treated as independent and do not result in ODR vialoation.
 */

#include <iostream>

static int g_x{};           // non-constant globals have external linkage by default, but can be given internal
                            // linkage via static keyword

const int g_y{ 1 };         // const globals have internal linkage by default
constexpr int g_z{ 2 };     // constexpr globals have internal linkage by default

int main () {
    std::cout << g_x << g_y << g_z << '\n';
     
    return 0;
}

/*
 * So what all the shit above means is that vairable g_x is global variable that is local to the file which it is used in. It happens due to static keyword
 * otherwise if static is not used other files can access that aswell.
 */

[[maybe_unused]] constexpr int g_x { 2 }; //let's say this declaration is in a file called a.cpp

//main.cpp
#include <iostream>

static int g_x { 3 };

int main () {
    std::cout << g_x << '\n';
    
    return 0;
}

/*
 * the code block above will print:
 * 3
 * because g_x is internal to each file, main.cpp has no idea that a.cpp also has a variable called g_x and vice versa.
 */

/*
 * The use of static keyword above is an example of storage class specifier, which sets both the name's linkage and it's storage duration.
 * The most used storage class specifiers are static, extern and mutable.
 */

/*
 * The C++ standard provides rationale as to why const variables have internal linkage by default. "Because const objects can be used as
 * compile-time values in C++, this feature urges the programmers to provide explicit intializer values for each const. This feature allows
 * the user to put const objects in header files that are included in many compilcation units."
 *
 * The designers of C++ intended two things:
 * 1. Const objects should be usable in constant expressions. In order to be usable in a constant expression, the compiler must have
 * seen a definition(not a declaration) so it be evaluated at compile time.
 * 2. Const objecst should be able to be propogated via header files.
 */
