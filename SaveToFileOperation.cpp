

#include "SaveToFileOperation.h"
#include "FileManager.h"



SaveToFileOperation::SaveToFileOperation(vector<User>& u, vector<Room>& r,
                                         vector<Reservation>& res, vector<Bill>& b)
    : users(u), rooms(r), reservations(res), bills(b) {}


    // الحلو هنا عملت حرفيا فانكشن من فانكشنز عاملها اللي هي سيف اول و اكسكيوت 
void SaveToFileOperation::execute() {
    FileManager fm;
    fm.saveAll(users, rooms, reservations, bills);
}