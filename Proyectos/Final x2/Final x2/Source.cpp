#include <Windows.h>
#include <stdlib.h>
#include <string>
#include <conio.h>
#include <iostream>
#include <commctrl.h>
#include <fstream>
#include "resource.h"

using namespace std;

#define IDT_TIMER1 900
#define IDT_TIMER2 901

#define BOLDDAY(ds, iDay)  \
        if (iDay > 0 && iDay < 32)(ds) |= (0x00000001 << (iDay - 1))

ofstream file;
ifstream lectura;
int tamaño;
char texto[1024];

struct Vet {
	char name[1024] = "";
	char lastname[1024] ="";
	char identificationcard[1024] = "";
	char completename[1024] = "";
	char MV[1024] = "";
	char carrer[1024] = "";
}*first, *backup;

int sizename;
int sizelastname;
bool justletters = 1;

struct User {
	char username[1024] = "";
	char password[1024] = "";
	char samepassword[1024] = "";
	char existinguser[1024] = "";
	User *sig;
	User *ant;
}*inicio, *auxiliar;

bool valid = 0;
bool valid2 = 0;
bool exists = 0;

struct Date {
	char client[1024] = "";
	char number[12] = "";
	char pet[1024] = "";
	char specie[1024] = "";
	char motivo[1024] = "";
	char price[1024] = "";
	char payment3[1024] = "";
	char payment6[1024] = "";
	char payment9[1024] = "";
	char date[1024] = "";
	char time[1024] = "";
	Date *prev;
	Date *next;
}*origin, *aux;

float payment;
float payment3;
float payment6;
float payment9;

int sizenumber;
int sizeprice;
int decimal;

bool petletters = 1;
bool validsizenumber = 1;
bool validnumber = 1;
bool validprice = 1;
bool validsizeprice = 1;

char imagenvet[1024] = "C:\\Users\\GONZALEZ\\Desktop\\Laboratorios\\P. Avanzada\\Final x2\\MV.bmp";
char imagenfirma[1024] = "C:\\Users\\GONZALEZ\\Desktop\\Laboratorios\\P. Avanzada\\Final x2\\Firma.bmp";
char imagenlogo[1024] = "C:\\Users\\GONZALEZ\\Desktop\\Laboratorios\\P. Avanzada\\Final x2\\Patasycolas.bmp";

void Image(HWND hWnd, WPARAM wParam, char *imagen, int m, int n);

void NewVet();
void NewUser();
void NewDate();

void ValidName();
void ValidPet();
void ValidNumber();
void ValidDate();
void ValidTime();
void ValidPrice();

void savefile();

HINSTANCE hInst;

int showMSG;
HWND hWnd;
HWND hLocaltime;
HWND hLocaldate;
SYSTEMTIME lt;
HWND hCalender;
HWND hDatePicker;
HWND hTimePicker;

HWND hStaticColor;
HWND hComboEspecie;
HWND hComboMotivo;
HWND hListCitas;
HWND hRadioHembra;
HWND hRadioMacho;
HWND hRadio3m;
HWND hRadio6m;
HWND hRadio9m;
HWND hRadioSin;

int index;
int idx;

