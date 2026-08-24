

#include "Bill.h"

Bill::Bill(int id, string guest) : billID(id), guestUsername(guest), totalAmount(0), paid(false) {}

void Bill::addCharge(string item, double cost) {
    charges.push_back(make_pair(item, cost));
    totalAmount += cost;
}