

#include "Room.h"

Room::Room(int num, string t, double price)
    : roomNumber(num), type(t), pricePerNight(price), available(true), guestAssigned(""), additionalCharges(0) {}

void Room::setAvailability(bool a) { available = a; }
void Room::assignGuest(string g) { guestAssigned = g; }
void Room::addServiceCharge(double amt) { additionalCharges += amt; }
void Room::resetCharges() { additionalCharges = 0; }