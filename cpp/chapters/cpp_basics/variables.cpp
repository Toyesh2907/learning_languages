//Introduction to variables

/*
int x; defines a varible named x (of type int)
At compile time, the compiler makes a note to itself that we want a variable with the name 'x', and that variable has data type int.
The compiler also handles how much memory to allocate for every datatype
| Data Type       | Typical Size (bytes)          | Notes                     |
| --------------- | ----------------------------- | ------------------------- |
| `bool`          | 1                             | True/false                |
| `char`          | 1                             | Always 1 byte             |
| `signed char`   | 1                             |                           |
| `unsigned char` | 1                             |                           |
| `short`         | 2                             | At least 16 bits          |
| `int`           | 4                             | Usually 32 bits           |
| `unsigned int`  | 4                             |                           |
| `long`          | 8 (Linux/macOS) / 4 (Windows) | Platform dependent        |
| `unsigned long` | 8 / 4                         | Platform dependent        |
| `long long`     | 8                             | At least 64 bits          |
| `float`         | 4                             | IEEE 754 single precision |
| `double`        | 8                             | IEEE 754 double precision |
| `long double`   | 8, 12, or 16                  | Compiler dependent        |
| `wchar_t`       | 2 (Windows) / 4 (Linux)       | Platform dependent        |
| `char16_t`      | 2                             | UTF-16                    |
| `char32_t`      | 4                             | UTF-32                    |
| `void`          | —                             | No storage                |

Quick Rule of Thumb (64-bit Linux/macOS)
int → 4 bytes
long → 8 bytes
long long → 8 bytes
double → 8 bytes

C++ also allows you to make your own datatypes

*/

int main () {
  int x; //definition of variable x
  
  
  int a, b; //defining multiple variables of the same type
  int a, int b; //gives a compiler error
  int a, double b; //gives a compiler error
  int a; int b; //correct but not recommended becase of code readability

  int this_var; // variable declaration
  this_var = 5; // variable initialization character '=' is used for initialization
  
  int foo {5}; //defines a varible foo and initializes with initial value of 5 { } is the initializer which initializes a variable with a value
  int a;         // default-initialization (no initializer)

  // Traditional initialization forms:
  int b = 5;     // copy-initialization (initial value after equals sign)
  int c ( 6 );   // direct-initialization (initial value in parenthesis)

  // Modern initialization forms (preferred):
  int d { 7 };   // direct-list-initialization (initial value in braces)
  int e {};      // value-initialization (empty braces)
                 //
  int width { 5 };    // direct-list-initialization of initial value 5 into variable width (preferred)
  int height = { 6 }; // copy-list-initialization of initial value 6 into variable height (rarely used)

  int width {}; // value-initialization / zero-initialization to value 0

  return 0;
}


  
  /*
  In C++ incase a variable is initialized and not used it throws an error saying variable initialzed but not used
  To address such cases, C++17 introduced the [[maybe_unused]] attribute, which allows us to tell the compiler that we’re okay with a variable being unused. The compiler will not generate unused variable warnings for such variables.

The following program should generate no warnings/errors:

Additionally, the compiler will likely optimize these variables out of the program, so they have no performance impact.

The [[maybe_unused]] attribute should only be applied selectively to variables that have a specific and legitimate reason for being unused (e.g. because you need a list of named values, but which specific values are actually used in a given program may vary). Otherwise, unused variables should be removed from the program.
  */


#include <iostream>

int main1()
{
    [[maybe_unused]] double pi { 3.14159 };  // Don't complain if pi is unused
    [[maybe_unused]] double gravity { 9.8 }; // Don't complain if gravity is unused
    [[maybe_unused]] double phi { 1.61803 }; // Don't complain if phi is unused

    std::cout << pi << '\n';
    std::cout << phi << '\n';

    // The compiler will no longer warn about gravity not being used

    return 0;
}



