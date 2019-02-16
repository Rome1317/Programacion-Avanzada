#include <iostream>
#include <time.h>
using namespace std;

int a1[5];
int a2[5];
int a3[5];
int a4[5];
int a5[5];

int *point[5];

void main() {

	srand(time(NULL));

	for (int i = 0; i < 5; i++) {

		a1[i] = rand() % 100;
		a2[i] = rand() % 100;
		a3[i] = rand() % 100;
		a4[i] = rand() % 100;
		a5[i] = rand() % 100;

	}

	point[0] = a1;
	point[1] = a2;
	point[2] = a3;
	point[3] = a4;
	point[4] = a5;

	for (int i = 0; i < 5; i++) {

		for (int j = 0; j < 5; j++) {

			cout << *point[i] << endl;
			point[i]++;

		}

		cout << endl;

	}

	system("pause > nul");

}