#include <memory>   
#include <iostream>
#include <string>

using namespace std;

class Dog {

    private:
        string _name = "<un-named>";

    public:
        Dog() { cout << "Dog constructor: name = " << _name << endl; }
        Dog(string name) { _name = name; cout << "Dog constructor: name = " << name << endl; }
        ~Dog() { cout << "Dog destructor: name = " << _name << endl; }

        string get_Name() { return _name; }
        void bark() { cout << "Bark: Woof! Woof!" << endl; }
};

void DisplayPointerCount( string name, int count )
{
    cout << "Dog " <<  name << " has " << count << " pointers." << endl;
}

void TestSharedPointerCounts()
{
    // new object passed in pointer constructor 
    cout << "New Dog created." << endl;
    
    // This declaration includes 2 steps:
    // (1) create dog (which could exception) and cause memory leak
    // (2) assign to pointer
    // Alt: use make_shared which does the above in one step.
    // shared_ptr<Dog> dogMax( new Dog( "Max" ) );
    auto dogMax = make_shared<Dog>( Dog("Max") ); 
    DisplayPointerCount( dogMax->get_Name(), dogMax.use_count() );
    {
        cout << "Existing Dog assigned to another pointer." << endl;
        // pointer assigned to existing object
        auto dogMax2 = dogMax;
        DisplayPointerCount( dogMax->get_Name(), dogMax.use_count());
    }
    cout << "Second pointer out of scope." << endl;
    DisplayPointerCount( dogMax->get_Name(), dogMax.use_count());
}


// mixing in raw pointers can cause undefined behavior.  Fix: Don't mix raw pointer with "smart" pointers. 
void TestSharedPointersUndef()
{
    cout << "---------- TestSharedPointersUndef() ----------" << endl;
    cout << "Create dog using raw pointer." << endl;
    Dog* ptrDog = new Dog( "Dexter" );
    cout << "Assign dog to shared pointer." << endl;
    shared_ptr<Dog> dog1( ptrDog );
    DisplayPointerCount( dog1->get_Name(), dog1.use_count() );
    {
        cout << "Assign dog to another shared pointer." << endl;
        shared_ptr<Dog> dog2( ptrDog );
        DisplayPointerCount( dog2->get_Name(), dog1.use_count() );
    }
    cout << "Shared pointer 2 is out of scope." << endl;
    try
    {
        DisplayPointerCount( dog1->get_Name(), dog1.use_count() );
    }
    catch(const std::exception& e)
    {
        cout << "Exception caught: Shared pointer 1 is undefined because shared pointer 2 deleted the object." << endl;
        cout << "Exception message: " << e.what() << endl;
    }
}

// cyclic reference can cause memory leak.  Fix: weak pointers.
void TestSharedPointersMemoryLeak()
{
    struct Foo
    {
        shared_ptr<Dog> _dog;
        public:
             Foo(Dog dog) { _dog = shared_ptr<Dog>( dog );  }
    }
}

// ----------------------------------------------------

void TestSharedPointers()
{
    TestSharedPointerCounts();
    TestSharedPointersUndef();
    TestSharedPointersMemoryLeak();
}