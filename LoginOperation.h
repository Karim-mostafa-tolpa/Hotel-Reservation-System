

#ifndef LOGINOPERATION_H
#define LOGINOPERATION_H

#include <vector>
#include "User.h"
using namespace std;

//عملت لوج ان اوبريشن و ربطها باليوزر اللي عمر كان عامله و استخدمت اكسزكيوت برضو

class LoginOperation {
    vector<User>& users;
public:
    LoginOperation(vector<User>& u);
    int execute();
};

#endif