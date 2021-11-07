#pragma once
#include <iostream>
#include <vector>
#include "Bang.h"
using namespace std;
class ListBang
{
private:
	Bang* dsbang;
	int n;
public:
	ListBang();
	int lenght();
	void add(Bang&);
	int search(Bang&);
	int searchmb(string);
	bool remove(Bang&);
	bool removeat(int);
	bool update(string);
	Bang& operator[](int);
	friend ostream& operator<<(ostream&, const ListBang&);
	void show();
	friend class TD;
};

