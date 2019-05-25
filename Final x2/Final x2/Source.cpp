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
}*first;

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
bool exists = 0;

struct Date {
	char client[1024] = "";
	char number[12] = "";
	char pet[1024] = "";
	char specie[1024] = "";
	char sexo[1024] = "";
	char motivo[1024] = "";
	char price[1024] = "";
	char payment3[1024] = "";
	char payment6[1024] = "";
	char payment9[1024] = "";
	char payment[1024] = "";
	char date[1024] = "";
	char time[1024] = "";
	char dateok[1024] = "";
	char timeok[1024] = "";
	int id;
	Date *prev;
	Date *next;
}*origin, *aux, *last;

char userverification[1024];
char passwordverification[1024];

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
bool validdate = 1;
bool validtime = 1;
bool flag = 1;

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
void ValidDateTime();
void ConvertirFecha(char*Fecha);
void ConvertirHora(char*Hora);
void ConvertirFechasl(char*Fecha);
void ValidPrice();

char Fechaok[11];
char Horaok[11];
char Fechasl[11];
char FechaL[11];
char HoraL[9];

int dateid;

void FillDate();
void Delete();
void SaveFile();
void ReadFile();

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

			HWND username = GetDlgItem(hWnd, IDC_EDIT1);
			GetWindowText(username, userverification, 1024);

			break;
		}
		case IDC_EDIT2:
		{

			HWND password = GetDlgItem(hWnd, IDC_EDIT2);
			GetWindowText(password, passwordverification, 1024);


			break;
		}
		case IDC_STATIC7:
		{
			DialogBox(hInst, MAKEINTRESOURCE(IDD_PASSWORD), hWnd, PASSWORD);

		}

		break;
		case IDC_STATIC2:
		{
			DialogBox(hInst, MAKEINTRESOURCE(IDD_SINGUP), hWnd, SINGUP);
		}

		break;
		case IDOK:
		{

			auxiliar = inicio;

			if (userverification[0] == NULL || passwordverification[0] == NULL) {

				MessageBox(NULL, "Complete todos los campos", "Error", NULL);
				break;

			}

			while (auxiliar->sig != NULL) {
				if (strcmp(userverification, auxiliar->username) == 0 && strcmp(passwordverification, auxiliar->password) == 0) {
					valid = true;
					break;
				}
				else {
					
						auxiliar = auxiliar->sig;
				}
				
			}

	
			TCHAR buff[1] = TEXT("");

			if (valid == 0) {

				MessageBox(NULL, "Datos Incorrectos", "Error", NULL);

				SetDlgItemText(hWnd, IDC_EDIT1, buff);
				SetDlgItemText(hWnd, IDC_EDIT2, buff);
			}
			else {

				EndDialog(hWnd, 0);
				DialogBox(hInst, MAKEINTRESOURCE(IDD_PRINCIPAL), hWnd, PRINCIPAL);
			}
		}
			break;
		}
		break;
	case WM_DESTROY:
		DestroyWindow;
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
		ReadFile();

		int num = 1;

		Date *temp = NULL;

		temp = origin;
		if (temp != NULL) {
			
			while (temp->next != NULL) {
				temp = temp->next;
				if (temp->id > num) {
					num = temp->id;

				}
			}
			
			dateid = num +1;
		}

		Image(hWnd, IDC_STATIC5, imagenlogo, 400, 230);
	
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
		case ID_VETERINARIO_INFORMACION:

			DialogBox(hInst, MAKEINTRESOURCE(IDD_INFO), hWnd, INFO);

			break;
		case ID_VETERINARIO_EDITAR:

			DialogBox(hInst, MAKEINTRESOURCE(IDD_INFO), hWnd, INFO);

			break;
		case ID_CITA_NUEVA:

			DialogBox(hInst, MAKEINTRESOURCE(IDD_NEWDATE), hWnd, NEWDATE);

			break;
		case ID_CITA_EDITAR:

			DialogBox(hInst, MAKEINTRESOURCE(IDD_AGENDA), hWnd, AGENDA);

			break;
		case ID_CITA_ELIMINAR:

			DialogBox(hInst, MAKEINTRESOURCE(IDD_AGENDA), hWnd, AGENDA);

			break;
		case ID_AGENDA_VER:

			DialogBox(hInst, MAKEINTRESOURCE(IDD_AGENDA), hWnd, AGENDA);

			break;
		case ID_SALIR:

			SaveFile();
			PostQuitMessage(0);

			break;
		}
	case WM_DESTROY:
		DestroyWindow;
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


