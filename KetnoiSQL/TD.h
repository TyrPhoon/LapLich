#pragma once
#include <iostream>
#include <string>
#include "ListBang.h"
#include "console.h"
using namespace std;
class TD
{
private:
    string matran;
    string mabang;
    string madoi1;
    string madoi2;
    int suat;
    int ngay;
    bool trangthai;
public:
    TD(string = "", string = "", string = "", string = "", int = 0, int = 0, bool = false);
    //void showMT();
    string gettd1(ListBang&);
    string gettd2(ListBang&);
    void show(ListBang &);
    friend ostream& operator<<(ostream&, const TD&);
    friend istream& operator>>(istream&, TD&);
    ~TD();
    friend class Lichthidau;
};

