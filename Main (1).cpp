#include <iostream>
#include <thread>
#include<chrono>
#include "common.h"




//void func1()
//{
//	std::thread::id func_id_1 = std::this_thread::get_id();
//	std::cout << "Hello from function - " << func_id_1 << std::endl;
//}

//class my_class {
//
//public:
//	void operator()()
//	{
//		std::thread::id func_id_1 = std::this_thread::get_id();
//		std::cout << "hello from the class with function call operator - " << func_id_1 << std::endl;
//	}
//};

//void test()
//{
//	std::thread::id func_id_1 = std::this_thread::get_id();
//	std::cout << "hello from test - " << func_id_1 << "\n" << std::endl;
//}
//
//void functionA()
//{
//	std::thread::id func_id_1 = std::this_thread::get_id();
//	std::cout << "hello from threadA - " << func_id_1 << "\n" << std::endl;
//	
//	std::thread threadC(test);
//	threadC.join();
//}
//
//
//void functionB()
//{
//	std::thread::id func_id_1 = std::this_thread::get_id();
//	std::cout << "hello from threadB - " << func_id_1 << "\n" << std::endl;
//}

/*---------------------------------------------------------------------------------*/




void foo()
{
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout << "Hello from foo - \n" << std::endl;
}


void bar()
{
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout << "Hello from bar - \n" << std::endl;
}

void other_operations()
{
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout << "this is another operation - \n";
	throw std::runtime_error("this is a runtime error");
}

void run()
{

	std::thread foo_thread(foo);
	thread_guard tg(foo_thread);

											// when program executes, it throws eception, and main goes out of scope
											// when it goes out of scope, objects created inside function //
											// will be destructed in reverse order in which they were created
	//std::thread bar_thread(bar);
	try {
		other_operations();
		foo_thread.join();
	}
	catch(...){
		foo_thread.join();
	}

	//bar_thread.detach();
	//printf("this is after bar thread detatch \n");

	/*foo_thread.join();
	printf("This is after foo thread join \n");*/

	//detach function should not block the calling thread and join should nlock calling thread until new thread finishes execution
}



// entry point for the program
int main()
{
	//create thread using fuction... 
													//LAUNCHING A THREAD, a callable object to thread class constructor
	//std::thread thread1(func1);						// the function is passed as the parameter for the thread class constructor
													// 


	//create thread using class with function call operator
	/*my_class mc;
	std::thread thread2(mc);*/

	//create thread using lambda expression
	//std::thread thread3([] {						// review lambda expressions
	//	std::thread::id func_id_1 = std::this_thread::get_id();
	//	std::cout << "hello from the lambda - " << func_id_1 << std::endl;
	//});


	//as soon as thread is constructed, it has possbility, after lauching, we need to JOIN the thread

	//thread1.join();		//forces main thread to wait until the thread it caled upon finishes it's execution
	//thread2.join();
	//thread3.join();


	/*std::thread threadA(functionA);
	if (threadA.joinable())
	{
		std::cout << "ThreadA is joinable before join\n";
	}
	else
	{
		std::cout << "ThreadA is not joinable before join\n";
	}
	std::thread threadB(functionB);
	if (threadB.joinable())
	{
		std::cout << "ThreadB is joinable before join\n";
	}
	else
	{
		std::cout << "ThreadB is not joinable before join\n";
	}


	threadA.join();
	if (threadA.joinable())
	{
		std::cout << "ThreadA is joinable after join\n";
	}
	else
	{
		std::cout << "ThreadA is not joinable after join\n";
	}
	
	threadB.join();
	if (threadB.joinable())
	{
		std::cout << "ThreadB is joinable after join\n";
	}
	else
	{
		std::cout << "ThreadB is not joinable after join\n";
	}*/
	
	std::cout << "\n \n /*----------------------------------------------------------------------*/ \n \n";


	run();

	/*
	std::thread::id func_id_2 = std::this_thread::get_id();
	std::cout << "Hello from main thread - " << func_id_2 << "\n" << std::endl;
	*/


}

/*
hello from threadA - 27584
hello from threadB - 26432


hello from test - 20716

Hello from main thread - 27304
*/