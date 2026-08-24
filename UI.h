

#ifndef UI_H
#define UI_H

#include <string>
using namespace std;

//عرفت شوية حاجات للمنيو هاحتاجها 
class UI {
public:
    int mainMenu();
    void loginMenu(string& u, string& p, string& t);
    int adminMenu();
    int guestMenu();
    void printMessage(const string& msg);
};

#endif