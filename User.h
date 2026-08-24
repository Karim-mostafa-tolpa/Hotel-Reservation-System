

#ifndef USER_H
#define USER_H


#include <string>
using namespace std;

class User {

public:
    string username, password, type;

    User(string u = "", string p = "", string t = "");
    bool login(string u, string p);
};
#endif