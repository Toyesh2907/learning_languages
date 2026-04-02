//Yeah I already know this

/* C++ operator precedence (1 = highest) and associativity
 * Prec  Assoc  Operators                          Description
 * 1     L->R   ::                                  scope resolution
 * 2     L->R   ()  []  .  ->  ++  --  typeid       call, subscript, member, post-inc/dec
 *              cast ops  sizeof...  noexcept       RTTI, casts, sizeof pack, noexcept, alignof
 * 3     R->L   +  -  ++  --  !  not  ~             unary plus/minus, pre-inc/dec, logical NOT, bitwise NOT
 *              (type)  sizeof  co_await            C-style cast, sizeof, co_await
 *              &  *  new  new[]  delete  delete[]  address-of, deref, new/delete
 * 4     L->R   ->*  .*                             pointer-to-member access
 * 5     L->R   *  /  %                             multiply, divide, remainder
 * 6     L->R   +  -                                addition, subtraction
 * 7     L->R   <<  >>                              shift left/right (or stream in/out)
 * 8     L->R   <=>                                three-way comparison (C++20)
 * 9     L->R   <  <=  >  >=                        relational comparisons
 * 10    L->R   ==  !=                              equality, inequality
 * 11    L->R   &                                   bitwise AND
 * 12    L->R   ^                                   bitwise XOR
 * 13    L->R   |                                   bitwise OR
 * 14    L->R   &&  and                             logical AND
 * 15    L->R   ||  or                              logical OR
 * 16    R->L   =  *=  /=  %=  +=  -=               assignments
 *              <<=  >>=  &=  |=  ^=                compound assignments
 *              ?:  throw  co_yield                 conditional, throw, co_yield
 * 17    L->R   ,                                   comma operator
 */

