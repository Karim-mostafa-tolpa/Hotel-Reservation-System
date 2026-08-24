#include <QApplication>
#include <QtWidgets>
#include "ApplicationManager.h"
#include "Guest.h"

ApplicationManager app; int g_userIdx = -1;
QString tow(const std::string& s) { return QString::fromStdString(s); }
std::string tos(const QString& s) { return s.toStdString(); }

class HotelApp : public QWidget {
public:
    QStackedWidget* S; QLabel* L;
    HotelApp() {
        setWindowTitle("MiniHotel System"); resize(800, 600);
        QVBoxLayout* M = new QVBoxLayout(this); S = new QStackedWidget();
        L = new QLabel("Status: Not logged in"); L->setObjectName("L"); L->setAlignment(Qt::AlignCenter);
        
        // Page 0: Home
        QWidget* p0 = new QWidget(); QVBoxLayout* l0 = new QVBoxLayout(p0);
        QLabel* T = new QLabel("MiniHotel System"); T->setObjectName("T"); T->setAlignment(Qt::AlignCenter);
        l0->addStretch(); l0->addWidget(T); l0->addSpacing(40);
        QHBoxLayout* hb = new QHBoxLayout();
        QPushButton* bA = new QPushButton("Admin Portal"); QPushButton* bG = new QPushButton("Guest Portal");
        hb->addWidget(bA); hb->addWidget(bG); l0->addLayout(hb); l0->addStretch();
        connect(bA, &QPushButton::clicked, [this]{ DoLog("admin"); });
        connect(bG, &QPushButton::clicked, [this]{ S->setCurrentIndex(2); });
        
        // Page 1: Admin
        QWidget* p1 = new QWidget(); QVBoxLayout* l1 = new QVBoxLayout(p1);
        QGroupBox* gA = new QGroupBox("ADMIN PANEL"); QGridLayout* ag = new QGridLayout(gA);
        auto add = [&](QString t, QGridLayout* g, int r, int c, auto f) {
            QPushButton* b = new QPushButton(t); g->addWidget(b, r, c); connect(b, &QPushButton::clicked, this, f);
        };
        add("Add Room",ag,0,0,[this]{DoAdd();}); add("Del Room",ag,0,1,[this]{DoDel();});
        add("Reservations",ag,1,0,[this]{DoRes();}); add("Bills",ag,1,1,[this]{DoBills();}); add("Tax",ag,2,0,[this]{DoTax();});
        QPushButton* outA = new QPushButton("Logout"); connect(outA, &QPushButton::clicked, [this]{DoOut();});
        l1->addWidget(gA); l1->addWidget(outA);

        // Page 2: Guest
        QWidget* p2 = new QWidget(); QVBoxLayout* l2 = new QVBoxLayout(p2);
        QGroupBox* gG = new QGroupBox("GUEST SERVICES"); QGridLayout* gg = new QGridLayout(gG);
        add("Login",gg,0,0,[this]{DoLog("guest");}); add("Register",gg,0,1,[this]{DoReg();});
        add("Search",gg,1,0,[this]{DoSearch();}); add("Book",gg,1,1,[this]{DoBook();});
        add("Check In",gg,2,0,[this]{DoIn();}); add("Check Out",gg,2,1,[this]{DoCheckOut();});
        add("Food",gg,3,0,[this]{DoFood();}); add("Bill",gg,3,1,[this]{DoBill();});
        QPushButton* outG = new QPushButton("Back / Logout"); connect(outG, &QPushButton::clicked, [this]{DoOut();});
        l2->addWidget(gG); l2->addWidget(outG);

        S->addWidget(p0); S->addWidget(p1); S->addWidget(p2);
        M->addWidget(L); M->addWidget(S);
    }
    void Upd() { L->setText(g_userIdx==-1 ? "Not Logged In" : "User: " + tow(app.users[g_userIdx].username)); }
    void Msg(QString m, bool e=0) { e ? QMessageBox::critical(this,"Err",m) : QMessageBox::information(this,"Info",m); }
    QString Inp(QString t) { bool ok; QString x=QInputDialog::getText(this,"Input",t,QLineEdit::Normal,"",&ok); return ok?x:""; }
    bool chk(QString t) { return g_userIdx!=-1 && app.users[g_userIdx].type==tos(t); }
    Room* r(int n) { for(auto& x:app.rooms) if(x.roomNumber==n) return &x; return nullptr; }
    
