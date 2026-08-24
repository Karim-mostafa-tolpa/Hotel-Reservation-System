

//ديه المنيو اللي هايتعملها رن في الماين ظبت فيها طريقة الكتابه 

#include "UI.h"
#include <iostream>
using namespace std;

int UI::mainMenu() {
    cout << "\n===== Hotel Management System =====\n";
    cout << "1. Login\n2. Register (Guest only)\n3. Exit\nChoice: ";
    int c; cin >> c; return c;
}

void UI::loginMenu(string& u, string& p, string& t) {
    cout << "\n----- Login -----\nUsername: "; cin >> u;
    cout << "Password: "; cin >> p;
    cout << "Type (admin/guest): "; cin >> t;
}

int UI::adminMenu() {
    cout << "\n===== Admin Menu =====\n";
    cout << "1. Add Room\n2. Delete Room\n3. View Reservations\n";
    cout << "4. View Bills\n5. Set Tax Rate\n6. Logout\nChoice: ";
    int c; cin >> c; return c;
}

int UI::guestMenu() {
    cout << "\n===== Guest Menu =====\n";
    cout << "1. Book Room\n2. Cancel Reservation\n3. Check In\n";
    cout << "4. Check Out\n5. Order Food\n6. Order Groceries\n";
    cout << "7. View My Bill\n8. Search Available Rooms\n9. Logout\nChoice: ";
    int c; cin >> c; return c;
}

void UI::printMessage(const string& msg) {
    cout << msg << "\n";
}