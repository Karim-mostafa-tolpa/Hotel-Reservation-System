

#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <vector>
#include <string>
using namespace std;

//هنا خلاصة الكلاسات اللي عملتها نوعا ما 

class User;
class Room;
class Reservation;
class Bill;

//هنا عملته في فيكتورززز

class FileManager {
public:
    void saveAll(const vector<User>& users, const vector<Room>& rooms,
                 const vector<Reservation>& reservations, const vector<Bill>& bills);
    void loadAll(vector<User>& users, vector<Room>& rooms,
                 vector<Reservation>& reservations, vector<Bill>& bills);
};

#endif