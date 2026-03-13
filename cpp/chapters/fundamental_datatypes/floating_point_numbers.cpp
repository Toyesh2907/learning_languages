/*
 * A floating point type variable is a variable that can hold a number with a fractional
 * component, such as 4320.0, -3.33, etc. The floating part of the name floating point refers
 * to the fact that the decimal point can "float". It can support a variable number of digits before and after
 * the decimal point.
 */

/*
 * C++ has three fundamental floating points data types: a single-precision float, double-precision double, and an extended-precesion
 * long double.As with integers, C++ does not define the actual size of these types.
 *
 * C++ types        Typical Size
 * float            // 4 bytes
 * double           // 8 bytes
 * long double      // 8, 12, or 16 bytes (implementation-defined)
 *
 * On modern architectures, floating points are conventionally implemented using one of the floating-point formats
 * defined in IEEE 754 standards refer to this:  https://en.wikipedia.org/wiki/IEEE_754
 * As a result, float and double is almost always 4 and 8 bytes respectively("almost" </3).
 *
 * long double is a strange type. On different platforms, its size can vary between 8 and 16 bytes and it may
 * or may not use an IEEE 754 complient format. Alex recommends to avoid using long double hence I shall (˶ᵔ ᵕ ᵔ˶)ゞ.
 */

#include <iostream>
#include <limits>

int main () {
    std::cout << std::boolalpha; //prints bool as true or false rather than 1 or 0
    std::cout << "float: " << std::numeric_limits<float>::is_iec559 << '\n';
    std::cout << "double: " << std::numeric_limits<double>::is_iec559 << '\n';
    std::cout << "long double: " << std::numeric_limits<long double>::is_iec559 << '\n';
    
    return 0;
}

/*
 * The piece of code above prints whether floating points I have are IEE 754 complient or not
 * forntunatly for me they are might not be for you :D
 *
 * float is almost always implemented using the 4-byte IEEE 754 single-precision format.
 * double is almost always implemented using the 8-byte IEEE 754 double-precision format.
 * 
 * However, the format used to implement long double varies by platform. Common choices include:
 * 
 * 8-byte IEEE 754 double-precision format (same as double).
 * 80-bit (often padded to 12 or 16 bytes) x87 extended-precision format (compatible with IEEE 754).
 * 16-byte IEEE 754 quadruple-precision format.
 * 16-byte double-double format (not compatible with IEEE 754).
 */

int a { 5 };
double b { 5.0 };
float c { 5.0f };

/*
 * Given above is how you declare and initialize floating point variables with a difference in integers
 * f suffix means float type
 * by default, floating point literals default to type double. An f suffix is used to denote a literal of type float.
 *
 * NOTE: It is important to make sure your literals match the type of the variables otherwise a type conversion happens during initialization
 * with a possible loss of information.
 */

int main1 () {
    std::cout << 5.0 << '\n';
    std::cout << 5.0f << '\n';

    std::cout << 5.7 << '\n';
    std::cout << 5.7f << '\n';

    std::cout << 9876543.21 << '\n';
    std::cout << 9876543.21f << '\n';
    return 0;
}

/*
 * For the code block above the following gets printed
 * 5
 * 6.7
 * 9.87654e+06
 *
 * In the first case std::cout printed 5, even though 5.0 and 5.0f was provided. By default std::cout will not print the fractional part of a number
 * if the fractional part is 0.
 *
 * In second case, the number printed as we expected i.e 5.7 in both the cases irrespective of whether f suffix was provided.
 * 
 * In the third case it prints the number is scientific notation.
 */

/* Floating point range (IEEE 754 and related)
*
* Format                         Range                                   Precision
* ---------------------------------------------------------------------------------------------
* IEEE 754 single-precision      ±1.18 x 10^-38 to ±3.4 x 10^38 and 0.0  6–9 significant digits,
* (4 bytes)                                                              typically 7
*
* IEEE 754 double-precision      ±2.23 x 10^-308 to ±1.80 x 10^308       15–18 significant digits,
* (8 bytes)                       and 0.0                                typically 16
*
* x87 extended-precision         ±3.36 x 10^-4932 to ±1.18 x 10^4932     18–21 significant digits
* (80 bits)                      and 0.0
*
* IEEE 754 quadruple-precision   ±3.36 x 10^-4932 to ±1.18 x 10^4932     33–36 significant digits
* (16 bytes)                     and 0.0
*/

