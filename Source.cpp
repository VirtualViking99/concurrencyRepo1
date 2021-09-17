#include<thread>
#include<iostream>
#include<mutex>
using namespace std;

void ThreadFn(mutex & mtx)
{
	lock_guard<mutex> lock(mtx); //3a. when it sleeps, the mutex gets 
								 //locked here because it is not locked by anyone else...
	cout << "I locked the mutex..." << endl;
	this_thread::sleep_for(chrono::seconds(5));//3b. the mutex gets locked for5 secconds
}

//. XX

int main()
{
	mutex mtx;
	thread th{ ThreadFn, ref(mtx) }; // 1. this line gets executed
	this_thread::sleep_for(chrono::seconds(3)); //2. thethread sleeps for one seconds
	unique_lock<mutex> lock(mtx);//4. as soon as 3. is completed, it unlocks the mutex, allowing this thread to lock.
	cout << "I am inside the main thread..." << endl;
	lock.unlock();

	th.join();
	return 0;
}

/*
what is Mutex:  Mutual exclusion:
		consider it as My or the Highway issue, 
		at any point in time you'll be agreeing to one person or not at all
*/

/*
		with unique_lock <mutex> , you can manualy lock and unlock the threads, whereas you can't with lock_guard.
	In places where you want to make sure the resource is acquired and released to get out of scope, you use
	lock_guard, and in places where you need to lock andunlock utex resources again and again, you use unique_lock.
	
*/