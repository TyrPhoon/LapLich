#include"KQ.h"
KQ::KQ() {
    this->n = 0;
    this->data = nullptr;
}
int KQ::lenght() {
    return this->n;
}
void KQ::add(const KQTD& v) {
    if (n == 0) {
        this->data = new KQTD[n + 1];
        this->data[0] = v;
    }
    else {
        KQTD* T = new KQTD[this->n];
        // KQTD temp[this->n];
        // for(int i=0;i<this->n;i++){
        //     temp[i]=this->data[i];
        // }
        for (int i = 0; i < this->n; i++) {
            *(T + i) = *(this->data + i);
        }
        delete[] this->data;
        this->data = new KQTD[this->n + 1];
        for (int i = 0; i < this->n; i++) {
            *(this->data + i) = *(T + i);
        }
        this->data[n] = v;
    }
    this->n++;
}
KQ::~KQ() {
    delete[] this->data;
}
ostream& operator<<(ostream& c, const KQ& p) {
    c << "DSKQTD" << endl;
    for (int i = 0; i < p.n; i++) {
        c << *(p.data + i);
    }
    return c;
}
void KQ::insert(const KQTD& s, int t) {
    if (t > n) {
        KQ::add(s);
    }
    else if (t < 0) {
        KQTD* T = new KQTD[this->n];
        for (int i=0; i < this->n; i++) {
            *(T + i) = *(this->data + i);
        }
        delete[] this->data;
        this->data = new KQTD[this->n + 1];
        this->data[0] = s;
        for (int i = 1; i <= this->n; i++) {
            *(this->data + i) = *(T + i - 1);
        }
    }
    else {
        KQTD* T = new KQTD[this->n - t + 1];
        for (int i = (t - 1); i < (this->n); i++) {
            *(T + i - t + 1) = *(this->data + i);
        }
        KQTD* X = new KQTD[t - 1];
        for (int i = 0; i < t - 1; i++) {
            *(X + i) = *(this->data + i);
        }
        delete[] this->data;
        this->data = new KQTD[this->n + 1];
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
int KQ::search(const KQTD& s) {
    static int error = -1;
    KQTD v;
    int i;
    for (i = 0; i < this->n; i++) {
        v = *(this->data + i);
        if ((s.matran == v.matran) && (s.madoi1 == v.madoi1) && (s.banthang1 == v.banthang1) && (s.banthang2 == v.banthang2) && (s.diem1 == v.diem1) && (s.diem2 == v.diem2)) break;
    }
    if (i < n) return i + 1;
    else return error;
}
bool KQ::removeat(int x) {
    if (x > n || x <= 0) return false;
    else {
        KQTD* T = new KQTD[x - 1];
        for (int i = 0; i < x - 1; i++) {
            *(T + i) = *(this->data + i);
        }
        KQTD* X = new KQTD[this->n - x];
        for (int i = x; i < this->n; i++) {
            *(X + i - x) = *(this->data + i);
        }
        delete[] this->data;
        this->data = new KQTD[this->n - 1];
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
bool KQ::remove(const KQTD& s) {
    int i;
    i = search(s);
    if (i == -1) return false;
    else {
        removeat(i);
        return true;
    }
}
KQTD& KQ::getKQTD(int x) {
    return *(this->data + x - 1);
}
bool KQ::setKQTD(KQTD& s) {
    KQTD v;
    int i;
    for (i = 0; i < this->n; i++) {
        v = *(this->data + i);
        if (s.matran == v.matran && s.madoi1 == v.madoi1) break;
    }
    if (i == n) return false;
    else {
        *(this->data + i) = s;
        return true;
    }
}
KQTD& KQ::operator[](int t) {
    static KQTD error(0, 0, 0);
    return (t >= 0 && t < this->n) ? *(this->data + t) : error;
}
bool KQ::update(string mt) {
    int  i; 
    KQTD v;
    for (i = 0; i < this->n; i++) {
        v = *(this->data + i);
        if (v.matran == mt) break;
    }
    if (i == n) return false;
    else
    {
        cout << " Nhap thong tin update: ";
        cin >> v;
        *(this->data + i) = v;
        return true;
    }
}



void KQ::show(ListBang& l) {
    cout << " Ket qua cua cac tran dau: " << endl;
    int X, Y;
    X = whereX();
    Y = whereY();
    gotoXY(X + 1, Y);
    cout << "Ma tran";
    gotoXY(X + 16, Y);
    cout << "Ket Qua";
    cout << endl;
    for (int i = 0; i < (this->n); i++) {
        this->data[i].show(l);
    }
}


string KQ::getmt(int index) {
    return this->data[index].matran;
}
int KQ::getb1(int i) {
    return this->data[i].banthang1;
}
int KQ::getb2(int i) {
    return this->data[i].banthang2;
}