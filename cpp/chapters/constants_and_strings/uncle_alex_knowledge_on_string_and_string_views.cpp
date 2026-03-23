//Yeah I know I could have come with a better name for the file pretty retarded

/*
 *
 * Uncle Alex's Analogy for Owners and viewers:
 * Let's say I want you want to pain a picture of bicycle but you don't own a bicycle
 * What will you do?
 * Steal? Buy one? Maybe renting one makes sense
 * Let's not try to steal anything and be upstanding citizens; let's say you go to a store and
 * buy a bike. Benifits: you have a bike that you can ride. Your bike will always be available when you want.
 * You can decorate it move it wherever you want.Now comes the downsides. Bicycles are expensive.
 * and you have to bare the responsiblity for it i.e maintainance and desposing off it if not needed anymore.
 *
 * Ownership can be expensive. As an owner, it is your responsiblity to acquire, manage and properly dispose of the objects
 * you own.
 *
 * On your way out of the house, you glance out of your window front. You notice that your neighbour has
 * parked their bike across from your window. You could just paint of your neighbour's bike. This way you
 * don't have to bother about buying a bike, maintainance and disposal of the bike. When you are done viewing
 * you can close your curtains, this ends your view of the object and you can about your business. There are potential
 * downsides to this aswell. You can't paint or customize your neighbour's bike. And while you are viewing the bike, your
 * neighbour may decide to change the way bike looks, or move it out of your view altogether. You may end up with a view of something
 * unexpected instead.
 *
 * Viewing is expensive. As a viewer, you no responsiblity for the objects you are viewing, but you have no control over those objects.
 *
 * std::string is a (sole) owner
 *
 * So why does std::string make an expensive copy everytime an object is created/instantiated
 * a piece of memory is allocated in order for that object to store whatever data it needs to use through its lifetime.
 * This memory is reserved for object, and guaranteed to exist for as long as the object does.
 * These objects store the initialization value in the memory alloted for them for manipulation later.
 *
 * Let's take a look at the example from string_view.cpp
 */

#include <iostream>
#include <print>
#include <string>

void print_something(std::string str){
    std::cout << str << "\n";
}

int main () {
    std::string s { "Baazy" };
    print_something(s);

    return 0;
}

/*
 * for the codeblock above when print_something is called with s str makes a copy of s. The function prints the string
 * and destroys it. Pretty expensive if you only want to print a string.
 *
 * Now s is already holding the string that we want to print, couldn't we just use the string that s is holding instead of making a copy?
 * The answer is possibly -- There are three criteria we need to assess:
 * 
 * Could s be destroyed while str is still using it? No, str dies at the end of the func, and s exists in the scope of the caller and can't be destroyed
 * before the function returns
 *
 * Could s be modified while str is still using it? No, str dies at the end of the function, and the caller has no oppurtunity to modify the s before the
 * function returns.
 *
 * Does str modify the string in some way that the caller would not expect?No, the function does not modify the string at all.
 *
 * Since all three above are false, there is no risk in using the string that s is holding instead of making a copy.
 * And since string copies are expensive. why pay for one that we don't need.
 */

/*
 * std::string is a viewer, instead of undergoing an expensive copy of std::string we can have an expensive
 * look at the string s.
 *
 * A view is dependent on the object that is being viewed while viewing if the object is changed while it is being
 * viewed unexpected or undefined behaviour will result.
 *
 * A std::string_view that is viewing a string that has been destroyed is sometimes called a dangling view.
 *
 * It is best used as a read-only func param
 */

#include <iostream>
#include <string>
#include <string_view>

void print_something(std::string_view str){ // now a std::string_view, creates a view of the argument
    std::cout << str << '\n';
}

int main () {
    print_something("Baazy");             //call with C-style string literal

    std::string s2 { "Baazy" };
    std::print(s2);                 // call with std::string

    std::string_view s3 { "Baazy" };
    std::print(s3);                 //call with std::string_view

    return 0;
}

/*
 * According to uncle Alex it is better to use std::string_view instead of passing the reference to the string
 * like str::string& reason unexplained and will be told later
 */

#include <iostream>
#include <string>
#include <string_view>

