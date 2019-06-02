#include <cstdio>
#include <cstdint>

// Convert unsigned 8 bit to string
const char* toString( const uint8_t & x )
{
    // count of bytes x size of byte + 1 byte for terminating character
    // note: count of bytes = 1 for uint8_t
    const int stringLength = sizeof(x) * 8 + 1;

    // create and initialize string
    static char buff[stringLength];
    for( char c : buff )
    {
        c = 0;
    }

    // Walk down the uint8_t one bit at a time ...
    char* bp = buff;
    for (uint8_t mask = 0b10000000; mask; mask >>= 1 )
    {
        *(bp++) = x & mask ? '1': '0';
    }
    return buff;
}

void TestToString()
{
    printf( "%s\n", toString( 1 ) );
    printf( "%s\n", toString( 2 ) );
    printf( "%s\n", toString( 3 ) );
    printf( "%s\n", toString( 4 ) );
    printf( "%s\n", toString( 5 ) );
    printf( "%s\n", toString( 6 ) );
    printf( "%s\n", toString( 7 ) );
    printf( "%s\n", toString( 8 ) );
    printf( "%s\n", toString( 9 ) );
    printf( "%s\n", toString( 10 ) );
    printf( "%s\n", toString( 255 ) );
}