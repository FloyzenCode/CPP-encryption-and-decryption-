#include <iostream>
#include <Windows.h>
#include <string>
#define _STD_USE_ using namespace std;
constexpr auto FOUR = 4;
constexpr auto sizearr = 1024;

_STD_USE_

// Структура функции SetWindowsPos с официального сайта Microsoft
/*
BOOL SetWindowPos(

HWND hWnd,            // дескриптор окна
HWND hWndInsertAfter, // дескриптор порядка размещения
int x,                // позиция по горизонтали
int y,                // позиция по вертикали
int cx,               // ширина
int cy,               // высота
UINT uFlags           // флажки позиционирования окна

);
*/

// конфигурация для проекта
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

// Работа с конфигурацией консоли
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

// Функции

class func {
public:
	// Стартовая информация в консоли
	void information() {
		string start = "\t\t\tПрограмма шифрования и дешифрования текста\n";
		string info = "\t\t     Чтобы приостановить работу нажмите F1 и ENTER.\n";

		for (int i = NULL; i < start.size(); i++) {
			cout << start[i]; 
			Sleep(80);
		}

		for (int q = NULL; q < info.size(); q++) {
			cout << info[q];
			Sleep(80);
		}
	}
	
	// Шифрование и дешифрование
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
			cout << "Введите текст: ";
			cin.getline(str, sizearr);
			for (int i = NULL; str[i]; i++)
				str[i] += de_encryptionNumber;
			cout << "Зашифрованный текст: " << str << endl;
			for (int u = NULL; str[u]; u++)
				str[u] -= de_encryptionNumber;
			cout << "Дешифрованный текст: " << str << "\n\n============================\n";
		}
		return 0;
	}
}; func function;

INT main(INT argc, CHAR *argv[]) {
	sys._config(); // применяем конфигурацию проекта
	MoveWindow(450, 300); // x, y - WinAPI, координаты запуска консоли для центрирования на мониторе
	function.information();
	function.de_and_encryption();
	return 0;
}
