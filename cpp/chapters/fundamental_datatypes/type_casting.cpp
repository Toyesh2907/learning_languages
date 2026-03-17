// #include <iostream>
//
// void print(double x){
//     std::cout << x << '\n';
// }
//
// int main () {
//     int x { 5 };
//     print(x);
//     return 0;
// }
//
// /*
//  * In the above function print func takes in a double and 
//  * shits out the number that was passed to it for above since it got an integer it undergoes implicit
//  * type conversion and converts that 5 into a double.
//  * 
//  * The process of converting one fundamental datatype to other is known as type conversion.
//  *
//  *When the compiler does type conversion on your behalf its called as implicit type conversion
//  */
//
// #include <iostream>
//     void print(int x){
//         std::cout << x << '\n';
//     }
//
// int main () {
//     print(5.5);
//     return 0;
// }
//
// /*
//  * The code block behaves depending on how your compiler is set
//  * If it treats warnings as error it will throw an error otherwise it will
//  * just show a warning saying that you will lose information which in this case would be
//  * the decimal value i.e .5
//  *
//  * So it will print 5
//  */
//
// #include <iostream>
//
// void print(int x){
//     std::cout << x << '\n';
// }
//
// int main () {
//     double d { 5.5 };
//     print(static_cast<int>(d));
//     return 0;
// }
//
// /*
//  * The code block above shows usage of static_cast for explicitly type casting a double into an int
//  * Because we are explicitly casting a double into an int
//  */
//
// #include <iostream>
//
// int main () {
//     char ch { 97 };
//     std::cout << ch << " has value: " << static_cast<int>(ch);
//     return 0;
// }

/*
 * The code block above prints:
 * a has value: 97
 * it converted the character ch into its ASCII value
 */

#include <iostream>
int main () {
    int s { -1 };
    std::cout << static_cast<unsigned int>(s) << '\n';

    unsigned int u {4294967295}; // largest 32-bit integer
    std::cout << static_cast<signed int>(u) << '\n';
    return 0;
}

/*
 * For the codeblock above I got the following printed:
 * 4294967295
 * -1
 *
 * signed int value -1 cannot be represented as an unsigned int. The result modulo
 * wraps to unsigned int value 4294967295
 *
 * unsigned 4294967295 cannot be represented as signed int. The result modulo wraps to -1
 */

#include <cstdint>
#include <iostream>
int main () {
    std::int8_t test_int { 65 };
    std::cout << test_int << '\n';
    return 0;
}

/*
 *You would expect the above to print 65 like any sane person
* but it doesn't int8_t and uint_8t are treated like signed and unsinged chars so in most
* machine it prints A i.e the ASCII value of A
 */

#include <cstdint>
#include <iostream>

int main () {
    std::cout << "Enter a number between 0 and 127";

    std::int8_t test_int {};
    std::cin >> test_int;

    std::cout << "You entered : " << static_cast<int>(test_int);
    return 0;
}

/*
 * Let's say for the above piece of code you enter 35
 * What does is print?
 * 35???
 * NO!!!!! ╯°□°)╯︵ ┻━┻
 * Why?
 * Because int8_t is treated as signed char 35 is treated as '3' and '5'
 * so '3' is extracted and '5' remains in the buffer
 * So it prints 51 what is ASCII value of 3
 */
