


#include "CancelReservationOperation.h"
#include <iostream>
using namespace std;

CancelReservationOperation::CancelReservationOperation(vector<Room>& r, vector<Reservation>& res, User& u)
    : rooms(r), reservations(res), currentUser(u) {}

void CancelReservationOperation::execute() {
    int id;
    cout << "Enter reservation ID to cancel: "; cin >> id;
    for (size_t i = 0; i < reservations.size(); i++) {
        if (reservations[i].reservationID == id && reservations[i].guestUsername == currentUser.username) {
            if (reservations[i].status == "checked_in" || reservations[i].status == "checked_out") {
                cout << "Cannot cancel checked-in/out reservation.\n";
            } else {
                reservations[i].status = "cancelled";
                for (size_t j = 0; j < rooms.size(); j++) {
                    if (rooms[j].roomNumber == reservations[i].roomNumber) {
                        rooms[j].available = true;
                        rooms[j].guestAssigned = "";
                        break;
                    }
                }
                cout << "Reservation cancelled.\n";
            }
            return;
        }
    }
    cout << "Reservation not found or not yours.\n";
}