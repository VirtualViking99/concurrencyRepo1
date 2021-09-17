#pragma once

#include <iostream>
#include <thread>
#include <chrono>


//	Pass Parameters to a thread
void func1(int x, int y)							// thread function(arguments)
{													//{
	std::cout << "X+Y= " << x + y << std::endl;				//function body which takes arguments;
}													//}

// Passing reference to a thread
void func2(int &x)
{
	while (true)
	{
		std::cout << "thread1 Value of X - " << x << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
}


void run()
{
	int p = 9;
	int q = 8;										// thread object(thread function, parameters)
	std::thread thread_1(func1, p, q);
	thread_1.join();
}


void run2()
{
	int x = 9;
	std::cout << "Main thread value of X - " << x << std::endl;
												//thread takes argument by value, so you hae to explicitly wrap the value in a reference, using std::ref(passed object)
	std::thread thread2(func2, std::ref(x));
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));

	int x = 15;
	std::cout << "Main thread value of X has been changed to - " << x << std::endl;
	thread2.join();

}

int main()
{
	run2();
}