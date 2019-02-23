#include <iostream>
#include <string>
using namespace std;

void imprimir();
void eliminar();

struct liga{
	string dato;
	liga *sig;
}*origin,*aux,*last;

void main(){
	origin = NULL;
	aux = last = origin;

	for (int i = 0; i < 5; i++){
		if (origin == NULL){
			liga *aux = new liga;

			cout << "Ingrese algo: ";

			getline(cin, aux->dato);
			aux->sig = NULL;
			last = aux;
			origin = aux;
		}
		else {

			aux = new liga;
			cout << "Ingrese otro algo: ";
			getline(cin, aux->dato);
			last->sig = aux;
		    last = last->sig;
			aux->sig = NULL;
			
		}

	}
	imprimir();
}

	

void imprimir(){

	system("cls");

	aux = origin;

	for (int i = 0; i < 5; i++){
		
		cout << aux->dato << endl;
		aux = aux->sig;
	}

	system("pause > nul");

	eliminar();
}

void eliminar(){

	system("cls");
	
	while (origin != NULL){
        aux = origin;

		if (aux != NULL){

			origin = origin->sig;
			delete aux;

			cout << "Nodo destruido" << endl;
			aux = NULL;
		}

		if (origin->sig == NULL){
		 delete origin;

		 cout << "Nodo destruido" << endl;
		
		 origin = NULL;

	  }
	}
	

	system("pause > nul");
}