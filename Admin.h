

#ifndef ADMIN_H
#define ADMIN_H


#include "User.h"

//عملت كلاس الادمين حرفيا نوعا ما زي اليوزر فورثت شوية حاجات اللي هي اليوزر و الباس و بيباس الادمن كاتايب 

class Admin : public User {
public:
    Admin(string u = "", string p = "");
};

#endif