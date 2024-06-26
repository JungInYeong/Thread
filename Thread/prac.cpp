#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
using namespace std;

class BankAccount
{
public:

	int balance = 1000; // 예금된 금액
	void deposit(int amount) // 입금
	{
		cout << "현재 금액 : " << balance << endl;
		cout << "얼마를 입금하시겠습니까? ";
		cin >> amount;
		cout << endl;

		balance = balance + amount;
		cout << "총 금액 : " << balance << endl;

	}
	void withdraw(int amount) // 출금
	{
		cout << "현재 금액 : " << balance << endl;
		cout << "얼마를 출금하시겠습니까? ";
		cin >> amount;

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


	// deposit_iter, withdraw_iter 스레드 객체로 생성
	// amount = 100, count = 100

}

void deposit_iter(BankAccount& ba, int amount, int count)
{
	cout << "몇 번을 입금하시겠습니까? ";
	cin >> count;

	for (int i = 0; i < count; i++)
	{

	}
}

void withdraw_iter(BankAccount& ba, int amount, int count)
{

}