BOOL CALLBACK SINGUP(HWND hWnd,
	UINT message,
	WPARAM wParam,
	LPARAM lParam)
{
	switch (message)
	{
	case WM_INITDIALOG:
	{
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

				NewUser();

				MessageBox(NULL, "Usuario creado con éxito", "Usuario", MB_ICONINFORMATION);
				EndDialog(hWnd, 0);
			}

		}
			break;

		}
		break;
	case WM_DESTROY:
		EndDialog(hWnd, 0);
		return TRUE;
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
		case SEARCH:
		{

			if (auxiliar->existinguser[0] == NULL) {

				MessageBox(NULL, "Complete todos los campos", "Error", NULL);
				break;
			}

			while (auxiliar->sig != NULL) {
				if (strcmp(auxiliar->existinguser, auxiliar->username) == 0) {
					exists = 1;

					HWND password = GetDlgItem(hWnd, IDC_EDIT2);
					GetWindowText(password, auxiliar->password, 1024);

					HWND cpassword = GetDlgItem(hWnd, IDC_EDIT5);
					GetWindowText(cpassword, auxiliar->samepassword, 1024);

					break;
				}
				else {
					auxiliar = auxiliar->sig;
				}
			}

			if (exists == 1) {
				EnableWindow(GetDlgItem(hWnd, IDC_EDIT2), TRUE);
				EnableWindow(GetDlgItem(hWnd, IDC_EDIT5), TRUE);

			}
			else {

				MessageBox(NULL, "No se encontro el usuario", "Usuario", NULL);
			}

		}
			break;
	    case IDOK:
	    {
		TCHAR buff[1] = TEXT("");


		if (auxiliar->existinguser[0] == NULL || auxiliar->password[0] == NULL || auxiliar->samepassword[0] == NULL ) {

			MessageBox(NULL, "Complete todos los campos", "Error", NULL);
			break;
		}
		if (exists == 0) {

			MessageBox(NULL, "La información no ha sido modificada", "Error", NULL);
			break;
		}

		if (strcmp(auxiliar->password, auxiliar->samepassword) != 0) {

			MessageBox(NULL, "Las contraseñas no coinciden", "Error", NULL);

			SetDlgItemText(hWnd, IDC_EDIT2, buff);
			SetDlgItemText(hWnd, IDC_EDIT5, buff);
		}
		else {

			MessageBox(NULL, "Contraseña guardada con éxito", "Contraseña", MB_ICONINFORMATION);
			EndDialog(hWnd, 0);
		}

	    }
			break;

		}
		break;
	case WM_DESTROY:
		EndDialog(hWnd, 0);
		return TRUE;
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
		SetWindowText(name, first->name);

		HWND lastname = GetDlgItem(hWnd, IDC_EDIT2);
		SetWindowText(lastname, first->lastname);

		HWND identificationcard = GetDlgItem(hWnd, IDC_EDIT9);
		SetWindowText(identificationcard, first->identificationcard);

		HWND completename = GetDlgItem(hWnd, IDC_EDIT5);
		SetWindowText(completename, first->completename);


		HWND carrer = GetDlgItem(hWnd, IDC_EDIT8);
		SetWindowText(carrer, first->carrer);

		if (first->name[0] != NULL) {

			EnableWindow(GetDlgItem(hWnd, IDC_EDIT1), FALSE);
			EnableWindow(GetDlgItem(hWnd, IDC_EDIT2), FALSE);
			EnableWindow(GetDlgItem(hWnd, IDC_EDIT9), FALSE);
			EnableWindow(GetDlgItem(hWnd, IDC_EDIT8), FALSE);

		}

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
		case IDEDIT:
		{
			EnableWindow(GetDlgItem(hWnd, IDC_EDIT1), TRUE);
			EnableWindow(GetDlgItem(hWnd, IDC_EDIT2), TRUE);
			EnableWindow(GetDlgItem(hWnd, IDC_EDIT9), TRUE);
			EnableWindow(GetDlgItem(hWnd, IDC_EDIT8), TRUE);

		}
		break;
		case IDCANCEL:
		{
			int msgboxID = MessageBox( NULL, "Se perderán todos los cambios no guardados.\n¿Desea continuar?", "Confirmación",MB_ICONEXCLAMATION | MB_YESNO);
			
			if (msgboxID == IDYES)
			{
			   EndDialog(hWnd, 0);
			}
		}
			break;
	   
		case IDOK:
		{
			HWND name = GetDlgItem(hWnd, IDC_EDIT1);
			GetWindowText(name, first->name, 1024);

			sizename = strlen(first->name);

			HWND lastname = GetDlgItem(hWnd, IDC_EDIT2);
			GetWindowText(lastname, first->lastname, 1024);

			sizelastname = strlen(first->lastname);

			HWND identificationcard = GetDlgItem(hWnd, IDC_EDIT9);
			GetWindowText(identificationcard, first->identificationcard, 1024);

			strcpy_s(first->completename, first->lastname);
			strcat_s(first->completename, " ");
			strcat_s(first->completename, first->name);

			strcpy_s(first->MV, first->name);
			strcat_s(first->MV, " ");
			strcat_s(first->MV, first->lastname);

			HWND completename = GetDlgItem(hWnd, IDC_EDIT5);
			SetWindowText(completename, first->completename);

			HWND nameinstatic = GetDlgItem(hWnd, IDC_STATIC4);
			SetWindowText(nameinstatic, first->MV);

			HWND carrer = GetDlgItem(hWnd, IDC_EDIT8);
			GetWindowText(carrer, first->carrer, 1024);

			TCHAR buff[1] = TEXT("");

			if (first->name[0] == NULL || first->lastname[0] == NULL || first->identificationcard[0] == NULL || first->carrer[0] == NULL) {

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

				GetWindowText(name, first->name, 1024);
				GetWindowText(lastname, first->lastname, 1024);

				strcpy_s(first->completename, first->lastname);
				strcat_s(first->completename, " ");
				strcat_s(first->completename, first->name);

				strcpy_s(first->MV, first->name);
				strcat_s(first->MV, " ");
				strcat_s(first->MV, first->lastname);

				justletters = 1;
			}
			else {

				KillTimer(hWnd, IDT_TIMER1);
				KillTimer(hWnd, IDT_TIMER2);
			
				MessageBox(NULL, "Información guardada con éxito.", "Veterinario", MB_ICONINFORMATION);
			
			}
		}
			break;

		}
		break;
	case WM_DESTROY:
		EndDialog(hWnd, 0);
		return TRUE;
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

