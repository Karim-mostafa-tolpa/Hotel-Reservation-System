


#include "SearchRoomOperation.h"
#include <iostream>
using namespace std;

SearchRoomOperation::SearchRoomOperation(vector<Room>& r) : rooms(r) {}

void SearchRoomOperation::execute() {
    cout << "Available Rooms:\n";
    for (size_t i = 0; i < rooms.size(); i++) {
        if (rooms[i].available) {
            cout << "Room " << rooms[i].roomNumber << " (" << rooms[i].type << ") - $"
                 << rooms[i].pricePerNight << " per night\n";
        }
    }
}