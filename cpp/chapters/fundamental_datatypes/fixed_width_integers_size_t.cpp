/*
 * Integers have a guaranteed minmum value but they could be larger, depending on the target system.
 * For example an int has a min size of 16 however in moder architectures its usually 32 bit.
 * So a variable let's say int x; may or may not overflow if x = 32767 and we do x = x + 1
 * depending on the architecture we are using.
 *
 * Why was this done. Previously everybody was coding in C and and computers were slow
 * so in order for a programmer to not worry about whether they could be using something more performant.
 *
 * To address this C++ introduced fixed width integers in C++11. Given their name pretty self explanatory
 * they have a fixed size.
 */

/*
 * Name             Size                Range                                           Notes
 * -----------      ------------        ------------------------------------------      ----------------------------------------------
 * std::int8_t      1 byte signed       -128 to 127                                     Treated like a signed char on many systems.
 * std::uint8_t     1 byte unsigned     0 to 255                                        Treated like an unsigned char on many systems.
 * std::int16_t     2 byte signed       -32,768 to 32,767
 * std::uint16_t    2 byte unsigned     0 to 65,535
 * std::int32_t     4 byte signed       -2,147,483,648 to 2,147,483,647
 * std::uint32_t    4 byte unsigned     0 to 4,294,967,295
 * std::int64_t     8 byte signed       -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
 * std::uint64_t    8 byte unsigned     0 to 18,446,744,073,709,551,615
*/

#include <iostream>
#include <iterator>
int main () 
{
    std::uint32_t x {32767};
    x = x + 1;
    std::cout << x << '\n';
    return 0;
}

/*
 * In the code block above x is always a 32 bit integer
 *
 * So fixed width integers actually don't define new types they are aliases for existing ones with the desired size.
 *
 * NOTE: Due to an oversight in C++ specifications, modern compilers treat std::int8_t and std::uint8_t the same as
 * signed char and unsigned char. So in modern systems 8-bit fixed-width integral types behave as char types.
 */

/*
 * SOME DOWN SIDES OF FIXED WIDTH INTEGERS:
 * 1. They are guaranteed to be defined on all architectures. They only exists on systems where there are
 * fundamental integral types that match their widths and following  a certain binary representation.
 *
 * 2. If you use a fixed width integer, it may be slower that a wider type depending on some architectures. For example,
 * if you need an integer that is guaranteed to be 32-bits, you migh decide to use std::int32_t, but your CPU might actually
 * be faster at processing 64-bit integers. However just because your CPU can process a give type faster doesn't mean your program will be faster overall
 * moder programs are often constrained by memory usage rather than CPU, and the larger memory footprint may slow your program more than the faster CPU
 * processing accelerates it. It's hard to know without actually measuring :D.
 */

/*
 * To help address above listed disadvantages two alternative sets of inegers that are guaranteed to exist were introduced
 * Fast and least integral types.
 *
 * The fast types (std::int_fast#_t and std::uint_fast#_t) provides the fastest integer for your CPU with a given width of atleast #(where # = 8, 16, 32, 64)
 * For example std::int_fast32_t will give you the fastest signed integer type that's atleast 32-bits. Here fastest integral type that can be
 * processed fastest but the CPU.
 *
 * The least types (std::int_least#_t and std::uint_least#_t) provides the smallest signed/unsigned integer type with a width of at least
 * #-bits(where # = 8, 16, 32, 64). For example, std::uint_least32_t will give you the smallest unsigned integer type that's at least
 * 32 bits.
 *
 * From my initial understanding they both look the same to me¯\_(ツ)_/¯.
 */

#include <cstdint> // for fast and least types
#include <iostream>

int main1()
{
	std::cout << "least 8:  " << sizeof(std::int_least8_t)  * 8 << " bits\n";
	std::cout << "least 16: " << sizeof(std::int_least16_t) * 8 << " bits\n";
	std::cout << "least 32: " << sizeof(std::int_least32_t) * 8 << " bits\n";
	std::cout << '\n';
	std::cout << "fast 8:  "  << sizeof(std::int_fast8_t)   * 8 << " bits\n";
	std::cout << "fast 16: "  << sizeof(std::int_fast16_t)  * 8 << " bits\n";
	std::cout << "fast 32: "  << sizeof(std::int_fast32_t)  * 8 << " bits\n";

	return 0;
}

/*
 * The results for the above peice of code differs depending on the machine architecture and compiler
 * For my machine the results were same i.e for all least and fast the sizeof operator returned the same
 * whereas for author std::int_least16_t was 16-bits where as std::int_fast16_t was 32-bits
 */

