

#ifndef CHECKINOPERATION_H
#define CHECKINOPERATION_H

#include <vector>
#include "Reservation.h"
#include "User.h"
using namespace std;

//بيتشيك ان الاوضه اللي يوزر حاجز فيها بس 

class CheckInOperation {
    vector<Reservation>& reservations;
    User& currentUser;
public:
    CheckInOperation(vector<Reservation>& res, User& u);
    void execute();
};

#endif