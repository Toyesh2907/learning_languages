/*
 * This was straight forward aswell nothing much to write apart from some good practices to follow which are as follows:
 * Prefer defining global variables inside a namespace rather than in global namespace to avoid collisions with local variables.
 *
 * They also have static duration they are created when the program starts and destroyed when the program ends.
 * Some developers also prefer a "g" or "g_" prefix to the global variable indicating that this is a global variable
 * there's reasons for doing that.
 * 1. Helps avoiding naming collisions with other identifiers
 * 2. It helps prevent inadvernt(I learnt a fancy word :D) name shadowing
 * 3. It helps indicate that the prefixed variable presist beyond the scope
 * 
 * There's also discussions about having a prefix g or g_ for global variables due to Hungarian notation
 * and there's no need to do allat. We are not living in the 90s afford a text editor that can flash what the variable is boomer
 */
