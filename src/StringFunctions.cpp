#include <iostream>
using namespace std;

//char* stringCopy( char*& dest, const char* source)
char* stringCopy( char* dest, const char* source)
{
    //dest = (char*) malloc(45);
    int i = 0;
    for (i = 0; *(source+i) != '\0'; i++)
    {
        *(dest+i) = *(source+i);    
    }
    *(dest+i) = '\0';

    return dest;
}

//----------------------------------------------------------------------------------------------------

void TestStringCopy()
{
    int length = 12;
    char source[] = "String Test";
    char* destination = (char*) malloc(length);//[length];

    stringCopy( destination, source );

    cout << "Source string: " << source << endl;
    cout << "Destination string: " << destination << endl;
}

void TestStringFunctions()
{
    TestStringCopy();
}