/*
 * Uncle Alex is dropping some history wisdom gather around:
 * 
 * "The 80-bit x87 extended-precision floating point type is a bit of a historical anomaly.
 * On modern processors, objects of this type are typically padded to 12 or 16 bytes (which is a more natural size for processors to handle).
 * This means those objects have 80-bits of floating point data, and the remaining memory is filler.

 * It may seem a little odd that the 80-bit floating point type has the same range as the 16-byte floating point type.
 * This is because they have the same number of bits dedicated to the exponent -- however, the 16-byte number can store more significant digits."
 */

#include <iostream>
#include <iomanip>

int main2 () {
    std::cout << std::setprecision(17); // show 17 digits of precision
    std::cout << 3.33333333333333333333333333333333333333f <<'\n'; // f suffix means float
    std::cout << 3.33333333333333333333333333333333333333 << '\n'; // no suffix means double
    
    return 0;
}

/*
 * The above code block prints the following
 * 3.3333332538604736
 * 3.3333333333333335
 *
 * Because we set the precision to 17 digits using std::setprecision(), each of the above numbers is printed with 17 digits. 
 * But, as you can see, the numbers certainly aren’t precise to 17 digits! And because floats are less precise than doubles, the float has more error.

 * Output manipulators (and input manipulators) are sticky -- meaning if you set them, they will remain set.
 * The one exception is std::setw. Some IO operations reset std::setw, so std::setw should be used every time it is needed.
 * 
 * precision issues impact numbers with too many significant digits aswell take a look below.
 */

int main3 () {
    float f { 123456789.0f }; // f has 10 singificant digits
    std::cout << std::setprecision(9);
    std::cout << f << '\n';
    
    return 0;
}

/*
 * The above codeblock prints:
 * 123456792. Why?
 * 123456792 is greater than 123456789. The value 123456789.0 has 10 significant digits, but float values
 * typically have 7 digits of precision so it was precise until 7 digits. We lost some precision. This situation is
 * called a rounding error.
 * 
 * ALEX KNOWLEDGE: Favor double over float unless space is at a premium, as lack of precision in a float will often lead to inaccuracies.
 */

#include <iomanip>
#include <iostream>

int main4 () {
    double d{ 0.1 };
    std::cout << d << '\n';
    std::cout << std::setprecision(17);
    std::cout << d << '\n';
    
    return 0;
}

/*
 * The above piece of code prints the following:
 * 0.1
 * 0.10000000000000001
 * Why?
 * because double is precise upto 16 significant digits and it results in a roudning error
 * It makes the number either slightly bigger or smaller
 */

#include <iostream>
#include <iomanip>

int main5 () {
    std::cout << std::setprecision(17);
    
    double d1 { 1.0 };
    std::cout << d1 << '\n';

    double d2 { 0.1 + 0.1 + 0.1+ 0.1+ 0.1+ 0.1+ 0.1+ 0.1+ 0.1+ 0.1 };
    std::cout << d2 << '\n';

    return 0;
}

/*
 * The code block above prints the following:
 * 1
 * 0.99999999999999989
 * 
 * I expected them to be the same but they are not (*￣m￣)
 * Such a pain in the ass.
 * floating point comparisons are not going to be fun
 * How does tensorflow and keras handles? Insane.
 */

#include <iostream>

int main6 () {
    double zero { 0.0 };

    double pos_inf { 5.0 / zero};
    std::cout << pos_inf << '\n';
    double neg_inf { -5.0 / zero};
    std::cout << neg_inf << '\n';
    
    double z1 { 0.0 / pos_inf};
    std::cout << z1 << '\n';
    
    double z2 { -0.0 / pos_inf};
    std::cout << z2 << '\n';

    double nan { zero / zero };
    std::cout << nan << '\n';
    return 0;
}

/*
 * The code block above prints the following
 * inf
 * -inf
 * 0
 * -0
 * nan
 * inf means infinity can be +ve or -ve
 * NaN in this context stands for "Not a Number"
 *
 * Even though your compiler allows division it is better to avoid it.
 */
