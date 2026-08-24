

#include "Reservation.h"

//برضوا فايل لذيذ جدا 

Reservation::Reservation(int id, string guest, int room, string cinD, string coutD)
    : reservationID(id), guestUsername(guest), roomNumber(room), checkInDate(cinD), checkOutDate(coutD), status("booked") {}