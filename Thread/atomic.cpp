#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <atomic>
using namespace std;


class BankAccount
{
private:
	atomic<int> balance = 1000;
public:


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
		
		ba.deposit(amount);
		
	}
}

void withdraw_iter(BankAccount& ba, int amount, int count)
{
	for (int i = 0; i < count; i++)
	{
		
		ba.withdraw(amount);
	
	}
}
