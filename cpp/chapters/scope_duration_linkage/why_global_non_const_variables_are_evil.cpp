// I don't like the title for this chaper uncle Alex (*￣m￣).

/*
 * From what I read the stuff is easy. Since non const variables can be updated from anywhere we don't want allat.
 * So now onto best practices.
 */

//Initialization order of global variables


/*
 * There are two phases of intialization of non static variables which happens as part of program startup.
 * First phase is static initialization which has two phases:
 * 1. Global variables with constexpr initializers are intialized to those values. This is called constant initialization.
 * 2. Global variables without intitilizers are zero-initialized. zero-initialized is considered to be a form of static initialization
 * since 0 is a constexpr value.
 *
 * The second phase is called dynamic intialization. This phase according to uncle Alex is complex but the gist of it is global varibales with
 * non-constexpr intializers are intialized.
 * which is given below
 */

int init(){
    return 5;
}

int g_something { init() };
