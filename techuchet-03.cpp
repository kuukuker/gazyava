#ifdef _WIN32
#include <windows.h>
#endif
#include <iostream>
#include <limits>
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

bool readInt(const string& prompt, int& value) {
    cout << prompt;
    if (cin >> value) { cin.ignore(numeric_limits<streamsize>::max(), '\n'); return true; }
    if (cin.eof()) return false;
    cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Введите целое число.\n";
    return false;
}

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8); SetConsoleCP(CP_UTF8);
#endif
    cout << "Здравствуйте! Добро пожаловать в систему учета инвентаря.\n";
    string role;
    if (!authenticate(role)) { cout << "Вход не выполнен.\n"; return 1; }
    bool running = true;
    while (running) {
        cout << "\n=== Учет инвентаря | " << role << " ===\n"
             << "0. Выход\n";
        int command;
        if (!readInt("Введите номер пункта: ", command)) continue;
        if (command == 0) running = false;
        else cout << "Функции учета будут добавляться по этапам.\n";
    }
    return 0;
}
