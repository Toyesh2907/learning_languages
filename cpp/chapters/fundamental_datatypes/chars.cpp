/*
 * Char datatype was introduced to hold a single character
 * It is an integral type since the underlying value it stores is an integer. Similar to how a boolean
 * value 0 is interpreted as false. The variables stored as interpreted as an ASCII(American Standards for Code Information Interchange) characters.
 */

/*
 * Code 0-31 are inprintable characters 32-126 are printable characters
 */

#include <immintrin.h>
#include <iostream>
int main () {
    char ch1{ 'a' };
    char ch2{ 97 };

    std::cout << ch1 << " " << ch2 << '\n';
    return 0;
}

/*
 * The code above prints:
 * a
 * a
 * because the integer get's converted to the the character that 97 is interpreted as i.e 'a'.
 */

#include <iostream>
int main () {
    char ch {};
    std::cin >> ch;
    std::cout << "You entered: " << ch << '\n';

    std::cin >> ch;
    std::cout << "You entered: " << ch << '\n';

    return 0;
}

/*
 * For the code block above let's say the input is abcd
 * cin extracts the first character and bcd is left in the input buffer which is later extracted by cin again which prints:
 * You entered: a
 * You entered: b
 *
 * Extracting whitespaces is a bit tricky with std::cin
 * let's say for the above the input is "a b"
 * The above will prints
 * You entered: a
 * You entered: b
 *
 * and the reason for that is std::cin leaves trailing whitespaces for input
 * so incase you enter "a   "
 * it will print a and ask for another expect another input
 */

#include <iostream>

int main()
{
    std::cout << "Input a keyboard character: "; // assume the user enters "a b" (without quotes)

    char ch{};
    std::cin.get(ch); // extracts a, leaves " b\n" in stream
    std::cout << "You entered: " << ch << '\n';

    std::cin.get(ch); // extracts space, leaves "b\n" in stream
    std::cout << "You entered: " << ch << '\n';

    return 0;
}

/*
 * The problem listed above can be solved using cin.get() as this function does not ignore
 * trailing whitespaces
 */

/*
 * By default car is defined in C++ to be 1 byte.
 * If its used to hold characters, you don't need to specify a sign(since both signed and
 * unsigned chars can hold between 0 to 127)
 *
 * If you are using chars to hold small integers(Should not be done until and unless you are optimizing for space
 * You have to be a twisted individual to even consider that an optimization), it should always be specifed
 * whether its signed or unsigned.
 * A signed char holds -128 to 127
 * wheere as unsigned char holds 0 to 255.
 */

/*
 * Other char types wchar_t, char8_t, char16_t, char32_t
 * Much like ASCII maps the integers 0-127 to American English characters, other character encoding standards exist to map integers (of varying sizes) to characters in other languages.
 * The most well-known mapping outside of ASCII is the Unicode standard, which maps over 144,000 integers to characters in many different languages.
 * Because Unicode contains so many code points, a single Unicode code point needs 32-bits to represent a character (called UTF-32).
 * However, Unicode characters can also be encoded using multiple 16-bit or 8-bit characters (called UTF-16 and UTF-8 respectively).
 *
 * char16_t and char32_t were added to C++11 to provide explicit support for 16-bit and 32-bit Unicode characters.
 * These char types have the same size as std::uint_least16_t and std::uint_least32_t respectively (but are distinct types).
 * char8_t was added in C++20 to provide support for 8-bit Unicode (UTF-8). It is a distinct type that uses the same representation as unsigned char.
 * 
 * You won’t need to use char8_t, char16_t, or char32_t unless you’re planning on making your program Unicode compatible.
 * wchar_t should be avoided in almost all cases (except when interfacing with the Windows API), as its size is implementation-defined.
 * 
 * Unicode and localization are generally outside the scope of these tutorials, so we won’t cover it further.
 * In the meantime, you should only use ASCII characters when working with characters (and strings).
 * Using characters from other character sets may cause your characters to display incorrectly.
 */
