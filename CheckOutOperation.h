

#ifndef CHECKOUTOPERATION_H
#define CHECKOUTOPERATION_H

#include <vector>
#include "Room.h"
#include "Reservation.h"
#include "User.h"
using namespace std;

//تشيك اوت  بيقبقى بس من اللي حاجز الاوضه 
class CheckOutOperation {
    vector<Room>& rooms;
    vector<Reservation>& reservations;
    User& currentUser;
public:
    CheckOutOperation(vector<Room>& r, vector<Reservation>& res, User& u);
    void execute();
};

#endif