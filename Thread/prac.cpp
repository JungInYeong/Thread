#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
using namespace std;

class BankAccount
{
public:

	int balance = 1000; // ���ݵ� �ݾ�
	void deposit(int amount) // �Ա�
	{
		cout << "���� �ݾ� : " << balance << endl;
		cout << "�󸶸� �Ա��Ͻðڽ��ϱ�? ";
		cin >> amount;
		cout << endl;

		balance = balance + amount;
		cout << "�� �ݾ� : " << balance << endl;

	}
	void withdraw(int amount) // ���
	{
		cout << "���� �ݾ� : " << balance << endl;
		cout << "�󸶸� ����Ͻðڽ��ϱ�? ";
		cin >> amount;

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


	// deposit_iter, withdraw_iter ������ ��ü�� ����
	// amount = 100, count = 100

}

void deposit_iter(BankAccount& ba, int amount, int count)
{
	cout << "�� ���� �Ա��Ͻðڽ��ϱ�? ";
	cin >> count;

	for (int i = 0; i < count; i++)
	{

	}
}

void withdraw_iter(BankAccount& ba, int amount, int count)
{

}
