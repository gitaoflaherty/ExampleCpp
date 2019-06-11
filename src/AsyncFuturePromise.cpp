
#include <iostream>     // std:cout
#include <future>       // std::async, std::future

using namespace std;

void factorial(int N, int& res) {
    res = 1;
    for (int i = 2; i <= N; i++)
    {
        /* code */
        res *= i;
    }
}

int factorial2(int N)
{
    int res = 1;
    for( int i=2; i<=N;i++)
    {
        res *= i;
    }
    return res;
}

// This code has flows - the res value is a shared resource being
// accessed by the main thread and the child thread.  It requires adding
// a mutex to lock and a condition_variable type to ?? ... 
// The alternative is to use the async constructs.  See TestAsync
void TestSimpleThread()
{
    // Call factorial on a child thread
    int x = 5;
    int fact;

    // thread is a class
    // Note: &fact does not work!  Need to use ref(fact)
    thread t1(factorial, x, ref(fact));
    t1.join();
    cout << "TestSimpleThread: Factorial of " <<  x << " = " << fact << endl;
}


void TestAsyncDefault()
{
    int x = 6;
    // future class 
    // async is a function and returns a future type
    // default is launch::asycn | launch::deferred
    //future<int> factFuture = async (launch::asycn | launch::deferred, factorial2, x );
    future<int> factFuture = async ( factorial2, x );

    // do something on main thread ...

    // Need value from async call
    // The get call waits for the child thread to finish and get the return
    // get() should be called once only ... a repeated call will generate an error
    int fact = factFuture.get();

    cout << "TestAsyncDefault: Factorial of " <<  x << " = " << fact << endl;
}

void TestAsyncDeferred()
{
    int x = 7;

    // the deferred parameter means do not start the factorial2 function until get is called
    future<int> factFuture = async ( launch::deferred, factorial2, x );

    // do something on main thread ...

    // the call to get() starts the factorial2 function on the main thread!
    int fact = factFuture.get();

    cout << "TestAsyncDeferred: Factorial of " <<  x << " = " << fact << endl;
}

void TestAsyncAsync()
{
    int x = 8;

    // the async parameter means create another thread
    future<int> factFuture = async ( launch::async, factorial2, x );

    // do something on main thread ...

    // Get value
    int fact = factFuture.get();

    cout << "TestAsyncAsync: Factorial of " <<  x << " = " << fact << endl;
}


//---------------------------------------------------------------------------------------------

void TestAsyncFuturePromise()
{
    TestSimpleThread();
    TestAsyncDefault();
    TestAsyncDeferred();
    TestAsyncAsync();
}

