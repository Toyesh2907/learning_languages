/* In order to use IO in cpp iostream library is needed io -> input output;
 * pretty slef explantory std :: cout prints stuff on the terminal std :: cin >>
 * takes a user input
 */

#include <iostream>
int main() {
    std ::cout << "prints stuff" << std ::endl;
    int foo;
    std ::cin >> foo;
    std ::cout << foo;
    return 0;
}
/*
 * The code block above prints stuff on terminal and takes an input for the
 * variable foo You can also print a variable directly as shown above
 * '<<' is called the insertion operator; why is it called that? because it
 * inserts data into stream in the code block above std :: cout is an output
 * stream object
 *
 * std :: endl is used to add another line after an output stream
 *
 * std :: cout is bufferd. What does that mean?
 * the data that is supposed to be displayed on screen is first stored in a
 * specific region in a memory called buffer after the data is displayed from
 * the buffer the buffer is fluhsed .
 *
 * A disgusting analogy would be your food is
 * collected in your stomach and later shit out by: <redacted incase somebody
 * visits this repo>.
 */

int main1() {
    std :: cout << "some stuff" << std :: endl;
    std :: cout << "some stuff2" << '\n';
    return 0;
}


/*
 * For the code block above both adds a new line however std :: endl is a bit slow because it flushes the data present in the buffer.
 * So if there are multiple lines in a piece of code which are printing stuff on the terminal if we have std :: endl';
 * It will clear the buffer every time and add a new line aswell
 * So you can add a new line with new line char i.e '\n'
 * 
 * In c++ single characters are represeted by 'c' in the code bloch '\n' contains two characters but works because
 * It is treated by the compiler as a single LineFeed(LF) 
 *
 * And you guessed it std::cin is also buffered
 */


int main2(){
    int x {};
    std :: cin >> x;
    std :: cout << x;
    return 0;
}

/*
 * For the code block above let's say you enter something that is not an int.
 *
 * incase input = 'c' 0 is printed on the terminal because 
 * c\n is added to buffer and c is a character and it cannot be extracted so x is initialized as 0
 *
 * incase input = "ab" 5a\n is added to the buffer 5 will be extracted converted to an integer and assigned to x
 * a\n will be left in the buffer for next extraction
 *
 * incase the input is 3.2 3.2\n is added to the buffer 3 is extracted and .2 remains in the buffer
 */ 