void NewVet() {

	if (first == NULL) {

		first = new Vet;
	}
}

void ValidName() {

	for (int i = 0; i < sizename; i++) {

		if (first->name[i] < 32 || first->name[i] > 32 && first->name[i] < 65 || first->name[i] > 122 || first->name[i] > 90 && first->name[i] < 97) {

			justletters = 0;

			break;
		}
	}

	for (int i = 0; i < sizelastname; i++) {

		if (first->lastname[i] < 32 || first->lastname[i] > 32 && first->lastname[i] < 65 || first->lastname[i] > 122 || first->lastname[i] > 90 && first->lastname[i] < 97) {

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
		NewDate();

		Image(hWnd, IDC_STATIC_IMAGE1, imagenvet, 100, 80);

		HWND nameinstatic = GetDlgItem(hWnd, IDC_STATIC4);
		SetWindowText(nameinstatic, first->MV);
		
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
		case IDC_COMBO2:
		{

			GetWindowText(hComboMotivo, aux->motivo, 1024);

			if (aux->motivo[0] == 79 && aux->motivo[1] == 116) {

				*aux->motivo = NULL;
				EnableWindow(GetDlgItem(hWnd, IDC_EDIT6), TRUE);
			}
		}
		break;
		case IDC_RADIO1:
		{

			HWND pago = GetDlgItem(hWnd, IDC_RADIO1);
			GetWindowText(pago, aux->payment, 1024);
		}
			break;
		case IDC_RADIO2:
		{
			HWND pago = GetDlgItem(hWnd, IDC_RADIO2);
			GetWindowText(pago, aux->payment, 1024);
		}
			break;
		case IDC_RADIO3:
		{
			HWND pago = GetDlgItem(hWnd, IDC_RADIO3);
			GetWindowText(pago, aux->payment, 1024);
		}
			break;
		case IDC_RADIO4:
		{
			HWND pago = GetDlgItem(hWnd, IDC_RADIO4);
			GetWindowText(pago, aux->payment, 1024);
		}
			break;
		case IDC_RADIO5:
		{
			HWND especie = GetDlgItem(hWnd, IDC_RADIO5);
			GetWindowText(especie, aux->sexo, 1024);
		}
			break;
		case IDC_RADIO6:
		{
			HWND especie = GetDlgItem(hWnd, IDC_RADIO6);
			GetWindowText(especie, aux->sexo, 1024);
		}
			break;
		case IDC_EDIT6:
		{
			HWND motivo = GetDlgItem(hWnd, IDC_EDIT6);
			GetWindowText(motivo, aux->motivo, 1024);
		}
		break;
		case IDC_EDIT7:
		{
			HWND price = GetDlgItem(hWnd, IDC_EDIT7);
			GetWindowText(price, aux->price, 1024);

			sizeprice = strlen(aux->price);

			payment = atof(aux->price);
				
			payment3 = payment / 3 + payment*.12;
			payment6 = payment / 6 + payment * .12;
			payment9 = payment / 9 + payment * .12;
			
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
		{
			int msgboxID = MessageBox(NULL, "Se perderán todos los cambios no guardados.\n¿Desea continuar?", "Confirmación", MB_ICONEXCLAMATION | MB_YESNO);

			if (msgboxID == IDYES)
			{
				EndDialog(hWnd, 0);
			}
		}
			break;
		case IDOK:
		{

			TCHAR buff[1] = TEXT("");


			if (aux->client[0] == NULL ||  aux->motivo[0] == NULL || aux->number[0] == NULL || aux->pet[0] == NULL || aux->specie[0] == NULL || aux->specie[0] == NULL || aux->price[0] == NULL || aux->payment[0] == NULL ) {

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

			SYSTEMTIME dateSelected, timeSelected;
			DateTime_GetSystemtime(hTimePicker, &timeSelected);
			MonthCal_GetCurSel(hDatePicker, &dateSelected);

			SendDlgItemMessage(hWnd, IDC_DATETIMEPICKER1, WM_GETTEXT, 1024, (LPARAM)aux->date);
			SendDlgItemMessage(hWnd, IDC_DATETIMEPICKER2, WM_GETTEXT, 1024, (LPARAM)aux->time);

			ConvertirFecha(aux->date);
			ConvertirHora(aux->time);

			GetLocalTime(&lt);
			snprintf(FechaL, 11, "%02d%02d%02d", lt.wDay, lt.wMonth, lt.wYear);
			snprintf(HoraL, 9, "%02d%02d%02d", lt.wHour, lt.wMinute, lt.wSecond);

			ValidDateTime();

			if (validdate == 0) {

				MessageBox(NULL, "Fecha Inválida.Seleccione otra fecha.", "Error", NULL);
				validdate = 1;
				*Fechaok = NULL;
				*Horaok = NULL;

				break;
			}
			if(validtime == 0) {

				MessageBox(NULL, "Hora Inválida.Seleccione otra hora.", "Error", NULL);
				validtime = 1;
				*Fechaok = NULL;
				*Horaok = NULL;

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
			else {

				KillTimer(hWnd, IDT_TIMER1);
				KillTimer(hWnd, IDT_TIMER2);

				MessageBox(NULL, "Información guardada con éxito.", "Veterinario", MB_ICONINFORMATION);

				*Fechaok = NULL;
				*Horaok = NULL;

				EndDialog(hWnd, 0);
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

void NewDate() {

	aux = origin;

	if (origin == NULL) {

		origin = new Date;
		origin->next = NULL;
		origin->prev = NULL;
		origin->id = dateid++;
		aux = origin;
		last = origin;
	}
	else {
		while (aux->next != NULL) {
			aux = aux->next;
		}
		aux->next = new Date;
		aux->next->prev = aux;
		aux->id = dateid++;
		aux = aux->next;
		last = aux;

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

void ConvertirFecha(char*Fecha)
{

	string cutMonth, FechaOri;
	cutMonth = Fecha; //Guarda en un string el valor de un char
	string Day = cutMonth.substr(0, 2); //Substraes el dia 
	string Month = cutMonth.substr(3, 2);//Substraes el mes 
	string Year = cutMonth.substr(6, 4);//Substraes el año 

	FechaOri = Day + Month + Year;
	strcat_s(Fechaok,FechaOri.c_str()); 
	strcat_s(aux->dateok, FechaOri.c_str());
	
}

void ConvertirHora(char*Fecha)
{
	string cutMonth, FechaOri;
	cutMonth = Fecha; //Guarda en un string el valor de un char
	string Day = cutMonth.substr(0, 2); //Substraes el dia 
	string Month = cutMonth.substr(3, 2);//Substraes el mes 
	string Year = cutMonth.substr(6, 2);//Substraes el año 

	FechaOri = Day + Month + Year; //Concatemas la fecha
	strcat_s(Horaok, FechaOri.c_str()); //La copias al char
	strcat_s(aux->timeok, FechaOri.c_str());
}

void ValidDateTime() {

	int ds, dl, hs, hl;

	ds = atoi(Fechaok);
    dl = atoi(FechaL);
	hs = atoi(Horaok);
	hl = atoi(HoraL);
	
	if (ds < dl) {

		validdate = 0;
	}
	else if (ds == dl) {

		if (hl >= 120000) {

		hs = hs + 120000;
	    }

	    if (hs < hl) {

		validtime = 0;

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

		HWND nameinstatic = GetDlgItem(hWnd, IDC_STATIC4);
		SetWindowText(nameinstatic, first->MV);

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
		case IDC_BUTTON3:
		{
			SendDlgItemMessage(hWnd, IDC_LIST3, LB_RESETCONTENT, 0, 0);

			aux = origin;

			SendDlgItemMessage(hWnd, IDC_DATETIMEPICKER1, WM_GETTEXT, 1024, (LPARAM)Fechasl);

			ConvertirFechasl(Fechasl);

			int ds, cita;

			ds = atoi(Fechaok);

			while (aux != NULL) {

				cita = atoi(aux->dateok);

				if (ds == cita) {

					hListCitas = GetDlgItem(hWnd, IDC_LIST3);
					SendMessage(hListCitas, LB_ADDSTRING, 0, (LPARAM)TEXT(aux->time));
			
				}
				aux = aux->next;
			}

			*Fechaok = NULL;
			
		}
		break;
		case IDC_LIST3:
		{
			if (HIWORD(wParam) == LBN_DBLCLK) {

				index = SendMessage(hListCitas, LB_GETCURSEL, 0, 0);
				idx = SendDlgItemMessage(hWnd, IDC_LIST3, LB_GETITEMDATA, index, 0);

				aux = origin;

				while (aux->id != idx) {
					if (aux->next != NULL) {
						aux = aux->next;
					}
					else {
						MessageBox(NULL, "Cita no encontrada.Inteta otra vez", "Error", NULL);
						flag = 0;
						break;
					}
				}

				if (flag == 1) {

					DialogBox(hInst, MAKEINTRESOURCE(IDD_EDITAR), hWnd, EDITAR);
				}
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

BOOL CALLBACK EDITAR(HWND hWnd,
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
		SetWindowText(nameinstatic, first->MV);

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


		hComboMotivo = GetDlgItem(hWnd, IDC_COMBO2);
		SendMessage(hComboMotivo, CB_ADDSTRING, 0, (LPARAM)TEXT("Esterilización"));
		SendMessage(hComboMotivo, CB_ADDSTRING, 0, (LPARAM)TEXT("Vacunas"));
		SendMessage(hComboMotivo, CB_ADDSTRING, 0, (LPARAM)TEXT("Alergias"));
		SendMessage(hComboMotivo, CB_ADDSTRING, 0, (LPARAM)TEXT("Infecciones"));
		SendMessage(hComboMotivo, CB_ADDSTRING, 0, (LPARAM)TEXT("Desparasitación"));
		SendMessage(hComboMotivo, CB_ADDSTRING, 0, (LPARAM)TEXT("Microchip de Identificación"));
		SendMessage(hComboMotivo, CB_ADDSTRING, 0, (LPARAM)TEXT("Otro"));


		hDatePicker = GetDlgItem(hWnd, IDC_DATETIMEPICKER1);
		hTimePicker = GetDlgItem(hWnd, IDC_DATETIMEPICKER2);

		hLocaltime = GetDlgItem(hWnd, IDC_STATIC6);
		hLocaldate = GetDlgItem(hWnd, IDC_STATIC9);

		SetTimer(hWnd, IDT_TIMER1, 1000, (TIMERPROC)NULL);
		SetTimer(hWnd, IDT_TIMER2, 1000, (TIMERPROC)NULL);

		HWND client = GetDlgItem(hWnd, IDC_EDIT2);
		SetWindowText(client, aux->client);

		HWND number = GetDlgItem(hWnd, IDC_EDIT4);
		SetWindowText(number, aux->number);

		HWND pet = GetDlgItem(hWnd, IDC_EDIT1);
		SetWindowText(pet, aux->pet);

		SetWindowText(hComboEspecie, aux->specie);

		HWND specie = GetDlgItem(hWnd, IDC_EDIT3);
		SetWindowText(specie, aux->specie);

		SetWindowText(hComboMotivo, aux->motivo);

		HWND motivo = GetDlgItem(hWnd, IDC_EDIT6);
		SetWindowText(motivo, aux->motivo);

		HWND price = GetDlgItem(hWnd, IDC_EDIT7);
		SetWindowText(price, aux->price);

		HWND payment = GetDlgItem(hWnd, IDC_STATIC30);
		SetWindowText(payment, aux->price);

		HWND payment9 = GetDlgItem(hWnd, IDC_STATIC29);
		SetWindowText(payment9, aux->payment9);

		HWND payment6 = GetDlgItem(hWnd, IDC_STATIC28);
		SetWindowText(payment6, aux->payment6);

		HWND payment3 = GetDlgItem(hWnd, IDC_STATIC27);
		SetWindowText(payment3, aux->payment3);

		hRadioHembra = GetDlgItem(hWnd, IDC_RADIO5);
		hRadioMacho = GetDlgItem(hWnd, IDC_RADIO6);
		hRadio3m = GetDlgItem(hWnd, IDC_RADIO1);
		hRadio6m = GetDlgItem(hWnd, IDC_RADIO2);
		hRadio9m = GetDlgItem(hWnd, IDC_RADIO3);
		hRadioSin = GetDlgItem(hWnd, IDC_RADIO4);

		if (aux->sexo[0] == 72) {

			SendMessage(hRadioHembra, BM_SETCHECK,(WPARAM)BST_CHECKED, 1);
		}
		else {

			SendMessage(hRadioMacho, BM_SETCHECK, (WPARAM)BST_CHECKED, 1);
		}



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
		case IDC_COMBO2:
		{

			GetWindowText(hComboMotivo, aux->motivo, 1024);

			if (aux->motivo[0] == 79 && aux->motivo[1] == 116) {

				*aux->motivo = NULL;
				EnableWindow(GetDlgItem(hWnd, IDC_EDIT6), TRUE);
			}
		}
		break;
		case IDC_RADIO1:
		{

			HWND pago = GetDlgItem(hWnd, IDC_RADIO1);
			GetWindowText(pago, aux->payment, 1024);
		}
		break;
		case IDC_RADIO2:
		{
			HWND pago = GetDlgItem(hWnd, IDC_RADIO2);
			GetWindowText(pago, aux->payment, 1024);
		}
		break;
		case IDC_RADIO3:
		{
			HWND pago = GetDlgItem(hWnd, IDC_RADIO3);
			GetWindowText(pago, aux->payment, 1024);
		}
		break;
		case IDC_RADIO4:
		{
			HWND pago = GetDlgItem(hWnd, IDC_RADIO4);
			GetWindowText(pago, aux->payment, 1024);
		}
		break;
		case IDC_RADIO5:
		{
			HWND especie = GetDlgItem(hWnd, IDC_RADIO5);
			GetWindowText(especie, aux->specie, 1024);
		}
		break;
		case IDC_RADIO6:
		{
			HWND especie = GetDlgItem(hWnd, IDC_RADIO6);
			GetWindowText(especie, aux->specie, 1024);
		}
		break;
		case IDC_EDIT6:
		{
			HWND motivo = GetDlgItem(hWnd, IDC_EDIT6);
			GetWindowText(motivo, aux->motivo, 1024);
		}
		break;
		case IDC_EDIT7:
		{
			HWND price = GetDlgItem(hWnd, IDC_EDIT7);
			GetWindowText(price, aux->price, 1024);

			sizeprice = strlen(aux->price);

			payment = atof(aux->price);

			payment3 = payment / 3 + payment * .12;
			payment6 = payment / 6 + payment * .12;
			payment9 = payment / 9 + payment * .12;

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
		{
			int msgboxID = MessageBox(NULL, "Se perderán todos los cambios no guardados.\n¿Desea continuar?", "Confirmación", MB_ICONEXCLAMATION | MB_YESNO);

			if (msgboxID == IDYES)
			{
				EndDialog(hWnd, 0);
			}
		}
		break;
		case IDOK:
		{

			TCHAR buff[1] = TEXT("");


			if (aux->client[0] == NULL || aux->motivo[0] == NULL || aux->number[0] == NULL || aux->pet[0] == NULL || aux->specie[0] == NULL || aux->price[0] == NULL || aux->payment[0] == NULL) {

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

			SYSTEMTIME dateSelected, timeSelected;
			DateTime_GetSystemtime(hTimePicker, &timeSelected);
			MonthCal_GetCurSel(hDatePicker, &dateSelected);

			SendDlgItemMessage(hWnd, IDC_DATETIMEPICKER1, WM_GETTEXT, 1024, (LPARAM)aux->date);
			SendDlgItemMessage(hWnd, IDC_DATETIMEPICKER2, WM_GETTEXT, 1024, (LPARAM)aux->time);

			ConvertirFecha(aux->date);
			ConvertirHora(aux->time);

			GetLocalTime(&lt);
			snprintf(FechaL, 11, "%02d%02d%02d", lt.wDay, lt.wMonth, lt.wYear);
			snprintf(HoraL, 9, "%02d%02d%02d", lt.wHour, lt.wMinute, lt.wSecond);

			ValidDateTime();

			if (validdate == 0) {

				MessageBox(NULL, "Fecha Inválida.Seleccione otra fecha.", "Error", NULL);
				validdate = 1;
				*Fechaok = NULL;
				*Horaok = NULL;

				break;
			}
			if (validtime == 0) {

				MessageBox(NULL, "Hora Inválida.Seleccione otra hora.", "Error", NULL);
				validtime = 1;
				*Fechaok = NULL;
				*Horaok = NULL;

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
			else {

				KillTimer(hWnd, IDT_TIMER1);
				KillTimer(hWnd, IDT_TIMER2);

				MessageBox(NULL, "Información guardada con éxito.", "Veterinario", MB_ICONINFORMATION);

				*Fechaok = NULL;
				*Horaok = NULL;

				EndDialog(hWnd, 0);
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

void Image(HWND hWnd, WPARAM wParam, char *imagen, int m, int n) {

	static HBITMAP bmp1, bmp2;

	bmp1 = (HBITMAP)SendDlgItemMessage(hWnd, wParam, STM_GETIMAGE, IMAGE_BITMAP, 0);
	bmp2 = (HBITMAP)LoadImage(NULL, imagen, IMAGE_BITMAP, m, n, LR_LOADFROMFILE);

	SendDlgItemMessage(hWnd, wParam, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmp2);

}

void ConvertirFechasl(char*Fecha) {

	string cutMonth, FechaOri;
	cutMonth = Fecha; //Guarda en un string el valor de un char
	string Day = cutMonth.substr(0, 2); //Substraes el dia 
	string Month = cutMonth.substr(3, 2);//Substraes el mes 
	string Year = cutMonth.substr(6, 4);//Substraes el año 

	FechaOri = Day + Month + Year;
	strcat_s(Fechaok, FechaOri.c_str());

}

void Delete() {

	if (origin == aux) {

		origin = aux->next;
		if (aux->next != NULL) {
			aux->next->prev = NULL;
		}
	}
	else {
		aux->prev->next = aux->next;
		if (aux->next != NULL) {
			aux->next->prev = aux->prev;
		}
	}

	delete aux;
}

void SaveFile() {

	Date info;
	Date *aux = 0, *borrar;
	file.open("SavedFile.txt", ios::binary | ios::trunc);
	if (file.is_open())
	{
		// LEER la lista ligada
		aux = origin;
		while (aux != 0)
		{
			file.write((char*)aux, sizeof(Date));
			borrar = aux;
			aux = aux->next;
			delete borrar;
		}
		file.close();
	}
	else
	{
		printf("El archivo no se pudo abrir.");
	}
}

void ReadFile() {

	Date *info = 0;

	lectura.open("SavedFile.txt", ios::binary);
	if (lectura.is_open())
	{
		info = new Date;
		lectura.read((char*)info, sizeof(Date));
		info->prev = 0;
		info->next = 0;

		while (!lectura.eof())
		{
			if (origin == NULL) {
				origin = info;
				last = info;
			}
			else {
				last->next = info;
				info->prev = last;

				last = info;
			}

			info = new Date;
			lectura.read((char*)info, sizeof(Date));
			info->prev = 0;
			info->next = 0;

		}
		lectura.close();
	}
	else
	{
		printf("El archivo no se pudo abrir.");
	}
}

