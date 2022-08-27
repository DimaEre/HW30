#include<iostream>
#include<windows.h>

using namespace std;

class Number
{
	
private:
	int number;
	int min;
	int max;
public:
	Number(int n, int min, int max)
	{
		number = n;
		this->min = min;
		this->max = max;
	}
	void frame()
	{
		if (number < min || number > max) throw "Error";
	}
	void add(int n)
	{
		number += n;
		try {
			frame();
		}
		catch(...)
		{ 
			cout << "Число виходить за рамки. Повертається минуле значення";
			number -= n;
		}
		show();
	}
	void take(int n)
	{
		number -= n;
		try {
			frame();
		}
		catch (...)
		{
			cout << "Число виходить за рамки. Повертається минуле значення";
			number += n;
		}
		show();
	}
	void show()
	{
		cout << number << " " << min << " " << max << endl;
	}
	
};
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n, command;
	Number n1(5, 0, 10);
	Number n2(9, 0, 100);
	while (true)
	{


		cout << "\nМеню:\n"
			<< "1 - додати до об'єктів\n"
			<< "2 - відняти від об'єктів\n"
			<< "3 - показати об'єкти\n";
		cin >> command;
		if (command == 1)
		{
			cout << " додати:";
			cin >> n;
			n1.add(n);
			n2.add(n);
		}
		else if (command == 2)
		{
			cout << " відняти:";
			cin >> n;
			n1.take(n);
			n2.take(n);
		}
		else if (command == 3)
		{
			n1.show();
			n2.show();
		}
	}
}
