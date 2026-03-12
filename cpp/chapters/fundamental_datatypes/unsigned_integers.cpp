/*
 * A byte if unsigned integer has a range from 0 to 255. Compare this to the 1-byte sgined intger it ranges b/w -128 to 127
 */

unsigned short us;              //ranges from 0 to 255
unsigned int ui;                //ranges from 0 to 65,535
unsigned long ul;               //ranges from 0 to 4,294,967,295
unsigned long long ull;         //ranges from 0 to 18,446,744,073,709,551,

//Given above is how you declare and initialize an unsinged integer in C++

#include <iostream>
int main () {
    unsigned short check = 65537;
    std::cout << check;
    return 0;
}

/*
 * Now from what I understood unsinged integer overflow is a bit trickey
 * the source that I studied from states that the source that they studided from listed that it is "impossible" for an overflow
 * when it comes to an unsigned integer but they differed that with the example above
 * for unsigned short int check with a value 65537 their copiler returned 65537 % 65535 = 1 (since it ranges from 0 to 635535)
 *
 * Now to me this looks like an overflow same as the author of my references. FUCK YOU C++ standards (╯°□°)╯︵ ┻━┻.
 *
 * NOTE: The behaviour above also depends on the compiler and OS that you are using :D(great!!)
 */

/*
 * So as a result of the bahviour listed above a lot of bugs happened in vedio games because of wrapping around
 * In arcade game Donkey Kong its not possible to go past level 22 due to an overflow bug that leaves the user with enough
 * bonus time to complete the level.
 *
 * In PC game civilisation, Gandhi was know for often being the first one to use nuclear weapons, which seems contrary to his expected
 * passive nature(not so AHINSAK after all). Player's theorized that Gandhi's aggression setting was intially 1 but if he chose a democractic
 * government, he'd get a -2 aggression modifer(lowering his current aggression value by 2). This would cause his aggression to overflow to
 * 255, making him maximally agressive(this is fucking beautiful HAHA xD)! But this wasn't the case according to game's author(surely).
 */

int main1 () {
    unsigned int x{2};
    unsigned int y{3};
    std::cout << x - y;
    return 0;
}

/*
 * Now because of behaviours listed above it developers generally avoid using unsinged ints because they can easily overflow.
 * Take a look at the example above it prints -1?
 * WROOOOOOOOONG
 * It prints 4294967295 why because of modulo operation -1 undergoes a modulo operation and gives that result
 *
 * NOTE: This is a note to self please don't use unsinged ints if you for a fact know what you are working will be in a certain range
 * and the integers are positive
 */

int main3 () {
    unsigned int u{3};
    unsigned int s{3};
    std::cout << u - s << '\n';
    return 0;
}

/*
 * Some would expect the above to print correct because atleast one of them is a signed into
 * WRONG AGAIN :D
 * since u is unsinged s get's type converted to unsigned which makes the result -1 getting treated 
 * as unsinged and causes an overflow hence UB
 */

int main4 () {
    signed int s {-1};
    unsigned int u {1};
    
    if (u < s){
        std::cout << "-1 is greater that 1";
    }
    else{
        std::cout << "1 is greater than -1";
    }
    return 0;
}

/*
 * So what get's printed
 * "-1 is greater than 1"
 * Because it implicitly converts s into an unsinged integer making it wrap with 4294967295 which is greater than 1
 * hence if condition gets printed
 * learn C++ they said
 * it will be fun they said
 * 3 days in and it is not fun :(
 */



