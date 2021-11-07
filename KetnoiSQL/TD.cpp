#include "TD.h"
TD::TD(string matran,string mabang, string madoi1, string madoi2, int suat, int ngay, bool tt)
    : matran(matran),mabang(mabang), madoi1(madoi1), madoi2(madoi2), suat(suat), ngay(ngay), trangthai(tt)
{

}
TD::~TD() {

}
string TD::gettd1( ListBang& l) {
    int i;
    for (i = 0; i < l.lenght(); i++) {
        if (this->mabang == l[i].getmb()) break;
    }
    if (i < l.lenght()) {
        return l[i].gettd(madoi1);
    }
    else return "";
}
string TD::gettd2(ListBang& l) {
    int i;
    for (i = 0; i < l.lenght(); i++) {
        if (this->mabang == l[i].getmb()) break;
    }
    if (i < l.lenght()) {
        return l[i].gettd(madoi2);
    }
    else return "";
}
void TD::show(ListBang &l) {
    int X, Y;
    X = whereX();
    Y = whereY();
    gotoXY(X + 2, Y);
    cout << this->matran;
    gotoXY(X + 14, Y);
    cout << this->gettd1(l);
    gotoXY(X + 26, Y);
    cout << this->gettd2(l);
    gotoXY(X + 41, Y);
    cout << this->suat;
    gotoXY(X + 57, Y);
    cout << this->ngay;
    gotoXY(X + 72, Y);
    cout << this->trangthai;
    cout << endl;
}
ostream& operator<<(ostream& c, const TD& s) {
    c << " Matran: " << s.matran;
    c << "  Madoi1: " << s.madoi1;
    c << "  Madoi2 : " << s.madoi2;
    c << "  Suat thi dau: " << s.suat;
    c << "  Ngay thi dau: " << s.ngay;
    c << "  Trang thai: " << s.trangthai;
    c << endl;
    return c;
}
istream& operator>>(istream& i, TD& s) {
    cout << "Nhap ma tran: ";
    fflush(stdin);
    getline(i, s.matran);
    cout << " Nhap ma doi 1: ";
    fflush(stdin);
    getline(i, s.madoi1);
    cout << " Nhap ma doi 2: ";
    fflush(stdin);
    getline(i, s.madoi2);
    cout << "Nhap suat thi dau :";
    i >> s.suat;
    cout << " Nhap ngay thi dau : ";
    i >> s.ngay;
    cout << " Nhap trang thai: ";
    i >> s.trangthai;
    return i;
}