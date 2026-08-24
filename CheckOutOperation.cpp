//Karim Mostafa

#include "CheckOutOperation.h"
#include <iostream>
using namespace std;

CheckOutOperation::CheckOutOperation(vector<Room>& r, vector<Reservation>& res, User& u)
    : rooms(r), reservations(res), currentUser(u) {}

void CheckOutOperation::execute() {
    int id;
    cout << "Enter reservation ID to check out: "; cin >> id;
    for (size_t i = 0; i < reservations.size(); i++) {
        if (reservations[i].reservationID == id && reservations[i].guestUsername == currentUser.username) {
            if (reservations[i].status == "checked_in") {
                reservations[i].status = "checked_out";
                for (size_t j = 0; j < rooms.size(); j++) {
                    if (rooms[j].roomNumber == reservations[i].roomNumber) {
                        rooms[j].available = true;
                        rooms[j].guestAssigned = "";
                        break;
                    }
                }
                cout << "Checked out. Please pay your bill.\n";
            } else {
                cout << "Cannot check out (status: " << reservations[i].status << ").\n";
            }
            return;
        }
    }
    cout << "Reservation not found.\n";
}