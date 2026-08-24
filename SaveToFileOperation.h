

#ifndef SAVETOFILEOPERATION_H
#define SAVETOFILEOPERATION_H


#include <vector>
#include "User.h"
#include "Room.h"
#include "Reservation.h"
#include "Bill.h"
using namespace std;

class SaveToFileOperation {
    vector<User>& users;
    vector<Room>& rooms;
    vector<Reservation>& reservations;
    vector<Bill>& bills;
public:
    SaveToFileOperation(vector<User>& u, vector<Room>& r, vector<Reservation>& res, vector<Bill>& b);

    
    void execute();
};

#endif