#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
using namespace std;

mutex mtx;

class BankAccount
{
public:

	int balance = 1000; // ���ݵ� �ݾ�
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
	int amount, count = 100;
	BankAccount ba;

	thread depo(deposit_iter,ref(ba), amount, count);
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
