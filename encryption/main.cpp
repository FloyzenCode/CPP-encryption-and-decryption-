#include <iostream>
#include <Windows.h>
#include <string>
#define _STD_USE_ using namespace std;
constexpr auto FOUR = 4;
constexpr auto sizearr = 1024;

_STD_USE_

// ��������� ������� SetWindowsPos � ������������ ����� Microsoft
/*
BOOL SetWindowPos(

HWND hWnd,            // ���������� ����
HWND hWndInsertAfter, // ���������� ������� ����������
int x,                // ������� �� �����������
int y,                // ������� �� ���������
int cx,               // ������
int cy,               // ������
UINT uFlags           // ������ ���������������� ����

);
*/

// ������������ ��� �������
class config {
public:
	void _config(void) {
	SetConsoleTextAttribute(console, color);
	SetConsoleTitle(title_window);
	setlocale(NULL, "");
	system("chcp 1251 > null");
}

private:
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD color = FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY;
	LPCWSTR title_window = L"Encryption Application";
}; config sys; // global varriable

// ������ � ������������� �������
void MoveWindow(int posx, int posy)
{
	RECT rectClient, rectWindow;
	HWND hWnd = GetConsoleWindow();
	GetClientRect(hWnd, &rectClient);
	GetWindowRect(hWnd, &rectWindow);
	MoveWindow(hWnd, posx, posy, rectClient.right - rectClient.left, rectClient.bottom - rectClient.top, TRUE);
}

void MoveCenter()
{
	RECT rectClient, rectWindow;
	HWND hWnd = GetConsoleWindow();
	GetClientRect(hWnd, &rectClient);
	GetWindowRect(hWnd, &rectWindow);
	int posx, posy;
	posx = GetSystemMetrics(SM_CXSCREEN) / 2 - (rectWindow.right - rectWindow.left) / 2,
		posy = GetSystemMetrics(SM_CYSCREEN) / 2 - (rectWindow.bottom - rectWindow.top) / 2,

		MoveWindow(hWnd, posx, posy, rectClient.right - rectClient.left, rectClient.bottom - rectClient.top, TRUE);
}

// �������

class func {
public:
	// ��������� ���������� � �������
	void information() {
		string start = "\t\t\t��������� ���������� � ������������ ������\n";
		string info = "\t\t     ����� ������������� ������ ������� F1 � ENTER.\n";

		for (int i = NULL; i < start.size(); i++) {
			cout << start[i]; 
			Sleep(80);
		}

		for (int q = NULL; q < info.size(); q++) {
			cout << info[q];
			Sleep(80);
		}
	}
	
	// ���������� � ������������
	char de_and_encryption() {
		INT de_encryptionNumber = rand() % 100;
		//	color	//	
		WORD forIndex = FOREGROUND_RED | BACKGROUND_INTENSITY;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), forIndex);
		cout << "Encryption index: " << de_encryptionNumber << endl;
		sys._config();
		while (true) {
			if (GetAsyncKeyState(VK_F1))
				break;
			char str[sizearr] = { NULL };
			cout << "������� �����: ";
			cin.getline(str, sizearr);
			for (int i = NULL; str[i]; i++)
				str[i] += de_encryptionNumber;
			cout << "������������� �����: " << str << endl;
			for (int u = NULL; str[u]; u++)
				str[u] -= de_encryptionNumber;
			cout << "������������� �����: " << str << "\n\n============================\n";
		}
		return 0;
	}
}; func function;

INT main(INT argc, CHAR *argv[]) {
	sys._config(); // ��������� ������������ �������
	MoveWindow(450, 300); // x, y - WinAPI, ���������� ������� ������� ��� ������������� �� ��������
	function.information();
	function.de_and_encryption();
	return 0;
}