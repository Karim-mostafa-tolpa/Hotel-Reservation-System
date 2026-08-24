


#ifndef GENERATEBILLOPERATION_H
#define GENERATEBILLOPERATION_H

#include <vector>
#include "Room.h"
#include "Reservation.h"
#include "Bill.h"
#include "User.h"
using namespace std;

class GenerateBillOperation {
    vector<Room>& rooms;
    vector<Reservation>& reservations;
    vector<Bill>& bills;
    User& currentUser;
    double taxRate;
public:
    GenerateBillOperation(vector<Room>& r, vector<Reservation>& res, vector<Bill>& b, User& u, double tax);
    void execute();
};

#endif