//Since I already know what logical operators are this file will only cover quirks of logical operators that I am not aware about

/*
 * New programmers (like me) might try something like
 * if (value == 0 || 1) do_something
 * above is incorrect because when 1 is evaluated it will implicitly get converted to bool true.
 * Thus above will always be true.
 *
 * if(value == 0 || value == 1) do_something
 * is correct
 */

/*
 * A bit about optimization
 * let's say you have a condition that is using and operator &&
 * incase the left operand results in false the right is not even bothered
 * with this is called short circuit evaluation. So its usually correct to write operands
 * that you are aware will result to false most of the time on left i.e let them be
 * evaluated first
 *
 * so if you have logic in your right side operand it is usally good to not keep it their
 * for example:
 * if (x == 1 && ++y == 2)
 *      //do something
 * for the code above incase x != 1 ++y won't be evaluated and it might side effect your
 * program
 *
 * you can use logical operators with keywords aswell
 * for example
 * std::cout << !a && (b || c);
 * becomes
 * std::cout << not a and (b or c);
 *
 * To be honest I won't be using that what the fuck is this python??
 */


