#include <iostream>
#include <conio.h>
#include <math.h>
#define PI 3.141592

using namespace std;

void menu();
void registrar();
void matrices();
void operaciones();

void buscar();
void suma(int m,int n);
void resta(int m,int n);
void mtimes(int m);
void multi(int m,int n);

void compuesta();
void translate();
void scale();
void rotate();
void xrotate();
void yrotate();
void zrotate();
void points();

void cuaternios();

int times;
int id = 1;
int idpoints = 1;
int a;
int b;
int c;
int choice;
char option;

float x = 0;
float y = 0;
float z = 0;

float vx = 0;
float vy = 0;
float vz = 0;

float theta = 0;
float s = 0;
float u = 0;

char first;
char second;
bool found = false;
bool found2 = false;

struct traslacion {
	char idmat[11] = ("Traslación");
	int filas = 4;
	int columnas = 4;
	float inthemat[5][5];
};

struct escala {
	char idmat[11] = ("Escalación");
	int filas = 4;
	int columnas = 4;
	float inthemat[5][5];
};

struct x_axis {
	char idmat[7] = ("X-axis");
	int filas;
	int columnas;
	float inthemat[5][5];
};

struct y_axis {
	char idmat[7] = ("Y-axis");
	int filas;
	int columnas;
	float inthemat[5][5];
};

struct z_axis {
	char idmat[7] = ("Z-axis");
	int filas;
	int columnas;
	float inthemat[5][5];
};

struct puntos {
	char idmat[7] = ("Puntos");
	int filas;
	int columnas;
	float inthemat[5][8];
};

struct transformacion {
	int idmat;
	int filas;
	int columnas;
	float inthemat[5][8];
};

struct matriz {
	char idmat = 65;
	int filas;
	int columnas;
	float inthemat[7][7];
};

struct cuaternio {
	char idmat[10] = ("Cuaternio");
	int filas;
	int columnas;
	float inthemat[5][5];
};

traslacion t[1];
escala e[1];
x_axis xaxis[1];
y_axis yaxis[1];
z_axis zaxis[1];
puntos p[1];
transformacion transformation[7];
cuaternio q[1];

matriz database[27];

int main() {

	locale::global(locale("spanish"));

	menu();

	return 0;
}

void menu() {

	system("cls");
	cout << "Menu: " << endl;
	cout << endl;

	cout << "Entrar a: " << endl;
	cout << "A. Registrar Matrices " << endl;
	cout << "B. Matrices Registradas" << endl;
	cout << "C. Operaciones" << endl;
	cout << "D. Matriz Compuesta" << endl;
	cout << "E. Cuaternios" << endl;
	cout << "F. Salir del Menu" << endl;
	cin >> option;

	if (option > 96) {
		option -= 32;
	}

	switch (option)
	{
	case 'A':

		registrar();

		break;
	case 'B':

		matrices();

		break;
	case 'C':

		operaciones();

		break;
	case 'D':

		compuesta();
	
		break;
	case 'E':

		cuaternios();

		break;
	case 'F':
		
		system("cls");
		cout << "Ha salido del programa." << endl;

		system("pause > nul");

		break;
	default:
		cout << endl;
		cout << "Ingrese una letra válida.";

		system("pause > nul");
		menu();
		break;

	}
}

void registrar() {

	system("cls");
	cout << "Registro de Matrices: " << endl;
	cout << endl;

	cout << "Matrices a ingresar: ";
	cin >> a;

	for (int i = 0; i < a; i++) {

		if (database[id].idmat > 90) {
			id = 1;
			database[id].idmat = 65;
		}

		cout << endl;


		cout << "Matriz " << database[id].idmat << ": " << endl;
		cout << "Ingresar filas x columnas. " << endl;
		cout << "Filas: ";
		cin >> database[id].filas;
		cout << "Columnas: ";
		cin >> database[id].columnas;
		cout << endl;

		for (int j = 1; j <= database[id].filas; j++) {

			for (int k = 1; k <= database[id].columnas; k++) {

				cout << "Ingrese el número[" << j << "][" << k << "]: ";
				cin >> database[id].inthemat[j][k];
			}

		}

		id++;
		database[id].idmat = database[id - 1].idmat + 1;
	}

	matrices();
}

