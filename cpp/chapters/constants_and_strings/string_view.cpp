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
