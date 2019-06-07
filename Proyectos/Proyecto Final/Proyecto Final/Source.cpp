#include <iostream>
#include <math.h>

using namespace std;

void menu();
void registrar();
void matrices();
void operaciones();
void matricescomp();
void mxv();

void buscar();
void suma(int, int);
void resta(int, int);
void mtimes(int);
void multi(int, int);

void compuesta();
void translate();
void scale();
void rotate();
void xrotate();
void yrotate();
void zrotate();
void points();

void compuesta2();

void cuaternios();

int times;
int id = 1;
int idmat = 65;
int idt = 1;
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
const float PI = 3.141592;

char first;
char second;
bool found = false;
bool found2 = false;

struct traslacion {
	char idmat[11] = ("Traslación");
	int filas;
	int columnas;
	float in[5][5];
};

struct escala {
	char idmat[11] = ("Escalación");
	int filas;
	int columnas;
	float in[5][5];
};

struct x_axis {
	char idmat[7] = ("X-axis");
	int filas;
	int columnas;
	float in[5][5];
};

struct y_axis {
	char idmat[7] = ("Y-axis");
	int filas;
	int columnas;
	float in[5][5];
};

struct z_axis {
	char idmat[7] = ("Z-axis");
	int filas;
	int columnas;
	float in[5][5];
};

struct puntos {
	char idmat[7] = ("Puntos");
	int filas;
	int columnas;
	float in[5][9];
};

struct transformacion {
	int idmat;
	int filas;
	int columnas;
	float in[5][9];
};

struct matriz {
	char idmat;
	int filas;
	int columnas;
	float in[11][11];
};

struct cuaternio {
	char idmat[10] = ("Cuaternio");
	int filas;
	int columnas;
	float in[5][5];
};

traslacion t;
escala e;
x_axis rx;
y_axis ry;
z_axis rz;
puntos p;
cuaternio q;
transformacion mt[11];

matriz m[26];

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
	cout << "D. Matriz x Vector" << endl;
	cout << "E. Matriz Compuesta" << endl;
	cout << "F. Cuaterniones" << endl;
	cout << "G. Matrices Compuestas Registradas" << endl;
	cout << "H. Salir del Menu" << endl;
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

		mxv();

		break;
	case 'E':

		compuesta();

		break;
	case 'F':

		cuaternios();

		break;
	case 'G':

		matricescomp();

		break;
	case 'H':

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

		m[id].idmat = idmat;

		if (m[id].idmat > 90) {
			id = 1;
			m[id].idmat = 65;
		}

		cout << endl;


		cout << "Matriz " << m[id].idmat << ": " << endl;
		cout << "Ingresar filas x columnas. " << endl;
		cout << "Filas: ";
		cin >> m[id].filas;
		cout << "Columnas: ";
		cin >> m[id].columnas;
		cout << endl;

		for (int j = 1; j <= m[id].filas; j++) {

			for (int k = 1; k <= m[id].columnas; k++) {

				cout << "Ingrese el número[" << j << "][" << k << "]: ";
				cin >> m[id].in[j][k];
			}

		}

		id++;
		idmat++;
	}

	matrices();
}

