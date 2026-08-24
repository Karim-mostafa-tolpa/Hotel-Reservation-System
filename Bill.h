


#ifndef BILL_H
#define BILL_H

#include <string>

#include <vector>
#include <utility>
using namespace std;

class Bill {
public:
    int billID;
    string guestUsername;
    double totalAmount;
    bool paid;
    vector<pair<string, double>> charges;

    Bill(int id = 0, string guest = "");
    void addCharge(string item, double cost);
};

#endif