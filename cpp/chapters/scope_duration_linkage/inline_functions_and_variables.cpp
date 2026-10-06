/*
 * Let's take an example of implementing something or writing a piece of code for doing a simple task like writing.
 * To a file or doing some simple calculation for exampple take a look below.
 */

#include <iostream>

int min(int x, int y){
    return (x < y) ? x : y;
}

int main () {
    std::cout << min(5, 6) << '\n';
    std::cout << min(3,2 ) << '\n';
    
    return 0;
}

/*
 * Now we take a look at the code above it has a min function that is responsible for calcuating the min of two numbers.
 * Everytime there is a function call their is a performance overhead that you have to bare. During the call to func min()
 * CPU has to store the address of the current instruction it is executing(so it knows where to continue after executing func min())
 * alond with the values of various CPU registers. Then parameters x and y are instantiated and then intialized. Then the execution path
 * has to jump to the code in min(). For functions that are large this overhead can be neglected since the func call takes more time than the
 * overhead but incase of funcs like min() this overhead is more than the time that func min will take to execute.
 *
 * A piece of mind to:-
 * DRY programmers. It is okay to repeat stuff in programming when the function is essentially beign called twice in an entire codebase
 * in latency sensitive systems. A piece of mind to functional it is okay to use classes instead of having 7 function calls for what
 * a class instance and respective class method would have solved stop increasing the call stack fuckwit.
 * So it is for the programmer to make the judicious decision on when to use these set of rules. Code readability is a guideline
 * not set in stone you can have a beautifully writen codebase that performs slower that a bank employee 2 hours prior to a lunk break.
 * Not really useful to users now is it ¯\_(ツ)_/¯.
 */

/*
 * Fortunatly for us C++ compiler has a trick that it can use to avoid such overhead cost. Inline expansion is a process where a function
 * call is replaced by the code from the called functions definiton.
 * the above piece of code can be refactored as:
 */

#include <iostream>

int main () {
    std::cout << ((5 < 6) ? 5 : 6) << '\n';
    std::cout << ((2 < 3) ? 2 : 3) << '\n';
    return 0;
}

/*
 * Now as you remove the function call you remove the cost of storing that function, cost of creating an overhead for that function and cost
 * of instantiating and intializing x and y for calculating the minimum. This is fine for inline functions that have with less parameters.
 * For this example the compiler changes the above constant expression ((5 < 6) ? 5 : 6) into 5 and makes the first statment in main()
 * std::cout << 5 << '\n';
 * 
 * If the body of the function would take more instructions than the function being replaced. Then each inline expression will cause the executable
 * to grow larger. Larger executables tend be slower(due to not fitting well in memory caches)
 */

/*
 * Historically, compilers either didn't have the capability to dertermine whether inline expansion would be benificial, or were not very good at it.
 * For this reason, C++ provided the inline keyword which was originally intended to be used as a hint to the compiler that a function would(probably)
 * beinifit from being expanded inline.
 */


#include <iostream>

inline int min(int x, int y){ // inline keyword means that this function is inline
    return (x < y) ? x : y;
}

int main () {
    std::cout << min(5, 6) << '\n';
    std::cout << min(3,2 ) << '\n';
    
    return 0;
}

/*
 * Seems handy right? Wrong:
 * 1. Using inline to request expansion is a form of premature optimization, and misuse could actually harm preformance.
 * 2. The inline keyword is just a hint to help compiler determine where to perform inline expansion. The compiler is completely free
 * to ignore the request, and it may very well do so :..( .The compiler is also free to perform inline expansion of functions that do
 * not use the inline keyword as part of its normal set of optimizations.
 * 3. The inline keyword is defined at the wrong level of granularity. We use the inline keyword on a function definition, but inline expansion
 * is actually dertermined per function call. It maybe beinficial to expand some functions but bad to do so for others, and there is no syntax
 * to influence this.
 *
 * Moder compilers are good at determining which function calls should be inline -- better than humans(ouch) in most cases. As a result,
 * the compiler will likely ignore or devalue any use of inline(basically the compiler will say: "Baary thinks he knows better then me; What a dumbass")
 * to request inline expansion for your functions.
 *
 * So according to uncle Alex: Don't use inline functions keyword to request inline expansion for your functions.
 */

/*
 * The following functions are implicit inline:
 * 1. Functions that are defined inside a class, struct or union type definition.
 * 2. Constexpr/ consteval functions
 * 3. Functions implicitly instantiated from function templates
 */
