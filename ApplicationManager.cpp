//كلنا 


#include "ApplicationManager.h"
#include "LoginOperation.h"
#include "RegisterOperation.h"
#include "BookRoomOperation.h"
#include "CancelReservationOperation.h"
#include "CheckInOperation.h"
#include "CheckOutOperation.h"
#include "AddRoomOperation.h"
#include "DeleteRoomOperation.h"
#include "SearchRoomOperation.h"
#include "SaveToFileOperation.h"
#include "GenerateBillOperation.h"
#include "FoodOrderOperation.h"
#include "GroceryOrderOperation.h"
#include "ApplyTaxOperation.h"
#include "Admin.h"
#include "FileManager.h"
#include <iostream>
using namespace std;

ApplicationManager::ApplicationManager() : currentUserIndex(-1), taxRate(0.15) {
    users.push_back(Admin("admin", "admin123"));
    rooms.push_back(Room(101, "Single", 100));
    rooms.push_back(Room(102, "Double", 150));
    rooms.push_back(Room(103, "Suite", 250));
    loadData();
}

void ApplicationManager::run() {
    int c;
    do {
        c = ui.mainMenu();
        if (c == 1) login();
        else if (c == 2) registerUser();
        else if (c == 3) { cout << "Exiting...\n"; saveData(); }
    } while (c != 3);
}

void ApplicationManager::login() {
    LoginOperation op(users);
    int idx = op.execute();
    if (idx != -1) {
        currentUserIndex = idx;
        if (users[idx].type == "admin") adminMenu();
        else guestMenu();
        currentUserIndex = -1;
    }
}

void ApplicationManager::registerUser() {
    RegisterOperation op(users);
    op.execute();
}

void ApplicationManager::logout() {
    currentUserIndex = -1;
    ui.printMessage("Logged out.");
}

void ApplicationManager::adminMenu() {
    int c;
    do {
        c = ui.adminMenu();
        if (c == 1) { AddRoomOperation op(rooms); op.execute(); }
        else if (c == 2) { DeleteRoomOperation op(rooms, reservations); op.execute(); }
        else if (c == 3) {
            cout << "All Reservations:\n";
            for (size_t i = 0; i < reservations.size(); i++)
                cout << "ID: " << reservations[i].reservationID << " Guest: " << reservations[i].guestUsername
                     << " Room: " << reservations[i].roomNumber << " Status: " << reservations[i].status << "\n";
        }
        else if (c == 4) {
            cout << "All Bills:\n";
            for (size_t i = 0; i < bills.size(); i++)
                cout << "Bill ID: " << bills[i].billID << " Guest: " << bills[i].guestUsername
                     << " Total: $" << bills[i].totalAmount << " Paid: " << (bills[i].paid ? "Yes" : "No") << "\n";
        }
        else if (c == 5) { ApplyTaxOperation op(taxRate); op.execute(); }
        else if (c == 6) { logout(); return; }
    } while (true);
}

void ApplicationManager::guestMenu() {
    int c;
    do {
        c = ui.guestMenu();
        if (c == 1) { BookRoomOperation op(rooms, reservations, users[currentUserIndex]); op.execute(); }
        else if (c == 2) { CancelReservationOperation op(rooms, reservations, users[currentUserIndex]); op.execute(); }
        else if (c == 3) { CheckInOperation op(reservations, users[currentUserIndex]); op.execute(); }
        else if (c == 4) { CheckOutOperation op(rooms, reservations, users[currentUserIndex]); op.execute(); }
        else if (c == 5) { FoodOrderOperation op(rooms, reservations, users[currentUserIndex]); op.execute(); }
        else if (c == 6) { GroceryOrderOperation op(rooms, reservations, users[currentUserIndex]); op.execute(); }
        else if (c == 7) { GenerateBillOperation op(rooms, reservations, bills, users[currentUserIndex], taxRate); op.execute(); }
        else if (c == 8) { SearchRoomOperation op(rooms); op.execute(); }
        else if (c == 9) { logout(); return; }
    } while (true);
}

void ApplicationManager::saveData() {
    FileManager fm;
    fm.saveAll(users, rooms, reservations, bills);
}

void ApplicationManager::loadData() {
    FileManager fm;
    fm.loadAll(users, rooms, reservations, bills);
    bool hasAdmin = false;
    for (size_t i = 0; i < users.size(); i++)
        if (users[i].type == "admin") hasAdmin = true;
    if (!hasAdmin) users.push_back(Admin("admin", "admin123"));
}