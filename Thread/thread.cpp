#include <iostream>
#include <thread>
#include <vector>
using namespace std;

void thread_function(int thread_id)
{
	cout << "thread" << thread_id << "is running" << endl;
}

int main()
{
	vector<thread> threads;
	int num_threads = 10;

	for (int i = 0; i < num_threads; ++i) {
		threads.emplace_back(thread_function, i); // i는 스레드 ID로 전달
	}

	// 모든 스레드가 종료될 때까지 대기
	for (auto& t : threads) 
	{
		if (t.joinable())
		{
			t.join();
		}
	}

	cout << "All threads have finished." << endl;

	return 0;
}

// 이게 더 좋은거같음
//#include <iostream>
//#include <thread>
//#include <vector>
//using namespace std;
//void printMessage(int thread_num)
//{
//    for (int i = 0; i < 10; i++)
//    {
//        cout << endl << thread_num << ": " << i + 1 << endl;
//    }
//}
//int main()
//{
//    vector <thread> threads;
//    threads.resize(5);
//    int i = 0;
//    for (auto& th : threads)
//    {
//        th = thread(printMessage, i);
//        i++;
//    }
//    for (auto& th : threads)
//    {
//        th.join();
//    }
//    return 0;
//}