void matrices() {

	system("cls");
	cout << "Matrices Registradas: " << endl;
	cout << endl;

	for (int i = 1; i < id; i++) {

		cout << "Matriz " << m[i].idmat << ": " << endl;

		for (int j = 1; j <= m[i].filas; j++) {

			for (int k = 1; k <= m[i].columnas; k++) {

				cout << "[" << m[i].in[j][k] << "]";
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

	if (first > 96) {
		first -= 32;
	}

	b = 1;

	while (b < id) {

		if (m[b].idmat == first) {
			cout << endl;
			cout << "Matriz " << m[b].idmat << ": " << endl;

			for (int j = 1; j <= m[b].filas; j++) {

				for (int k = 1; k <= m[b].columnas; k++) {

					cout << "[" << m[b].in[j][k] << "]";
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

			if (m[c].idmat == second) {
				cout << endl;
				cout << "Matriz " << m[c].idmat << ": " << endl;

				for (int j = 1; j <= m[c].filas; j++) {

					for (int k = 1; k <= m[c].columnas; k++) {

						cout << "[" << m[c].in[j][k] << "]";
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

	if (!found || !found2 && choice != 3) {
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

void suma(int, int) {

	cout << endl;
	cout << "Suma de Matrices: " << endl;

	if (m[b].filas != m[c].filas || m[b].columnas != m[c].columnas || !found || !found2) {

		cout << endl;
		cout << "La suma de matrices no se puede realizar ya que son de diferentes dimensiones.";

	}
	else {

		for (int i = 1; i <= m[b].filas; i++) {
			for (int j = 1; j <= m[c].columnas; j++) {

				m[id].in[i][j] = m[b].in[i][j] + m[c].in[i][j];
			}
		}

		m[id].filas = m[b].filas;
		m[id].columnas = m[b].columnas;
		m[id].idmat = idmat;

		cout << endl;
		cout << m[b].idmat << " + " << m[c].idmat << ":" << endl;

		for (int j = 1; j <= m[id].filas; j++) {

			for (int k = 1; k <= m[id].columnas; k++) {

				cout << "[" << m[id].in[j][k] << "]";
			}

			cout << endl;
		}

		cout << endl;
		cout << "Matriz registrada como: " << m[id].idmat;

		id++;
		idmat++;

	}
	system("pause > nul ");
	menu();
}

void resta(int, int) {

	cout << endl;
	cout << "Resta de Matrices: " << endl;

	if (m[b].filas != m[c].filas || m[b].columnas != m[c].columnas || !found || !found2) {

		cout << endl;
		cout << "La resta de matrices no se puede realizar ya que son de diferentes dimensiones.";
	}
	else {

		for (int i = 1; i <= m[b].filas; i++) {
			for (int j = 1; j <= m[c].columnas; j++) {

				m[id].in[i][j] = m[b].in[i][j] - m[c].in[i][j];
			}
		}

		m[id].filas = m[b].filas;
		m[id].columnas = m[b].columnas;
		m[id].idmat = idmat;

		cout << endl;
		cout << m[b].idmat << " - " << m[c].idmat << ":" << endl;

		for (int j = 1; j <= m[id].filas; j++) {

			for (int k = 1; k <= m[id].columnas; k++) {

				cout << "[" << m[id].in[j][k] << "]";
			}

			cout << endl;
		}

		cout << endl;
		cout << "Matriz registrada como: " << m[id].idmat;

		id++;
		idmat++;
	}

	system("pause > nul ");
	menu();
}

void mtimes(int) {

	cout << endl;
	cout << "Multiplicar matriz " << m[b].idmat << " por: ";
	cin >> times;

	cout << endl;
	cout << "Matriz por Número:" << endl;

	for (int i = 1; i <= m[b].filas; i++) {
		for (int j = 1; j <= m[b].columnas; j++) {

			m[id].in[i][j] = m[b].in[i][j] * times;
		}
	}

	m[id].filas = m[b].filas;
	m[id].columnas = m[b].columnas;
	m[id].idmat = idmat;

	cout << endl;
	cout << times << m[b].idmat << ":" << endl;

	for (int j = 1; j <= m[id].filas; j++) {

		for (int k = 1; k <= m[id].columnas; k++) {

			cout << "[" << m[id].in[j][k] << "]";
		}

		cout << endl;
	}

	cout << endl;
	cout << "Matriz registrada como: " << m[id].idmat;

	id++;
	idmat++;

	system("pause > nul ");
	menu();

}

void multi(int, int) {

	cout << endl;
	cout << "Matriz por Matriz: " << endl;

	if (m[b].columnas != m[c].filas || !found || !found2) {

		cout << endl;
		cout << "La multiplicacion de matrices no se puede realizar." << endl;
		cout << "El número de columnas de la Matriz " << m[b].idmat << " es diferente a el de las filas de la Matriz " << m[c].idmat << ".";
	}
	else {

		m[id].filas = m[b].filas;
		m[id].columnas = m[c].columnas;

		for (int i = 1; i <= m[b].filas; i++) {
			for (int j = 1; j <= m[c].columnas; j++) {

				m[id].in[i][j] = 0;

				for (int k = 1; k <= m[c].filas; k++) {

					m[id].in[i][j] = m[id].in[i][j] + m[b].in[i][k] * m[c].in[k][j];

				}
			}
		}

		m[id].idmat = idmat;

		cout << endl;
		cout << m[b].idmat << m[c].idmat << ":" << endl;

		for (int j = 1; j <= m[id].filas; j++) {

			for (int k = 1; k <= m[id].columnas; k++) {

				cout << "[" << m[id].in[j][k] << "]";
			}

			cout << endl;
		}

		cout << endl;
		cout << "Matriz registrada como: " << m[id].idmat;

		id++;
		idmat++;
	}
	system("pause > nul");
	menu();
}

void points() {

	for (int i = 1; i <= p.filas; i++) {
		for (int j = 1; j <= p.columnas; j++) {

			t.in[i][j] = p.in[i][j];
		}
	}


	system("cls");
	cout << "Puntos: " << endl;
	cout << endl;

	cout << "Puntos a ingresar: ";
	cin >> a;
	cout << endl;

	p.filas = 4;
	p.columnas = a;

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
		p.in[j][i] = x;
		p.in[j + 1][i] = y;
		p.in[j + 2][i] = z;
		p.in[j + 3][i] = 1;

	}

	/*
	cout << "Matriz de Puntos:" << endl;
	for (int j = 1; j <= p.filas; j++) {
		for (int k = 1; k <= p.columnas; k++) {
			cout << "[" << p.inthemat[j][k] << "]";
		}
		cout << endl;
	}
	system("pause>nul");
	*/


	mt[idt].filas = 4;
	mt[idt].columnas = p.columnas;

	for (int i = 1; i <= mt[idt].filas; i++) {
		for (int j = 1; j <= mt[idt].columnas; j++) {

			mt[idt].in[i][j] = 0;

			for (int k = 1; k <= p.filas; k++) {

				mt[idt].in[i][j] = mt[idt].in[i][j] + t.in[i][k] * p.in[k][j];

			}
		}
	}

	cout << "Puntos Resultantes:" << endl;
	cout << endl;

	for (int i = 1; i <= a; i++) {

		if (mt[idt].in[1][i] < 0.01 && mt[idt].in[1][i] > 0 || mt[idt].in[1][i] < 0 && mt[idt].in[1][i] > -0.01) {
			mt[idt].in[1][i] = 0;
		}
		if (mt[idt].in[2][i] < 0.01 && mt[idt].in[2][i] > 0 || mt[idt].in[2][i] < 0 && mt[idt].in[2][i] > -0.01) {
			mt[idt].in[2][1] = 0;
		}
		if (mt[idt].in[3][i] < 0.01 && mt[idt].in[3][i] > 0 || mt[idt].in[3][i] < 0 && mt[idt].in[3][i] > -0.01) {
			mt[idt].in[3][i] = 0;
		}

		cout << "Punto " << i << ": " << endl;
		cout << "x': " << mt[idt].in[1][i] << endl;
		cout << "y': " << mt[idt].in[2][i] << endl;
		cout << "z': " << mt[idt].in[3][i] << endl;

		cout << endl;
	}

	system("pause > nul");

	idt++;
	menu();

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

	t.filas = 4;
	t.columnas = 4;

	// traslacion
	for (int i = 1; i <= t.filas; i++) {
		for (int j = 1; j <= t.columnas; j++) {

			if (i == j) {
				t.in[i][j] = 1;
			}
			else {
				t.in[i][j] = 0;
			}
		}
	}

	t.in[1][4] = x;
	t.in[2][4] = y;
	t.in[3][4] = z;

	/*
	cout << "Matriz Traslacion:" << endl;
	for (int j = 1; j <= t.filas; j++) {
		for (int k = 1; k <= t.columnas; k++) {
			cout << "[" << t.in[j][k] << "]";
		}
		cout << endl;
	}
	system("pause>nul");
	*/

	mt[idt].filas = 4;
	mt[idt].columnas = 4;

	for (int i = 1; i <= mt[idt].filas; i++) {
		for (int j = 1; j <= mt[idt].columnas; j++) {

			mt[idt].in[i][j] = 0;

			for (int k = 1; k <= p.filas; k++) {

				mt[idt].in[i][j] = mt[idt].in[i][j] + t.in[i][k] * p.in[k][j];

			}
		}
	}

	cout << "Matriz Compuesta: " << endl;

	for (int i = 1; i <= mt[idt].filas; i++) {
		for (int j = 1; j <= mt[idt].columnas; j++) {
			cout << "[" << mt[idt].in[i][j] << "]";
		}
		cout << endl;
	}
	
	for (int i = 1; i <= p.filas; i++) {
		for (int j = 1; j <= p.columnas; j++) {

			p.in[i][j] = mt[idt].in[i][j];
		}
	}

	cout << endl;

	compuesta2();
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

	e.filas = 4;
	e.columnas = 4;

	//Escalacion
	for (int i = 1; i <= e.filas; i++) {
		for (int j = 1; j <= e.columnas; j++) {

			if (i == j) {
				e.in[i][j] = 1;
			}
			else {
				e.in[i][j] = 0;
			}
		}
	}
		 
	e.in[1][1] = x;
	e.in[2][2] = y;
	e.in[3][3] = z;

	/*
	cout << "Matriz Escalacion:" << endl;
	for (int j = 1; j <= e.filas; j++) {
		for (int k = 1; k <= e.columnas; k++) {
			cout << "[" << e.in[j][k] << "]";
		}
		cout << endl;
	}
	system("pause>nul");
	*/

	mt[idt].filas = 4;
	mt[idt].columnas = 4;

	for (int i = 1; i <= mt[idt].filas; i++) {
		for (int j = 1; j <= mt[idt].columnas; j++) {

			mt[idt].in[i][j] = 0;

			for (int k = 1; k <= p.filas; k++) {

				mt[idt].in[i][j] = mt[idt].in[i][j] + e.in[i][k] * p.in[k][j];

			}
		}
	}

	cout << "Matriz Compuesta: " << endl;
	
	for (int i = 1; i <= mt[idt].filas; i++) {
		for (int j = 1; j <= mt[idt].columnas; j++) {

			cout << "[" << mt[idt].in[i][j] << "]";
		}
		cout << endl;
	}

	for (int i = 1; i <= p.filas; i++) {
		for (int j = 1; j <= p.columnas; j++) {

			p.in[i][j] = mt[idt].in[i][j];
		}
	}


	cout << endl;

	compuesta2();

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

	compuesta2();

}

void xrotate() {

	rx.filas = 4;
	rx.columnas = 4;

	//Rotacion x
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {

			if (i == j) {
				rx.in[i][j] = 1;
			}		  
			else {	  
				rx.in[i][j] = 0;
			}
		}
	}

	rx.in[2][2] = cos(x);
	rx.in[2][3] = -sin(x);
	rx.in[3][2] = sin(x);
	rx.in[3][3] = cos(x);

	/*
	cout << "Matriz Rotacion en X:" << endl;
	for (int j = 1; j <= rx.filas; j++) {
		for (int k = 1; k <= rx.columnas; k++) {

			cout << "[" << rx.in[j][k] << "]";
		}
		cout << endl;
	}
	system("pause>nul");
	*/


	mt[idt].filas = 4;
	mt[idt].columnas = 4;

	for (int i = 1; i <= mt[idt].filas; i++) {
		for (int j = 1; j <= mt[idt].columnas; j++) {

			mt[idt].in[i][j] = 0;

			for (int k = 1; k <= p.filas; k++) {

				mt[idt].in[i][j] = mt[idt].in[i][j] + rx.in[i][k] * p.in[k][j];

			}
		}
	}

	cout << "Matriz Compuesta: " << endl;

	for (int i = 1; i <= mt[idt].filas; i++) {
		for (int j = 1; j <= mt[idt].columnas; j++) {

			if (mt[idt].in[i][j] < 0.01 && mt[idt].in[i][j] > 0 || mt[idt].in[i][j] < 0 && mt[idt].in[i][j] > -0.01) {
				mt[idt].in[i][j] = 0;
			}

			cout << "[" << mt[idt].in[i][j] << "]";
		}
		cout << endl;
	}

	for (int i = 1; i <= p.filas; i++) {
		for (int j = 1; j <= p.columnas; j++) {

			p.in[i][j] = mt[idt].in[i][j];
		}
	}


	cout << endl;
}


void yrotate() {

	ry.filas = 4;
	ry.columnas = 4;

	//Rotacion y
	for (int i = 1; i <= ry.filas; i++) {
		for (int j = 1; j <= ry.columnas; j++) {

			if (i == j) {
				ry.in[i][j] = 1;
			}
			else {
				ry.in[i][j] = 0;
			}
		}
	}

	ry.in[1][1] = cos(y);
	ry.in[1][3] = sin(y);
	ry.in[3][1] = -sin(y);
	ry.in[3][3] = cos(y);

	/*
	cout << "Matriz Rotacion en Y:" << endl;
	for (int j = 1; j <= ry.filas; j++) {
	for (int k = 1; k <= ry.columnas; k++) {
	cout << "[" << ry.in[j][k] << "]";
	}
	cout << endl;
	}
	system("pause>nul");
	*/

	mt[idt].filas = 4;
	mt[idt].columnas = 4;

	for (int i = 1; i <= mt[idt].filas; i++) {
		for (int j = 1; j <= mt[idt].columnas; j++) {

			mt[idt].in[i][j] = 0;

			for (int k = 1; k <= p.filas; k++) {

				mt[idt].in[i][j] = mt[idt].in[i][j] + ry.in[i][k] * p.in[k][j];

			}
		}
	}

	cout << "Matriz Compuesta: " << endl;

	for (int i = 1; i <= mt[idt].filas; i++) {
		for (int j = 1; j <= mt[idt].columnas; j++) {

			if (mt[idt].in[i][j] < 0.01 && mt[idt].in[i][j] > 0 || mt[idt].in[i][j] < 0 && mt[idt].in[i][j] > -0.01) {
				mt[idt].in[i][j] = 0;
			}

			cout << "[" << mt[idt].in[i][j] << "]";
		}
		cout << endl;
	}

	for (int i = 1; i <= p.filas; i++) {
		for (int j = 1; j <= p.columnas; j++) {

			p.in[i][j] = mt[idt].in[i][j];
		}
	}

	cout << endl;
}

void zrotate() {

	rz.filas = 4;
	rz.columnas = 4;

	//Rotacion z
	for (int i = 1; i <= rz.filas; i++) {
		for (int j = 1; j <= rz.columnas; j++) {

			if (i == j) {
				rz.in[i][j] = 1;
			}
			else {
				rz.in[i][j] = 0;
			}
		}
	}

	rz.in[1][1] = cos(z);
	rz.in[1][2] = -sin(z);
	rz.in[2][1] = sin(z);
	rz.in[2][2] = cos(z);

	/*
	cout << "Matriz Rotacion en Z:" << endl;
	for (int j = 1; j <= rz.filas; j++) {
	for (int k = 1; k <= rz.columnas; k++) {
	cout << "[" << rz.in[j][k] << "]";
	}
	cout << endl;
	}
	system("pause>nul");
	*/

	mt[idt].filas = 4;
	mt[idt].columnas = 4;

	for (int i = 1; i <= mt[idt].filas; i++) {
		for (int j = 1; j <= mt[idt].columnas; j++) {

			mt[idt].in[i][j] = 0;

			for (int k = 1; k <= p.filas; k++) {

				mt[idt].in[i][j] = mt[idt].in[i][j] + rz.in[i][k] * p.in[k][j];

			}
		}
	}

	cout << "Matriz Compuesta: " << endl;


	for (int i = 1; i <= mt[idt].filas; i++) {
		for (int j = 1; j <= mt[idt].columnas; j++) {

			if (mt[idt].in[i][j] < 0.01 && mt[idt].in[i][j] > 0 || mt[idt].in[i][j] < 0 && mt[idt].in[i][j] > -0.01) {
				mt[idt].in[i][j] = 0;
			}

			cout << "[" << mt[idt].in[i][j] << "]";
		}
		cout << endl;
	}

	for (int i = 1; i <= p.filas; i++) {
		for (int j = 1; j <= p.columnas; j++) {

			p.in[i][j] = mt[idt].in[i][j];
		}
	}

	cout << endl;
}

void compuesta() {

	if (idt == 11) {
		idt = 1;
	}

	p.filas = 4;
	p.columnas = 4;

	for (int i = 1; i <= p.filas; i++) {
		for (int j = 1; j <= p.columnas; j++) {

			if (i == j) {
				p.in[i][j] = 1;
			}
			else {
				p.in[i][j] = 0;
			}
		}
	}

	system("cls");
	cout << "Matriz Compuesta: " << endl;
	cout << endl;

	cout << "Realizar:" << endl;
	cout << "R. Rotacion" << endl;
	cout << "S. Escalacion" << endl;
	cout << "T. Traslacion" << endl;
	cin >> option;

	if (option > 96) {
		option -= 32;
	}

	switch (option) {
	case 'R':

	    rotate();

		break;
	case 'S':

		scale();

		break;
	case 'T':

		translate();

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

	if (idt == 11) {
		idt = 1;
	}

	system("cls");
	cout << "Cuaterniones: " << endl;
	cout << endl;

	cout << "Punto: " << endl;
	cout << "x: ";
	cin >> x;
	cout << "y: ";
	cin >> y;
	cout << "z: ";
	cin >> z;
	cout << endl;

	p.filas = 3;
	p.columnas = 1;

	p.in[1][1] = x;
	p.in[2][1] = y;
	p.in[3][1] = z;

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
	theta = theta * (PI / 180);

	u = (vx * vx) + (vy * vy) + (vz * vz);

	vx = vx / sqrt(u);
	vy = vy / sqrt(u);
	vz = vz / sqrt(u);

	s = cos(theta);
	vx = vx * sin(theta);
	vy = vy * sin(theta);
	vz = vz * sin(theta);

	q.filas = 3;
	q.columnas = 3;

	q.in[1][1] = 1 - (2 * pow(vy, 2)) - (2 * pow(vz, 2));
	q.in[1][2] = (2 * vx * vy) - (2 * s * vz);
	q.in[1][3] = (2 * vx * vz) + (2 * s * vy);
		  
	q.in[2][1] = (2 * vx * vy) + (2 * s * vz);
	q.in[2][2] = 1 - (2 * vx * vx) - (2 * vz * vz);
	q.in[2][3] = (2 * vy * vz) - (2 * s * vx);
		  
	q.in[3][1] = (2 * vx * vz) - (2 * s * vy);
	q.in[3][2] = (2 * vy * vz) + (2 * s * vx);
	q.in[3][3] = 1 - (2 * pow(vx, 2)) - (2 * pow(vy, 2));

	/*
	cout << endl;
	cout << "Matriz Cuaternios:" << endl;
	for (int j = 1; j <= q.filas; j++) {
	for (int k = 1; k <= q.columnas; k++) {
	cout << "[" << q.in[j][k] << "]";
	}
	cout << endl;
	}
	system("pause>nul");
	*/

	mt[idt].filas = 3;
	mt[idt].columnas = 1;

	for (int i = 1; i <= mt[idt].filas; i++) {
		for (int j = 1; j <= p.columnas; j++) {

			mt[idt].in[i][j] = 0;

			for (int k = 1; k <= p.filas; k++) {

				mt[idt].in[i][j] = mt[idt].in[i][j] + q.in[i][k] * p.in[k][j];

			}
		}
	}

	if (mt[idt].in[1][1] < 0.01 && mt[idt].in[1][1] > 0 || mt[idt].in[1][1] < 0 && mt[idt].in[1][1] > -0.01) {
		mt[idt].in[1][1] = 0;
	}
	if (mt[idt].in[2][1] < 0.01 && mt[idt].in[2][1] > 0 || mt[idt].in[2][1] < 0 && mt[idt].in[2][1] > -0.01) {
		mt[idt].in[2][1] = 0;
	}
	if (mt[idt].in[3][1] < 0.01 && mt[idt].in[3][1] > 0 || mt[idt].in[3][1] < 0 && mt[idt].in[3][1] > -0.01) {
		mt[idt].in[3][1] = 0;
	}

	cout << endl;

	cout << "Q' Punto: " << endl;
	cout << "x': " << mt[idt].in[1][1] << endl;
	cout << "y': " << mt[idt].in[2][1] << endl;
	cout << "z': " << mt[idt].in[3][1] << endl;

	cout << endl;

	idt++;

	system("pause > nul");

	menu();
}

void compuesta2() {

	cout << "Realizar otra transformaciòn:" << endl; 
	cout << "R.Rotar" << endl;
	cout << "S.Escalar" << endl;
	cout << "T.Trasladar" << endl;
	cout << "U.Aplicar Puntos" << endl;
	cin >> option;

	if (option > 96) {
		option -= 32;
	}

	switch (option) {
	case 'R':
		rotate();
		break;
	case 'S':
		scale();
		break;
	case 'T':
		translate();
		break;
	case 'U':
		points();
		break;
	default:
		
		cout << endl;
		cout << "Ingresa una letra valida." << endl;
	}
}

void matricescomp() {

	system("cls");
	cout << "Matrices Compuestas Registradas: " << endl;
	cout << endl;

	for (int i = 1; i < idt; i++) {

		cout << "Matriz " << i << ": " << endl;

		for (int j = 1; j <= mt[i].filas; j++) {

			for (int k = 1; k <= mt[i].columnas; k++) {

				cout << "[" << mt[i].in[j][k] << "]";
			}

			cout << endl;
		}

		cout << endl;

	}

	system("pause > nul");

	menu();
}

void mxv() {

	system("cls");
	cout << "Matriz por Vector: " << endl;
	cout << endl;

	m[id].idmat = idmat;

	if (m[id].idmat > 90) {
		id = 1;
		m[id].idmat = 65;
	}

	cout << "Matriz:" << endl;

	e.filas = 1;
	e.columnas = 3;

	for (int j = 1; j <= e.filas; j++) {

		for (int k = 1; k <= e.columnas; k++) {

			cout << "Ingrese el número[" << j << "][" << k << "]: ";
			cin >> e.in[j][k];
		}

	}

	p.filas = 3;
	p.columnas = 1;

	cout << endl;
	cout << "Vector:" << endl;
	cout << "x: ";
	cin >> x;
	cout << "y: ";
	cin >> y;
	cout << "z: ";
	cin >> z;

	p.in[1][1] = x;
	p.in[2][1] = y;
	p.in[3][1] = z;

	m[id].filas = e.filas;
	m[id].columnas = p.columnas;

	for (int i = 1; i <= m[id].filas; i++) {
		for (int j = 1; j <= m[id].columnas; j++) {

			m[id].in[i][j] = 0;

			for (int k = 1; k <= p.filas; k++) {

				m[id].in[i][j] = m[id].in[i][j] + e.in[i][k] * p.in[k][j];

			}
		}
	}

	cout << endl;
	cout << "Matriz Resultante: " << endl;
	cout << "[" << m[id].in[1][1] << "]" << endl;

	cout << endl;
	cout << "Matriz registrada como: " << m[id].idmat;

	id++;
	idmat++;

	system("pause > nul ");
	menu();

}