void matrices() {

	system("cls");
	cout << "Matrices Registradas: " << endl;
	cout << endl;

	for (int i = 1; i < id; i++) {

		cout << "Matriz " << database[i].idmat << ": " << endl;

		for (int j = 1; j <= database[i].filas; j++) {

			for (int k = 1; k <= database[i].columnas; k++) {

				cout << "[" << database[i].inthemat[j][k] << "]";
			}

			cout << endl;
		}

		cout << endl;

	}

	system("pause > nul");

	operaciones();
}

void operaciones() {

	system("cls");
	cout << "Operaciones de Matrices: " << endl;
	cout << endl;

	cout << "Realizar: " << endl;
	cout << "1. Matriz + Matriz" << endl;
	cout << "2. Matriz - Matriz" << endl;
	cout << "3. Matriz x Número" << endl;
	cout << "4. Matriz x Matriz" << endl;
	cout << "5. Ir al Menu" << endl;
	cin >> choice;

	if (choice < 5) {
		buscar();
	}
	else {

		switch (choice) {
		case 5:
			menu();
			break;
		default:
			cout << endl;
			cout << "Ingrese un número válido.";

			system("pause > nul");
			operaciones();
			break;
		}
	}
}

void buscar() {

	system("cls");
	cout << "Operaciones de Matrices: " << endl;
	cout << endl;

	cout << "Elegir Primera Matriz: ";
	cin >> first;

	if (first > 96 ) {
		first -= 32;
	}

	b = 1;

	while (b < id) {

		if (database[b].idmat == first) {
			cout << endl;
			cout << "Matriz " << database[b].idmat << ": " << endl;

			for (int j = 1; j <= database[b].filas; j++) {

				for (int k = 1; k <= database[b].columnas; k++) {

					cout << "[" << database[b].inthemat[j][k] << "]";
				}

				cout << endl;
			}
           
			found = true;
			break;

		}

		b++;
	}


	if (!found) {
		cout << endl;
		cout << "No había registros con " << first << "." << endl;

		system("pause > nul");
	}

    c = 1;

	if (choice != 3) {

		cout << endl;
		cout << "Elegir Segunda Matriz: ";
		cin >> second;

		if (second > 96) {
			second -= 32;
		}

		while (c < id) {

			if (database[c].idmat == second) {
				cout << endl;
				cout << "Matriz " << database[c].idmat << ": " << endl;

				for (int j = 1; j <= database[c].filas; j++) {

					for (int k = 1; k <= database[c].columnas; k++) {

						cout << "[" << database[c].inthemat[j][k] << "]";
					}

					cout << endl;
				}


				found2 = true;
				break;

			}

			c++;
		}


		if (!found2) {
			cout << endl;
			cout << "No había registros con " << second << "." << endl;

			system("pause > nul");
		}
	}

	if (!found || !found2 && choice !=3 ) {
		menu();
	}
	else {

		if (choice == 1) {
			suma(b, c);
		}
		else if (choice == 2) {
			resta(b, c);
		}
		else if (choice == 3) {
			mtimes(b);
		}
		else {
			multi(b, c);
		}
	}
}

void suma(int m, int n) {

	cout << endl;
	cout << "Suma de Matrices: " << endl;

	if (database[b].filas != database[c].filas || database[b].columnas != database[c].columnas || !found || !found2) {

		cout << endl;
		cout << "La suma de matrices no se puede realizar ya que son de diferentes dimensiones.";

	}
	else {

		for (int i = 1; i <= database[b].filas; i++) {
			for (int j = 1; j <= database[c].columnas; j++) {

				database[id].inthemat[i][j] = database[b].inthemat[i][j] + database[c].inthemat[i][j];
			}
		}

		database[id].filas = database[b].filas;
		database[id].columnas = database[b].columnas;
		database[id].idmat = database[id - 1].idmat + 1;

		cout << endl;
		cout << database[b].idmat << " + " << database[c].idmat << ":" << endl;

		for (int j = 1; j <= database[id].filas; j++) {

			for (int k = 1; k <= database[id].columnas; k++) {

				cout << "[" << database[id].inthemat[j][k] << "]";
			}

			cout << endl;
		}

		cout << endl;
		cout << "Matriz registrada como: " << database[id].idmat;

		id++;
		database[id].idmat = database[id - 1].idmat + 1;

	}
	system("pause > nul ");
	menu();
}

