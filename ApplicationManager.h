


#ifndef APPLICATIONMANAGER_H
#define APPLICATIONMANAGER_H

#include <vector>
#include <string>
#include "User.h"
#include "Room.h"
#include "Reservation.h"
#include "Bill.h"
#include "UI.h"
using namespace std;

class ApplicationManager {
public:
    vector<User> users;
    vector<Room> rooms;
    vector<Reservation> reservations;
    vector<Bill> bills;
    int currentUserIndex;
    UI ui;
    double taxRate;

    ApplicationManager();
    void run();
    void saveData();
    void loadData();
    void adminMenu();
    void guestMenu();
    void login();
    void registerUser();
    void logout();
};

#endif