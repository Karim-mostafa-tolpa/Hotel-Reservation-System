

#include "AddRoomOperation.h"
//
#include <iostream>
using namespace std;

//
AddRoomOperation::AddRoomOperation(vector<Room>& r) : rooms(r) {}

//
void AddRoomOperation::execute() {
    int num; string typ; double pr;
    cout << "Enter room number: "; cin >> num;
    cout << "Enter room type: "; cin >> typ;
    cout << "Enter price per night: "; cin >> pr;
    rooms.push_back(Room(num, typ, pr));
    cout << "Room added.\n";
}
//