void resta(int m, int n) {

	cout << endl;
	cout << "Resta de Matrices: " << endl;

	if (database[b].filas != database[c].filas || database[b].columnas != database[c].columnas || !found || !found2) {

		cout << endl;
		cout << "La resta de matrices no se puede realizar ya que son de diferentes dimensiones.";
	}
	else {

		for (int i = 1; i <= database[b].filas; i++) {
			for (int j = 1; j <= database[c].columnas; j++) {

				database[id].inthemat[i][j] = database[b].inthemat[i][j] - database[c].inthemat[i][j];
			}
		}

		database[id].filas = database[b].filas;
		database[id].columnas = database[b].columnas;
		database[id].idmat = database[id - 1].idmat + 1;

		cout << endl;
		cout << database[b].idmat << " - " << database[c].idmat << ":" << endl;

		for (int j = 1; j <= database[id].filas; j++) {

			for (int k = 1; k <= database[id].columnas; k++) {

				cout << "[" << database[id].inthemat[j][k] << "]";
			}

			cout << endl;
		}

		cout << endl;
		cout << "Matriz registrada como: " << database[id].idmat;

		id++;
		database[id].idmat = database[id - 1].idmat + 1;
	}

	system("pause > nul ");
	menu();
}

void mtimes(int m) {

	cout << endl;
	cout << "Multiplicar matriz " << database[b].idmat << " por: ";
	cin >> times;

	cout << endl;
	cout << "Matriz por Número:" << endl;

	for (int i = 1; i <= database[b].filas; i++) {
			for (int j = 1; j <= database[b].columnas; j++) {

				database[id].inthemat[i][j] = database[b].inthemat[i][j] * times;
			}
	}

	database[id].filas = database[b].filas;
	database[id].columnas = database[b].columnas;
	database[id].idmat = database[id - 1].idmat + 1;

	cout << endl;
	cout << times << database[b].idmat << ":" << endl;

	for (int j = 1; j <= database[id].filas; j++) {

		for (int k = 1; k <= database[id].columnas; k++) {

				cout << "[" << database[id].inthemat[j][k] << "]";
		}

			cout << endl;
	}

	cout << endl;
	cout << "Matriz registrada como: " << database[id].idmat;

	id++;
	database[id].idmat = database[id - 1].idmat + 1;

    system("pause > nul ");
	menu();

}

void multi(int m, int n){

	cout << endl;
	cout << "Matriz por Matriz: " << endl;

	if (database[b].columnas != database[c].filas || !found || !found2) {

		cout << endl;
		cout << "La multiplicacion de matrices no se puede realizar." << endl;
		cout << "El número de columnas de la Matriz " << database[b].idmat << " es diferente a el de las filas de la Matriz " << database[c].idmat << ".";
	}
	else {

		database[id].filas = database[b].filas;
		database[id].columnas = database[c].columnas;

		for (int i = 1; i <= database[b].filas; i++) {
			for (int j = 1; j <= database[c].columnas; j++){

				database[id].inthemat[i][j] = 0;

					for (int k = 1; k <= database[c].filas; k++) {

						database[id].inthemat[i][j] = database[id].inthemat[i][j] + database[b].inthemat[i][k] * database[c].inthemat[k][j];

				}
			}
		}

		database[id].idmat = database[id - 1].idmat + 1;

		cout << endl;
		cout << database[b].idmat << database[c].idmat << ":" << endl;

		for (int j = 1; j <= database[id].filas; j++) {

			for (int k = 1; k <= database[id].columnas; k++) {

				cout << "[" << database[id].inthemat[j][k] << "]";
			}

			cout << endl;
		}

		cout << endl;
		cout << "Matriz registrada como: " << database[id].idmat;

		id++;
		database[id].idmat = database[id - 1].idmat + 1;
	}
	system("pause > nul");
	menu();
}

