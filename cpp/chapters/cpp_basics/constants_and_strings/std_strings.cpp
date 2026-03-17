#include <iostream>
#include <istream>
#include <string>
int main () {
    std::string name {};
    name = "test_string";
    return 0;
}

/*
 * For the code block above C++ provides std::string which is a class instead of a type
 * Why don't we use strings as we used in C, incase we use more space than the alloted bits undefined
 * behaviour fucks you in the ass.
 *
 * We also have std::string_view which was introduced in C++17
 * in order to use strings we need <string> header
 */

#include <iostream>
#include <string>
int main () {
    std::string empty_string {};
    std::cout << '[' << empty_string << ']';

    return 0;
}

/*
 * The code block above will print:
 * [] i.e empty strings print nothing
 */

#include <iostream>
#include <string>

int main () {
    std::string test_string {" Alex "};
    std::cout << test_string << '\n';

    test_string = "Jason";
    std::cout << test_string << '\n';
    
    test_string = "Jay";
    std::cout << test_string << '\n';

    return 0;
}

/*
 * The code block above prints:
 * Alex
 * Jason
 * Jay
 * That means it can store strings of different lengths
 * incase std::string runs out of memory to store a string it gets more during runtime
 * using a form of dynamic memory allocation(wdym form of??)
 */

#include <iostream>
#include <string>

int main () {
    std::string name;
    std::cout << "Enter your name: ";
    std::cin >> name;

    std::cout << "Enter your favorite colour: ";
    std::string colour {};
    std::cin >> colour;

    return 0;
}

/*
 * For the code block above
 * Let's say you enter "John Doe" for Enter your name
 * cin does not read trailing whitespaces so John is taken as the valid input and \nDoe is
 * saved in the buffer for next extraction
 * So how do you handle this?
 * We use std::getline method
 */

#include <iostream>
#include <string>

int main () {
    std::cout << "Enter your full name";
    std::string name {};
    std::getline(std::cin >> std::ws, name);

    std::cout << "Enter your favorite colour: ";
    std::string colour {};
    std::getline(std::cin >> std::ws, colour);

    std::cout << "Your name is " << name << " and your favorite colour is " << colour << '\n';
    return 0;
}

/*
 * For the code block above it can now take strings with whitespaces like "John Doe"
 * What is std::ws?
 * We have used something similar to this they are called output and input manipulators
 * An example of this is std::setprecision that allows you to manipulate output for floating points
 * Similarly std::ws is a input manipulater std::ws tells std::cin to ignore any whitespaces before extraction.
 * 
 * As uncle ALEX said incase you are reading strings use std::ws along with std::getline
 * if you don't want to deal with shitty errors.
 * (˶ᵔ ᵕ ᵔ˶)ゞ
 */

#include <iostream>
#include <string>

int main () {
    std::string name { "Baazy" };
    std::cout << name << "has " << name.length() << " characters\n";

    return 0;
}

/*
 * std::string comes with a length method that allows to find the number of characters a string has
 * The above piece of code prints:
 * Baazy has 5 characters
 *
 * Above is an example of a member function instead of doing func(obj) we do obj.func()
 */


#include <iostream>
#include <string>

int main () {
    std::string name { "Baazy" };
    std::cout << name << " has " << std::size(name) << "characters\n";
    return 0;
}

/*
 * We can also use std::size function to get the length of a std::string as a large signed integral
 * type std::ptrdiff_t
 *
 * Since std::ptrdiff_t may be larger than an int so it's better to static_cast it to int
 *
 * int len { static_cast<int>(std::size(name)) };
 */

/*
 * When a std::string is passed to a function by value, the std::string func param must be
 * initialized and initialized with the argument. This results in an expensive copy.
 *
 * Best practice according to uncle Alex:
 * Do not pass std::string by value to func params
 */

/*
 *You would expect that since its expensive to call func params using std::string
 * returning them would be the same however it is not really the case
 * and its generally a rule of thumb to return std::string by value when the expression
 * of the return statements resolves to any of the following:
 * - A local variable of type std::string
 * - A std::string that has been returned by value from another func call or operator
 * - A std::string temporary that is created as part of the return statement
 *
 * And the reason for that is std::string supports a capability called move semantics
 * So what is move semantics?
 * Move semantics allows an object that will be destroyed at the end of the function
 * to instead be returned by value without making a copy.
 * Prett neat imo
 *
 * in certain cases std::string may also be returned by const reference, which is another way to avoid making a copy.
 */

#include <iostream>
#include <string>

int main () {
    using namespace std::string_literals;

    std::cout << "foo\n";       // no suffix is a C-styled string literal
    std::cout << "foo_bar\n"s;  // s suffix is a std::string literal

    return 0;
}

/*
 * "Hello"s resolves to std::string { "Hello", 5 }, this creates a temporary std::string initialized
 * with C-style string literal "Hello"
 */


/*
 * You cannot use constexpr for std::string as it is only compatible with very limited cases in C++20/23
 * and for that we need std::string_view
 */
