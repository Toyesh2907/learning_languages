/*
 * In order to perform bitwise operations on specific bits we need a mask because we can't perform operations
 * on bit positions. A bit mask is a predefined set of bits that is used to select spcific bits which will be uppdated.
 *
 * Why is it important let's say you have hired a painter with cerebral palsy or parkinsons and if you are unlucky they have both.
 * If you instruct him to paint the windows he is most likely to paint the walls aswell. So you apply a guard so that inclusive painter has less room
 * for error. Same way you apply a bit mask to prevent bitwise operations from not touching unintended bits.
 *
 * So let's say your cowerker Barry who does not how to do bitwise operations properly doesn't accidently dumps your core (˶ᵔ ᵕ ᵔ˶)ゞ.
 */

#include <cstdint>

constexpr std::uint8_t mask0{ 0b0000'0001 }; // represents bit 0
constexpr std::uint8_t mask1{ 0b0000'0010 }; // represents bit 1
constexpr std::uint8_t mask2{ 0b0000'0100 }; // represents bit 2
constexpr std::uint8_t mask3{ 0b0000'1000 }; // represents bit 3
constexpr std::uint8_t mask4{ 0b0001'0000 }; // represents bit 4
constexpr std::uint8_t mask5{ 0b0010'0000 }; // represents bit 5
constexpr std::uint8_t mask6{ 0b0100'0000 }; // represents bit 6
constexpr std::uint8_t mask7{ 0b1000'0000 }; // represents bit 7

/*
 * Simplest way of creating a mask for each bit position is to define one bit mask for each bit position. 1s define the bits
 * that we want to modify.
 * Above is how you can define bit masks in C++14
 * Now that is completly different case for C++11 because it doesn't support binary literals, so we have to use other methods to
 * set symbolic constants. There are two goods methods:
 * Use hexadecimal literals:Code blocks given below explains how that can be done
 * I am not gonna be bothering writing 4 bit representation of hexadecimal
 */

constexpr std::uint8_t mask0{ 0x01 }; // hex for 0000 0001
constexpr std::uint8_t mask1{ 0x02 }; // hex for 0000 0010
constexpr std::uint8_t mask2{ 0x04 }; // hex for 0000 0100
constexpr std::uint8_t mask3{ 0x08 }; // hex for 0000 1000
constexpr std::uint8_t mask4{ 0x10 }; // hex for 0001 0000
constexpr std::uint8_t mask5{ 0x20 }; // hex for 0010 0000
constexpr std::uint8_t mask6{ 0x40 }; // hex for 0100 0000
constexpr std::uint8_t mask7{ 0x80 }; // hex for 1000 0000
                                      //
/*
 * The code block above is how bit masks can be formed for C++11 versions
 */