int main2 () {
    std::uint_fast16_t sometype { 0 };
    sometype = sometype - 1;

    std::cout << sometype << '\n';

    return 0;
}

/*
 * This code will produce results depending on whether std::uint_fast16_t is 16, 32, 64 bits! (╯°□°)╯︵ ┻━┻
 * This is pretty much the fucking same when it comes to fixed width integers. Over engineer some shit and bites
 * you in the ass back.
 *
 * NOTE: Avoid using fast and least integral types because they may exhibit different behaviours on architectures where they resolve
 * to different size.
 *
 * So what to do?
 * Can't thank Alex enough!!
 * Prefer int when the size of integer doesn't matter*(eg. the number will always fit within the range
 * of a 2 byte-signed integer). For example, if you're asking the user to enter their age, or counting from
 * 1 to 10, it doesn't matter whether int is 16-bits or 32-bits(the number will fit either way). This will
 * cover the vast majority of the cases you're likely to run across.
 *
 * Prefer std::int#_t when storing a quantity that needs a guaranteed range.
 * Prefer std::uint#_t when doing bit manipulation or well-defined wrap around behaviour is required(eg. cryptography or random number generation).
 *
 * Avoid the following when possible:
 *
 * short and long integers(prefer a fixed-width integer type instead).
 * The fast and least integral types (prefer a fixed-width integer type instead).
 * Unsigned types for holding quantities (prefer a signed integer type instead).
 * The 8-bit fixed-width integer types (prefer a 16-bit fixed-width integer type instead).
 * Any compiler-specific fixed-width integers (for example, Visual Studio defines __int8, __int16, etc…)
 */

int main4 () {
    std::cout << sizeof(int) << '\n';
    return 0;
}

/*
 * On authors machine this prints 4 same as mine
 * 
 * Pretty simple right? What can we infer from this
 * sizeof operator returns an integer value. But which?
 * An int? short? long? long long?
 * The correct answer to this is std::size_t.
 * std::size_t is an alias for an implementation-defined unsigned integral type.
 * In other words, the compiler decides if std::size_t is an unsigned int, unsigned long, unsigned long long, etc.
 *
 * Author NOTES:
 * std::size_t is an alias for implementation-defined integral type. It is used within the standard library to
 * represent the byte-size or length of objects.
 *
 * std::size_t is actually a typedef. Will be covered later on.
 */

#include <iostream>
#include <cstddef> //for std::size_t
int main5 () {
    int x { 5 };
    std::size_t s { sizeof(x)};
    std::cout << s << '\n';
    
    return 0;
}

/*
 * If af any given point std::size_t is supposed to be used use the header cstddef
 * even though use of header is not required
 * Above was suggested by author maybe has to do with varying compilers.
 */

int main6 () {
    std::cout << sizeof(std::size_t);
    
    return 0;
}

/*
 * The above compiles as 4 for author and 8 for me
 * The sizeof operator must be able to return the byte-size of an object as a value of type std::size_t.
 * Therefore, the byte-size of an object can be no longer than the largest value std::size_t can hold.
 *
 * If it were possible to create a larger object, sizeof would not be able to return its byte-size, as it would be outside the range that a std::size_t could hold. Thus, creating an object with a size (in bytes) larger than the largest value an object of type std::size_t can hold is invalid (and will cause a compile error).

 * For example, let’s assume that std::size_t has a size of 4 bytes on our system. An unsigned 4-byte integral type has range 0 to 4,294,967,295.
 * Therefore, a 4-byte std::size_t object can hold any value from 0 to 4,294,967,295. Any object with a byte-size of 0 to 4,294,967,295 could have 
 * it’s size returned in a value of type std::size_t, so this is fine. However, if the byte-size of an object were larger than 4,294,967,295 bytes,
 * then sizeof would not be able to return the size of that object accurately, as the value would be outside the range of a std::size_t. 
 * Therefore, no object larger than 4,294,967,295 bytes could be created on this system.
 * 
 * As an aside…
 * 
 * The size of std::size_t imposes a strict mathematical upper limit on an object’s size. 
 * In practice, the largest creatable object may be smaller than this amount (perhaps significantly so).
 * 
 * Some compilers limit the largest creatable object to half the maximum value of std::size_t (an explanation for this can be found here).
 * 
 * Other factors may also play a role, such as how much contiguous memory your computer has available for allocation.
 * 
 * When 8-bit and 16-bit applications were the norm, this limit imposed a significant constraint on the size of objects. 
 * In the 32-bit and 64-bit era, this is rarely an issue, and therefore not something you generally need to worry about.
 */
