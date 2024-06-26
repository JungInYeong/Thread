#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
using namespace std;

mutex mtx;

class BankAccount
{
public:

	int balance = 1000; // 예금된 금액
	void deposit(int amount) // 입금
	{
		balance = balance + amount;
		cout << "총 금액 : " << balance << endl;

	}
	void withdraw(int amount) // 출금
	{
		balance = balance - amount;
		cout << "총 금액 : " << balance << endl;
	}

};

// count 횟수 만큼 amount를 입금(deposit)
void deposit_iter(BankAccount& ba, int amount, int count);

// count 횟수 만큼 amount를 출금(withdraw)
void withdraw_iter(BankAccount& ba, int amount, int count);


int main()
{
	int amount = 100;
	int count = 100;
	BankAccount ba;

	thread depo(deposit_iter, ref(ba), amount, count);
	thread with(withdraw_iter, ref(ba), amount, count);

	depo.join();
	with.join();
	// deposit_iter, withdraw_iter 스레드 객체로 생성
	// amount = 100, count = 100

}

void deposit_iter(BankAccount& ba, int amount, int count)
{
	for (int i = 0; i < count; i++)
	{
		mtx.lock();
		ba.deposit(amount);
		mtx.unlock();
	}
}

void withdraw_iter(BankAccount& ba, int amount, int count)
{
	for (int i = 0; i < count; i++)
	{
		mtx.lock();
		ba.withdraw(amount);
		mtx.unlock();
	}
}
