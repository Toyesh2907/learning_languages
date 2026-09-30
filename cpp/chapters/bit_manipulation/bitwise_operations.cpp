/*
 * Aight let's have a quick summary of all the bitwise operators that I have to relook everytime
 * because my peanut sized brain can't remember shit
 *
 * left shit << used as x << n the bits of x are shifted left by n positions
 * right shit >> used as x >> n the bits of x are shifted right by n positions
 * bitwise NOT ~ used as ~x each bit from x is flipped
 * bitwise AND & used as x&y eah but is set when both corresponding bits in x and y are 1.
 * bitwise OR | used as x|y each but is set when either corresponding bits in x and y are 1.
 * bitwise XOR ^ used as x^y each but is set when either corresponding bits in x and y are different.
 */

/*
 * Uncle Alex recommended to use bitwise operators with unsigned integral operands or std::bitset and I shall follow.
 * Although later when I am feeling rebellious I will try it out (*￣m￣).
 */


#include <concepts>
#include <iostream>
#include <bitset>
#include <type_traits>

int main () {
    std::bitset<4> x{0b1100};

    std::cout << x <<'\n';
    std::cout << (x >> 1) << '\n';  // shifts right by 1 bit
    std::cout << (x << 1) << '\n';  // shifts left by 1 bit
    return 0;
}

/*
 * The code block above prints:
 *
 * 1100
 * 0110
 * 1000
 *
 * Another thing to note, bit shifting in C++ is endian-agnostic. Left-shift is towards the most significant
 * bit and right shift is towards the lest significant bit.
 */

/*
 * Event though we use the same operator for input/output and left/right shift, how does the compiler understand what operation it is supposed
 * to perform? And the answer to that is looking at the operand towards left if operator '<<' has a left operand which is an integral type it performs
 * shift operation and if the left operand is an output stream object for e.g. std::cout it prints the value of the variable.
 * This is called operator overloading.
 *
 * Simple simple right take a look at the code below
 */


#include <iostream>
#include <bitset>
int main () {
    std::bitset<4> x{0b0110};

    std::cout << x << 1 << '\n';
    std::cout << (x << 1) << '\n';
    return 0;
}

/*
 * For the code block above incase the shift operation is not parenthesized << operator gives priority to stream object operand and treats
 * it as a print command so the following gets printed
 * 01101
 * 1100
 */

#include <iostream>
#include <bitset>

int main () {
    std::bitset<4> b4{0b0100};     //b4 is 0100
    std::bitset<8> b8{0b0100};     //b8 is 0000 0100
    
    std::cout << "Initial value:\n";
    std::cout << "Bits: " << b4 << ' ' << b8 << '\n';
    std::cout << "Values: " << b4.to_ulong()<< ' ' << b8.to_ulong() << '\n';
    
    b4 = ~b4;       //flips the bit to 1011
    b8 = ~b8;       //flips the bit to 1111 1011
    
    std::cout << "After BITWISE NOT";
    std::cout << "Bits: " << b4 << ' ' << b8 << '\n';
    std::cout << "Values: " << b4.to_ulong()<< ' ' << b8.to_ulong() << '\n';

    return 0;
}

/*
 * The above will print the following:
 * Initial values:
 * Bits: 0100 00000100
 * Values: 4 4 
 *
 * Initial values:
 * Bits: 1011 11111011
 * Values: 11 251
 * goes without saying that you have to mindful about bitwise operations and be sure what the size of the bitset variable is
 * while performing flip operations
 */

#include <iostream>
#include <bitset>

int main () {
    
    std::cout << (std::bitset<4> {0b0101} | std::bitset<4> {0b0110}) << '\n';
    return 0;
}

/*
 * the code block above prints the xor of bits 0101 and 0110 so the output is 0111
 */


#include <iostream>
#include <bitset>

int main () {
    
    std::cout << (std::bitset<4> {0b0101} & std::bitset<4> {0b0110}) << '\n';
    return 0;
}

/*
 * the code block above prints the AND of bits 0101 and 0110 so the output is 0100
 */


/*
 * And then we arrive to our last operator i.e. Bitwise XOR
 *  0 1 1 0 XOR
 *  0 0 1 1
 *  -------
 *  0 1 0 1
 */

/*
 * There are bitwise assignment operators aswell similar to arithmetic assignment operators,
 * <<=
 * >>=
 * ^=
 * &=
 * |=
 *
 * NOT operator does not have a bitwise assignment operator because it has a unary operand so you cannot do x~=
 * in case we want to flip bits of an object, we can simply do x = ~x;
 */

/*
 * Incase we have short int operands after bitwise operation they are promoted to int or unsigned int, and the result is also an int or
 * unsigned int. In many cases it doesn't matter says Uncle Alex, but let's see.
 */

#include <bitset>
#include <cstdint>
#include <iostream>

int main () {
    std::uint8_t c {0b00001111};

    std::cout << std::bitset<32>(~c) << '\n';      //incorrect prints 11111111111111111111111111110000
    std::cout << std::bitset<32>(c << 6) << '\n';  //incorrect prints 0000000000000000001111000000
    std::uint8_t cneg{ ~c };                            //Error: narrowing conversions from unsigned int to std::uint8_t
    c = ~c;                                             //Possible warning: narrowing conversion from unsigned int to std::uint8_t
    return 0;
}

/*
 * For the codeblock above we have a 8bit integer and we are trying a NOT and left shift operation on a 32 bit integer
 * depending on the compiler you have you get a error for std::uint8_t cneg { ~c } narrowing conversion
 * 
 * the above code block prints wrong values because of narrowing conversions this issue can be solved using static_cast
 */

#include <bitset>
#include <cstdint>
#include <iostream>

int main () {
    std::uint8_t c {0b00001111};

    std::cout << std::bitset<32> (static_cast<uint8_t>(~c)) << '\n';
    std::cout << std::bitset<32> (static_cast<uint8_t>(c << 6)) << '\n';
    std::uint8_t cneg {static_cast<uint8_t>(~c)};
    c = static_cast<uint8_t>(~c);

    return 0;
}

/*
 * The piece of code above prints the following:
 * 00000000000000000000000011110000
 * 0000000000000000000011000000
 * The lines that were previously problematic compiles and warnings this time
 * 
 * So bitwise operators will promote operands with narrower integral types to int or unsinged int.
 * Operator ~ and Operator << are width sensitive and may produce different results depending on the width
 * of the operand. static_cast the result of such operations to ensure correct results.
 *
 * But since "THE PEOPLE ARE RETARDED (*￣m￣)" it is best to not use these operators on something that is smaller than int
 */



