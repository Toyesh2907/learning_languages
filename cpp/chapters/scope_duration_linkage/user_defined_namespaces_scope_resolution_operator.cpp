/*
 * An example of naming collision
 */

//foo.cpp
#include <iostream>
#include <print>
#include <stdio.h>
int do_somehting(int x, int y){
    return x + y;
}

//goo.cpp
int do_something(int x, int y){
    return x - y;
}

//main.cpp

int do_somehting(int x, int y); // forward declaration of do_somehting
int main () {
    std::cout << do_something(4, 3) << '\n'; //which do_somehting will we get?
    return 0;
}

/*
 * From what I remember the order of compilation decides what do_something we get if the frist gets compiled first we get
 * 7 else 1. And since we don't have a header guard for already declared function we can possible get a error for that aswell
 */

/*
 * Yeah scratch what I said above it will be a naming collision since both of them compiled eventually shit I need to read back on some concepts.
 * (*￣m￣)
 *
 * C++ allows defining your own namespace to handle such collisions. Namespaces that are created by user are called user defined namespaces.
 * (According to uncle Alex it is more accurate to call them program defined namespaces)
 */

/*
 * The syntax of defining a namespace is:
 * namespace NamespaceIdentifier{
 * // content of namespace
 * }
 * For good practices it is suggested to use CamelCase for namespace identifiers
 */

//Using the namespace method now we can handle the collisions the following way

//foo.cpp

namespace Foo{
    int do_something(int x, int y){
        return x + y;
    }
}

//goo.cpp
namespace Goo{
    int do_something(int x, int y){
        return x - y;
    }
}

//main.cpp
int do_something(int x, int y);
int main () {
    std::cout << do_something(4, 3) << '\n';
    return 0;
}

/*
 * The codeblock above should throw an error and the reason for that is we had a forward declaration of the function
 * do_something. However the compiler could not find the function in global namespace so it gives the following error.
 * ConsoleApplication1.obj : error LNK2019: unresolved external symbol "int __cdecl doSomething(int,int)" (?doSomething@@YAHHH@Z) referenced in function _main
 *
 * There are two ways of telling compiler what version of do_something is needed. One is via scope resolution operator (::) or via using statements.
 * So the implementation of main.cpp becomes the one given below incase let's say you want to use do_something from namespace Foo followed by Goo
 */


int do_something(int x, int y);
int main () {
    std::cout << Foo::do_something(4, 3) << '\n';
    std::cout << Goo::do_something(4, 3) << '\n';
    return 0;
}

/*
 * This time we don't get an error. However if we try to use do_something without a scope resolution operator we will get the same error.
 * Because we have forward declared func do_something which doesn't exist in the namespace
 */

/*
 * Using scope resoltion operator with no name prefix calls the global namespace for example
 */

void print(){
    std::cout << "Global namespace" << '\n';
}

namespace Foo{
    void print(){
        std::cout << "Foo namespace" << '\n';
    }
}

int main () {
    Foo::print(); // prints "Global namespace"
    ::print();    // prints "Foo namespace"

    return 0;
}

/*
 * Identifier resolution in a namespace
 */

#include <iostream>

void print(){
    std::cout << "Global namespace" << '\n';
}

namespace Foo{
    void print(){
        std::cout << "Foo namespace" << '\n';
    }
    void print_namespace(){
        print();
        ::print();
    }
}

int main () {
    Foo::print_namespace();
    return 0;
}

/*
 * The codeblock above prints:
 * Foo namespace
 * Global namespace
 * because when the function print_namespace is called it is inside Foo namespace so for that namespace Foo::print is equivalent to print.
 * The compiler first checks whether a declaration of that function in the namespace in which the functions is being called. Which in this case
 * is Foo namespace if it is not found it checks in the outer namespace which in this case would be global namespace so if Foo::print does not exist
 * print resolves to global namespace's print function.
 */

//Forward declaration of content in namespace

//Let below be a file called add.h
#ifndef ADD_H
#define ADD_H

namespace BasicMath {
    //func add is part of namespace basic math
    int add(int x, int y);
}

#endif // !ADD_H

//Let below be a file called add.cpp
#include "add.h"

namespace BasicMath{
    //define the function add inside namespace BasicMath
    int add(int x,int y){
        return x + y;
    }
}

//Let below be the file called main.cpp
#include <add.h>
#include <iostream>

int main () {
    std::cout << BasicMath::add(4, 3) << '\n';

    return 0;
}

/*
 * If the forward declaration for add() wasn't places inside namespace BasicMath, then add() would be declared in
 * the global namespace instead, and the compiler would complain that it handn't seen a declaration for the call to
 * BasicMath::add(3, 4). If the definition of function add() wasn't inside namespace BasicMath, the linker would complain
 * that it couldn't find a matching definition for the call to BasicMath::add(4, 3).
 */

//Multiple namespace blocks are allowed!!

//Let's take a file circle.h

#ifndef CIRCLE_H
#define CIRCLE_H
namespace BasicMath{
    constexpr double pi{3.14};
}

#endif // !CIRCLE_H

//Let's take a file growth.h

#ifndef GROWTH_H
#define GROWTH_H
namespace BasicMath {
    constexpr double e {2.7};
}

#endif // !GROWTH_H

//Now let's take main.cpp

#include "circle.h">
#include "growth.h">

#include <iostream>
int main () {
    std::cout << BasicMath::pi << '\n';
    std::cout << BasicMath::e << '\n';

    return 0;
}

/*
 * The above prints:
 * 3.14
 * 2.7
 * The standard library makes extensive use of this otherwise every method would just be a huge ass header file.
 * Uncle Alex says not to add anything to standard namespace doing so causes undefined behaviour most of the time.
 * The troll potential on a codebase is massive with this
 * namespace std{
 * void cout(){
 * ::cout << "HAHA YOU THOUGHT";
 * }
 * }
 * would be fun to use
 */

//Nested namespaces

#include <iostream>

namespace Foo{
    namespace Goo{
        int add(int x, int y){
            return x + y;
        }
    }
}

int main () {
    std::cout << Foo::Goo::add(1, 2) << '\n';
    return 0;
}

/*
 * Self explanatory you have nested namespaces and can access stuff inside nested namespaces using scope resoltion operator
 * Below is another way of doing it. C++17 introduced another way of creating nested namespaces
 */

namespace Foo::Goo {
    int add(int x, int y){
        return x + y;
    }
}

int main () {
    std::cout << Foo:Goo::add(1, 2) << '\n';
    return 0;
}

/*
 * Since using namespace objects using scope resoltion operator can be a leading cause of carpel tunnel (╯°□°)╯︵ ┻━┻
 * We can use aliases for a namespace to save that pain
 */

#include <iostream>

namespace Foo:Goo {
    int add(int x, int y){
        return x + y;
    }
}

int main () {
    namespace Active = Foo::Goo;
    std::cout << Active::add(1, 2) << '\n'; //This is really Foo::Goo::add()
    
    return 0;
} //Active alias ends here

/*
 * Uncle Alex's knowledge on namespace usage:
 * Namespaces were intially introduced for preventing naming collisions. As evidence of this, note that the entirety of the standard
 * library lives under the single top-level namespace std. Newer standard library features that introduces lots of names have started
 * using nested namespaces(e.g. std::ranges) to avoid naming collisions with std namespace.
 * When working on a large personal project or at a JOB which will most likely include lots of third party libraries, namespacing your code
 * can help prevent naming collisions with lirbaries that aren't properly namespaced(i.e. lazy programmers (¬_¬)).
 */