void points() {

	system("cls");
	cout << "Puntos: " << endl;
	cout << endl;

	cout << "Puntos a ingresar: ";
	cin >> a;
	cout << endl;

	p[0].filas = 4;
	p[0].columnas = a;

	for (int i = 1; i <= a; i++) {

		cout << "Punto " << i << ": " << endl;
		cout << "x: ";
		cin >> x;
		cout << "y: ";
		cin >> y;
		cout << "z: ";
		cin >> z;
		cout << endl;

		int j = 1;
		p[0].inthemat[j][i] = x;
		p[0].inthemat[j + 1][i] = y;
		p[0].inthemat[j + 2][i] = z;
		p[0].inthemat[j + 3][i] = 1;

	}

	/*
	cout << "Matriz de Puntos:" << endl;

	for (int j = 1; j <= p[0].filas; j++) {

		for (int k = 1; k <= p[0].columnas; k++) {

			cout << "[" << p[0].inthemat[j][k] << "]";
		}

		cout << endl;
	}

	system("pause>nul");
	*/
}

void translate() {

	system("cls");
	cout << "Translacion: " << endl;
	cout << endl;

	cout << "Ingresar coordenadas de traslacion:" << endl;
	cout << "Tx: ";
	cin >> x;
	cout << "Ty: ";
	cin >> y;
	cout << "Tz: ";
	cin >> z;
	cout << endl;

	t[0].filas = 4;
	t[0].columnas = 4;

	// traslacion
	for (int i = 1; i <= t[0].filas ; i++) {
		for (int j = 1; j <= t[0].columnas; j++) {

			if (i == j) {
				t[0].inthemat[i][j] = 1;
			}
			else {
				t[0].inthemat[i][j] = 0;
			}
		}
	}

	t[0].inthemat[1][4] = x;
	t[0].inthemat[2][4] = y;
	t[0].inthemat[3][4] = z;

	/*
	cout << "Matriz Traslacion:" << endl;

	for (int j = 1; j <= t[0].filas; j++) {

		for (int k = 1; k <= t[0].columnas; k++) {

			cout << "[" << t[0].inthemat[j][k] << "]";
		}

		cout << endl;
	}

	system("pause>nul");
	*/

	transformation[idpoints].filas = t[0].filas;
	transformation[idpoints].columnas = p[0].columnas;

	for (int i = 1; i <= t[0].filas; i++) {
		for (int j = 1; j <= p[0].columnas; j++) {

			transformation[idpoints].inthemat[i][j] = 0;

			for (int k = 1; k <= p[0].filas; k++) {

				transformation[idpoints].inthemat[i][j] = transformation[idpoints].inthemat[i][j] + t[0].inthemat[i][k] * p[0].inthemat[k][j];

			}
		}
	}

	/*
	cout << endl;
	cout << "T" << p->idmat <<":" << endl;

	for (int j = 1; j <= transformation[idpoints].filas; j++) {

		for (int k = 1; k <= transformation[idpoints].columnas; k++) {

			cout << "[" << transformation[idpoints].inthemat[j][k] << "]";
		}

		cout << endl;
	}
	*/

	for (int i = 1; i <= a; i++) {

		int j = 1;

		cout << "T Punto " << i << ": " << endl;
		cout << "x': " << transformation[idpoints].inthemat[j][i] << endl;
		cout << "y': " << transformation[idpoints].inthemat[j + 1][i] << endl;
		cout << "z': " << transformation[idpoints].inthemat[j + 2][i] << endl;

		cout << endl;
	}

	idpoints++;

	system("pause > nul");

	menu();

}

