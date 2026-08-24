//Karim Mostafa

#include "BookRoomOperation.h"
#include <iostream>
using namespace std;

BookRoomOperation::BookRoomOperation(vector<Room>& r, vector<Reservation>& res, User& u)
    : rooms(r), reservations(res), currentUser(u) {}

void BookRoomOperation::execute() {
    if (currentUser.type != "guest") {
        cout << "Only guests can book rooms.\n";
        return;
    }
    int num; string cinD, coutD;
    cout << "Enter room number: "; cin >> num;
    bool found = false, avail = false;
    for (size_t i = 0; i < rooms.size(); i++) {
        if (rooms[i].roomNumber == num) {
            found = true;
            avail = rooms[i].available;
            break;
        }
    }
    if (!found) { cout << "Room not found.\n"; return; }
    if (!avail) { cout << "Room not available.\n"; return; }
    cout << "Check-in date (YYYY-MM-DD): "; cin >> cinD;
    cout << "Check-out date (YYYY-MM-DD): "; cin >> coutD;
    int id = reservations.size() + 1001;
    reservations.push_back(Reservation(id, currentUser.username, num, cinD, coutD));
    for (size_t i = 0; i < rooms.size(); i++) {
        if (rooms[i].roomNumber == num) {
            rooms[i].available = false;
            rooms[i].guestAssigned = currentUser.username;
            break;
        }
    }
    cout << "Reservation created. ID: " << id << "\n";
}