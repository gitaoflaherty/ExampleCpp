 #include <iostream>
 #include <vector>
 #include <string>

 using namespace std;

void TestPointersReferences()
{
    int x = 7;    
    int *ip = &x;
    int &y = x;
    y = 42;
    int z = 73;
    ip = &z; // Pointer reassigned to a different memory location

    cout << endl;    
    cout << "*ip=" << *ip << endl;
    cout << "x=" << x << endl;
    cout << "y=" << y << endl;
    cout << "z=" << z << endl;
}


