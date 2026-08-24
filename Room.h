


#ifndef ROOM_H
#define ROOM_H

#include <string>
using namespace std;

//عملت كلاس للأوض 

class Room {
public:
    int roomNumber;
    string type;
    //ديه اللي بنحط فيها السعر لل ليله الواحده و حاولنا نستخدم على قدما نقدر اسامي منطقية شوية يعني 
    double pricePerNight;
    bool available;
    string guestAssigned;
    double additionalCharges;
//هنا عملت كونستراكتر في السيتات و الجيتات و مع عمر كل الجديد عملت ريستات كمان 
    Room(int num = 0, string t = "", double price = 0.0);
    void setAvailability(bool a);
    //سميتها اسايت مش سيت عشان قدام احتاجنا الاسم ده فارجعت عديلته بجددد تبا للايرور
    void assignGuest(string g);
    void addServiceCharge(double amt);
    void resetCharges();
};

//عايز بونصصصصصصصصصصصصصصصصصصصصصصصصصصصصصصصصصصصصصصصصصصصصصصصصصص
#endif