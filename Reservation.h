

#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>
using namespace std;

//زي كله عملتهم عشان اتشيك ان تشيك اوت و عملت اي دي للحجز 
class Reservation {
public:
    int reservationID;
    string guestUsername;
    int roomNumber;
    string checkInDate, checkOutDate, status;

    Reservation(int id = 0, string guest = "", int room = 0, string cinD = "", string coutD = "");
};

#endif