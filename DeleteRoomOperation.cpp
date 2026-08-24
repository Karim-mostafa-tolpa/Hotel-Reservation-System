//Abdelrahman Ayman Hamdy


#include "DeleteRoomOperation.h"
#include <iostream>
using namespace std;

DeleteRoomOperation::DeleteRoomOperation(vector<Room>& r, vector<Reservation>& res)
    : rooms(r), reservations(res) {}

void DeleteRoomOperation::execute() {
    int num;
    cout << "Enter room number to delete: "; cin >> num;
    for (size_t i = 0; i < reservations.size(); i++) {
        if (reservations[i].roomNumber == num &&
            (reservations[i].status == "booked" || reservations[i].status == "checked_in")) {
            cout << "Cannot delete room with active reservations.\n";
            return;
        }
    }
    for (size_t i = 0; i < rooms.size(); i++) {
        if (rooms[i].roomNumber == num) {
            rooms.erase(rooms.begin() + i);
            cout << "Room deleted.\n";
            return;
        }
    }
    cout << "Room not found.\n";
}