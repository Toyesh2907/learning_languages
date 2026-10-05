#include <iostream>

int main () {
    int apples { 5 };

    {
        std::cout << apples << '\n';
        
        int apples { 0 };
        std::cout << apples << '\n';

        apples = 10;
        std::cout << '\n';
    }
    std::cout << apples << '\n';
    
    return 0;
}
/*
 * The code block above prints the following
 * 5
 * 10
 * 5
 * At first since there is only one declaration of the variable apples it prints 5. Later there are two definitions of the variable
 * apples so inside the codeblock the local variable is preffered over the global variable and it is tempraroly hidden. This is called
 * name hiding or shadowing.
 */

//Shadowing of global variables

#include <iostream>

int value { 5 };

void foo(){
    std::cout << "global variable value" << value << '\n';
}

int main () {

    int value { 7 };
    ++value;
    std::cout << "local variable value: " << value << '\n';
    foo();
    
    return 0;
}

/*
 * The above piece of code prints:
 * local variable value: 8
 * global variable value: 5
 * because when the main func is ran it hides the global variable value and uses the value variable which is local to it
 * when foo is called since it doesn't have a local variable called values it uses the global variable called value.
 */

/*
 * Variable shadowing should be avoided. Why? Pretty self explanatory. What kind of a fucking lazy prick are you if you can't think of a second
 * name for a variable add a prefix or a suffix and make life easier and stop letting compiler dictate your logic.
 *
 * GCC also has a flag called -Wshadow that will generate a warning if a variable is shadowed. There are several subvariants of this flag.
 * -Wshadow=global, -Wshadow=local abd -Wshadow=compatible-local.
 */
