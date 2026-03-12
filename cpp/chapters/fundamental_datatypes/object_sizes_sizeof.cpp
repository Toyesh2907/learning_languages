/*
 * Fundamental datatype sizes
 * integral types are char, short, int, long, longlong have a minmum size of 8, 16, 16, 32 and 64 bits respectively
 * char and char8_t are exactly 1 byte(at least 8 bits)
 *
 * When we talk about the size of a type we talk about the size of an instance of that type
 */

/*
 * According to modern architectures
 * - A byte is 8 bits
 * - Memory is byte addressable(We can access every byte of the Memory independently)
 * - Floating point support is IEE-754 complient
 *   We are on a 32-bit or 64-bit architecture
 * Using the above assumptions we can reasonably state the following
 *    Category       Type         Min size      Typical size
 *    ------------------------------------------------------
 *    Boolean        bool         1 byte        1 byte
 *
 *    Character      char         1 byte        1 byte
 *                wchar_t      1 byte        2 or 4 bytes
 *                char8_t      1 byte        1 byte
 *                char16_t     2 bytes       2 bytes
 *                char32_t     4 bytes       4 bytes
 *
 *    Integral       short        2 bytes       2 bytes
 *                int          2 bytes       4 bytes
 *                long         4 bytes       4 or 8 bytes
 *                long long    8 bytes       8 bytes
 *
 *    Floating pt    float        4 bytes       4 bytes
 *                double       8 bytes       8 bytes
 *                long double  8 bytes       8, 12, or 16 bytes
 *
 *    Pointer        std::nullptr_t 4 bytes     4 or 8 bytes
*/


#include <iomanip> // for std::setw(which sets the width of subsequent output)
#include <iostream>
#include <climits> // for CHAR_BIT

int main () {
    std::cout << "A but is " << CHAR_BIT << "bits\n\n";
    std::cout<< std::left; //left JUSTIFY output
    std::cout << std::setw(16) << "bool" << sizeof(bool) << "bytes\n\n";
    std::cout << std::setw(16) << "char" << sizeof(char) << "bytes\n\n";
    std::cout << std::setw(16) << "short" << sizeof(short) << "bytes\n\n";
    std::cout << std::setw(16) << "int" << sizeof(int) << "bytes\n\n";
    std::cout << std::setw(16) << "long" << sizeof(long) << "bytes\n\n";
    std::cout << std::setw(16) << "long long" << sizeof(long long) << "bytes\n\n";
    std::cout << std::setw(16) << "float" << sizeof(float) << "bytes\n\n";
    std::cout << std::setw(16) << "double" << sizeof(double) << "bytes\n\n";
    std::cout << std::setw(16) << "long double" << sizeof(long double) << "bytes\n\n";
    std::cout << std::setw(16) << "void" << sizeof(void) << "bytes\n\n"; //depending on the compiler throws an error

    return 0;
}
    
//The results for above vary on the compiler, computer architecture and the OS that is being used.
