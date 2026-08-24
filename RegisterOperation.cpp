//Karim Mostafa

#include "RegisterOperation.h"
#include "Guest.h"
#include "UI.h"
#include <iostream>
using namespace std;

RegisterOperation::RegisterOperation(vector<User>& u) : users(u) {}

void RegisterOperation::execute() {
    UI ui;
    string u, p;
    cout << "Enter username: "; cin >> u;
    cout << "Enter password: "; cin >> p;
    for (size_t i = 0; i < users.size(); i++) {
        //عشان يبقى ساين اب مش لوج ان فاعملت ديه تشيك اليوزر موجود ولا لا عشان لو موجود يبقى يعمل لوح ان بقى 
        if (users[i].username == u) {
            ui.printMessage("Username already exists.");
            return;
        }
    }
    users.push_back(Guest(u, p));
    ui.printMessage("Registration successful.");
}