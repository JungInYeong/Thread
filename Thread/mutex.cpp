#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
using namespace std;

mutex mtx;
int counter = 0;

void increment()
{
	for (int i = 0; i < 1000; i++)
	{
		//mtx.lock();
		++counter;
		//mtx.unlock();
	}
}

void incrementCounter() {
	for (int i = 0; i < 1000; ++i) {
		std::lock_guard<std::mutex> lock(mtx);
		++counter;
	}
}

int main()
{
	//thread t1(increment);
	//thread t2(increment);
	//thread t3(increment);

	//t1.join();
	//t2.join();
	//t3.join();
	vector<thread> threads;

	for (int i = 0; i < 40000; ++i) {
		threads.emplace_back(incrementCounter);
	}

	for (thread& th : threads) {
		th.join();
	}

	std::cout << "Final counter value: " << counter << std::endl;
	

	return 0;
}