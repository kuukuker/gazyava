#ifdef _WIN32
#include <windows.h>
#endif

#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

struct Room {
    int id{};
    string name;
};

struct Equipment {
    int id{};
    string number;
    string name;
    string model;
    string status = "В работе";
    int roomId{};
};

class Inventory {
private:
    vector<Room> rooms;
    vector<Equipment> items;
    int nextItem = 1;
    int nextRoom = 1;
    const string dataFile = "inventory.txt";

    static bool readInt(const string& prompt, int& value) {
        while (true) {
            cout << prompt;
            if (cin >> value) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return true;
            }
            if (cin.eof()) return false;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Введите целое число.\n";
        }
    }

    static string readText(const string& prompt) {
        string value;
        cout << prompt;
        getline(cin, value);
        return value;
    }

    int itemIndex(int id) const {
        for (int i = 0; i < static_cast<int>(items.size()); ++i)
            if (items[i].id == id) return i;
        return -1;
    }

    int roomIndex(int id) const {
        for (int i = 0; i < static_cast<int>(rooms.size()); ++i)
            if (rooms[i].id == id) return i;
        return -1;
    }

    string roomName(int id) const {
        int index = roomIndex(id);
        return index < 0 ? "Не закреплено" : rooms[index].name;
    }

    

    

    void printEquipment(const Equipment& item) const {
        cout << "ID: " << item.id
             << " | Инв. номер: " << item.number
             << " | Название: " << item.name
             << " | Модель: " << item.model
             << " | Статус: " << item.status
             << " | Аудитория: " << roomName(item.roomId) << '\n';
    }

public:
        public:
    void run(const string& role) {
        bool running=true;
        while(running){
            cout << "\n=== Учет инвентаря | " << role << " ===\n";
            cout << "0. Выход\n";
            int c; if(!readInt("Введите номер пункта: ",c)) break;
            switch(c){
                case 0: running=false; cout<<"До свидания!\n"; break;
                default: cout<<"Такого пункта нет.\n";
            }
        }
    }
};

bool authenticate(string& role) {
    for (int attempt = 1; attempt <= 3; ++attempt) {
        string username;
        string password;

        cout << "Логин: ";
        if (!(cin >> username)) return false;
        cout << "Пароль: ";
        if (!(cin >> password)) return false;

        if (username == "admin" && password == "admin123") {
            role = "администратор";
            return true;
        }
        if (username == "operator" && password == "operator123") {
            role = "оператор";
            return true;
        }

        cout << "Неверный логин или пароль. Попытка "
             << attempt << " из 3.\n";
    }
    return false;
}

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
    cout << "Здравствуйте! Добро пожаловать в систему учета инвентаря.\n";
    string role;
    if (!authenticate(role)) { cout << "Вход не выполнен.\n"; return 1; }
    Inventory app;
    app.run(role);
    return 0;
}
