#include <iostream>
#include <string>
int main () {
    int x { 5 };
    std::cout << x << '\n';

    std::string name { "name" };
    std::cout << name << '\n';

    return 0;
}

/*
 *The code above uses the copy constructor to intialize a variable int x with a value 5
  * So what's happening in this case is it's copying the value 5 into the memory that was allocated
  * to the variable x.
  * Now copying and intializing a variable is fast but this becomes slow for name which is std::string
  * so for initiliaztion an instance of the name is created and then string literal is copied to the memory alloted for
  * str:string name and all we are doing is creating a std::string and printing it and then its destroyed
  */

#include <iostream>
#include <string>

void print_string(std::string str){
    std::cout << str << '\n';
}

int main () {
    std::string s { "foo bar" };
    print_string(s);
    return 0;
}

/*
 * for the code block above there will be two copies of std::string name made once during initiliaztion
 * and once when it passed to the func parameter making it even slower
 *
 * So to handle the above std::string_view was introduced it provides read only access to an existing string
 * (whether it be Cstring, std::string, or another std::string_view) without making a copy of it. It is only used when
 * you want to read the value of a string but not modify it.
 */

#include <iostream>
#include <string_view>

void printSV(std::string_view str)
{
    std::cout << str << '\n';
}

int main()
{
    std::string_view s{ "Hello, world!" };
    printSV(s);

    return 0;
}

/*
 * According to uncle Alex: It's best to use std::string_view if you want
 * read only strings for func parameters
 */

#include <iostream>
#include <string_view>

int main () {
    std::string_view s1 { "BaazY" };
    
    std::string s2 { "Baazy" };
    
    std::string_view s3 { s1 };
    return 0;
}

/*
 * std::string_view are pretty flexible and can be initialized using a Cstring, std::string
 * std::string_view
 *
 * In std::string_view is being used as a func param and a Cstring or a std::string is passed
 * an implcit conversion happens from the string type entered to std::string_view
 *
 * But the converse is not true for std::string
 * std::string does not implcit cast to std::string_view because copies of std::strings are already expensive
 * However explcit casting is possible using static_cast and it is possible to create a std::string with
 * std::string_view since this will rarely be done unintentionally(The world is not all smart uncle Alex)
 * as shown bellow
 */


#include <iostream>
#include <string_view>
#include <string>

void print_something(std:: string str){
    std::cout << str << '\n';
}

int main () {
    std::string_view sv{ "Baazy" };

    std::string s { sv };
    print_something(s);

    print_something(static_cast<std::string>(sv));

    return 0;
}


#include <iostream>
#include <string_view>

int main () {
    std::string_view { "Alex" };
    std::string_view sv { name };
    std::cout << sv << '\n';

    sv = "John";
    std::cout << sv << '\n';
    std::cout << name << '\n';

    return 0;
}

/*
 * The code above prints:
 * Alex
 * John
 * Alex
 * std::string_view when reassigned views the new string instead of the std::string instance
 * and does modify the prior string beind viewed anyway
 */

#include <iostream>
#include <string>
#include <string_view>

int main () {
    using namespace std::string_literals;
    using namespace std::string_view_literals;

    std::cout << "foo\n";           //Cstring literal
    std::cout << "goo\n"s;          //std::string literal
    std::cout << "boo\n"sv;         //std::string_view literal
    return 0;
}

/*
 * It is fine to initialize std::string_view with a C-style string literal.
 * initializing a std::string_view using a std::string_view literal won't cause problems
 * (according to uncle Alex such literals are actually Cstring literals in disguise).
 */

#include <iostream>
#include <string_view>

int main () {
    constexpr std::string_view s { "Baazy" };
    std::cout << s << '\n';
    
    return 0;
}

/*
 * Unlike std::string constexpr can be used for std::string_view
 * for piece of code above s is replaced by "Baazy" at compile time
 */
