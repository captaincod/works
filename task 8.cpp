#include <iostream>
#include <cmath>
#include <conio.h>
using namespace std;

int main() {

	//Необходимо найти количество чисел, не превышающих 10 000 000, у которых кол-во единиц в восьмеричной 
	//и двоичной записях равно
	
	int max = 10000000;
	int quantity_of_numbers = 0, binary_one_quant = 0, octal_one_quant = 0;

	for (int number = 1; number <= max; number++) {
		int binary_num = number;
		while (binary_num > 0) {
			if (binary_num % 2 == 1) {
				binary_one_quant++;
			}
			binary_num /= 2;
		}
		int octal_num = number;
		while (octal_num > 0) {
			if (octal_num % 8 == 1) {
				octal_one_quant++;
			}
			octal_num /= 8;
		}

		if ( (binary_one_quant == octal_one_quant) && binary_one_quant != 0) {
			quantity_of_numbers++;
		}
		binary_one_quant = 0;
		octal_one_quant = 0;
	}

	cout << "Quantity of numbers: " <<quantity_of_numbers;
	_getch();
	return 0;
}