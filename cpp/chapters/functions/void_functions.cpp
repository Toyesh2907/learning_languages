#include <iostream>
void foo(){
    std::cout << "There goes foo!";
}

int main () {
    foo();
    return 0;
}

/*
 * The code block has a void function; what does that mean?
 * A void returns nothing it returns to its caller after execting the code inside it
 * techincall you can do return; but that is the same not writing it at all so save some lines :D
 */

int main1 () {
    std::cout<<"What happened to foo?"<< foo();
    return 0;
}

/*
 * The above piece of code is not legal as you cannot make void function call in an expression
 * if foo() was returning a str::string "There goes foo!" it would have worked
 */

