


#ifndef ADDROOMOPERATION_H
#define ADDROOMOPERATION_H

#include <vector>
#include "Room.h"
using namespace std;


class AddRoomOperation {
    vector<Room>& rooms;
public:
    AddRoomOperation(vector<Room>& r);
    void execute();
};
//
#endif