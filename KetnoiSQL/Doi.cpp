#include"Doi.h"
Doi::Doi(string madoi, string s, float nhom, string mb) : madoi(madoi), tendoi(s), nhom(nhom), mabang(mb) {

}
Doi::~Doi() {
}
ostream& operator<<(ostream& c, const Doi& s) {
    c << " Madoi: " << s.madoi;
    c << " Tendoi: " << s.tendoi;
    c << " Nhom : " << s.nhom;
    c << " Ma Bang : " << s.mabang;
    c << endl;
    return c;
}
istream& operator>>(istream& i, Doi& n) {
    cout << "Nhap Madoi: ";
    i >> n.madoi;
    cout << "Nhap ten doi: ";
    i >> n.tendoi;
    cout << "Nhap nhom: ";
    i >> n.nhom;
    cout << "Nhap ma bang :";
    i >> n.mabang;
    return i;
}
void Doi::show() {
    int x, y;
    x = whereX();
    y = whereY();
    gotoXY(x + 3, y);
    cout << this->madoi;
    gotoXY(x + 10, y);
    cout << this->tendoi;
    gotoXY(x + 20, y);
    cout << this->mabang;
    gotoXY(x + 27, y);
    cout << this->nhom;
    cout << endl;
}
string Doi::getMD() {
    return this->madoi;
}