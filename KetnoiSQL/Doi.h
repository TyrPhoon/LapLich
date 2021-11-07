#pragma once

#include<iostream>
#include<string>
#include "console.h"
using namespace std;
class Doi
{
private:
    string madoi;
    string tendoi;
    float nhom;
    string mabang;
public:
    Doi(string = "", string = "", float = 0, string = "");
    void show();
    string getMD();
    friend ostream& operator<<(ostream&, const Doi&);
    friend istream& operator>>(istream&, Doi&);
    ~Doi();
    friend class Bang;
};