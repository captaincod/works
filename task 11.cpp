#include <iostream>
#include <cmath>
#include <conio.h>
#include <string>

using namespace std;

//Гирьки

int power(int chislo, int stepen) {
	int umnozhitel = chislo;
	for (int i = 1; i < stepen; i++) {
		chislo *= umnozhitel;
	}
	return chislo;
}
int number_of_digits(int chislo) {
	int number_of_digits = 0;
	while (chislo > 0) {
		chislo /= 10;
		number_of_digits++;
	}
	return number_of_digits;
}

int main() {
	int dividers[] = { 10, 5, 2, 1 };

	int m;
	cout << "Enter the mass:";
	cin >> m;

	string output = "";

	if (number_of_digits(m) > 0) {

		while (m > 0) {
			if (number_of_digits(m) > 1) {
				for (int i = 0; i < 4; i++) {
					dividers[i] *= power(10, number_of_digits(m) - 1);
				}
			}
			for (int j = 0; j < 4; j++) {
				if (m - dividers[j] >= 0) {
					output += to_string(dividers[j]) + " ";
					m -= dividers[j];
				}
			}
			dividers[0] = 10;
			dividers[1] = 5;
			dividers[2] = 2;
			dividers[3] = 1;
		}
		cout << "This number consists of: " << output;
	}



	else {
		cout << "There are some problems with your input";
	}


	_getch();
	return 0;
}