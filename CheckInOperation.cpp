//Karim Mostafa

#include "CheckInOperation.h"
#include <iostream>
using namespace std;


CheckInOperation::CheckInOperation(vector<Reservation>& res, User& u)
    : reservations(res), currentUser(u) {}

void CheckInOperation::execute() {
    int id;
    cout << "Enter reservation ID to check in: "; cin >> id;
    for (size_t i = 0; i < reservations.size(); i++) {
        if (reservations[i].reservationID == id && reservations[i].guestUsername == currentUser.username) {
            if (reservations[i].status == "booked") {
                reservations[i].status = "checked_in";
                cout << "Checked in successfully.\n";
            } else {
                cout << "Cannot check in (status: " << reservations[i].status << ").\n";
            }
            return;
        }
    }
    cout << "Reservation not found.\n";
}