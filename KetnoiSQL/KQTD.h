#pragma once
#include <iostream>
#include <string>
#include "ListBang.h"
#include "console.h"
using namespace std;
class KQTD
{
private:
    string matran;
    string mabang;
    string madoi1;
    string madoi2;
    int banthang1;
    int banthang2;
    int diem1;
    int diem2;
public:
    KQTD(string = "", string ="", string = "", string = "", int = 0, int = 0);
    ~KQTD();
    string gettd1(ListBang&);
    string gettd2(ListBang&);
    void show(ListBang&);
    friend ostream& operator<<(ostream&, const KQTD&);
    friend istream& operator>>(istream&, KQTD&);
    friend class KQ;
};


