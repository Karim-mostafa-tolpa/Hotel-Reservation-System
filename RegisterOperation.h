//Karim Mostafa

#ifndef REGISTEROPERATION_H
#define REGISTEROPERATION_H

#include <vector>
#include "User.h"
using namespace std;

//جبت في الكلاس ده الفيكتور بتاع اليوزرز 
class RegisterOperation {
    vector<User>& users;
public:
    RegisterOperation(vector<User>& u);
    void execute();
};

#endif