BOOL CALLBACK AGENDA(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK EDITAR(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK ELIMINAR(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK INFO(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK NEWDATE(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK PASSWORD(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK SINGUP(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK PRINCIPAL(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK LOGIN(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(_In_ HINSTANCE hInstance,
	_In_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nCmdShow)
{
	hInst = hInstance;
	showMSG = nCmdShow;

	first = NULL;
	inicio = auxiliar = NULL;
	origin = aux = NULL;
	NewUser();
	NewVet();
	NewDate();

	hWnd = CreateDialog(
		hInst,
		MAKEINTRESOURCE(IDD_PRINCIPAL),
		NULL,
		PRINCIPAL
	);

	
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}

BOOL CALLBACK LOGIN(HWND hWnd,
	UINT message,
	WPARAM wParam,
	LPARAM lParam)
{
	switch (message)
	{
	case WM_INITDIALOG:
	{
		/*
		lectura.open("Savedfile.txt", ios::in | ios::binary | ios::ate);
		if (lectura.is_open()) {

			lectura.seekg(0, ios::end);
			tamaño = lectura.tellg();

			while (!lectura.eof()) {
				lectura.read((char*)texto,tamaño);
			}
		}
		lectura.close();
		*/

		auxiliar = inicio;

	}
	break;
	case WM_CTLCOLORSTATIC:
	{

		switch (GetDlgCtrlID((HWND)lParam))
		{
		case IDC_STATIC5:
		{
			HDC hdcStatic = (HDC)wParam;
			SetTextColor(hdcStatic, RGB(0, 0, 0));
			SetBkColor(hdcStatic, RGB(236, 240, 241));
		}
		break;
		case IDC_STATIC3:
		{
			HDC hdcStatic = (HDC)wParam;
			SetTextColor(hdcStatic, RGB(0, 0, 0));
			SetBkColor(hdcStatic, RGB(236, 240, 241));
		}
		break;
		case IDC_STATIC7:
		{
		
			HDC hdcStatic = (HDC)wParam;
			SetTextColor(hdcStatic, RGB(51, 199, 255));
			SetBkColor(hdcStatic, RGB(236, 240, 241));
		}
		break;
		case IDC_STATIC2:
		{
		
			HDC hdcStatic = (HDC)wParam;
			SetTextColor(hdcStatic, RGB(51, 199, 255));
			SetBkColor(hdcStatic, RGB(236, 240, 241));
		}
		}
		//HDC hdcStatic = (HDC)wParam;
		//SetTextColor(hdcStatic, RGB(0, 0, 255)); 

		return (LRESULT)GetStockObject(NULL_BRUSH);
		break;
	}
	break;
	case WM_COMMAND:

		switch (LOWORD(wParam))
		{
		case IDC_EDIT1:
		{

			char buff[1024];
			HWND username = GetDlgItem(hWnd, IDC_EDIT1);
			GetWindowText(username, buff, 1024);


			while (auxiliar->sig != NULL) {
				if (strcmp(buff, auxiliar->username) == 0) {
					valid = true;
					break;
				}

			}

			break;
		}
		case IDC_EDIT2:
		{

			char buff[1024];
			HWND password = GetDlgItem(hWnd, IDC_EDIT2);
			GetWindowText(password, buff, 1024);

			while (auxiliar->sig != NULL) {
				if (strcmp(buff, auxiliar->password) == 0) {
					valid2 = true;
					break;
				}
			}


			break;
		}
		case IDC_STATIC7:
		{
			DialogBox(hInst, MAKEINTRESOURCE(IDD_PASSWORD), hWnd, PASSWORD);

		}

		break;
		case IDC_STATIC2:
		{
			EndDialog(hWnd, 0);
			DialogBox(hInst, MAKEINTRESOURCE(IDD_SINGUP), hWnd, SINGUP);
		}

		break;
		case IDOK:
		{
			TCHAR buff[1] = TEXT("");

			if (valid == 0 || valid2 == 0) {

				MessageBox(NULL, "Datos Incorrectos", "Error", NULL);

				SetDlgItemText(hWnd, IDC_EDIT1, buff);
				SetDlgItemText(hWnd, IDC_EDIT2, buff);
			}
			else {

				EndDialog(hWnd, 0);
				CreateDialog(hInst, MAKEINTRESOURCE(IDD_PRINCIPAL), hWnd, PRINCIPAL);
			}
		}
			break;
		}
		break;
	case WM_DESTROY:
		DestroyWindow(hWnd);
		break;
	case WM_CLOSE:
		PostQuitMessage(0);
		break;
	default:
		return FALSE;
		break;
	}
	return FALSE;
}


BOOL CALLBACK PRINCIPAL(HWND hWnd,
	UINT message,
	WPARAM wParam,
	LPARAM lParam)
{
	switch (message)
	{
	case WM_INITDIALOG:
	{

		Image(hWnd, IDC_STATIC5, imagenlogo, 400, 220);
	
		hLocaltime = GetDlgItem(hWnd, IDC_STATIC1);
		hLocaldate = GetDlgItem(hWnd, IDC_STATIC2);
		
		SetTimer(hWnd, IDT_TIMER1, 1000, (TIMERPROC)NULL);
		SetTimer(hWnd, IDT_TIMER2, 1000, (TIMERPROC)NULL);
	}
	break;
	case WM_TIMER:

		switch (wParam)
		{
		case IDT_TIMER1:
		{
			GetLocalTime(&lt);

			TCHAR buff[1024];
			snprintf(buff, 1024, "The local time is % 02d : % 02d  : % 02d", lt.wHour, lt.wMinute, lt.wSecond);
			SetWindowText(hLocaltime, buff);

		}
		break;
		case IDT_TIMER2:
		{
			GetLocalTime(&lt);
			TCHAR buff[1024];
			snprintf(buff, 1024, "% 02d / % 02d  / % 02d", lt.wDay, lt.wMonth, lt.wYear);
			SetWindowText(hLocaldate, buff);

		}
		break;
		}
		break;
	case WM_COMMAND:

		switch (LOWORD(wParam))
		{
		}
	case WM_DESTROY:
		DestroyWindow(hWnd);
		break;
	case WM_CLOSE:
		PostQuitMessage(0);
		break;
	default:
		return FALSE;
		break;
	}
	return FALSE;
}

void savefile() {

	file.open("Savedfile", ios::out | ios::trunc | ios::binary);
	file.write(texto,tamaño);
	file.close();
}

BOOL CALLBACK SINGUP(HWND hWnd,
	UINT message,
	WPARAM wParam,
	LPARAM lParam)
{
	switch (message)
	{
	case WM_INITDIALOG:
	{
		NewUser();
	}
	break;
	case WM_COMMAND:

		switch (LOWORD(wParam))
		{
		case IDC_EDIT1:
		{

			HWND username = GetDlgItem(hWnd, IDC_EDIT1);
			GetWindowText(username, auxiliar->username, 1024);



		}
		break;
		case IDC_EDIT2:
		{

			HWND password = GetDlgItem(hWnd, IDC_EDIT2);
			GetWindowText(password, auxiliar->password, 1024);




		}
		break;
		case IDC_EDIT5:
		{

			HWND cpassword = GetDlgItem(hWnd, IDC_EDIT5);
			GetWindowText(cpassword, auxiliar->samepassword, 1024);



		}
		break;
		case IDOK:
		{
			TCHAR buff[1] = TEXT("");

			if (auxiliar->username[0] == NULL || auxiliar->password[0] == NULL || auxiliar->samepassword[0] == NULL) {

				MessageBox(NULL, "Complete todos los campos", "Error", NULL);
				break;
			}
			else if (strcmp(auxiliar->password, auxiliar->samepassword) != 0) {

				MessageBox(NULL, "Las contraseñas no coinciden", "Error", NULL);

				SetDlgItemText(hWnd, IDC_EDIT2, buff);
				SetDlgItemText(hWnd, IDC_EDIT5, buff);
			}
			else {

				MessageBox(NULL, "Usuario creado con éxito", "Usuario", MB_ICONINFORMATION);

				if (inicio == NULL) {
					inicio = auxiliar;
				}

				EndDialog(hWnd, 0);
			    DialogBox(hInst, MAKEINTRESOURCE(IDD_LOGIN), hWnd, LOGIN);
			}

		}
			break;

		}
		break;
	case WM_DESTROY:
		EndDialog(hWnd, 0);
		break;
	case WM_CLOSE:
		EndDialog(hWnd, 0);
		break;
	default:
		return FALSE;
		break;
	}
	return FALSE;
}

void NewUser() {

	auxiliar = inicio;

	if (inicio == NULL) {

		inicio = new User;
		inicio->sig = NULL;
		inicio->ant = NULL;
		auxiliar = inicio;
	}
	else {
		while (auxiliar->sig != NULL) {
			auxiliar = auxiliar->sig;
		}
		auxiliar->sig = new User;
		auxiliar->sig->ant = auxiliar;
		auxiliar = auxiliar->sig;
		auxiliar->sig = NULL;
	}
}

BOOL CALLBACK PASSWORD(HWND hWnd,
	UINT message,
	WPARAM wParam,
	LPARAM lParam)
{
	switch (message)
	{
	case WM_INITDIALOG:
	{
		auxiliar = inicio;
	
	}
	break;
	case WM_COMMAND:
	

		switch (LOWORD(wParam))
		{
	
		case IDC_EDIT1:
		{

			HWND username = GetDlgItem(hWnd, IDC_EDIT1);
			GetWindowText(username, auxiliar->existinguser, 1024);


		}
		break;
		case IDC_EDIT2:
		{
			HWND password = GetDlgItem(hWnd, IDC_EDIT1);
			GetWindowText(password, auxiliar->password, 1024);

		}
		break;
		case IDC_EDIT5:
		{
			HWND cpassword = GetDlgItem(hWnd, IDC_EDIT1);
			GetWindowText(cpassword, auxiliar->samepassword, 1024);

		}
		break;
		case SEARCH:

			if (auxiliar->existinguser[0] == NULL ) {

				MessageBox(NULL, "Complete todos los campos", "Error", NULL);
				
			}

			while (auxiliar != NULL) {
				if (strcmp(auxiliar->existinguser, auxiliar->username) == 0) {
					exists = 1;
					break;
				}
				auxiliar = auxiliar->sig;
			}

			if (exists == 1) {
				EnableWindow(GetDlgItem(hWnd, IDC_EDIT2), TRUE);
				EnableWindow(GetDlgItem(hWnd, IDC_EDIT5), TRUE);
			}
			else {

				MessageBox(NULL, "No se encontro el usuario", "Usuario", NULL);
			}
		
	
			break;
		case IDOK:
			
			if (auxiliar->existinguser[0] == NULL) {

				MessageBox(NULL, "Complete todos los campos", "Error", NULL);

			}
			
			break;

		}
		break;
	case WM_DESTROY:
		DestroyWindow(hWnd);
		break;
	case WM_CLOSE:
		PostQuitMessage(0);
		break;
	default:
		return FALSE;
		break;
	}
	return FALSE;
}

BOOL CALLBACK INFO(HWND hWnd,
	UINT message,
	WPARAM wParam,
	LPARAM lParam)
{
	switch (message)
	{
	case WM_INITDIALOG:
	{
		Image(hWnd, IDC_STATIC_IMAGE2, imagenvet, 100, 80);
		Image(hWnd, IDC_STATIC_FIRMA, imagenfirma, 135, 50);

		HWND name = GetDlgItem(hWnd, IDC_EDIT1);
		SetWindowText(name, backup->name);

		HWND lastname = GetDlgItem(hWnd, IDC_EDIT2);
		SetWindowText(lastname, backup->lastname);

		HWND identificationcard = GetDlgItem(hWnd, IDC_EDIT9);
		SetWindowText(identificationcard, backup->identificationcard);

		HWND completename = GetDlgItem(hWnd, IDC_EDIT5);
		SetWindowText(completename, backup->completename);


		HWND carrer = GetDlgItem(hWnd, IDC_EDIT8);
		SetWindowText(carrer, backup->carrer);

		hLocaltime = GetDlgItem(hWnd, IDC_STATIC7);
		hLocaldate = GetDlgItem(hWnd, IDC_STATIC8);

		SetTimer(hWnd, IDT_TIMER1, 1000, (TIMERPROC)NULL);	
		SetTimer(hWnd, IDT_TIMER2, 1000, (TIMERPROC)NULL);
	
	}
	break;
	case WM_TIMER:

		switch (wParam)
		{
		case IDT_TIMER1:
		{
			GetLocalTime(&lt);
			TCHAR buff[1024];
			snprintf(buff, 1024, "The local time is % 02d : % 02d  : % 02d", lt.wHour, lt.wMinute, lt.wSecond);
			SetWindowText(hLocaltime, buff);

		}
			break;
		case IDT_TIMER2:
		{
			GetLocalTime(&lt);
			TCHAR buff[1024];
			snprintf(buff, 1024, "% 02d / % 02d  / % 02d", lt.wDay, lt.wMonth, lt.wYear);
			SetWindowText(hLocaldate, buff);

		}
		break;
		}
	break;
	case WM_COMMAND:

		switch (LOWORD(wParam))
		{
		case IDC_EDIT1:
		{
			HWND name = GetDlgItem(hWnd, IDC_EDIT1);
			GetWindowText(name, backup->name, 1024);

			sizename = strlen(backup->name);
		}
		break;
		case IDC_EDIT2:
		{
			HWND lastname = GetDlgItem(hWnd, IDC_EDIT2);
			GetWindowText(lastname, backup->lastname, 1024);

			sizelastname = strlen(backup->lastname);
		
		}
		break;
		case IDC_EDIT9:
		{
			HWND identificationcard = GetDlgItem(hWnd, IDC_EDIT9);
			GetWindowText(identificationcard, backup->identificationcard, 1024);

			strcpy_s(backup->completename, backup->lastname);
			strcat_s(backup->completename, " ");
			strcat_s(backup->completename, backup->name);

			strcpy_s(backup->MV, backup->name);
			strcat_s(backup->MV, " ");
			strcat_s(backup->MV, backup->lastname);

			HWND completename = GetDlgItem(hWnd, IDC_EDIT5);
			SetWindowText(completename, backup->completename);

			HWND nameinstatic = GetDlgItem(hWnd, IDC_STATIC4);
			SetWindowText(nameinstatic, backup->MV);

		}
		break;
		case IDC_EDIT8:
		{
			HWND carrer = GetDlgItem(hWnd, IDC_EDIT8);
			GetWindowText(carrer, backup->carrer, 1024);

		}
		break;
		case IDCANCEL:
		{
			int msgboxID = MessageBox( NULL, "Se perderán todos los cambios no guardados.\n¿Desea continuar?", "Confirmación",MB_ICONEXCLAMATION | MB_YESNO);
			
			if (msgboxID == IDYES)
			{
			   backup = first;
			}
			if (msgboxID == IDNO)
			{
			   
			}


		}
			break;
		case IDOK:
		{
			strcpy_s(backup->completename, backup->lastname);
			strcat_s(backup->completename, " ");
			strcat_s(backup->completename, backup->name);

			strcpy_s(backup->MV, backup->name);
			strcat_s(backup->MV, " ");
			strcat_s(backup->MV, backup->lastname);

			HWND completename = GetDlgItem(hWnd, IDC_EDIT5);
			SetWindowText(completename, backup->completename);

			TCHAR buff[1] = TEXT("");

			if (backup->name[0] == NULL || backup->lastname[0] == NULL || backup->identificationcard[0] == NULL || backup->carrer[0] == NULL) {

				MessageBox(NULL, "Complete todos los campos", "Error", NULL);
				break;
			}

			ValidName();

			if (justletters == 0) {

				MessageBox(NULL, "Nombre Inválido. Ingrese solo letras.", "Error", NULL);

				SetDlgItemText(hWnd, IDC_EDIT1, buff);
				SetDlgItemText(hWnd, IDC_EDIT2, buff);
				SetDlgItemText(hWnd, IDC_EDIT5, buff);
				SetDlgItemText(hWnd, IDC_STATIC4, buff);

				justletters = 1;
			}
			else {

				KillTimer(hWnd, IDT_TIMER1);

				MessageBox(NULL, "Información guardada con éxito.", "Veterinario", MB_ICONINFORMATION);
				first = backup;
			}
		}
			break;

		}
		break;
	case WM_DESTROY:
		DestroyWindow(hWnd);
		break;
	case WM_CLOSE:
		PostQuitMessage(0);
		break;
	default:
		return FALSE;
		break;
	}
	return FALSE;
}

void NewVet() {

	if (first == NULL) {

		first = new Vet;
		backup = first;
	}
}

void ValidName() {

	for (int i = 0; i < sizename; i++) {

		if (backup->name[i] < 32 || backup->name[i] > 32 && backup->name[i] < 65 || backup->name[i] > 122 || backup->name[i] > 90 && backup->name[i] < 97) {

			justletters = 0;

			break;
		}
	}

	for (int i = 0; i < sizelastname; i++) {

		if (backup->lastname[i] < 32 || backup->lastname[i] > 32 && backup->lastname[i] < 65 || backup->lastname[i] > 122 || backup->lastname[i] > 90 && backup->lastname[i] < 97) {

			justletters = 0;

			break;
		}

	}

}

BOOL CALLBACK NEWDATE(HWND hWnd,
	UINT message,
	WPARAM wParam,
	LPARAM lParam)
{
	switch (message)
	{
	case WM_INITDIALOG:
	{

		Image(hWnd, IDC_STATIC_IMAGE1, imagenvet, 100, 80);

		HWND nameinstatic = GetDlgItem(hWnd, IDC_STATIC4);
		SetWindowText(nameinstatic, backup->MV);
		
		hComboEspecie = GetDlgItem(hWnd, IDC_COMBO1);
		SendMessage(hComboEspecie, CB_ADDSTRING, 0, (LPARAM)TEXT("Caballo"));
		SendMessage(hComboEspecie, CB_ADDSTRING, 0, (LPARAM)("Cerdo"));
		SendMessage(hComboEspecie, CB_ADDSTRING, 0, (LPARAM)TEXT("Conejo"));
		SendMessage(hComboEspecie, CB_ADDSTRING, 0, (LPARAM)TEXT("Gato"));
		SendMessage(hComboEspecie, CB_ADDSTRING, 0, (LPARAM)TEXT("Hamster"));
		SendMessage(hComboEspecie, CB_ADDSTRING, 0, (LPARAM)TEXT("Pajaro"));
		SendMessage(hComboEspecie, CB_ADDSTRING, 0, (LPARAM)TEXT("Pato"));
		SendMessage(hComboEspecie, CB_ADDSTRING, 0, (LPARAM)TEXT("Perro"));
		SendMessage(hComboEspecie, CB_ADDSTRING, 0, (LPARAM)TEXT("Pez"));
		SendMessage(hComboEspecie, CB_ADDSTRING, 0, (LPARAM)TEXT("Tortuga"));
		SendMessage(hComboEspecie, CB_ADDSTRING, 0, (LPARAM)TEXT("Otro")); 

		index = SendMessage(hComboEspecie, CB_SETCURSEL, 8, 0);

		hComboMotivo = GetDlgItem(hWnd, IDC_COMBO2);
		SendMessage(hComboMotivo, CB_ADDSTRING, 0, (LPARAM)TEXT("Esterilización"));
		SendMessage(hComboMotivo, CB_ADDSTRING, 0, (LPARAM)TEXT("Vacunas"));
		SendMessage(hComboMotivo, CB_ADDSTRING, 0, (LPARAM)TEXT("Alergias"));
		SendMessage(hComboMotivo, CB_ADDSTRING, 0, (LPARAM)TEXT("Infecciones"));
		SendMessage(hComboMotivo, CB_ADDSTRING, 0, (LPARAM)TEXT("Desparasitación"));
		SendMessage(hComboMotivo, CB_ADDSTRING, 0, (LPARAM)TEXT("Microchip de Identificación"));
		SendMessage(hComboMotivo, CB_ADDSTRING, 0, (LPARAM)TEXT("Otro"));

		idx = SendMessage(hComboMotivo, CB_SETCURSEL, 6, 0);
		SendMessage(hComboMotivo, CB_GETLBTEXT, idx, (LPARAM)aux->motivo);

		hRadioHembra = GetDlgItem(hWnd, IDC_RADIO5);
		hRadioMacho = GetDlgItem(hWnd, IDC_RADIO6);
		hRadio3m = GetDlgItem(hWnd, IDC_RADIO1);
		hRadio6m = GetDlgItem(hWnd, IDC_RADIO2);
		hRadio9m = GetDlgItem(hWnd, IDC_RADIO3);
		hRadioSin = GetDlgItem(hWnd, IDC_RADIO4);

		hDatePicker = GetDlgItem(hWnd, IDC_DATETIMEPICKER1);
		hTimePicker = GetDlgItem(hWnd, IDC_DATETIMEPICKER2);

		hLocaltime = GetDlgItem(hWnd, IDC_STATIC6);
		hLocaldate = GetDlgItem(hWnd, IDC_STATIC9);

		SetTimer(hWnd, IDT_TIMER1, 1000, (TIMERPROC)NULL);
		SetTimer(hWnd, IDT_TIMER2, 1000, (TIMERPROC)NULL);

	}
	break;
	case WM_TIMER:

		switch (wParam)
		{
		case IDT_TIMER1:
		{
			GetLocalTime(&lt);
			TCHAR buff[1024];
			snprintf(buff, 1024, "The local time is % 02d : % 02d  : % 02d", lt.wHour, lt.wMinute, lt.wSecond);
			SetWindowText(hLocaltime, buff);

		}
		break;
		case IDT_TIMER2:
		{
			GetLocalTime(&lt);
			TCHAR buff[1024];
			snprintf(buff, 1024, "% 02d / % 02d  / % 02d", lt.wDay, lt.wMonth, lt.wYear);
			SetWindowText(hLocaldate, buff);

		}
		break;
		}
		break;
	case WM_NOTIFY:
		if (((LPNMHDR)lParam)->code == MCN_GETDAYSTATE)
		{
			MONTHDAYSTATE rgMonths[12] = { 0 };
			int cMonths = ((NMDAYSTATE*)lParam)->cDayState;
			for (int i = 0; i < cMonths; i++)
			{
				BOLDDAY(rgMonths[i], 1);
				BOLDDAY(rgMonths[i], 15);
			}
			((NMDAYSTATE*)lParam)->prgDayState = rgMonths;
			return TRUE;
		}
		break;
	case WM_COMMAND:

		switch (LOWORD(wParam))
		{
		case IDC_EDIT2:
		{

			HWND client = GetDlgItem(hWnd, IDC_EDIT2);
			GetWindowText(client, aux->client, 1024);

			sizename = strlen(aux->client);

		}
		break;
		case IDC_EDIT4:
		{
			HWND number = GetDlgItem(hWnd, IDC_EDIT4);
			GetWindowText(number, aux->number, 1024);

			sizenumber = strlen(aux->number);

		}
		break;
		case IDC_EDIT1:
		{
			HWND pet = GetDlgItem(hWnd, IDC_EDIT1);
			GetWindowText(pet, aux->pet, 1024);

			sizelastname = strlen(aux->pet);

		}
		break;
		case IDC_COMBO1:
		{
			if (HIWORD(wParam) == CBN_SELENDOK) {

				SendMessage(hComboEspecie, CB_GETLBTEXT, index, (LPARAM)aux->specie);
			}

			GetWindowText(hComboEspecie, aux->specie, 1024);

			if (aux->specie[0] == 79 && aux->specie[1] == 116) {

				*aux->specie = NULL;
				EnableWindow(GetDlgItem(hWnd, IDC_EDIT3), TRUE);
			}

		}
		break;
		case IDC_EDIT3:
		{
			HWND specie = GetDlgItem(hWnd, IDC_EDIT3);
			GetWindowText(specie, aux->specie, 1024);

		}
		break;
		case IDC_DATETIMEPICKER1:
		{

		}
		break;
		case IDC_DATETIMEPICKER2:
		{

		}
		break;
		case IDC_COMBO2:
		{

			GetWindowText(hComboMotivo, aux->motivo, 1024);

			if (aux->motivo[0] == 79 && aux->motivo[1] == 116) {

				*aux->motivo = NULL;
				EnableWindow(GetDlgItem(hWnd, IDC_EDIT6), TRUE);
			}
		}
		break;
		case IDC_EDIT6:
		{
			HWND motivo = GetDlgItem(hWnd, IDC_EDIT3);
			GetWindowText(motivo, aux->motivo, 1024);
		}
		break;
		case IDC_EDIT7:
		{
			HWND price = GetDlgItem(hWnd, IDC_EDIT7);
			GetWindowText(price, aux->price, 1024);

			sizeprice = strlen(aux->price);

			payment = atof(aux->price);
				
			payment3 = payment + payment * .12;
			payment6 = payment9 = payment3;

			payment3 = payment3 / 3;
			payment6 = payment6 / 6;
			payment9 = payment9 / 9;
			
			sprintf_s(aux->payment3, "%.1f", payment3);
			sprintf_s(aux->payment6, "%.1f", payment6);
			sprintf_s(aux->payment9, "%.1f", payment9);

			HWND payment = GetDlgItem(hWnd, IDC_STATIC30);
			SetWindowText(payment, aux->price);
			
			HWND payment9 = GetDlgItem(hWnd, IDC_STATIC29);
			SetWindowText(payment9, aux->payment9);

			HWND payment6 = GetDlgItem(hWnd, IDC_STATIC28);
			SetWindowText(payment6, aux->payment6);

			HWND payment3 = GetDlgItem(hWnd, IDC_STATIC27);
			SetWindowText(payment3, aux->payment3);
	
		}
		break;
		case IDCANCEL:


			break;
		case IDOK:
		{

			SYSTEMTIME dateSelected, timeSelected;
			DateTime_GetSystemtime(hTimePicker, &timeSelected);
			MonthCal_GetCurSel(hDatePicker, &dateSelected);
			int i = 0;

			TCHAR buff[1] = TEXT("");


			if (aux->client[0] == NULL ||  aux->motivo[0] == NULL || aux->number[0] == NULL || aux->pet[0] == NULL || aux->specie[0] == NULL || aux->price[0] == NULL) {

				MessageBox(NULL, "Complete todos los campos", "Error", NULL);
				break;
			}
		

			UINT Radio5 = IsDlgButtonChecked(hWnd, IDC_RADIO5);
			UINT Radio6 = IsDlgButtonChecked(hWnd, IDC_RADIO6);
			if (Radio5 == BST_UNCHECKED && Radio6 == BST_UNCHECKED)
			{
				MessageBox(NULL, "Complete todos los campos", "Error", NULL);
				break;
			}

			UINT Radio1 = IsDlgButtonChecked(hWnd, IDC_RADIO1);
			UINT Radio2 = IsDlgButtonChecked(hWnd, IDC_RADIO2);
			UINT Radio3 = IsDlgButtonChecked(hWnd, IDC_RADIO3);
			UINT Radio4 = IsDlgButtonChecked(hWnd, IDC_RADIO4);
			if (Radio1 == BST_UNCHECKED && Radio2 == BST_UNCHECKED && Radio3 == BST_UNCHECKED && Radio4 == BST_UNCHECKED)
			{
				MessageBox(NULL, "Complete todos los campos", "Error", NULL);
				break;
			}
			
			ValidPet();

			if (justletters == 0) {

				MessageBox(NULL, "Nombre Inválido. Ingrese solo letras.", "Error", NULL);

				SetDlgItemText(hWnd, IDC_EDIT2, buff);
				justletters = 1;

				break;
			}

			if (petletters == 0) {

				MessageBox(NULL, "Nombre Inválido. Ingrese solo letras.", "Error", NULL);

				SetDlgItemText(hWnd, IDC_EDIT1, buff);
				petletters = 1;

				break;
			}

			ValidNumber();

			if (validsizenumber == 0) {

				
				MessageBox(NULL, "Número Inválido. El número debe de tener 8, 10 o 12 dígitos.", "Error", NULL);
				
				SetDlgItemText(hWnd, IDC_EDIT4, buff);
                validsizenumber == 1;

				break;
			}

			if (validnumber == 0) {

				MessageBox(NULL, "Número Inválido. Ingrese solo números.", "Error", NULL);

				SetDlgItemText(hWnd, IDC_EDIT4, buff);

				break;
			}

			ValidPrice();
			
			if (validprice == 0) {

				MessageBox(NULL, "Número Inválido. Ingrese solo números.", "Error", NULL);

				SetDlgItemText(hWnd, IDC_EDIT7, buff);
				validprice == 1;

				break;
			}

			if (validsizeprice == 0) {

				MessageBox(NULL, "Número Inválido. Ingrese solo 1 decimal.", "Error", NULL);

				SetDlgItemText(hWnd, IDC_EDIT7, buff);
				validsizeprice == 1;

				break;
			}

		}
			break;

		}
		break;
	case WM_DESTROY:
		DestroyWindow(hWnd);
		break;
	case WM_CLOSE:
		PostQuitMessage(0);
		break;
	default:
		return FALSE;
		break;
	}
	return FALSE;
}

void NewDate() {

	aux = origin;

	if (origin == NULL) {

		origin = new Date;
		origin->next = NULL;
		origin->prev = NULL;
		aux = origin;
	}
	else {
		while (aux->next != NULL) {
			aux = aux->next;
		}
		aux->next = new Date;
		aux->next->prev = aux;
		aux = aux->next;

		aux->next = NULL;
	}

}

void ValidPet() {

	for (int i = 0; i < sizename; i++) {

		if (aux->client[i] < 32 || aux->client[i] > 32 && aux->client[i] < 65 || aux->client[i] > 122 || aux->client[i] > 90 && aux->client[i] < 97) {

			justletters = 0;

			break;
		}
	}

	for (int i = 0; i < sizelastname; i++) {

		if (aux->pet[i] < 32 || aux->pet[i] > 32 && aux->pet[i] < 65 || aux->pet[i] > 122 || aux->pet[i] > 90 && aux->pet[i] < 97) {

			petletters = 0;

			break;
		}
	}
	
}

void ValidNumber(){

	if (sizenumber == 8 || sizenumber == 10 || sizenumber == 12) {

		validsizenumber = 1;

		for (int i = 0; i < sizenumber; i++) {
			
			if (aux->number[i] < 48 || aux->number[i] > 57) {

				validnumber = 0;
				break;

			}

		}

	}
	else {

		validsizenumber = 0;
	}
}

void ValidPrice() {

	for (int i = 0; i < sizeprice; i++) {

		if (aux->price[i] < 46 || aux->price[i] > 46 && aux->price[i] < 48 || aux->price[i] > 57) {

			validprice = 0;
			
			break;

		}
		if (aux->price[i] == 46) {

			if (sizeprice - 1 > i + 1) {

				validsizeprice = 0;

			}

		}

	}

	
}

BOOL CALLBACK AGENDA(HWND hWnd,
	UINT message,
	WPARAM wParam,
	LPARAM lParam)
{
	switch (message)
	{
	case WM_INITDIALOG:
	{
		aux = origin;

		Image(hWnd, IDC_STATIC_IMAGE1, imagenvet, 100, 80);

		while (aux->next != NULL) {

			hListCitas = GetDlgItem(hWnd, IDC_LIST3);
			SendMessage(hListCitas, LB_ADDSTRING, 0, (LPARAM)TEXT(aux->time));
			aux = aux->next;
		}

		HWND nameinstatic = GetDlgItem(hWnd, IDC_STATIC4);
		SetWindowText(nameinstatic, backup->MV);

		hLocaltime = GetDlgItem(hWnd, IDC_STATIC3);
		hLocaldate = GetDlgItem(hWnd, IDC_STATIC5);

		SetTimer(hWnd, IDT_TIMER1, 1000, (TIMERPROC)NULL);
		SetTimer(hWnd, IDT_TIMER2, 1000, (TIMERPROC)NULL);


	}
	break;
	case WM_TIMER:

		switch (wParam)
		{
		case IDT_TIMER1:
		{
			GetLocalTime(&lt);
			TCHAR buff[1024];
			snprintf(buff, 1024, "The local time is % 02d : % 02d  : % 02d", lt.wHour, lt.wMinute, lt.wSecond);
			SetWindowText(hLocaltime, buff);

		}
		break;
		case IDT_TIMER2:
		{
			GetLocalTime(&lt);
			TCHAR buff[1024];
			snprintf(buff, 1024, "% 02d / % 02d  / % 02d", lt.wDay, lt.wMonth, lt.wYear);
			SetWindowText(hLocaldate, buff);

		}
		break;
		}
		break;
	case WM_COMMAND:

		switch (LOWORD(wParam))
		{
		case IDC_MONTHCALENDAR1:
		{

		}
		break;
		case IDC_LIST3:
		{
			

		}
		break;
		case IDC_BUTTON1:
		{

		}
		break;
		case IDC_BUTTON2:
		{

		}
		break;
		case IDCANCEL:
			
			break;
		case IDOK:

			break;

		}
		break;
	case WM_DESTROY:
		DestroyWindow(hWnd);
		break;
	case WM_CLOSE:
		PostQuitMessage(0);
		break;
	default:
		return FALSE;
		break;
	}
	return FALSE;
}

BOOL CALLBACK EDITAR(HWND hWnd,
	UINT message,
	WPARAM wParam,
	LPARAM lParam)
{
	switch (message)
	{
	case WM_INITDIALOG:
	{
		hComboEspecie = GetDlgItem(hWnd, IDC_COMBO1);
		SendMessage(hComboEspecie, CB_ADDSTRING, 0, (LPARAM)TEXT("Caballo"));
		SendMessage(hComboEspecie, CB_ADDSTRING, 0, (LPARAM)TEXT("Cerdo"));
		SendMessage(hComboEspecie, CB_ADDSTRING, 0, (LPARAM)TEXT("Conejo"));
		SendMessage(hComboEspecie, CB_ADDSTRING, 0, (LPARAM)TEXT("Gato"));
		SendMessage(hComboEspecie, CB_ADDSTRING, 0, (LPARAM)TEXT("Hamster"));
		SendMessage(hComboEspecie, CB_ADDSTRING, 0, (LPARAM)TEXT("Pajaro"));
		SendMessage(hComboEspecie, CB_ADDSTRING, 0, (LPARAM)TEXT("Pato"));
		SendMessage(hComboEspecie, CB_ADDSTRING, 0, (LPARAM)TEXT("Perro"));
		SendMessage(hComboEspecie, CB_ADDSTRING, 0, (LPARAM)TEXT("Pez"));
		SendMessage(hComboEspecie, CB_ADDSTRING, 0, (LPARAM)TEXT("Tortuga"));
		SendMessage(hComboEspecie, CB_ADDSTRING, 0, (LPARAM)TEXT("Otro"));

		hComboMotivo = GetDlgItem(hWnd, IDC_COMBO2);
		SendMessage(hComboMotivo, CB_ADDSTRING, 0, (LPARAM)TEXT("Esterilización"));
		SendMessage(hComboMotivo, CB_ADDSTRING, 0, (LPARAM)TEXT("Vacunaciones"));
		SendMessage(hComboMotivo, CB_ADDSTRING, 0, (LPARAM)TEXT("Alergias"));
		SendMessage(hComboMotivo, CB_ADDSTRING, 0, (LPARAM)TEXT("Infecciones"));
		SendMessage(hComboMotivo, CB_ADDSTRING, 0, (LPARAM)TEXT("Desparasitación"));
		SendMessage(hComboMotivo, CB_ADDSTRING, 0, (LPARAM)TEXT("Microchip de Identificación"));
		SendMessage(hComboMotivo, CB_ADDSTRING, 0, (LPARAM)TEXT("Otro"));
	}
	break;
	case WM_COMMAND:

		switch (LOWORD(wParam))
		{
		case IDC_BUTTON3:
		{

		}
		break;
		case IDC_EDIT1:
		{
			switch (HIWORD(wParam))
			{
			case EN_CHANGE:
			{

			}
			}

		}
		break;

		case IDCANCEL:

			break;
		case IDOK:

			break;

		}
		break;
	case WM_DESTROY:
		DestroyWindow(hWnd);
		break;
	case WM_CLOSE:
		PostQuitMessage(0);
		break;
	default:
		return FALSE;
		break;
	}
	return FALSE;
}

BOOL CALLBACK ELIMINAR(HWND hWnd,
	UINT message,
	WPARAM wParam,
	LPARAM lParam)
{
	switch (message)
	{
	case WM_INITDIALOG:
	{

		hComboEspecie = GetDlgItem(hWnd, IDC_COMBO1);
		SendMessage(hComboEspecie, CB_ADDSTRING, 0, (LPARAM)TEXT("Caballo"));
		SendMessage(hComboEspecie, CB_ADDSTRING, 0, (LPARAM)TEXT("Cerdo"));
		SendMessage(hComboEspecie, CB_ADDSTRING, 0, (LPARAM)TEXT("Conejo"));
		SendMessage(hComboEspecie, CB_ADDSTRING, 0, (LPARAM)TEXT("Gato"));
		SendMessage(hComboEspecie, CB_ADDSTRING, 0, (LPARAM)TEXT("Hamster"));
		SendMessage(hComboEspecie, CB_ADDSTRING, 0, (LPARAM)TEXT("Pajaro"));
		SendMessage(hComboEspecie, CB_ADDSTRING, 0, (LPARAM)TEXT("Pato"));
		SendMessage(hComboEspecie, CB_ADDSTRING, 0, (LPARAM)TEXT("Perro"));
		SendMessage(hComboEspecie, CB_ADDSTRING, 0, (LPARAM)TEXT("Pez"));
		SendMessage(hComboEspecie, CB_ADDSTRING, 0, (LPARAM)TEXT("Tortuga"));
		SendMessage(hComboEspecie, CB_ADDSTRING, 0, (LPARAM)TEXT("Otro"));

		hComboMotivo = GetDlgItem(hWnd, IDC_COMBO2);
		SendMessage(hComboMotivo, CB_ADDSTRING, 0, (LPARAM)TEXT("Esterilización"));
		SendMessage(hComboMotivo, CB_ADDSTRING, 0, (LPARAM)TEXT("Vacunaciones"));
		SendMessage(hComboMotivo, CB_ADDSTRING, 0, (LPARAM)TEXT("Alergias"));
		SendMessage(hComboMotivo, CB_ADDSTRING, 0, (LPARAM)TEXT("Infecciones"));
		SendMessage(hComboMotivo, CB_ADDSTRING, 0, (LPARAM)TEXT("Desparasitación"));
		SendMessage(hComboMotivo, CB_ADDSTRING, 0, (LPARAM)TEXT("Microchip de Identificación"));
		SendMessage(hComboMotivo, CB_ADDSTRING, 0, (LPARAM)TEXT("Otro"));
	
	}
	break;
	case WM_COMMAND:

		switch (LOWORD(wParam))
		{
		case IDC_BUTTON3:
		{

		}
		break;
		case IDC_EDIT1:
		{
			switch (HIWORD(wParam))
			{
			case EN_CHANGE:
			{

			}
			}

		}
		break;

		case IDCANCEL:

			break;
		case IDOK:

			break;

		}
		break;
	case WM_DESTROY:
		DestroyWindow(hWnd);
		break;
	case WM_CLOSE:
		PostQuitMessage(0);
		break;
	default:
		return FALSE;
		break;
	}
	return FALSE;
}

void Image(HWND hWnd, WPARAM wParam, char *imagen, int m, int n) {

	static HBITMAP bmp1, bmp2;

	bmp1 = (HBITMAP)SendDlgItemMessage(hWnd, wParam, STM_GETIMAGE, IMAGE_BITMAP, 0);
	bmp2 = (HBITMAP)LoadImage(NULL, imagen, IMAGE_BITMAP, m, n, LR_LOADFROMFILE);

	SendDlgItemMessage(hWnd, wParam, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmp2);

}