    void DoLog(std::string t) { QString u=Inp("User:"); if(u=="") return; QString p=Inp("Pass:");
        for(size_t i=0; i<app.users.size(); i++) if(app.users[i].username==tos(u) && app.users[i].password==tos(p) && app.users[i].type==t)
            { g_userIdx=i; Upd(); S->setCurrentIndex(t=="admin"?1:2); return Msg("Welcome!"); } Msg("Invalid.",1); }
    void DoOut() { g_userIdx=-1; Upd(); S->setCurrentIndex(0); }
    void DoReg() { QString u=Inp("User:"); if(u!="") { app.users.push_back(Guest(tos(u),tos(Inp("Pass:")))); Msg("Registered."); } }
    void DoAdd() { if(!chk("admin")) return; QString n=Inp("Room #:"); if(n!="") app.rooms.push_back(Room(n.toInt(),tos(Inp("Type:")),Inp("Price:").toDouble())); Msg("Added."); }
    void DoDel() { if(!chk("admin")) return; int n=Inp("Room #:").toInt(); for(size_t i=0;i<app.rooms.size();i++) if(app.rooms[i].roomNumber==n) { app.rooms.erase(app.rooms.begin()+i); return Msg("Deleted."); } Msg("N/A",1); }
    void DoRes() { QString o; for(auto& x:app.reservations) o+="ID:"+QString::number(x.reservationID)+"\n"; Msg(o==""?"None":o); }
    void DoBills() { QString o; for(auto& x:app.bills) o+="ID:"+QString::number(x.billID)+" $"+QString::number((int)x.totalAmount)+"\n"; Msg(o==""?"None":o); }
    void DoTax() { QString r=Inp("Tax:"); if(r!="") { app.taxRate=r.toDouble(); Msg("Updated."); } }
    void DoSearch() { if(!chk("guest")) return; QString o; for(auto& x:app.rooms) if(x.available) o+="Room "+QString::number(x.roomNumber)+"\n"; Msg(o==""?"None":o); }
    void DoBook() { if(!chk("guest")) return; Room* rm=r(Inp("Room #:").toInt()); if(!rm||!rm->available) return Msg("N/A",1);
        int i=app.reservations.size()+1001; app.reservations.push_back(Reservation(i,app.users[g_userIdx].username,rm->roomNumber,"",""));
        rm->available=false; rm->guestAssigned=app.users[g_userIdx].username; Msg("Booked ID:"+QString::number(i)); }
    void DoIn() { if(!chk("guest")) return; int id=Inp("Res ID:").toInt(); for(auto& x:app.reservations) if(x.reservationID==id&&x.status=="booked"){ x.status="checked_in"; return Msg("Done"); } Msg("Fail",1); }
    void DoCheckOut() { if(!chk("guest")) return; int id=Inp("Res ID:").toInt(); for(auto& x:app.reservations) if(x.reservationID==id&&x.status=="checked_in"){ x.status="checked_out"; if(Room* rm=r(x.roomNumber)){rm->available=true;} return Msg("Done"); } Msg("Fail",1); }
    void DoFood() { if(!chk("guest")) return; double p=Inp("Price:").toDouble(); for(auto& x:app.reservations) if(x.guestUsername==app.users[g_userIdx].username&&x.status=="checked_in"){ if(Room* rm=r(x.roomNumber)){rm->additionalCharges+=p; return Msg("Ordered");}} Msg("Fail",1); }
    void DoBill() { if(!chk("guest")) return; std::string u=app.users[g_userIdx].username; double t=0;
        for(auto& rv:app.reservations) if(rv.guestUsername==u&&(rv.status=="checked_in"||rv.status=="checked_out")) if(Room* rm=r(rv.roomNumber)) { t+=rm->pricePerNight+rm->additionalCharges; rm->resetCharges(); }
        Msg("Total Due: $"+QString::number((int)(t*(1+app.taxRate)))); }
};

const char* QSS = "QWidget{background:#0f1115;color:#e2e8f0;font:14px 'Segoe UI'} QGroupBox{background:#1a1d24;border:1px solid #2d3139;border-radius:12px;margin:20px;padding:20px} "
"QGroupBox::title{subcontrol-origin:margin;subcontrol-position:top center;padding:5px 15px;background:#0f1115;border:1px solid #2d3139;border-radius:8px;color:#38bdf8;font:bold 13px} "
"QPushButton{background:#2563eb;color:#fff;border:none;border-radius:6px;padding:15px;font:bold 14px;min-width:150px} QPushButton:hover{background:#3b82f6} "
"#T{font:bold 40px;color:#fff} #L{font:500 14px;color:#94a3b8;padding:10px} QLineEdit,QInputDialog{background:#1a1d24;color:#fff;border:1px solid #334155;border-radius:6px;padding:8px}";

int main(int c, char* v[]) { QApplication a(c,v); app.loadData(); if(app.users.empty()) app.users.push_back(User("admin","admin","admin"));
    HotelApp w; a.setStyleSheet(QSS); w.show(); int r=a.exec(); app.saveData(); return r; }