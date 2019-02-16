#include <iostream>
using namespace std;

void main() {
	
	int imp[10];
	int *pointer;

	for (int i = 0; i < 10; i++){

		imp[i] = 2 * i + 1;

	}

	for (int z = 0; z < 2; z++) {

		pointer = imp; // pointer = imp[0]

		for (int i = 0; i < 10; i++) {


			cout << *pointer << " " << pointer << endl;
			pointer++;

		}

		cout << endl;

	}

	system("pause>nul");

}