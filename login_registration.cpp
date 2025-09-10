#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void registerUser() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ofstream fout(username + ".txt");
    fout << username << endl << password;
    fout.close();

    cout << "Registration successful!\n";
}

bool loginUser() {
    string username, password, fileUser, filePass;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream fin(username + ".txt");
    if (!fin) {
        cout << "User not found.\n";
        return false;
    }
    getline(fin, fileUser);
    getline(fin, filePass);

    if (fileUser == username && filePass == password) {
        cout << "Login successful!\n";
        return true;
    }
    cout << "Invalid credentials.\n";
    return false;
}

int main() {
    int choice;
    cout << "1. Register\n2. Login\nChoose: ";
    cin >> choice;
    if (choice == 1) registerUser();
    else if (choice == 2) loginUser();
    else cout << "Invalid choice.\n";
    return 0;
}