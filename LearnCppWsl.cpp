 #include <iostream>
 #include <vector>
 #include <string>
 #include "Tests.h"

 using namespace std;

 void TestHelloWorld()
 {
   vector<string> msg {"Hello", "C++", "World", "from", "VS Code!", "and the C++ extension!"};
   for (const string& word : msg)
   {
      cout << word << " ";
   }
   cout << endl;
 }



 int main()
 {
    //TestHelloWorld();
    
    //TestPointersReferences();

    //TestPrimitiveArray();

    // TestRangeBasedForLoop();

    TestToString();
 }