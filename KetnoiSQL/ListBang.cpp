#include "ListBang.h"
ListBang::ListBang() {
	this->dsbang = nullptr;
	this->n = 0;
}
int ListBang::lenght() {
	return this->n;
}
void ListBang::add(Bang& b) {
	if (this->n == 0) {
		this->dsbang = new Bang[n + 1];
		this->dsbang[0] = b;
	}
	else
	{
		Bang* t = new Bang[this->n];
		for (int i = 0; i < this->n; i++) {
			*(t + i) = *(this->dsbang + i);
		}
		delete[] this->dsbang;
		this->dsbang = new Bang[this->n + 1];
		for (int i = 0; i < this->n; i++) {
			*(this->dsbang + i) = *(t + i);
		}
		this->dsbang[n] = b;
	}
	(this->n)++;
}
Bang& ListBang::operator[](int index) {
	static Bang error("-1", "-1");
	return (index >= 0 && index < this->n) ? *(this->dsbang + index) : error;
}
int ListBang::search(Bang& b) {
	static int error = -1;
	Bang v;
	int i;
	for ( i = 0; i < this->n; i++) {
		v = *(this->dsbang + i);
		if (v.mabang == b.mabang && v.tenbang == b.tenbang) break;
	}
	if (i < this->n) return i + 1;
	else return error;
}
int ListBang::searchmb(string s) {
	static int error = -1;
	Bang v;
	int i;
	for ( i = 0; i < this->n; i++) {
		v = *(this->dsbang + i);
		if (v.mabang == s) break;
	}
	if (i < this->n) return i + 1;
	else return error;
}
bool ListBang::removeat(int x) {
	if (x > n || x <= 0) return false;
	else {
		Bang* T = new Bang[x - 1];
		for (int i = 0; i < x - 1; i++) {
			*(T + i) = *(this->dsbang + i);
		}
		Bang* X = new Bang[this->n - x];
		for (int i = x; i < this->n; i++) {
			*(X + i - x) = *(this->dsbang + i);
		}
		delete[] this->dsbang;
		this->dsbang = new Bang[this->n - 1];
		for (int i = 0; i < x - 1; i++) {
			*(this->dsbang + i) = *(T + i);
		}
		for (int i = x - 1; i < this->n - 1; i++) {
			*(this->dsbang + i) = *(X + i - x + 1);
		}
		(this->n)--;
		return true;
	}
}
bool ListBang::remove(Bang &b){
	int i;
	i = search(b);
	if (i == -1) return false;
	else {
		removeat(i);
		return true;
	}
}

bool ListBang::update(string t) {
	int i;
	string a;
	Bang v;
	for (i = 0; i < this->n; i++) {
		v = *(this->dsbang + i);
		if (v.mabang == t) break;
	}
	if (i == n) return false;
	else
	{
		cout << " Nhap ten bang cho bang co ma bang : " << v.mabang << endl << "Tenbang :";
		fflush(stdin);
		getline(std::cin, a);
		dsbang[i].settb(a);
		return true;
	}
}

ostream& operator<<(ostream& c, const ListBang& p) {
	c << "Danh sach cac bang: " << endl;
	for (int i = 0; i < p.n; i++) {
		c << "  Bang : " <<(p.dsbang+i)->gettb() << "   Ma Bang : " << (p.dsbang + i)->getmb() << endl;
	}
	return c;
}


void ListBang::show() {
	int i;
	for (i = 0; i < this->n; i++) {
		this->dsbang[i].show();
		cout << endl;
	}
}
