#include <iostream>

void fA() { puts( "This is fA" ); }
void fB() { puts( "This is fB" ); }
void fC() { puts( "This is fC" ); }
void fD() { puts( "This is fD" ); }
void fE() { puts( "This is fE" ); }

// Address of functions is assigned to a pointer
// Array of function pointers
void(*functions[])()  = { fA, fB, fC, fD, fE };

// Prompt for a character
// TODO: H
char prompt()
{
    puts("Enter the function letter (A through E):" );
    printf(">> ");
    fflush(stdout);               // Flush after prompt
    const int size = 16;
    static char response[size];   // static storage for response
    fgets(response, size, stdin); // get response from console
    return response[0];
}

// Precondition: capital letters only!
// Jump to the method specified by character
// Return false if Q'
int jump( char c )
{
    if ( c == 'Q' )
    {
        return 0;
    }

    // convert char to array integer
    int index = c - 'A'; 
    functions[index]();
    return 1;
}

//---------------------------------------------------------
// TEST METHODS
//---------------------------------------------------------
void TestSimpleFunctionPointer()
{
    void (*pFunction)() = fA;
    pFunction();
}

void TestJumpFunctionTable()
{
    while( jump( prompt() ) ){};
    puts( "Done!" );
}