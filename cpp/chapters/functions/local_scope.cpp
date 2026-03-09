int global_foo = 5;

int foo_bar(int a, int b){
    int foo_bar_local_summation = a + b + global_foo;
    return foo_bar_local_summation;
}

int main (){
    int main_local = foo_bar(2,3 );
    return 0;
}

/*
 * The code block above talks about scoping of variable
 * global_foo can be accessed by both foo_bar and main since its initialised at a global scope
 * while foo_bar_local_summation and main_local can only be accessed by their respective functions
 * The local vairables only live until the function is running once the function is done executing they are destroyed
 * There lifetime starts at initialization and ends when the function finishes execution
 */
