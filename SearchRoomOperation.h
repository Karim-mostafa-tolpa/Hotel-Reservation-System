


#ifndef SEARCHROOMOPERATION_H
#define SEARCHROOMOPERATION_H

#include <vector>
#include "Room.h"
using namespace std;

class SearchRoomOperation {
    vector<Room>& rooms;
public:
    SearchRoomOperation(vector<Room>& r);
    void execute();
};

#endif