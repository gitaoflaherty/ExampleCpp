#include <iostream>

void TestPrimitiveArray()
{
    int ia[5];// declares a 5 element array

    // Two ways to initialize the first element
    ia[0] = 1; // index
    *ia = 32;  // de-reference operator

    int *ip = ia; // array name is an int pointer
    *ip = 328; // first element set to 2

    // set the second element using pointer
    ++ip;
    *ip = 528;
    
    // set the third element in one statement
    *(++ip) = 730;

}