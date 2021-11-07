#include "Lichthidau.h"
Lichthidau::Lichthidau() {
    this->n = 0;
    this->data = nullptr;
}
int Lichthidau::lenght() {
    return this->n;
}
void Lichthidau::add(const TD& t) {
    if (this->n == 0) {
        this->data = new TD[n + 1];
        *(this->data + 0) = t;
    }
    else {
        TD* s = new TD[this->n];
        for (int i = 0; i < (this->n); i++) {
            *(s + i) = *(this->data + i);
        }
        delete[] this->data;
        this->data = new TD[this->n + 1];
        for (int i = 0; i < (this->n); i++) {
            *(this->data + i) = *(s + i);
        }
        *(this->data + n) = t;
    }
    this->n++;
}
void Lichthidau::insert(const TD& t, int x) {
    if (x > this->n) {
        add(t);
    }
    else {
        if (x < 0) {
            TD* s = new TD[this->n];
            for (int i = 0; i < (this->n); i++) {
                *(s + i) = *(this->data + i);
            }
            delete[] this->data;
            this->data = new TD[this->n + 1];
            *(this->data + 0) = t;
            for (int i = 1; i <= this->n; i++) {
                *(this->data + i) = *(s + i - 1);
            }
        }
        else {
            TD* s = new TD[this->n];
            for (int i = 0; i < (this->n); i++) {
                *(s + i) = *(this->data + i);
            }
            delete[] this->data;
            this->data = new TD[this->n + 1];
            for (int i = 0; i < x - 1; i++) {
                *(this->data + i) = *(s + i);
            }
            *(this->data + (x - 1)) = t;
            for (int i = x; i <= (this->n); i++) {
                *(this->data + i) = *(s + i - 1);
            }
        }
        (this->n)++;
    }
}
int Lichthidau::search(const TD& t) {
    static int error = -1;
    int i;
    TD x;
    for (i = 0; i < (this->n); i++) {
        x = *(this->data + i);
        if (t.matran == x.matran && t.madoi1 == x.madoi1 && t.madoi2 == x.madoi2 && t.suat == x.suat && t.ngay == x.ngay && t.trangthai == x.trangthai) break;
    }
    if (i < (this->n)) return i + 1;
    else return error;
}
int Lichthidau::searchmd(const string t) {
    static int error = -1;
    int i;
    TD x;
    for (i = 0; i < (this->n); i++) {
        x = *(this->data + i);
        if (t == x.matran) break;
    }
    if (i < (this->n)) return i + 1;
    else return error;
}
bool Lichthidau::removeat(int t) {
    if (t <= 0 || t > n) return false;
    else {
        TD* s = new TD[this->n];
        for (int i = 0; i < (this->n); i++) {
            *(s + i) = *(this->data + i);
        }
        delete[] this->data;
        this->data = new TD[this->n - 1];
        for (int i = 0; i < t - 1; i++) {
            *(this->data + i) = *(s + i);
        }
        for (int i = t; i < this->n; i++) {
            *(this->data + (i - 1)) = *(s + i);
        }
        this->n--;
        return true;
    }
}
bool Lichthidau::remove(const TD& t) {
    int k;
    bool kq;
    k = search(t);
    kq = removeat(k);
    return kq;
}
ostream& operator<<(ostream& c, const Lichthidau& t) {
    c << " Lich thi dau: " << endl;
    for (int i = 0; i < (t.n); i++) {
        c << *(t.data + i);
    }
    return c;
}
TD& Lichthidau::operator[](int t) {
    static TD error("", "", "", "", 0, 0, 0);
    return (t >= 0 && t < (this->n)) ? *(this->data + t) : error;
}
bool Lichthidau::update(const string& t) {
    int a, b, c, d, i;
    bool e;
    TD x;
    for (i = 0; i < (this->n); i++) {
        x = *(this->data + i);
        if (t == x.matran) break;
    }
    if (i == n) return false;
    else
    {
        cout << " Nhap ma doi 1: ";
        cin >> a;
        cout << " Nhap ma doi 2: ";
        cin >> b;
        cout << "Nhap suat thi dau :";
        cin >> c;
        cout << " Nhap ngay thi dau : ";
        cin >> d;
        cout << " Nhap trang thai: ";
        cin >> e;
        x.madoi1 = a;
        x.madoi2 = b;
        x.suat = c;
        x.ngay = d;
        x.trangthai = e;
        *(this->data + i) = x;
        return true;
    }

}

string Lichthidau::getmt(int index) {
    return this->data[index].matran;
}
string Lichthidau::getmd1(int index) {
    return this->data[index].madoi1;
}
string Lichthidau::getmd2(int index) {
    return this->data[index].madoi2;
}
string Lichthidau::getmb(int index) {
    return this->data[index].mabang;
}
int Lichthidau::getsuat(int index) {
    return this->data[index].suat;
}
int Lichthidau::getngay(int index) {
    return this->data[index].ngay;
}
void Lichthidau::show(ListBang& l) {
    cout << " Lich thi dau: " << endl;
    int X, Y;
    X = whereX();
    Y = whereY();
    gotoXY(X + 1, Y);
    cout << "Ma tran";
    gotoXY(X + 12, Y);
    cout << "Ten doi1";
    gotoXY(X + 24, Y);
    cout << "Ten doi2";
    gotoXY(X + 36, Y);
    cout << "Suat thi dau";
    gotoXY(X + 52, Y);
    cout << "Ngay thi dau";
    gotoXY(X + 68, Y);
    cout << "Trang thai";
    cout << endl;
    for (int i = 0; i < (this->n); i++) {
        this->data[i].show(l);
    }
}