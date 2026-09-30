//This is completely optional according to uncle Alex, but might aswell learn it cause why the fuck not ¯\_(ツ)_/¯.
/*
 * Why might somebody need manipulation?
 * For example a byte has 8 bits let's say a bool value is being stored it will occupy 8 bits but since
 * a bool is essentially 0 or 1 having extra bits there is a bit wasteful(pun intended) so we can use a single byte contain 8 different bool value
 * saves space however this might is too much work most of the time since we are not living in poor times.
 *
 * Bit manipulation is helpful in cases like graphics, encryption, compression, optimization, but not as much in general programming.
 * Hence the chapter is optional.
 */

/*
 * A bit holding value 0 is said to be "false", "off" and "not set" and vice-versa for when it's 1
 * When the value of a bit changes from 0 to 1 or 1 to 0 it is said to be flipped.
 */

#include <bitset>
#include <iterator>

int main () {
    std::bitset<8> mybitset{};
    return 0;
}

/*
 * For the code block above mybitset has room for 8 flags so it can essentially contain 8 boolean values
 * Also bit manipulation is one of the times when we should be using unsigned integers or std::bitset
 */

/*
 * This goes without saying for the following bit sequence:
 * 0 0 0 0 0 1 0 1
 * 7 6 5 4 3 2 1 0 <- bit sequence
 * */

#include <bitset>
#include <iostream>
int main () {
    std::bitset<8> bits{0b0000'0101};  // we need 8 bits start with bit pattern 0000 0101
    bits.set(3);                       // set the bit position 3 to 1 (now we have 0000 1101)
    bits.flip(4);                      // flip the bit 4 now we have (0001 1101)
    bits.reset(4);                     // set bit 4 back to 0 (now we have 0000 1101)
    
    std::cout << "All the bits: " << bits << '\n';
    std::cout << "Bit 3 has value: " << bits.test(3) << '\n';
    std::cout << "Bit 4 has value: " << bits.test(4) << '\n';

    return 0;
}
/*
 * For the code block aobve it prints the following
 *
 *    All the bits: 00001101
 *    Bit 3 has value: 1
 *    Bit 4 has value: 0
 *    Giving our bits names can help our code be more readable
 */

#include <bitset>
#include <iostream>
int main () {
    [[maybe_unused]] constexpr int is_hungry {0};
    [[maybe_unused]] constexpr int is_sad {1};
    [[maybe_unused]] constexpr int is_mad {2};
    [[maybe_unused]] constexpr int is_happy {3};
    [[maybe_unused]] constexpr int is_laughing {4};
    [[maybe_unused]] constexpr int is_asleep {5};
    [[maybe_unused]] constexpr int is_dead {6};
    [[maybe_unused]] constexpr int is_crying {7};

    std::bitset<8> me{0b0000'0101};
    me.set(is_happy);
    me.flip(is_laughing);
    me.reset(is_laughing);

    std::cout << "All the bits: " << me << '\n';
    std::cout << "I am happy: " << me.test(is_happy) << '\n';
    std::cout << "I am is_laughing: " << me.test(is_laughing) << '\n';

    return 0;
}

/*
 * std::bitset is optimized for speed not memory saving. The size of a std::bitset is typically the number of bytes needed to hold the bits, round up the
 * nearest sizeof(size_t), which is 4 bytes on a 32-bit machine, and 8 bytes on a 64 bit machine.
 *
 * Thus, a std::bitset<8> will typically use either 4 or 8 bytes not 1 byte even though it only needs 1 byte to store 8 bits.
 * So according to uncle Alex std::bitset is most useful when we desire convenience, not memory saving.
 */

/*
 * Querying std::bitset
 * size() returns the number of bits in bitset.
 * count() returns the number of bits in the bitset that are set to true.
 * all() returns a boolean indicating whether all bits are set to true.
 * any() returns a boolean indicating whether any bits is set to true.
 * none() returns a boolean indicating whether no bits are set to true
 */
