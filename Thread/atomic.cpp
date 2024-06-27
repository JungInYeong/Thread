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


	void deposit(int amount) // �Ա�
	{
		balance = balance + amount;
		cout << "�� �ݾ� : " << balance << endl;

	}
	void withdraw(int amount) // ���
	{
		balance = balance - amount;
		cout << "�� �ݾ� : " << balance << endl;
	}
	
};

// count Ƚ�� ��ŭ amount�� �Ա�(deposit)
void deposit_iter(BankAccount& ba, int amount, int count);

// count Ƚ�� ��ŭ amount�� ���(withdraw)
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
	// deposit_iter, withdraw_iter ������ ��ü�� ����
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
