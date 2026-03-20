//Yeah I know I could have come with a better name for the file pretty retarded

/*
 * So why does std::string make an expensive copy everytime an object is created/instantiated
 * a piece of memory is allocated in order for that object to store whatever data it needs to use through its lifetime.
 * This memory is reserved for object, and guaranteed to exist for as long as the object does.
 * These objects store the initialization value in the memory alloted for them for manipulation later.
 */
