//Abdelrahman Ayman Hamdy


#include "GenerateBillOperation.h"
#include <iostream>
using namespace std;

GenerateBillOperation::GenerateBillOperation(vector<Room>& r, vector<Reservation>& res,
                                             vector<Bill>& b, User& u, double tax)
    : rooms(r), reservations(res), bills(b), currentUser(u), taxRate(tax) {}

void GenerateBillOperation::execute() {
    int idx = -1;
    for (size_t i = 0; i < bills.size(); i++) {
        if (bills[i].guestUsername == currentUser.username && !bills[i].paid) {
            idx = i;
            break;
        }
    }
    if (idx == -1) {
        bills.push_back(Bill(bills.size() + 2001, currentUser.username));
        idx = bills.size() - 1;
    }
    double total = 0;
    for (size_t i = 0; i < reservations.size(); i++) {
        if (reservations[i].guestUsername == currentUser.username &&
            (reservations[i].status == "checked_out" || reservations[i].status == "checked_in")) {
            for (size_t j = 0; j < rooms.size(); j++) {
                if (rooms[j].roomNumber == reservations[i].roomNumber) {
                    total += rooms[j].pricePerNight + rooms[j].additionalCharges;
                    rooms[j].resetCharges();
                    break;
                }
            }
        }
    }
    bills[idx].addCharge("Room Charges", total);
    double tax = total * taxRate;
    bills[idx].addCharge("Tax (" + to_string(int(taxRate * 100)) + "%)", tax);

    cout << "Bill ID: " << bills[idx].billID << "\n";
    cout << "Guest: " << bills[idx].guestUsername << "\nItems:\n";
    for (size_t i = 0; i < bills[idx].charges.size(); i++) {
        cout << "  " << bills[idx].charges[i].first << ": $" << bills[idx].charges[i].second << "\n";
    }
    cout << "Total: $" << bills[idx].totalAmount << "\nMark as paid? (y/n): ";
    char c; cin >> c;
    if (c == 'y') bills[idx].paid = true;
}