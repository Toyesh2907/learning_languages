//I saw the name of the post and I knew this will be really fucking strupid to read through

// #include <iostream>
//
// int main()
// {
//     std::cout << "Enter an integer: ";
//     int x{};
//     std::cin >> x;
//
//     std::cout << "Enter another integer: ";
//     int y{};
//     std::cin >> y;
//
//     if (x == y)
//         std::cout << x << " equals " << y << '\n';
//     if (x != y)
//         std::cout << x << " does not equal " << y << '\n';
//     if (x > y)
//         std::cout << x << " is greater than " << y << '\n';
//     if (x < y)
//         std::cout << x << " is less than " << y << '\n';
//     if (x >= y)
//         std::cout << x << " is greater than or equal to " << y << '\n';
//     if (x <= y)
//         std::cout << x << " is less than or equal to " << y << '\n';
//
//     return 0;
// }

/*
 * For the peice of code above we have all relational operators offered by cpp
 * Thank fucking god we don't have === like we do in JavaScript attrocious
 * Pretty straight forward no explanation needed
 */

/*
 * Let's say that you have a boolean comparison
 * bool b1 = True;
 *
 * if (b1 == True)
 *      codeblock
 * if (b1 ==false)
 *      codeblock
 *
 * it can also be written as:
 * if (b1) or if (!b1)
 * so according to uncle Alex there's no need to add unnecessary == and != to conditions. It makes them harder
 * to read without offerning any additional values.
 * Makes sense
 */

#include <cstdlib>
#include <ios>
#include <iostream>
int main () {
    constexpr double d1 { 100.0 - 99.99 };
    constexpr double d2 { 10.0 - 9.99 };

    if (d1 == d2)
        std::cout << "d1 == d2" << '\n';
    else if (d1 < d2)
        std::cout << "d1 < d2" << '\n';
    else if(d1 > d2)
        std::cout << "d1 > d2" << '\n';
    
    return 0;
}

/*
 * The piece of code above prints:
 * d1 > d2
 * Why? Remember floating point precisons :D
 * So closely inspecting d1 and d2 might give something like
 * d1 = 0.010000000000005116 and d2 = 0.0099999999999997868.
 *
 * So what can be done I am under an assumption that setting precision can be used
 * They have a similar result with == and != operators aswell
 * std::cout << std::boolalpha << (0.3 == 0.2 + 0.1);//prints false
 *
 * So according to uncle Alex it is best to avoid using == operator with floating comparisons if there is a chance
 * of those values being calculated.
 */

#include <iostream>
int main () {
    constexpr double gravity { 9.8 };
    if(gravity == 9.8){
        std::cout << "We are on Earth!" << '\n';
    }
    
    return 0;
}

/*
 * It is okay to compare constant floating literals as they are not calculated and results won't be UB
 */


#include <cmath>
bool approximately_equal_abs(double a, double b, double absEpsilon){
    return std::abs(a - b) <= absEpsilon;
}

/*
 * Above func can be used to test close enough as a metric to check whether two
 * floats are equal or not in this case since cmath offers a func called std::abs that returns
 * the absolute value of the number entered
 * So above designed func returns True or False based on whether two numbers are close enough respectively
 *
 * While this func "can" work(Uncle Alex some of us would use this and call it a day (*￣m￣)) it's not great. An epsilon of 0.000001
 * is good for inputs around 1.0, too big for inputs around 0.00000001, and too
 * small for inputs like 10,000.
 *
 * So we would have to change the epsilon according to our inputs.
 */

#include <algorithm>
#include <cmath>


bool approximately_equal_rel(double a, double b, double rel_epsilon){
    return std::abs(a - b) <= (std::max(std::abs(a), std::abs(b)) * rel_epsilon);
}

/*
 * What the fuck am I looking at?
 * on the return statement abs(a - b) tells the +ve distance between a and b
 * On right side we need to calculate the largest value "close enough" means
 * a and b are within 1% of the larger of a and b, we pass rel_epsilon of 0.001. The value for rel_epsilon can be
 * adjusted to whatever is most appropraite for the circumstances.
 *
 * So this a robust solution right? RIGHT?
 */

#include <algorithm>
#include <cmath>
#include <iostream>


bool approximately_equal_rel(double a, double b, double rel_epsilon){
    return std::abs(a - b) <= (std::max(std::abs(a), std::abs(b)) * rel_epsilon);
}

int main () {
    constexpr double a{ 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 };

    constexpr double rel_epsilon{ 1e-8 };
    constexpr double abs_epsilon{ 1e-12 };
    
    std::cout << std::boolalpha;
    std::cout <<  approximately_equal_rel(a, 1.0, rel_epsilon) << '\n';
    std::cout << approximately_equal_rel(a - 1.0, 0.0, rel_epsilon) << '\n';
    
    return 0;
}

/*
 * The above peice of code prints:
 * True
 * False
 *
 * So what to do
 * Behold the making of approximately_equal functions constexpr
 */

#include <algorithm>
#include <cmath>

constexpr bool approximately_equal_rel(double a, double b, double abs_epsilon, double rel_epsilon){
    return std::abs(a - b) <= (std::max(std::abs(a), std::abs(b)) * rel_epsilon);
}

const bool approximately_equal_abs_rel(double a, double b, double abs_epsilon, double rel_epsilon){
    if (std::abs(a - b) <= abs_epsilon)
        return true;
    return approximately_equal_abs_rel(a , b, rel_epsilon);
}

/*
 * The above piece of code only works for C++ version > 23
 * prior to this we run into an issue because a constexpr func that is used
 * in a constant expression can't call a non-constexpr function, and std::abs wasn't made
 * constexpr until C++23
 *
 * In order for this to work we can use the piece of code give below and I am not even going to claim
 * about having the slightest of idea how that is done
 */

// C++14/17/20 version
#include <algorithm> // for std::max
#include <iostream>

// Our own constexpr implementation of std::abs (for use in C++14/17/20)
// In C++23, use std::abs
// constAbs() can be called like a normal function, but can handle different types of values (e.g. int, double, etc...)
template <typename T>
constexpr T constAbs(T x)
{
    return (x < 0 ? -x : x);
}

// Return true if the difference between a and b is within epsilon percent of the larger of a and b
constexpr bool approximatelyEqualRel(double a, double b, double relEpsilon)
{
    return (constAbs(a - b) <= (std::max(constAbs(a), constAbs(b)) * relEpsilon));
}

// Return true if the difference between a and b is less than or equal to absEpsilon, or within relEpsilon percent of the larger of a and b
constexpr bool approximatelyEqualAbsRel(double a, double b, double absEpsilon, double relEpsilon)
{
    // Check if the numbers are really close -- needed when comparing numbers near zero.
    if (constAbs(a - b) <= absEpsilon)
        return true;

    // Otherwise fall back to Knuth's algorithm
    return approximatelyEqualRel(a, b, relEpsilon);
}

int main()
{
    // a is really close to 1.0, but has rounding errors
    constexpr double a{ 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 };

    constexpr double relEps { 1e-8 };
    constexpr double absEps { 1e-12 };

    std::cout << std::boolalpha; // print true or false instead of 1 or 0

    constexpr bool same { approximatelyEqualAbsRel(a, 1.0, absEps, relEps) };
    std::cout << same << '\n';

    return 0;
}
