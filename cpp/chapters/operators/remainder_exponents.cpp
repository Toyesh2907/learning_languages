#include <iostream>
int main () {
    int x { 5 };
    int y { 3 };

    std::cout << x % y << '\n';
    std::cout << y % x << '\n';

    return 0;
}

/*
 * % operation is pretty self explanatory it retuns the remainder of the division between numbers.
 * The code block above prints:
 * 2
 * 3
 */

/*
 * Some knowledge from uncle Alex:
 * In C++ operator% isn't exactly modulo becuase
 * -21 modulo 4 would be 3
 * -21 remainder 4 would be -1
 * which is the same result as -21 % 4 = -1
 * so it is called remainder operator in C++
 */

#include <iostream>
#include <cmath>

int main () {
    double x { std::pow(3.0, 4.0 )};
    std::cout << x;

    return 0;
}

/*
 * The code block above is used to print 3 to the power of 4 with the help of func pow given by cmath library
 */

#include <cassert> // for assert
#include <cstdint> // for std::int64_t
#include <iostream>

// note: exp must be non-negative
// note: does not perform range/overflow checking, use with caution
constexpr std::int64_t powint(std::int64_t base, int exp)
{
	assert(exp >= 0 && "powint: exp parameter has negative value");

	// Handle 0 case
	if (base == 0)
		return (exp == 0) ? 1 : 0;

	std::int64_t result{ 1 };
	while (exp > 0)
	{
		if (exp & 1)  // if exp is odd
			result *= base;
		exp /= 2;
		base *= base;
	}

	return result;
}

int main()
{
	std::cout << powint(7, 12) << '\n'; // 7 to the 12th power

	return 0;
}

/*
 * According to uncle Alex:
 * its usually better to write your own function in order to calcualte exponents for +ve ints because pow func
 * returns floating points and in case you need exponents for simple ints above func can be used
 *
 * The above function is made with constant expression so that it can be evaluated at compile time instead of runtime
 *
 * So what is the problem with the function
 * That's right our old bitchass problem integer overflow and since we are dealing with signed integers it will be UB
 * and not a modulo expression :D so deal with that.
 */

#include <cassert> // for assert
#include <cstdint> // for std::int64_t
#include <iostream>
#include <limits> // for std::numeric_limits

// A safer (but slower) version of powint() that checks for overflow
// note: exp must be non-negative
// Returns std::numeric_limits<std::int64_t>::max() if overflow occurs
constexpr std::int64_t powint_safe(std::int64_t base, int exp)
{
    assert(exp >= 0 && "powint_safe: exp parameter has negative value");

    // Handle 0 case
    if (base == 0)
        return (exp == 0) ? 1 : 0;

    std::int64_t result { 1 };

    // To make the range checks easier, we'll ensure base is positive
    // We'll flip the result at the end if needed
    bool negativeResult{ false };

    if (base < 0)
    {
        base = -base;
        negativeResult = (exp & 1);
    }

    while (exp > 0)
    {
        if (exp & 1) // if exp is odd
        {
            // Check if result will overflow when multiplied by base
            if (result > std::numeric_limits<std::int64_t>::max() / base)
            {
                std::cerr << "powint_safe(): result overflowed\n";
                return std::numeric_limits<std::int64_t>::max();
            }

            result *= base;
        }

        exp /= 2;

        // If we're done, get out here
        if (exp <= 0)
            break;

        // The following only needs to execute if we're going to iterate again

        // Check if base will overflow when multiplied by base
        if (base > std::numeric_limits<std::int64_t>::max() / base)
        {
            std::cerr << "powint_safe(): base overflowed\n";
            return std::numeric_limits<std::int64_t>::max();
        }

        base *= base;
    }

    if (negativeResult)
        return -result;

    return result;
}

int main()
{
	std::cout << powint_safe(7, 12) << '\n'; // 7 to the 12th power
	std::cout << powint_safe(70, 12) << '\n'; // 70 to the 12th power (will return the max 64-bit int value)

	return 0;
}

/*
 * The above piece of code is an implementation of overflow safe exponent function
 * that we defined above
 */

