#include <Windows.h>
#include <stdlib.h>
#include <iostream>
#include "resource.h"

struct Vet {
	char name[1024];
	char lastname[1024];
	int cedula;
	char carrer[1024];
}*first;

struct User {
	int number;
	char username[1024];
	char password[1024];
	char cpassword[1024];
	User *next;
}*second, *aux2;

bool valid = 0;
bool valid2 = 0;
int iduser = 1;

struct Date {
	char client[1024];
	char number[12];
	char pet[1024];
	char especie[1024];
	char fecha[1024];
	char hora[1024];
	char motivo[1024];
	char price;
	Date *prev;
	Date *sig;
}*origin, *aux;

HINSTANCE hInst;
HINSTANCE hIDD_Agenda;
HINSTANCE hIDD_Editar;
HINSTANCE hIDD_Eliminar;
HINSTANCE hIDD_Info;
HINSTANCE hIDD_Login;
HINSTANCE hIDD_Newdate;
HINSTANCE hIDD_Singup;

HWND hWnd;
HWND hStaticColor;
HWND hComboBox;

BOOL CALLBACK AGENDA(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK EDITAR(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK ELIMINAR(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK INFO(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK NEWDATE(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK SINGUP(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK PRINCIPAL(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK LOGIN(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(_In_ HINSTANCE hInstace,
	_In_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nCmdShow)
{
	hIDD_Singup = hInstace;
	hWnd = CreateDialog(
		hIDD_Singup,
		MAKEINTRESOURCE(IDD_SINGUP),
		NULL,
		SINGUP
	);

	first = NULL;
	second = NULL;
	aux2 = second;
	origin = NULL;
	aux = origin;

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

		aux2 = second;

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
			switch (HIWORD(wParam))
			{
			case EN_CHANGE:
			{
				char buff[1024];
				GetDlgItemText(hWnd, IDC_EDIT1, buff, 1024);


				while (aux2->next != NULL) {
					if (buff == aux2->username) {
						valid = true;
						break;
					}

				}
			}

			}
			break;
		}
		case IDC_EDIT2:
		{
			switch (HIWORD(wParam))
			{
			case EN_CHANGE:
			{
				char buff[1024];
				GetDlgItemText(hWnd, IDC_EDIT2, buff, 1024);

				while (aux2->next != NULL) {
					if (buff == aux2->password) {
						valid2 = true;
						break;
					}
				}
			}

			}
			break;
		}
		case IDOK:

			if (valid == 0 || valid2 == 0) {

				MessageBox(NULL, "Datos Incorrectos", "Error", NULL);

			}
			else {

			DialogBox(hInst, MAKEINTRESOURCE(IDD_PRINCIPAL), hWnd, PRINCIPAL);

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
	
	}
	break;
	case WM_COMMAND:

		switch (LOWORD(wParam))
		{
		case IDC_VET:
		{
			DialogBox(hIDD_Info, MAKEINTRESOURCE(IDD_INFO), hWnd, INFO);

		}
		break;
		case IDC_DATE:
		{
			DialogBox(hIDD_Newdate, MAKEINTRESOURCE(IDD_NEWDATE), hWnd, NEWDATE);

		}
		break; case IDC_AGENDA:
		{
			DialogBox(hIDD_Agenda, MAKEINTRESOURCE(IDD_AGENDA), hWnd, AGENDA);

		}
		break;
		case IDC_EXIT:
		{
			DestroyWindow(hWnd);
			PostQuitMessage(0);

		}
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

BOOL CALLBACK SINGUP(HWND hWnd,
	UINT message,
	WPARAM wParam,
	LPARAM lParam)
{
	switch (message)
	{
	case WM_INITDIALOG:
	{

		if (second == NULL) {

			second = new User;
			second->number = iduser++;
			*second->username = -1;
			*second->password = -2;
			*second->cpassword = -3;
			second->next = NULL;
			aux2 = second;
		}
		else {
			while (aux2->next != NULL) {
				aux2 = aux2->next;
			}
			aux2->next = new User;
			aux2 = aux2->next;
			aux2->number = iduser++;
			*aux2->username = -1;
			*aux2->password = -2;
			*aux2->cpassword = -3;
			aux2->next = NULL;
		}
	}
	break;
	case WM_COMMAND:

		switch (LOWORD(wParam))
		{
		case IDC_EDIT1:
		{
			switch (HIWORD(wParam))
			{
			case EN_CHANGE:
			{
         		GetDlgItemText(hWnd, IDC_EDIT1, aux2->username, 1024);
			}
			}

		}
		break;
		case IDC_EDIT2:
		{
			switch (HIWORD(wParam))
			{
			case EN_CHANGE:
			{
				GetDlgItemText(hWnd, IDC_EDIT2, aux2->password, 1024);
			}
			}

		}
		break;
		case IDC_EDIT5:
		{
			switch (HIWORD(wParam))
			{
			case EN_CHANGE:
			{
				GetDlgItemText(hWnd, IDC_EDIT5, aux2->cpassword, 1024);

			}

			}
			break;
		}
		case IDOK:
			
		

				MessageBox(NULL, "Usuario creado con éxito", "Usuario", NULL);
				DialogBox(hIDD_Login, MAKEINTRESOURCE(IDD_LOGIN), hWnd, LOGIN);
		
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
		case IDC_EDIT2:
		{
			switch (HIWORD(wParam))
			{
			case EN_CHANGE:
			{
				
			}
			}

		}
		break;
		case IDC_EDIT9:
		{
			switch (HIWORD(wParam))
			{
			case EN_CHANGE:
			{
				
			}
			}

		}
		break;
		case IDC_EDIT5:
		{
			switch (HIWORD(wParam))
			{
			case EN_CHANGE:
			{
				
			}
			}

		}
		break;
		case IDC_EDIT8:
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

BOOL CALLBACK AGENDA(HWND hWnd,
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

BOOL CALLBACK NEWDATE(HWND hWnd,
	UINT message,
	WPARAM wParam,
	LPARAM lParam)
{
	switch (message)
	{
	case WM_INITDIALOG:
	{
		hComboBox = GetDlgItem(hWnd, IDC_COMBO1);
		SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)TEXT("Caballo"));
		SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)TEXT("Cerdo"));
		SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)TEXT("Conejo"));
		SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)TEXT("Gato"));
		SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)TEXT("Hamster"));
		SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)TEXT("Pajaro"));
		SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)TEXT("Pato"));
		SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)TEXT("Perro"));
		SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)TEXT("Pez"));
		SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)TEXT("Tortuga"));
		SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)TEXT("Otro"));
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

BOOL CALLBACK EDITAR(HWND hWnd,
	UINT message,
	WPARAM wParam,
	LPARAM lParam)
{
	switch (message)
	{
	case WM_INITDIALOG:
	{
		hComboBox = GetDlgItem(hWnd, IDC_COMBO1);
		SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)TEXT("Caballo"));
		SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)TEXT("Cerdo"));
		SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)TEXT("Conejo"));
		SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)TEXT("Gato"));
		SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)TEXT("Hamster"));
		SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)TEXT("Pajaro"));
		SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)TEXT("Pato"));
		SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)TEXT("Perro"));
		SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)TEXT("Pez"));
		SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)TEXT("Tortuga"));
		SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)TEXT("Otro"));
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
		hComboBox = GetDlgItem(hWnd, IDC_COMBO1);
		SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)TEXT("Caballo"));
		SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)TEXT("Cerdo"));
		SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)TEXT("Conejo"));
		SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)TEXT("Gato"));
		SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)TEXT("Hamster"));
		SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)TEXT("Pajaro"));
		SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)TEXT("Pato"));
		SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)TEXT("Perro"));
		SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)TEXT("Pez"));
		SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)TEXT("Tortuga"));
		SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)TEXT("Otro"));
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



