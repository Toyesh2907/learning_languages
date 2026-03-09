/*
 * Unline other languages C/C++ does not automatically assign a value to a variable for example 0.
 * When a variable that is not initialized is given a memory address to store data, The value of that variable is whatever value
 * is present in that memory space at that time(often called as garbage value)
 *
 * This lack of initialization is performance optimization was inhertited from C, back when everyone was working potatoes
 * lets say a program has 100,000 variables if all of them are initialized at the start its going to make your
 * computer cry :..( but now there is close to no gain in using this practice because systems nowdays are strong
 * which makes a lot of programmers write suboptimal code(Call of Duty devs trying not to make a game that takes 500GBs)
 */

#include <iostream>
int main () {
    int x;
    std :: cout << x; // try gambling on what this would print
    return 0;
}

/*
 * the code block above can print whatever is in the memory location where x is kept
 * The behaviour listed above is called UndefinedBehaviour i.e we don't know WTF is going to happen ¯\_(ツ)_/¯
 * The following are behavious that can be listed as UB
   - Your program produces different results every time it is run.
   - Your program consistently produces the same incorrect result.
   - Your program behaves inconsistently (sometimes produces the correct result, sometimes not).
   - Your program seems like it’s working but produces incorrect results later in the program.
   - Your program crashes, either immediately or later.
   - Your program works on some compilers but not others.
   - Your program works until you change some other seemingly unrelated code. 
 * So try to avoid these situations!!
 */

