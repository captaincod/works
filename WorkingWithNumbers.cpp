#include <iostream>
#include "WorkingWithNumbers.h"
using namespace std;



class Chislo
{
	// ��������� �� �����
	int* number;
	// ������� ������� ���������
	int system;

public:
	//�����������
	Chislo(int number, int numeralSystem = DEFAULT_SYSTEM);

	//����������
	~Chislo();

	// ������ ������� ���������
	void changeSystem(int new_numeralSystem);

	// ��������� �������� ��������
	Chislo adding(Chislo summand);

	// ��������� �������� ���������
	Chislo subtracting(Chislo subtract);

	// ��������� �������� �������
	Chislo dividing(Chislo divider);

	// ��������� �������� ���������
	Chislo multiplication(Chislo multiplier);

	// ��������� �������� ���������� � �������
	Chislo powering(int power);

	// ��������� �������� ���������
	Chislo comparing(Chislo compared);
};
Chislo::Chislo(int _number, int numeralSystem)
{
	if ((numeralSystem >= 2) or (numeralSystem <= 36))
		numeralSystem = DEFAULT_SYSTEM;
	else
		system = numeralSystem;
	number = (int*)_number;
}

Chislo::~Chislo()
{
	delete number;
}


int power(int a, int n) {
	if (n % 2 == 0)
		power(a, n / 2)* power(a, n / 2);
	else
		a * power(a, n / 2);
}

void Chislo::changeSystem(int new_numeralSystem) {
	if (new_numeralSystem <= 0)
		new_numeralSystem = DEFAULT_SYSTEM;

	int new_number = 0;

	for (int i = 0; *number > 0; i++) {
		new_number += (*number % (power(10, i + 1)))* system;
	}

	if (new_numeralSystem == DEFAULT_SYSTEM) {
		*number = new_number;
		system = DEFAULT_SYSTEM;
	}
	else {
		string perevernutoe_chislo;
		while (new_number > 0) {
			int delitel = new_number / new_numeralSystem;
			perevernutoe_chislo += new_number - delitel * new_numeralSystem;
		}
	}
	
}

Chislo Chislo::adding(Chislo summand) {

}

Chislo Chislo::subtracting(Chislo subtract) {

}

Chislo Chislo::dividing(Chislo divider) {

}

Chislo Chislo::multiplication(Chislo multiplier) {

}

Chislo Chislo::powering(int power) {

}

Chislo Chislo::comparing(Chislo compared) {

}