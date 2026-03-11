//take the following square.h as an example
int get_square_side(){
    return 4; //yeah yeah I know for now assume the square has a side 2 because I am fucking lazy
}

//assume we have a header file wave.h
#include "square.h"

//assume we have the following main.cpp

#include "square.h"
#include "wave.h"

int main () {
    
    return 0;
}

/*
 * The program above looks like its going to compile it has a two header files wave.h and square.h
 * and a main.cpp but it doesn't why?
 * Because of how the preprocessing happens before compilation wave.h includes square.h but square.h is already included
 * this makes the function to be written twice hence causing the situation where the function was declared twice
 * So how do we guard against this situation where headers are fucking us over
 * Using header guards(spledid word play) 
 *
 * This would be done using the directive #ifndef that checks whether a certain directive has been defined or not
 */

#ifndef SOME_UNIQUE_NAME_HERE
#define SOME_UNIQUE_NAME_HERE

#endif

/*
 * The above peice of code checks whether SOME_UNIQUE_NAME_HERE has been previously defined if not
 * the code block defines it
 * So if the above is encountered from a header and SOME_UNIQUE_NAME_HERE has already been defined it won't be
 * defined again
 *
 * It is generally a good practive to have header guards in all of your C++ files to not encounter the bitch ass situation above
 */

#ifndef SQUARE_H
#define SQUARE_H
int get_square_sides1(){
    return 4;
}
#endif

/*
 * In the code block above now if the header file is encountered first we done SQUARE_H and the piece of code gets replaced
 * exactly once in any other file that uses the header
 * 
 * It is generally a good practive to have some sort of unique identification in your header guard definations
 * Why? let's say you have two different configs in a project one for a SERVICE_A and one for SERVICE_B
 * in that case it is necessary to seperate these two otherwise both header guards will conflict with CONFIG_H
 * Some "good convetions" suggested are: PROJECT_PATH_FILE_H, FILE_LARGE-RANDOM-NUMBER_H, or FILE_CREATION-DATE_H
 *
 * So taking the above into consideration here's how the files will be rewritten
 */

//square.h
#ifndef SQUARE_H
#define SQUARE_H

int get_square_sides2(){
    return 4;
}

#endif // !SQUARE_H

//wave.h
#ifndef WAVE_H

#include "square.h"

#endif

//main.cpp
#include <iostream>
#include "square.h"
#include "wave.h"
int main () {
    return 0;
}

/*
 * There is another way of guarding the situation above we can use #pragma once directive
 * which tells the compiler to guard the header instead of developer manually handeling it
 * so it is good to use this imo inorder to not get into conflits related to header guard naming
 *
 * Sounds simple but the world is not all sunshine and rainbows pragma once was designed for specific
 * OMFG what does that mean it might work on some compilers and might not work on others
 * (╯°□°)╯︵ ┻━┻ PATHETIC
 */