void scale() {

	system("cls");
	cout << "Escalacion: " << endl;
	cout << endl;

	cout << "Ingresar coordenadas de Escalacion:" << endl;
	cout << "Sx: ";
	cin >> x;
	cout << "Sy: ";
	cin >> y;
	cout << "Sz: ";
	cin >> z;
	cout << endl;

	e[0].filas = 4;
	e[0].columnas = 4;

	//Escalacion
	for (int i = 1; i <= e[0].filas; i++) {
		for (int j = 1; j <= e[0].columnas; j++) {

			if (i == j) {
				e[0].inthemat[i][j] = 1;
			}
			else {
				e[0].inthemat[i][j] = 0;
			}
		}
	}

	e[0].inthemat[1][1] = x;
	e[0].inthemat[2][2] = y;
	e[0].inthemat[3][3] = z;

	/*
	cout << "Matriz Escalacion:" << endl;

	for (int j = 1; j <= e[0].filas; j++) {
		for (int k = 1; k <= e[0].columnas; k++) {
			cout << "[" << e[0].inthemat[j][k] << "]";
		}
		cout << endl;
	}

	system("pause>nul");
	*/

	transformation[idpoints].filas = e[0].filas;
	transformation[idpoints].columnas = e[0].columnas;

	for (int i = 1; i <= e[0].filas; i++) {
		for (int j = 1; j <= e[0].columnas; j++) {

			transformation[idpoints].inthemat[i][j] = 0;

			for (int k = 1; k <= p[0].filas; k++) {

				transformation[idpoints].inthemat[i][j] = transformation[idpoints].inthemat[i][j] + e[0].inthemat[i][k] * p[0].inthemat[k][j];

			}
		}
	}

	/*
	cout << endl;
	cout << "S" << p->idmat <<":" << endl;

	for (int j = 1; j <= transformation[idpoints].filas; j++) {
		for (int k = 1; k <= transformation[idpoints].columnas; k++) {
			
			cout << "[" << transformation[idpoints].inthemat[j][k] << "]";
		}
		cout << endl;
	}
	
	system("pause > nul");
	*/

	for (int i = 1; i <= a; i++) {

		int j = 1;

		cout << "S Punto " << i << ": " << endl;
		cout << "x': " << transformation[idpoints].inthemat[j][i] << endl;
		cout << "y': " << transformation[idpoints].inthemat[j + 1][i] << endl;
		cout << "z': " << transformation[idpoints].inthemat[j + 2][i] << endl;

		cout << endl;
	}

	idpoints++;

	system("pause > nul");

	menu();
}

void rotate() {

	system("cls");
	cout << "Rotacion: " << endl;
	cout << endl;

	cout << "Ingresar grados de Rotacion:" << endl;
	cout << "Rx: ";
	cin >> x;
	x = x * (PI / 180);
	cout << "Ry: ";
	cin >> y;
	y = y * (PI / 180);
	cout << "Rz: ";
	cin >> z;
	z = z * (PI / 180);
	cout << endl;

	if (x != 0) {

		xrotate();
	}

	if (y != 0) {

		yrotate();
	}

	if (z != 0) {

		zrotate();
	}

	idpoints++;
	menu();
}

