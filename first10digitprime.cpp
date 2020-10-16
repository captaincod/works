//Иванова Олеся 14221

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

const long long numbers_of_e = 1000000;

long long chislo = 0;

bool is_prime(long long chislo) {
	if (chislo == 2) {
		return true;
	}
	else {
		for (long long i = 2; i < sqrt(chislo); i++) {

			if (chislo % i == 0) {
				return false;
			}
		}

		return true;
	}
	
}

int main() {
	
	ifstream file("e_2mil.txt");
	char content;

	while ((content = file.get()) != EOF) {
		
		chislo %= numbers_of_e;
		chislo *= 10;
		int plus = content - '0';  // char - '0' - ýòî ïåðåâîä öèôðû â ÷èñëî
		chislo += plus;


		if(is_prime(chislo)) {
			if (chislo > (numbers_of_e / 10)) {
				cout << "First 10 digit prime is " << chislo;
				break;
			}
		}
	}


	file.close();

}