int main()
{
    std::string_view sv{};

    { // create a nested block
        std::string s{ "Hello, world!" }; // create a std::string local to this nested block
        sv = s; // sv is now viewing s
    } // s is destroyed here, so sv is now viewing an invalid string

    std::cout << sv << '\n'; // undefined behavior

    return 0;
}

/*
 * For the codeblock above the scope of s is inside the nested {} block it get's destroyed as the block ends
 * so during cout of sv we are viewing an invalid object so undefined behaviour happens.
 *
 * Another similar issue is listed below
 */

#include <iostream>
#include <string>
#include <string_view>

std::string get_name(){
    std::string name { "Alex" };
    return name;
}

int main () {
    std::string_view name { get_name() };
    std::cout << name << '\n';
    return 0;
}

/*
 * The codeblock above has UB aswell since the scope of std::string name is inside the func get_name and return values are temp
 * objects that are destroyed at the end of full expression containing the func call. We must either use this return value immediatly,
 * or copy it to use later. But since std::string_view creates a view for the object and the object is destroyed that leaves
 * std::string_view dangling
 */

#include <iostream>
#include <string>
#include <string_view>

int main (int argc, char *argv[]) {
    using namespace std::string_literals;
    std::string_view name { "Baazy"s };// Create's a temporary std::string
    std::cout << name << '\n';
    return 0;
}

/*
 * A std::string literaly creatd via the s literal suffix creates a temp std::string object. So in this case, "Alex" creates
 * a temp std::string, which we then use as the initializer for name. At this point, name is viewing the temporary std::string. Then
 * the temp std::string is destroyed, leaving name dangling. We get undefined behvaiour when we use name.
 *
 * Bro that piece of code looked so innocent I can feel my dumbass using that someday (*￣m￣).
 *
 * So according to uncle Alex don't use std::string literals for initialization of std::string_view as they leave them dangling
 *
 * It is okay to initialize it using a C-style string literal, C-style string object, std::string_view literal, std::string_view object
 * and std::string object but not std::string literal, as long as the object outlives the view
 */

#include <iostream>
#include <string>
#include <string_view>

int main (int argc, char *argv[]) {
    std::string s { "Baazy" };
    std::string_view sv {s}; // sv viewing s

    s = "Baazy Man!"; // s modifed
    std::cout << sv << '\n'; //UB

    return 0;
}

/*
 *
 * For the code block above we have sv viewing s and later it is updated to "BaazyMan" from "Baazy"
 * any string views to s are likely to be invalidated after any modification
 *
 * If the std::string reallocates memory in order to accommodate the new string data,
 * it will return the memory used for the old string data back to the operating system.
 * Since the std::string_view is still viewing the old string data, it is now dangling (pointing to a now-invalid object).
 *
* If the std::string does not reallocate memory, it will copy the new string data over the old string data (starting at the same memory address).
* The std::string_view will now be viewing the new string data (since it was placed at the same memory address as it was viewing),
* but it will not realize that the length of the std::string has probably changed.
* If the new string is longer than the old string, the std::string_view will now be viewing a substring of the new string (of the same length as the old string).
* If the new string is shorter than the old string, the std::string_view will now be viewing a superstring of the new string (consisting of the entire new string,
* plus whatever garbage characters are still in the memory beyond the end of the string).
*
* They can be revalidated by making them view the new string after the update
*/

#include <iostream>
#include <string>
#include <string_view>

int main (int argc, char *argv[]) {
    std::string_view str { "Peach" };
    std::cout << str << '\n';

    str.remove_prefix(1);
    std::cout << str << '\n';

    str.remove_suffix(2);
    std::cout << str << '\n';

    str = "Peach";
    std::cout << str << '\n';

    return 0;
}

/*
 * The code block above prints:
 * Peach
 * each
 * ea
 * Peach
 *
 * remove_prefix removes n characters from left side of the view and remove_suffix removes n characters
 * from right end of the string
 *
 * It's like putting curtains to the string
 */

/*
 * The ability to view sub-strings come with one consequence of a std::string-view may or may not be null terminated.
 *
 * Consider the string "snowball", which is null terminated as all C-style string literals are always null terminated.
 * If a std::string_view views the whole string, then it is viewing a null terminated string. However, if std::string_view is only
 * viewing the substring "now", the that substring is not null terminated(the next character is 'b').
 *
 * C-style string literals and std::strings are always null terminated
 * So don't write any code that assumes that std::string_view is null terminated
 */
