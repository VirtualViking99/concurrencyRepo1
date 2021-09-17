#include<thread>
#include <iostream>
#include<initializer_list>
#include<vector>

/**/
//we know threads can take thread functions as their parameters, but thread functions can ALSO be templated parameters.
/*using namespace std;

template<typename Type>
void threadFN() //this is the function which will be passed into a thread
{
	cout << "Type is => " << typeid(Type).name() << endl;
	cout << endl;
	/*
	cout << "I am inside a thread function" << endl;
	cout << this_thread::get_id() << endl; //it is possible to print thread ID
	*/
	/*}*/
	/*int main()
	{
		thread t1(threadFN<int>);  // you can call the thread function with an int
		this_thread::sleep_for(chrono::milliseconds(1000));
		thread t2(threadFN<float>);// you can also call the thread function with a float inside a new thread t2
		cout << this_thread::get_id() << endl;
		t1.join(); // join is used if I want to wait for my thread to complete before exiting the main function
		t2.join();
		return 0;
	}*
	*/


	//output will be.....
	/*

	Type is => int
		(sleep fr one second)
	Type if => float

	*/

	/*--------------------------------------------------------------------------------------------------*/

							/* we can also include Sandard Text Libraries (STL's)*/
						  /* in this example we will use #include<initializer_list>*/

	/*using namespace std;


	void threadFN(initializer_list<int> il){ //this is the function which will be passed into the thread
		cout << "Size of list =>" << il.size() << endl;
	}


	int main()
	{
		initializer_list<int> il = {1,2,3,4,5,6}; //you can pass this created initializer list iside a thread function.

		thread t1{ threadFN, il };  // you can call the thread function with an int

		t1.join(); // join is used if I want to wait for my thread to complete before exiting the main function
		return 0;
	}
	*/

	/*output
	Size of list=>6
	*/
	/*--------------------------------------------------------------------------------------------------*/

						  /* This is also applicaple when using #include<vector>*/

using namespace std;


void threadFN(initializer_list<int> il)
{ //this is the function which will be passed into the thread
	cout << "Size of list =>" << il.size() << endl;
}


int main()
{
	vector<int> il = { 1,2,3,4,5,6 }; //you can pass this created initializer list iside a thread function.

	thread t1{ threadFN, il };  // you can call the thread function with an int

	t1.join(); // join is used if I want to wait for my thread to complete before exiting the main function
	return 0;
}
//you'll get the same output

	// Note:implicit conversions might not happen. 	thread t1{ threadFN, {1, 2, 3, 4, 5, 6} }; . 
	//This won't work because it is in curly braces, and if you try it with a vector, it can't 
	//Make heads or tailsof it.you need to pass the name of the type in as the argument for the
	//thread.


	/*--------------------------------------------------------------------------------------------------*/