void xrotate() {

	xaxis[0].filas = 4;
	xaxis[0].columnas = 4;

	//Rotacion x
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {

			if (i == j) {
				xaxis[0].inthemat[i][j] = 1;
			}
			else {
				xaxis[0].inthemat[i][j] = 0;
			}
		}
	}

	xaxis[0].inthemat[2][2] = cos(x);
	xaxis[0].inthemat[2][3] = -sin(x);
	xaxis[0].inthemat[3][2] = sin(x);
	xaxis[0].inthemat[3][3] = cos(x);

	/*
	cout << "Matriz Rotacion en X:" << endl;

	for (int j = 1; j <= xaxis[0].filas; j++) {
		for (int k = 1; k <= xaxis[0].columnas; k++) {
			
			cout << "[" << xaxis[0].inthemat[j][k] << "]";
		}

		cout << endl;
	}

	system("pause>nul");
	*/

	transformation[idpoints].filas = xaxis[0].filas;
	transformation[idpoints].columnas = p[0].columnas;

	for (int i = 1; i <= xaxis[0].filas; i++) {
		for (int j = 1; j <= p[0].columnas; j++) {

			transformation[idpoints].inthemat[i][j] = 0;

			for (int k = 1; k <= p[0].filas; k++) {

				transformation[idpoints].inthemat[i][j] = transformation[idpoints].inthemat[i][j] + xaxis[0].inthemat[i][k] * p[0].inthemat[k][j];
			}
		}
	}

	/*
	cout << endl;
	cout << "Rx" << p->idmat <<":" << endl;

	for (int j = 1; j <= transformation[idpoints].filas; j++) {
		for (int k = 1; k <= transformation[idpoints].columnas; k++) {
			
			cout << "[" << transformation[idpoints].inthemat[j][k] << "]";
		}
		cout << endl;
	}
	*/

	if ( y == 0 && z == 0) {
		for (int i = 1; i <= a; i++) {

			int j = 1;

			cout << "Rx Punto " << i << ": " << endl;
			cout << "x': " << transformation[idpoints].inthemat[j][i] << endl;
			cout << "y': " << transformation[idpoints].inthemat[j + 1][i] << endl;
			cout << "z': " << transformation[idpoints].inthemat[j + 2][i] << endl;

			cout << endl;
		}

		system("pause > nul");
	}
}

void yrotate() {

	yaxis[0].filas = 4;
	yaxis[0].columnas = 4;

	//Rotacion y
	for (int i = 1; i <= yaxis[0].filas; i++) {
		for (int j = 1; j <= yaxis[0].columnas; j++) {

			if (i == j) {
				yaxis[0].inthemat[i][j] = 1;
			}
			else {
				yaxis[0].inthemat[i][j] = 0;
			}
		}
	}

	yaxis[0].inthemat[1][1] = cos(y);
	yaxis[0].inthemat[1][3] = sin(y);
	yaxis[0].inthemat[3][1] = -sin(y);
	yaxis[0].inthemat[3][3] = cos(y);

	/*
	cout << "Matriz Rotacion en Y:" << endl;

	for (int j = 1; j <= yaxis[0].filas; j++) {
	for (int k = 1; k <= yaxis[0].columnas; k++) {

	cout << "[" << xaxis[0].inthemat[j][k] << "]";
	}

	cout << endl;
	}

	system("pause>nul");
	*/

	transformation[idpoints].filas = yaxis[0].filas;
	transformation[idpoints].columnas = p[0].columnas;


	if (x == 0) {

		for (int i = 1; i <= yaxis[0].filas; i++) {
			for (int j = 1; j <= p[0].columnas; j++) {

				transformation[idpoints].inthemat[i][j] = 0;

				for (int k = 1; k <= p[0].filas; k++) {

					transformation[idpoints].inthemat[i][j] = transformation[idpoints].inthemat[i][j] + yaxis[0].inthemat[i][k] * p[0].inthemat[k][j];

				}
			}
		}
	}

	else {

		for (int i = 1; i <= yaxis[0].filas; i++) {
			for (int j = 1; j <= p[0].columnas; j++) {

				transformation[idpoints].inthemat[i][j] = 0;

				for (int k = 1; k <= p[0].filas; k++) {

					transformation[idpoints].inthemat[i][j] = transformation[idpoints].inthemat[i][j] + yaxis[0].inthemat[i][k] * transformation[idpoints].inthemat[k][j];

				}
			}
		}

	}

	/*
	cout << endl;
	cout << "Ry" << p->idmat <<":" << endl;

	for (int j = 1; j <= transformation[idpoints].filas; j++) {
	for (int k = 1; k <= transformation[idpoints].columnas; k++) {

	cout << "[" << transformation[idpoints].inthemat[j][k] << "]";
	}
	cout << endl;
	}
	*/

	for (int i = 1; i <= a; i++) {

		if (x == 0 && z == 0) {
			cout << "Ry Punto " << i << ": " << endl;
		}
		else {
			cout << "Rxy Punto " << i << ": " << endl;
		}

		int j = 1;

		cout << "x': " << transformation[idpoints].inthemat[j][i] << endl;
		cout << "y': " << transformation[idpoints].inthemat[j + 1][i] << endl;
		cout << "z': " << transformation[idpoints].inthemat[j + 2][i] << endl;

		cout << endl;
	}

        system("pause > nul");
}

