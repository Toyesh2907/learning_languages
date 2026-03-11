/*previosly in order to use code from some other file we used forward decalration
 * let's say we have add.cpp as follows
 * int add(int x, int y){
 * return x + y;
 * }
 *
 * and we have main.cpp as
 *
 * #include <iostream>
 *
 * int main () {
 std::cout<< "Summation of 3 and 4 is :" << add(3 ,4)<<'\n';
     return 0;
 }
 * In order for the above to work we would have to compile in a manner where add.cpp is compiled first other linker won't be
 * able to link add func to main file in order to not go through this painful procedure we use header files
 */

//lets say we have a file called add.h
int add(int x, int y){
    return x + y;
}

//let's say we have a file called main.cpp
#include <iostream>
#include "add.h"
int main () {
    std::cout << "summation of 3 and 4 is : " << add(3,4);
    return 0;
}

/*
 * In the code block above we have a header file called add.h that let's you a piece of code which is replaced by #include "add.h"
 * So during preprocessing #include "add.h" is replaced with the add function which is present in the file and the code compiles
 * Another thing to note the difference between <> and "" in include directives is that
 * <> includes header file from global whereas "" includes files from current project
 * let's say there is a file called multiply.h kept in some other project it won't compile because comiler won't be
 * able to find "multiply.h"
 */

/*
 * A little peek into the history as we know that in C global header files had a .h like #include <stdio.h>
 * This used to be the case for C++ aswell #include <iostream.h> used to exist previously in C++
 * The original versions of cout and cin were declared in iostream.h. Life was consistent, and it was good.
 * But then, somebody wanted a raise:D. So when the language was standardized by ANSI they decided to
 * move all of the names used in the standard library into the std namespace to help avoid conflicts with user-declared
 * identifers(over enginnering!). This had a problem: if they moved all the names into the std namespace, none of the old programs
 * would work anymore(surprise surprise!!)
 *
 * To mitigate this they introduced new header files that lack .h extension. These new header files declare
 * all names into the std namespace. This way, older programs that included #include <iostream.h> would work and newer programs
 * can be written using #include<iostream>
 * Why was this needed? Guess I am not smart enough to know ¯\_(ツ)_/¯
 */
