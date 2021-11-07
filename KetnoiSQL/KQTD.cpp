#include "KQTD.h"

KQTD::KQTD(string mt,string mb, string md1, string md2, int bthg1, int bthg2) : matran(mt),mabang(mb), madoi1(md1), madoi2(md2), banthang1(bthg1), banthang2(bthg2)
{
    if (bthg1 > bthg2) {
        this->diem1 = 3; this->diem2 = 0;
    }
    else if (bthg1 == bthg2) {
        this->diem1 = 1; this->diem2 = 1;
    }
    else {
        this->diem1 = 0; this->diem2 = 3;
    }
}

KQTD::~KQTD()
{
}


string KQTD::gettd1(ListBang& l) {
    int i;
    for (i = 0; i < l.lenght(); i++) {
        if (this->mabang == l[i].getmb()) break;
    }
    if (i < l.lenght()) {
        return l[i].gettd(madoi1);
    }
    else return "";
}
string KQTD::gettd2(ListBang& l) {
    int i;
    for (i = 0; i < l.lenght(); i++) {
        if (this->mabang == l[i].getmb()) break;
    }
    if (i < l.lenght()) {
        return l[i].gettd(madoi2);
    }
    else return "";
}
void KQTD::show(ListBang& l) {
    int X, Y;
    X = whereX();
    Y = whereY();
    gotoXY(X + 3, Y);
    cout << this->matran;
    gotoXY(X + 11, Y);
    cout << this->gettd1(l);
    gotoXY(X + 16, Y);
    cout << this->banthang1 << "  -  ";
    gotoXY(X + 22, Y);
    cout << this->banthang2;
    gotoXY(X + 25, Y);
    cout << this->gettd2(l);
    cout << endl;
}

ostream& operator<<(ostream& c, const KQTD& k) {
    c << " Tran dau voi ma tran :";
    c << k.matran << "    co ket qua la: ";
    c << k.madoi1 << "   " << k.banthang1 << " - " << k.banthang2 << "   " << k.madoi2 << endl;
    return c;
}
istream& operator>>(istream& i, KQTD& k) {
    cout << " Nhap ket qua: ";
    cout << " Ma tran : ";
    fflush(stdin);
    getline(i, k.matran);
    cout << " Nhap ma doi 1 : ";
    fflush(stdin);
    getline(i, k.madoi1);
    cout << " Nhap ma doi 2 : ";
    fflush(stdin);
    getline(i, k.madoi2);
    cout << " Nhap ban thang1 : ";
    i >> k.banthang1;
    cout << " Nhap ban thang2 : ";
    i >> k.banthang2;
    if (k.banthang1 > k.banthang2) {
        k.diem1 = 3; k.diem2 = 0;
    }
    else if (k.banthang1 == k.banthang2) {
        k.diem1 = 1; k.diem2 = 1;
    }
    else {
        k.diem1 = 0; k.diem2 = 3;
    }
    return i;
}