#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <chrono>
using namespace std;

bool alarrm_set = false;
mutex mtx;
condition_variable cv;

void timer(int sec)
{
	this_thread::sleep_for(chrono::seconds(sec));
	unique_lock<mutex> lock(mtx);
	alarrm_set = true;
	cv.notify_one();
}

void wait_for_alarm()
{
	unique_lock<mutex>lock(mtx);
	cv.wait(lock, []{ return alarrm_set; }); //alarrm set 이 false일동안 wait
	cout << "알람이 울립니다!!" << endl;
}

int main()
{
	cout << "알람을 기다리는 중.." << endl;
	thread T_timer(timer, 5);
	thread Wait(wait_for_alarm);

	T_timer.join();
	Wait.join();

	return 0;
}