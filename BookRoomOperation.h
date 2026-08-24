


#ifndef BOOKROOMOPERATION_H
#define BOOKROOMOPERATION_H

#include <vector>
#include "Room.h"
#include "Reservation.h"
#include "User.h"
using namespace std;

class BookRoomOperation {
    vector<Room>& rooms;
    vector<Reservation>& reservations;
    User& currentUser;
public:
    BookRoomOperation(vector<Room>& r, vector<Reservation>& res, User& u);
    void execute();
};

#endif