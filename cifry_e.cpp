/*
	B - основание системы счисления
		B = 10 = > 1 разряд
		B = 100 = > 2 разряда

		N - кол - во разрядов экспоненты
		K = N / log по основанию 10 от B - колво элементов массива

		e = 1 + Сумма бесконечность k=1 (1/k);    1/k - uk

		1/(k+1)! = 1/(k!)*1/(k+1)
*/

#include <iostream>
#include <cmath>

using namespace std;
typedef unsigned long long mytype;

int B = 10000;
int N = 1000;
//const int K = N / log10(B) + 1;
const int K = 251;
int k = 1;

long long array[K];

mytype* e = new mytype[K];
mytype* uk = new mytype[K];


void SetData(int K, mytype* x, int n) {
	for (int i = 1; i < K; i++) {
		x[i] = 0;
	}
	x[0] = n;
}

bool IsZero(int K, mytype* uk) {
	for (int i = 0; i < K; i++) {
		if (uk[i] != 0) {
			return false;
		}
	}
	return true;
}

void Add(mytype* x, mytype* y, int N) {
	mytype carry = 0;

	for (int i = N - 1; i >= 0; i--) {
		x[i] += y[i] + carry;
		if (x[i] >= B) {
			x[i] -= B;
			carry = 1;
		}
		else carry = 0;
	}
}

void Div(mytype* x, int d) {
	mytype carry = 0, xi, q;
	for (int i = 0; i < N; i++) {
		xi = x[i] + carry * B;
		q = xi / d;   // не поняла, почему выскакивает Unhandled exception Access violation reading location
		carry = xi - q * d;
		x[i] = q;
	}
}

int main() {
	SetData(K, uk, 1);
	SetData(K, e, 1); //заполняет нулями
	while (!IsZero(K, uk)) { //IsZero смотрит, все ли числа 0
		Add(e, uk, K); //e+uk
		Div(uk, k); //делит uk на k
		k++;
	}
}







