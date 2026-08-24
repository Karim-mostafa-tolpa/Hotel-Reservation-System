//Omar & Abdo


#include "GroceryOrderOperation.h"
#include <iostream>
using namespace std;

GroceryOrderOperation::GroceryOrderOperation(vector<Room>& r, vector<Reservation>& res, User& u)
    : rooms(r), reservations(res), currentUser(u) {}

void GroceryOrderOperation::execute() {
    string item; double price;
    cout << "Enter grocery item: "; cin >> item;
    cout << "Enter price: "; cin >> price;
    for (size_t i = 0; i < reservations.size(); i++) {
        if (reservations[i].guestUsername == currentUser.username && reservations[i].status == "checked_in") {
            for (size_t j = 0; j < rooms.size(); j++) {
                if (rooms[j].roomNumber == reservations[i].roomNumber) {
                    rooms[j].additionalCharges += price;
                    cout << "Grocery order added to room charges.\n";
                    return;
                }
            }
        }
    }
    cout << "No active check-in found.\n";
}