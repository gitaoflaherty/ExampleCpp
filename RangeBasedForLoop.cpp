#include <iostream>

void TestRangeBasedForLoop()
{
    int array[] = { 1, 2, 3, 4, 5 };

    for (int i : array )
    {
        //printf( "i is %d", i );
        cout << i << endl;
    }
    
}