void zrotate() {

	zaxis[0].filas = 4;
	zaxis[0].columnas = 4;

	//Rotacion z
	for (int i = 1; i <= zaxis[0].filas; i++) {
		for (int j = 1; j <= zaxis[0].columnas; j++) {

			if (i == j) {
				zaxis[0].inthemat[i][j] = 1;
			}
			else {
				zaxis[0].inthemat[i][j] = 0;
			}
		}
	}

	zaxis[0].inthemat[1][1] = cos(z);
	zaxis[0].inthemat[1][2] = -sin(z);
	zaxis[0].inthemat[2][1] = sin(z);
	zaxis[0].inthemat[2][2] = cos(z);

	/*
	cout << "Matriz Rotacion en Z:" << endl;

	for (int j = 1; j <= zaxis[0].filas; j++) {
	for (int k = 1; k <= zaxis[0].columnas; k++) {

	cout << "[" << xaxis[0].inthemat[j][k] << "]";
	}

	cout << endl;
	}

	system("pause>nul");
	*/

	transformation[idpoints].filas = zaxis[0].filas;
	transformation[idpoints].columnas = p[0].columnas;


	if (x == 0 && y == 0) {
		for (int i = 1; i <= zaxis[0].filas; i++) {
			for (int j = 1; j <= p[0].columnas; j++) {

				transformation[idpoints].inthemat[i][j] = 0;

				for (int k = 1; k <= p[0].filas; k++) {

					transformation[idpoints].inthemat[i][j] = transformation[idpoints].inthemat[i][j] + zaxis[0].inthemat[i][k] * p[0].inthemat[k][j];

				}
			}
		}
	}
	else {
		for (int i = 1; i <= zaxis[0].filas; i++) {
			for (int j = 1; j <= p[0].columnas; j++) {

				transformation[idpoints].inthemat[i][j] = 0;

				for (int k = 1; k <= p[0].filas; k++) {

					transformation[idpoints].inthemat[i][j] = transformation[idpoints].inthemat[i][j] + zaxis[0].inthemat[i][k] * transformation[idpoints].inthemat[k][j];

				}
			}
		}

	}

	/*
	cout << endl;
	cout << "Rz" << p->idmat <<":" << endl;

	for (int j = 1; j <= transformation[idpoints].filas; j++) {
	for (int k = 1; k <= transformation[idpoints].columnas; k++) {

	cout << "[" << transformation[idpoints].inthemat[j][k] << "]";
	}
	cout << endl;
	}
	*/

	for (int i = 1; i <= a; i++) {

		if (x == 0 && y == 0) {
			cout << "Rz Punto " << i << ": " << endl;
		}
		else if (x != 0 && y == 0) {
			cout << "Rxz Punto " << i << ": " << endl;
		}
		else if (x == 0 && y != 0) {
			cout << "Ryz Punto " << i << ": " << endl;
		}
		else {
			cout << "Rxyz Punto " << i << ": " << endl;
		}

		int j = 1;

		cout << "x': " << transformation[idpoints].inthemat[j][i] << endl;
		cout << "y': " << transformation[idpoints].inthemat[j + 1][i] << endl;
		cout << "z': " << transformation[idpoints].inthemat[j + 2][i] << endl;

		cout << endl;
	}


	system("pause > nul");
}

