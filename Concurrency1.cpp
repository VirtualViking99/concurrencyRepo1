#include<thread>
#include<iostream>

using namespace std;

void ThrdFunc() //this is the function which will be passed into a thread
						 //Sometimes you need to pass in values
{
	cout << "I am inside a thread function" << endl;

}


int main()
{
	thread t1{ ThrdFunc };

	t1.join();
	return 0;
}

