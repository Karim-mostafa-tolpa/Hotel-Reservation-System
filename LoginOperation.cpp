//Karim Mostafa

#include "LoginOperation.h"
#include "UI.h"
#include <iostream>
using namespace std;

LoginOperation::LoginOperation(vector<User>& u) : users(u) {}

int LoginOperation::execute() {
    UI ui;
    string u, p, t;
    ui.loginMenu(u, p, t);
    for (size_t i = 0; i < users.size(); i++) {
        if (users[i].username == u && users[i].password == p && users[i].type == t) {
            ui.printMessage("Login successfully.");
            return i;
        }
    }
    ui.printMessage("Invalid .");
    return -1;
}