void compuesta() {

	system("cls");
	cout << "Matriz Compuesta: " << endl;
	cout << endl;

	cout << "Realizar:" << endl;
	cout << "R. Rotacion" << endl;
	cout << "S. Escalacion" << endl;
	cout << "T. Traslacion" << endl;
	cout << "U. Ir al Menu" << endl;
	cin >> option;

	if (option > 96) {
		option -= 32;
	}

	switch (option){
	case 'R':

		points();
		rotate();

		break;
	case 'S':

		points();
		scale();

		break;
	case 'T':

		points();
		translate();

		break;
	case 'U':

		menu();

		break;
	default:

		cout << endl;
		cout << "Ingrese una letra válida.";

		system("pause > nul");
		compuesta();

		break;
	}

}

void cuaternios() {

	system("cls");
	cout << "Cuaternios: " << endl;
	cout << endl;

	cout << "Punto: " << endl;
	cout << "x: ";
	cin >> x;
	cout << "y: ";
	cin >> y;
	cout << "z: ";
	cin >> z;
	cout << endl;

	p[0].filas = 3;
	p[0].columnas = 1;

	p[0].inthemat[1][1] = x;
	p[0].inthemat[2][1] = y;
	p[0].inthemat[3][1] = z;

	cout << "Vector: " << endl;
	cout << "Vx: ";
	cin >> vx;
	cout << "Vy: ";
	cin >> vy;
	cout << "Vz: ";
	cin >> vz;
	cout << endl;

	cout << "Ángulo: ";
	cin >> theta;
	theta = theta / 2;

	u = (vx * vx) + (vy * vy) + (vz * vz);

	vx = vx / sqrt(u);
	vy = vy / sqrt(u);
	vz = vz / sqrt(u);

	if (theta == 90) {
		s = 0;
	}
	else {
		theta = theta * (PI / 180);

		s = cos(theta);
		vx = vx * sin(theta);
		vy = vy * sin(theta);
		vz = vz * sin(theta);

	}

	q[0].filas = 3;
	q[0].columnas = 3;

	q[0].inthemat[1][1] = 1 - (2 * pow(vy,2)) - (2 * pow(vz, 2));
	q[0].inthemat[1][2] = (2 * vx * vy) - (2 * s * vz);
	q[0].inthemat[1][3] = (2 * vx * vz)+ (2 * s * vy);
		
	q[0].inthemat[2][1] = (2 * vx * vy) + (2 * s * vz);
    q[0].inthemat[2][2] = 1 - (2 * vx * vx) - (2 * vz * vz);
	q[0].inthemat[2][3] = (2 * vy * vz) - (2 * s * vx);

	q[0].inthemat[3][1] = (2 * vx * vz) - (2 * s * vy);
	q[0].inthemat[3][2] = (2 * vy * vz) + (2 * s * vx);
	q[0].inthemat[3][3] = 1 - (2 * pow(vx, 2)) - (2 * pow(vy, 2));
    
	/*
	cout << endl;
	cout << "Matriz Cuaternios:" << endl;

	for (int j = 1; j <= q[0].filas; j++) {
	for (int k = 1; k <= q[0].columnas; k++) {
	cout << "[" << q[0].inthemat[j][k] << "]";
	}
	cout << endl;
	}

	system("pause>nul");
	*/
	
    
	transformation[idpoints].filas = 3;
	transformation[idpoints].columnas = 1;

	for (int i = 1; i <= t[0].filas; i++) {
		for (int j = 1; j <= p[0].columnas; j++) {

			transformation[idpoints].inthemat[i][j] = 0;

			for (int k = 1; k <= p[0].filas; k++) {

				transformation[idpoints].inthemat[i][j] = transformation[idpoints].inthemat[i][j] + q[0].inthemat[i][k] * p[0].inthemat[k][j];

			}
		}
	}

	cout << endl;

	cout << "Q' Punto: " << endl;
	cout << "x': " << transformation[idpoints].inthemat[1][1] << endl;
	cout << "y': " << transformation[idpoints].inthemat[2][1] << endl;
	cout << "z': " << transformation[idpoints].inthemat[3][1] << endl;

	cout << endl;

	idpoints++;

	system("pause > nul");

	menu();

}


