#pragma once

#include<iostream>
#include"Doi.h"
using namespace std;
class Bang
{
private:
    string mabang;
    string tenbang;
    Doi* data;
    int n;
public:
    Bang(string = "", string = "");
    string getmb();
    string gettb();
    void settb(string);
    int lenght();
    bool add(const Doi&);
    // them dt doi vao vi tri t
    void insert(const Doi&, int);
    // tim kiem dt doi co trong bang hay ko
    int search(const Doi&);
    // tim kiem dt doi theo ma doi
    int searchmd(string);
    // xoa pt trung voi pt truyen vao
    bool remove(const Doi&);
    //xoa pt co vi tri n
    bool removeat(int);
    //lay dt doi ra de edit theo dt doi
    Doi& getdoi(int);
    // Lay ra ma doi
    string getmd(int);
    // edit dt doi 
    string gettd(string);
    bool setdoi(Doi&);
    ~Bang();
    void show();
    friend ostream& operator<<(ostream&, const Bang&);
    friend istream& operator>>(istream&, Bang&);
    Doi& operator[](int);
    bool update(string &);
    friend class ListBang;
};
