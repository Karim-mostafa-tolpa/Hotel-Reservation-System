

#include "User.h"

//اهوه الهيدر

//جبت اليوزر الل متعرف في الهيدر هنا 
User::User(string u, string p, string t) : username(u), password(p), type(t) {}

//هنا لو اليوزر عمل لوج ان ترجع ترو و تطلب بقى الجامدان ده 
bool User::login(string u, string p) {
    return (username == u && password == p);
}