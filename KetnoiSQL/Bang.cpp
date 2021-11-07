#include"Bang.h"
#define max 20

Bang::Bang(string mabang, string tenbang) : mabang(mabang), tenbang(tenbang){
    this->n = 0;
    this->data = nullptr;
}
string Bang::getmb() {
    return this->mabang;
}

string Bang::gettb() {
    return this->tenbang;
}
void Bang::settb(string s) {
    this->tenbang = s;
}
int Bang::lenght() {
    return this->n;
}
bool Bang::add(const Doi& v) {
    if (n == 0) {
        this->data = new Doi[n + 1];
        this->data[0] = v;
    }
    else {
        Doi* T = new Doi[this->n];
        // sv temp[this->n];
        // for(int i=0;i<this->n;i++){
        //     temp[i]=this->data[i];
        // }
        for (int i = 0; i < this->n; i++) {
            *(T + i) = *(this->data + i);
        }
        delete[] this->data;
        this->data = new Doi[this->n + 1];
        for (int i = 0; i < this->n; i++) {
            *(this->data + i) = *(T + i);
        }
        this->data[n] = v;
    }
    this->n++;
    return true;
}
Bang::~Bang() {
    delete[] this->data;
}
ostream& operator<<(ostream& c, const Bang& p) {
    if (p.n == 0) {
        c << " Khong co doi nao trong bang " << endl;
    }
    else {
        c << "Danh sach doi trong bang: " << endl;
        for (int i = 0; i < p.n; i++) {
            c << *(p.data + i);
        }
    }
    return c;
}
istream& operator>>(istream& i, Bang& n) {
    cout << "Nhap Madoi: ";
    i >> n.mabang;
    cout << "Nhap ten doi: ";
    i >> n.tenbang;
    return i;
}

void Bang::show() {
    if (this->n == 0) {
        cout << " Khong co doi nao trong bang " << this->tenbang << endl;
    }
    else {
        cout << " Bang  " << this->tenbang << endl;
        int X, Y;
        X = whereX();
        Y = whereY();
        gotoXY(X + 1, Y);
        cout << "Ma doi";
        gotoXY(X + 8, Y);
        cout << "Ten doi";
        gotoXY(X + 17, Y);
        cout << "Ma bang";
        gotoXY(X + 26, Y);
        cout << "Nhom";

        cout << endl;
        for (int i = 0; i < (this->n); i++) {
            this->data[i].show();
        }
    }
    
}
void Bang::insert(const Doi& s, int t) {
    if (t > n) {
        add(s);
    }
    else {
        if (t < 0) {
            Doi* T = new Doi[this->n];
            for (int i = 0; i < (this->n); i++) {
                *(T + i) = *(this->data + i);
            }
            delete[] this->data;
            this->data = new Doi[this->n + 1];
            this->data[0] = s;
            for (int i = 1; i <= this->n; i++) {
                *(this->data + i) = *(T + i - 1);
            }
        }
        else {
            Doi* T = new Doi[this->n - t + 1];
            for (int i = (t - 1); i < (this->n); i++) {
                *(T + i - t + 1) = *(this->data + i);
            }
            Doi* X = new Doi[t - 1];
            for (int i = 0; i < t - 1; i++) {
                *(X + i) = *(this->data + i);
            }
            delete[] this->data;
            this->data = new Doi[(this->n) + 1];
            for (int i = 0; i < t - 1; i++) {
                *(this->data + i) = *(X + i);
            }
            *(this->data + t - 1) = s;
            for (int i = t; i <= (this->n); i++) {
                *(this->data + i) = *(T + i - t);
            }
        }
        (this->n)++;
    }
}
int Bang::search(const Doi& s) {
    static int error = -1;
    Doi v;
    int i;
    for (i = 0; i < this->n; i++) {
        v = *(this->data + i);
        if ((s.madoi == v.madoi) && (s.tendoi == v.tendoi) && (s.nhom == v.nhom)) break;
    }
    if (i < n) return i + 1;
    else return error;
}
int Bang::searchmd(string t) {
    static int error = -1;
    int i;
    Doi v;
    for (i = 0; i < this->n; i++) {
        v = *(this->data + i);
        if (t == v.madoi) break;
    }
    if (i < n) return i + 1;
    else return error;
}
bool Bang::removeat(int x) {
    if (x > n || x <= 0) return false;
    else {
        Doi* T = new Doi[x - 1];
        for (int i = 0; i < x - 1; i++) {
            *(T + i) = *(this->data + i);
        }
        Doi* X = new Doi[this->n - x];
        for (int i = x; i < this->n; i++) {
            *(X + i - x) = *(this->data + i);
        }
        delete[] this->data;
        this->data = new Doi[this->n - 1];
        for (int i = 0; i < x - 1; i++) {
            *(this->data + i) = *(T + i);
        }
        for (int i = x - 1; i < this->n - 1; i++) {
            *(this->data + i) = *(X + i - x + 1);
        }
        (this->n)--;
        return true;
    }
}
bool Bang::remove(const Doi& s) {
    int i;
    i = search(s);
    if (i == -1) return false;
    else {
        removeat(i);
        return true;
    }
}
Doi& Bang::getdoi(int x) {
    return *(this->data + x - 1);
}
string Bang::getmd(int x) {
    //Doi v= this->data[x];
    return this->data[x].madoi;
}
bool Bang::setdoi(Doi& s) {
    Doi v;
    int i;
    for (i = 0; i < this->n; i++) {
        v = *(this->data + i);
        if (s.madoi == v.madoi) break;
    }
    if (i == n) return false;
    else {
        *(this->data + i) = s;
        return true;
    }
}
Doi& Bang::operator[](int t) {
    static Doi error(0, "", 0);
    return (t >= 0 && t < this->n) ? *(this->data + t) : error;
}
bool Bang::update(string &t) {
    int i; float d;
    string a;
    Doi v;
    for (i = 0; i < this->n; i++) {
        v = *(this->data + i);
        if (v.madoi == t) break;
    }
    if (i == n) return false;
    else
    {
        cout << " Nhap ten doi va nhom cho doi co ma doi : " << v.madoi << endl << "Tendoi :";
        fflush(stdin);
        getline(std::cin, a);
        cout << " Nhom : ";
        cin >> d;
        v.nhom = d;
        v.tendoi = a;
        v.madoi = t;
        *(this->data + i) = v;
        return true;
    }
}

string Bang::gettd(string s) {
    int i;
    for (i = 0 ; i < this->n; i++) {
        if (s == this->data[i].madoi) break;
    }
    if (i < n) return this->data[i].tendoi;
    else return "";
}