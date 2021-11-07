#pragma once
#include <iostream>
#include "TD.h"
using namespace std;
class Lichthidau
{
private:
    TD* data;
    int n;
public:
    Lichthidau();
    void add(const TD&);
    int lenght();
    void show(ListBang &);
    //void createdv();
    // them dt TD vao vi tri t
    void insert(const TD&, int);
    // tim kiem dt TD co trong Lichthidau hay ko
    int search(const TD&);
    // tim kiem dt TD theo ma TD
    int searchmd(const string);
    // xoa pt trung voi pt truyen vao
    bool remove(const TD&);
    //xoa pt co vi tri n
    bool removeat(int);
    //lay dt TD ra de edit theo dt TD
    //TD& getTD(int);
    // Lay ra ma TD
    string getmt(int);
    // edit dt TD 
    string getmd1(int);
    string getmd2(int);
    string getmb(int);
    int getsuat(int);
    int getngay(int);
    //bool setTD(TD&);
    friend ostream& operator<<(ostream&, const Lichthidau&);
    TD& operator[](int);
    bool update(const string&);
};
