/*In C++ we typically work with "byte-sized" chunks of data
 * What does you mean typically?
 * My assumption is that it depends on the operating system or the archicture that you are working on but who knows ¯\_(ツ)_/¯
 */

/*
 * In mathematics an "integer" is a number with no decimal can and ranges between -inf to +inf. The term "integral"
 * has different meanings and interpretations however in the context of C++ it means "like an integer"
 * I don't why that is the case fucking Socrates of Computer Science¯\_(ツ)_/¯
 * 
 * The standard integer types are short, int, long, long long(including there signed and unsigned variants)
 * The integral types are bool, various char types, and the standard integer types.
 */

/*
 * C++ contains three sets of types:
 *  "fundamental data types"
 *  "compound data types"
 *  "types provided by C++ standard library."
 *
 * NOTE: Many of the types in newer versions of C++ for eg.(std::nullptr_t) uses a _t suffix which means "type" 
 * If there is a suffix with _t its most probably a type(nothing is guaranteed :D) but there are instances where
 * types don't have a suffix _t with them.
 */

/*
 * Void is the easiest of types it means "NOTHING"
 * Void is an example of such types. An incomplete type is a type that has been declared but not defined.
 * So the compiler knows it exists but doesn't have enough information to determine how much memory to allocate for objects of type Void
 */

void value; //won't work, variables can't be defined with incomplete void type

#include <iostream>
int get_void(void){
    int x;
    std::cin>>x;
    return x;
}

/*
 * In C void is used as func parameters indicating that function does take any parameters
 * although this will compile in C++(for backwards compatibility) this use is considered deprecated
 * you can simply do get_void() in order to indicate a func does not take any params
 * empty func params for example get_value() is an implicit void
 */
