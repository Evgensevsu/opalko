#include <iostream>
#include <string>

using namespace std;

string encrypt(string message, int key) {
    string result = "";
    for (char c : message) {
        if (isalpha(c)) {
            char shifted = toupper(c) + key;
            if (shifted > 'Z') {
                shifted -= 26;
            }
            result += shifted;
        } else {
            result += c;
        }
    }
    return result;
}

string decrypt(string message, int key) {
    string result = "";
    for (char c : message) {
        if (isalpha(c)) {
            char shifted = toupper(c) - key;
            if (shifted < 'A') {
                shifted += 26;
            }
            result += shifted;
        } else {
            result += c;
        }
    }
    return result;
}

int main() {
    int choice;
    cout << "Выберите действие:" << endl;
    cout << "1. Зашифровать текст" << endl;
    cout << "2. Расшифровать текст" << endl;
    cin >> choice;

    string message;
    int key;
    if (choice == 1) {
        cout << "Введите текст для шифрования: ";
        cin.ignore();
        getline(cin, message);
        cout << "Введите ключ для шифрования: ";
        cin >> key;
        string encrypted = encrypt(message, key);
        cout << "Зашифрованный текст: " << encrypted << endl;
    } else if (choice == 2) {
        cout << "Введите текст для расшифрования: ";
        cin.ignore();
        getline(cin, message);
        cout << "Введите ключ для расшифрования: ";
        cin >> key;
        string decrypted = decrypt(message, key);
        cout << "Расшифрованный текст: " << decrypted << endl;
    } else {
        cout << "Ошибка: неверный выбор действия." << endl;
    }

    return 0;
}