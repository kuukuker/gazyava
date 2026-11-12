#ifdef _WIN32
#include <windows.h>
#endif
#include <iostream>
using namespace std;
int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8); SetConsoleCP(CP_UTF8);
#endif
    cout << "Система учета инвентаря колледжа\n0. Выход\nВведите номер пункта: ";
    int command; if (!(cin >> command)) return 1;
    if (command == 0) cout << "До свидания!\n";
    else cout << "Пункт пока не реализован.\n";
    return 0;
}
