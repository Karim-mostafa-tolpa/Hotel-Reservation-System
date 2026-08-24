// Omar Abdelfattah 

//اهم فايل عملته حرفيا 

#include "FileManager.h"
#include "User.h"
#include "Admin.h"
#include "Guest.h"
#include "Room.h"
#include "Reservation.h"
#include "Bill.h"

//كنت بدور على طريقة زي اللي في البايثون ويذ اوبن و اف رايت و كده عشان اكتب في فايلات تيكست لاقيت دول 
#include <fstream>
#include <sstream>

#include <iostream>
using namespace std;

void FileManager::saveAll(const vector<User>& users, const vector<Room>& rooms,
                          const vector<Reservation>& reservations, const vector<Bill>& bills) {
    //زي ويث اوبن في البايثون                         
    ofstream u("users.txt");
    //عملت فايل و كتبت في ال يوزرز اليوزر نيم و الباس بتاعهم
    for (size_t i = 0; i < users.size(); i++)
        u << users[i].type << "," << users[i].username << "," << users[i].password << "\n";
    u.close();

    ofstream r("rooms.txt");
    //عملت فايل و كتبت في الاوض 
    for (size_t i = 0; i < rooms.size(); i++)
        r << rooms[i].roomNumber << "," << rooms[i].type << "," << rooms[i].pricePerNight
          << "," << rooms[i].available << "," << rooms[i].guestAssigned << "," << rooms[i].additionalCharges << "\n";
    r.close();

    ofstream res("reservations.txt");
    //عملت فايل و كتبت في الحجوزات و الاي دي والرقم بتاع كل اوضه محجوزه
    for (size_t i = 0; i < reservations.size(); i++)
        res << reservations[i].reservationID << "," << reservations[i].guestUsername << ","
            << reservations[i].roomNumber << "," << reservations[i].checkInDate << ","
            << reservations[i].checkOutDate << "," << reservations[i].status << "\n";
    res.close();

    ofstream b("bills.txt");
    //عملت فايل و كتبت في الفواتير 
    for (size_t i = 0; i < bills.size(); i++) {
        b << bills[i].billID << "," << bills[i].guestUsername << ","
          << bills[i].totalAmount << "," << bills[i].paid << "\n";
        ofstream c("charges_" + to_string(bills[i].billID) + ".txt");
        for (size_t j = 0; j < bills[i].charges.size(); j++)
            c << bills[i].charges[j].first << "," << bills[i].charges[j].second << "\n";
        c.close();
    }
    b.close();
}

void FileManager::loadAll(vector<User>& users, vector<Room>& rooms,
                          vector<Reservation>& reservations, vector<Bill>& bills) {
    users.clear();
    ifstream u("users.txt");
    if (u.is_open()) {
        string line;
        while (getline(u, line)) {
            stringstream ss(line);
            string type, user, pass;
            getline(ss, type, ',');
            getline(ss, user, ',');
            getline(ss, pass, ',');
            if (type == "admin")
                users.push_back(Admin(user, pass));
            else
                users.push_back(Guest(user, pass));
        }
        u.close();
    }

    rooms.clear();
    ifstream r("rooms.txt");
    if (r.is_open()) {
        string line;
        while (getline(r, line)) {
            stringstream ss(line);
            string num, typ, pr, av, guest, add;
            getline(ss, num, ','); getline(ss, typ, ','); getline(ss, pr, ',');
            getline(ss, av, ','); getline(ss, guest, ','); getline(ss, add, ',');
            Room rm(stoi(num), typ, stod(pr));
            rm.available = (av == "1");
            rm.guestAssigned = guest;
            rm.additionalCharges = stod(add);
            rooms.push_back(rm);
        }
        r.close();
    }

    reservations.clear();
    ifstream res("reservations.txt");
    if (res.is_open()) {
        string line;
        while (getline(res, line)) {
            stringstream ss(line);
            string id, guest, room, cinD, coutD, stat;
            getline(ss, id, ','); getline(ss, guest, ','); getline(ss, room, ',');
            getline(ss, cinD, ','); getline(ss, coutD, ','); getline(ss, stat, ',');
            Reservation rv(stoi(id), guest, stoi(room), cinD, coutD);
            rv.status = stat;
            reservations.push_back(rv);
        }
        res.close();
    }

    bills.clear();
    ifstream b("bills.txt");
    if (b.is_open()) {
        string line;
        while (getline(b, line)) {
            stringstream ss(line);
            string id, guest, total, paidStr;
            getline(ss, id, ','); getline(ss, guest, ',');
            getline(ss, total, ','); getline(ss, paidStr, ',');
            Bill bl(stoi(id), guest);
            bl.totalAmount = stod(total);
            bl.paid = (paidStr == "1");
            ifstream c("charges_" + id + ".txt");
            if (c.is_open()) {
                string cl;
                while (getline(c, cl)) {
                    stringstream css(cl);
                    string item, costStr;
                    getline(css, item, ',');
                    getline(css, costStr, ',');
                    bl.charges.push_back(make_pair(item, stod(costStr)));
                }
                c.close();
            }
            bills.push_back(bl);
        }
        b.close();
    }
}

// بجد كان صعب اوييي تبا لليرورات و الفور لوبببب