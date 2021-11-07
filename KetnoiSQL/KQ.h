#pragma once
#include<iostream>
#include"KQTD.h"
using namespace std;
class KQ
{
private:
    KQTD* data;
    int n;
public:
    KQ();
    int lenght();
    // them dt KQTD
    void add(const KQTD&);
    // them dt KQTD vao vi tri t
    void insert(const KQTD&, int);
    // tim kiem dtKQTD co trong dsKQTD hay ko
    int search(const KQTD&);
    // xoa pt trung voi pt truyen vao
    bool remove(const KQTD&);
    //xoa pt co vi tri n
    bool removeat(int);
    //lay dtKQTD ra de edit theo dtKQTD
    KQTD& getKQTD(int);
    // edit dtKQTD
    bool setKQTD(KQTD&);
    ~KQ();
    friend ostream& operator<<(ostream&, const KQ&);
    KQTD& operator[](int);
    // update dua tren matran va madoi
    bool update(const string);
    void show(ListBang&);
    string getmt(int);
    int getb1(int);
    int getb2(int);
};

