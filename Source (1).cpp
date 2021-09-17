/*
							http://www.cplusplus.com/reference/future/async/
	Futures: a Future is nothing but a mechanism for creating asynchronous programming in c++.
						this can be acieved without creating explicit threads.

	Promise: a Promise is nothing but a container for a future
*/

#include<thread>
#include<iostream>
#include<future> //future must be included

using namespace std;

void AsyncFunc()
{
	cout << "Async Thread = >" << this_thread::get_id() << endl;
	cout << "I am inside a function" << endl; //this will be our asynchronous function
}
														/*
					the future is an object which takes a template argument of the return type of the asynchronous function.
									we then call the function fn = async with two parameters,

													1. launch::async
										2. the name of the Asynchronous function

														*/
int main()
{
	cout << "main Thread = >" << this_thread::get_id() << endl;
	future<void> fn = async(launch::async, AsyncFunc);	//
														//	What this line does is it ensures that the 
														//function launches asynchronousy in a sepparate thread, and 
														//executes independently of the main thread

																/*
				to get the return value of the function in the main thread, we need to use a function called fn.get
																*/

	 
																/*
				What this will do is it will wait until the execution of the asynchronous function is completed, if it's
								completed before that time, it will return the value immediately
																*/
	
	
																/*
				What this will do is it will wait until the execution of the asynchronous function is completed, if it's
								completed before that time, it will return the value immediately
																*/

																/*
							the way to show that the threads are different is to write the lines
								1. cout << "main Thread = >" << this_thread::get_id() << endl;
								2. 	cout << "async Thread = >" << this_thread::get_id() << endl;

							this function will show that each thread has sepparate id from one another
															*/

	//there is another option for the launch function called "deferred".  what this does is it does not call the sepparate function until we do .get
	//and it actually doesn't run it asynchronously.  the output of the thread id for each function will end up being THE SAME
	//future<void> fn = async(launch::deferred, AsyncFunc);
	
	//one final option is the keyword "any", which launches the codes in whatever way they want.
	//future<void> fn = async(launch::any, AsyncFunc);


	fn.get();  //once this line is called, it can't be called again
	//
	return 0;
}

	