#include "PointersReferences.cpp"
#include "PrimitiveArray.cpp"
#include "RangeBasedForLoop.cpp"
#include "BitwiseOperators.cpp" // toString()
#include "FunctionPointers.cpp"
#include "SharedPointers.cpp"
#include "AsyncFuturePromise.cpp"
#include "StringFunctions.cpp"

void TestPointersReferences();

void TestPrimitiveArray();

void TestRangeBasedForLoop();

void TestToString();

void TestSimpleFunctionPointer();
void TestJumpFunctionTable(); 

void TestSharedPointers();

void TestAsyncFuturePromise();

void TestStringFunctions();

//---------------------------------------------------------
 void TestHelloWorld()
 {
   vector<string> msg {"Hello", "C++", "World", "from", "VS Code!", "and the C++ extension!"};
   for (const string& word : msg)
   {
      cout << word << " ";
   }
   cout << endl;

   puts("This is the end of the hello world example!");
 }

 void TestSizeof()
 {
     struct X 
     {
         int a;
         int b;
         int c;
         char d;
         char e;
         long long int f;
         long long int g;
     };

    cout << "size of int is " << sizeof (int) << endl;
    cout << "size of char is " << sizeof (char) << endl;
    cout << "size of long long int is " << sizeof (long long int) << endl;
    cout << "size of X is " << sizeof (X) << endl;
 }