#ifdef _WIN32
#include <windows.h>
#endif
#include <iostream>
#include <string>
using namespace std;

bool authenticate(string& role) {
    for (int attempt = 1; attempt <= 3; ++attempt) {
        string username, password;
        cout << "Логин: "; if (!(cin >> username)) return false;
        cout << "Пароль: "; if (!(cin >> password)) return false;
        if (username == "admin" && password == "admin123") { role = "администратор"; return true; }
        if (username == "operator" && password == "operator123") { role = "оператор"; return true; }
        cout << "Неверный логин или пароль. Попытка " << attempt << " из 3.\n";
    }
    return false;
}

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8); SetConsoleCP(CP_UTF8);
#endif
    cout << "Здравствуйте! Добро пожаловать в систему учета инвентаря.\n";
    string role;
    if (!authenticate(role)) { cout << "Вход не выполнен.\n"; return 1; }
    cout << "\nЗдравствуйте, " << role << ".\n0. Выход\n";
    cout << "Введите номер пункта: "; int command;
    if (cin >> command && command == 0) cout << "До свидания!\n";
    return 0;
}
