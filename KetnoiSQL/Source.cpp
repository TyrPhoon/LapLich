#include <iostream>
#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>
#include <conio.h>
#include "Ketnoi.h"
#include "Doi.h"
#include <string.h>
#include "Lichthidau.h"
#include "KQ.h"
//use the std namespace
using namespace std;



//Ham doc danh sach cac bang trong SQL
void docbang(Ketnoi database, ListBang& l) {
    char c;
    system("cls");
    database.SelectBang(l);
    c = _getch();
}


// Them bang
void thembang(ListBang& l) {
    Bang b1;
    int t;
    char c;
    do {
        system("cls");
        cout << "Nhap cac thong tin cua bang can them: " << endl;
        cin >> b1;
        cout << "Nhap vi tri muon them : ";
        cin >> t;
        l.add(b1);
        cout << "Ban co muon tiep tuc khong?(c/k)" << endl;
        c = _getch();
    } while (c == 'c' || c == 'C');
}
// Sua bang
void suabang(ListBang& l) {
    bool kt;
    string x;
    char c;
    do {
        system("cls");
        cout << "Nhap ma doi ma ban muon sua : ";
        fflush(stdin);
        cin >> x;
        kt = l.update(x);
        if (kt == true) cout << " Sua thanh cong! " << endl;
        else cout << " Ma doi nhap vao khong hop le! " << endl;
        cout << "Ban co muon tiep tuc khong?(c/k)" << endl;
        c = _getch();
    } while (c == 'c' || c == 'C');
}
// Xoa bang
void xoabang(ListBang& l) {
    char c;
    bool kt;
    int t, x;
    string mabang;
    Bang b;

    do {
        system("cls");
        cout << " Ban muon xoa bang theo cach nao? " << endl;
        cout << " 1. Xoa dua tren vi tri cua bang." << endl << " 2. Xoa doi bang cach nhap ma bang." << endl;
        cout << " 3 Xoa doi dua tren viec nhap bang." << endl << " Moi ban chon:";
        cin >> t;
        switch (t)
        {
        case 1: {
            cout << "Nhap vi tri doi muon xoa: ";
            cin >> x;
            kt = l.removeat(x);
            if (kt == true) cout << " Xoa doi thanh cong! " << endl;
            else cout << " Vi tri nhap vao khong hop le! " << endl;
            break;
        }
        case 2: {
            cout << "Nhap ma doi muon xoa: ";
            fflush(stdin);
            cin >> mabang;
            int y = l.searchmb(mabang);
            kt = l.removeat(y);
            if (kt == true) cout << " Xoa doi thanh cong! " << endl;
            else cout << " Ma doi nhap vao khong hop le! " << endl;
            break;
        }
        case 3: {
            cout << "Nhap doi muon xoa." << endl;
            cin >> b;
            kt = l.remove(b);
            if (kt == true) cout << " Xoa doi thanh cong! " << endl;
            else cout << " Doi nhap vao khong hop le! " << endl;
            break;
        }
        default:
        {cout << "Nhap khong hop le! Moi ban nhap so trong khoang (1;3)" << endl;
        break; }
        }
        cout << " Ban muon tiep tuc khong (c/k)? " << endl;
        c = _getch();
    } while (c == 'c' || c == 'C');
}
// Tim kiem bang
void tkbang(ListBang& l) {
    int t;
    Bang b;
    string x;
    char c;
    cout << " Ban muon tim kiem doi theo cach nao? " << endl;
    cout << " 1. Tim kiem bang cach nhap ma doi." << endl << " 2. Tim kiem bang cach nhap doi." << endl;
    cout << " Moi ban chon:";
    do {
        system("cls");
        cout << " Ban muon tim kiem bang theo cach nao? " << endl;
        cout << " 1. Tim kiem bang cach nhap ma bang." << endl << " 2. Tim kiem bang cach nhap bang." << endl;
        cout << " Moi ban chon:";
        cin >> t;
        switch (t)
        {
        case 1: {
            cout << "Nhap ma bang muon tim kiem: ";
            cin >> x;
            t = l.searchmb(x);
            if (t != -1) cout << " Vi tri cua bang can tim la : " << t << endl;
            else cout << " Khong co bang can tim trong danh sach! " << endl;
            break;
        }
        case 2: {
            cout << "Nhap bang muon tim kiem : " << endl;
            cin >> b;
            t = l.search(b);
            if (t != -1) cout << " Vi tri cua bang can tim la : " << t << endl;
            else cout << " Khong co bang can tim trong danh sach! " << endl;
            break;
        }
        default:
        {cout << "Nhap khong hop le! Moi ban nhap so trong khoang (1;2)" << endl;
        break; }
        }
        cout << " Ban muon tiep tuc khong (c/k)? " << endl;
        c = _getch();
    } while (c == 'c' || c == 'C');
}


void qlbang(Ketnoi database, ListBang& l) {
    int t;
    char c;
    int d = 8;
    string mb;
    HANDLE mau;
    mau = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(mau, 7);
    do {
        system("cls");
        cout << "============= Quan ly bang ================" << endl;
        cout << " 1. Doc du lieu tu SQL" << endl;
        SetConsoleTextAttribute(mau, d);
        cout << " 2. Them bang " << endl;
        cout << " 3. Sua bang " << endl;
        cout << " 4. Xoa bang " << endl;
        cout << " 5. Tim kiem bang " << endl;
        cout << " 6. Hien thi danh sach bang " << endl;
        SetConsoleTextAttribute(mau, 7);
        cout << " 0. Thoat!" << endl;
        cout << " Lua chon cua ban: ";
        cin >> t;
        if (t == 1) {
            d = 7;
            docbang(database, l);
        }
        else if (t == 2) {
            if (d == 8) {
                cout << " Ban phai thuc hien cac chuc nang 1 truoc!" << endl;
                c = _getch();
            }
            else {
                thembang(l);
            }
        }
        else if (t == 3) {
            if (d == 8) {
                cout << " Ban phai thuc hien cac chuc nang 1 truoc!" << endl;
                c = _getch();
            }
            else {
                suabang(l);
            }
             
        }
        else if (t == 4) {
            if (d == 8) {
                cout << " Ban phai thuc hien cac chuc nang 1 truoc!" << endl;
                c = _getch();
            }
            else {
                xoabang(l);
            }
             
        }
        else if (t == 5) {
            if (d == 8) {
                cout << " Ban phai thuc hien cac chuc nang 1 truoc!" << endl;
                c = _getch();
            }
            else {
                tkbang(l);
            }
             
        }
        else if (t == 6) {
            if (d == 8) {
                cout << " Ban phai thuc hien cac chuc nang 1 truoc!" << endl;
                c = _getch();
            }
            else {
                cout << l;
                c = _getch();
            }
            
        }
        else if (t == 0) {
            break;
        }
        else {
            cout << " Ban nhap khong hop le ! ";
        }
    } while (t != 0);
}



// Cap nhat doi
void capnhatdoi(Bang& s) {
    bool kt;
    char c;
    Doi v;
    do {
        system("cls");
        cout << "Nhap doi ma ban muon cap nhat : " << endl;;
        cin >> v;
        kt = s.add(v);
        if (kt == true) cout << " Cap nhat thanh cong! " << endl;
        else cout << " Loi! " << endl;
        cout << "Ban co muon tiep tuc khong?(c/k)" << endl;
        c = _getch();
    } while (c == 'c' || c == 'C');
}
// Them doi
void themdoi(Bang& s) {
    Doi s1;
    int t;
    char c;
    do {
        system("cls");
        cout << "Nhap cac thong tin cua doi can them: " << endl;
        cin >> s1;
        cout << "Nhap vi tri muon them : ";
        cin >> t;
        s.insert(s1, t);
        cout << "Ban co muon tiep tuc khong?(c/k)" << endl;
        c = _getch();
    } while (c == 'c' || c == 'C');
}
// Sua doi
void suadoi(Bang& s) {
    bool kt;
    string x;
    char c;
    do {
        system("cls");
        cout << "Nhap ma doi ma ban muon sua : ";
        fflush(stdin);
        cin >> x;
        kt = s.update(x);
        if (kt == true) cout << " Sua thanh cong! " << endl;
        else cout << " Ma doi nhap vao khong hop le! " << endl;
        cout << "Ban co muon tiep tuc khong?(c/k)" << endl;
        c = _getch();
    } while (c == 'c' || c == 'C');
}
// Xoa doi
void xoadoi(Bang& s) {
    char c;
    bool kt;
    int t, x;
    string madoi;
    Doi v;
    
    do {
        system("cls");
        cout << " Ban muon xoa doi theo cach nao? " << endl;
        cout << " 1. Xoa dua tren vi tri cua doi." << endl << " 2. Xoa doi bang cach nhap ma doi." << endl;
        cout << " 3 Xoa doi dua tren viec nhap doi." << endl << " Moi ban chon:"; 
        cin >> t;
        switch (t)
        {
        case 1: {
            cout << "Nhap vi tri doi muon xoa: ";
            cin >> x;
            kt = s.removeat(x);
            if (kt == true) cout << " Xoa doi thanh cong! " << endl;
            else cout << " Vi tri nhap vao khong hop le! " << endl;
            break;
        }
        case 2: {
            cout << "Nhap ma doi muon xoa: ";
            fflush(stdin);
            cin >> madoi;
            int y = s.searchmd(madoi);
            kt = s.removeat(y);
            if (kt == true) cout << " Xoa doi thanh cong! " << endl;
            else cout << " Ma doi nhap vao khong hop le! " << endl;
            break;
        }
        case 3: {
            cout << "Nhap doi muon xoa." << endl;
            cin >> v;
            kt = s.remove(v);
            if (kt == true) cout << " Xoa doi thanh cong! " << endl;
            else cout << " Doi nhap vao khong hop le! " << endl;
            break;
        }
        default:
        {cout << "Nhap khong hop le! Moi ban nhap so trong khoang (1;3)" << endl;
        break; }
        }
        cout << " Ban muon tiep tuc khong (c/k)? " << endl;
        c = _getch();
    } while (c == 'c' || c == 'C');
}
// Tim kiem doi
void tkdoi(Bang& s) {
    int t;
    Doi v;
    string x;
    char c;
    cout << " Ban muon tim kiem doi theo cach nao? " << endl;
    cout << " 1. Tim kiem bang cach nhap ma doi." << endl << " 2. Tim kiem bang cach nhap doi." << endl;
    cout << " Moi ban chon:";
    do {
        system("cls");
        cout << " Ban muon tim kiem doi theo cach nao? " << endl;
        cout << " 1. Tim kiem bang cach nhap ma doi." << endl << " 2. Tim kiem bang cach nhap doi." << endl;
        cout << " Moi ban chon:";
        cin >> t;
        switch (t)
        {
        case 1: {
            cout << "Nhap ma doi muon tim kiem: ";
            cin >> x;
            t = s.searchmd(x);
            if (t != -1) cout << " Vi tri cua doi can tim la : " << t << endl;
            else cout << " Khong co doi can tim trong danh sach! " << endl;
            break;
        }
        case 2: {
            cout << "Nhap doi muon tim kiem : " << endl;
            cin >> v;
            t = s.search(v);
            if (t != -1) cout << " Vi tri cua doi can tim la : " << t << endl;
            else cout << " Khong co doi can tim trong danh sach! " << endl;
            break;
        }
        default:
        {cout << "Nhap khong hop le! Moi ban nhap so trong khoang (1;2)" << endl;
        break; }
        }
        cout << " Ban muon tiep tuc khong (c/k)? " << endl;
        c = _getch();
    } while (c == 'c' || c == 'C');
}




//Ham doc danh sach cac doi co trong SQL
void docdoi(Ketnoi database, ListBang& l) {
    char c;
    system("cls");
    database.SelectDoi(l);
    c = _getch();
}

// ham quan ly doi

void qldoi(Ketnoi database, ListBang& l) {
    int t;
    char c;
    int d = 8;
    string mb;
    HANDLE mau;
    mau = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(mau, 7);
    do {
        system("cls");
        cout << "============= Quan ly doi ================" << endl;
        cout << " 1. Doc du lieu tu SQL" << endl;
        SetConsoleTextAttribute(mau, d);
        cout << " 2. Them doi " << endl;
        cout << " 3. Sua doi " << endl;
        cout << " 4. Xoa doi " << endl;
        cout << " 5. Tim kiem doi " << endl;
        cout << " 6. Hien thi danh sach doi " << endl;
        SetConsoleTextAttribute(mau, 7);
        cout << " 0. Thoat!" << endl;
        cout << " Lua chon cua ban: ";
        cin >> t;
        if (t == 1) {
            d = 7;
            docdoi(database, l);
        }
        else if (t == 2) {
            if (d == 8) {
                cout << " Ban phai thuc hien cac chuc nang 1 truoc!" << endl;
                c = _getch();
            }
            else {
                cout << " Nhap ma bang can them doi ";
                fflush(stdin);
                cin >> mb;
                for (int i = 0; i < l.lenght(); i++) {
                    if (mb == l[i].getmb()) themdoi(l[i]);
                }
            }
            
        }
        else if (t == 3) {
            if (d == 8) {
                cout << " Ban phai thuc hien cac chuc nang 1 truoc!" << endl;
                c = _getch();
            }
            else {
                cout << " Nhap ma bang can sua doi ";
                fflush(stdin);
                cin >> mb;
                for (int i = 0; i < l.lenght(); i++) {
                    if (mb == l[i].getmb()) suadoi(l[i]);
                }
            }
            
        }
        else if (t == 4) {
            if (d == 8) {
                cout << " Ban phai thuc hien cac chuc nang 1 truoc!" << endl;
                c = _getch();
            }
            else {
                cout << " Nhap ma bang can xoa doi ";
                fflush(stdin);
                cin >> mb;
                for (int i = 0; i < l.lenght(); i++) {
                    if (mb == l[i].getmb()) xoadoi(l[i]);
                }
            }
            
        }
        else if (t == 5) {
            if (d == 8) {
                cout << " Ban phai thuc hien cac chuc nang 1 truoc!" << endl;
                c = _getch();
            }
            else {
                cout << " Nhap ma bang can tim kiem doi ";
                fflush(stdin);
                cin >> mb;
                for (int i = 0; i < l.lenght(); i++) {
                    if (mb == l[i].getmb()) tkdoi(l[i]);
                }
            }
            
        }
        else if (t == 6) {
            if (d == 8) {
                cout << " Ban phai thuc hien cac chuc nang 1 truoc!" << endl;
                c = _getch();
            }
            else {
                cout << " Nhap ma bang can hien thi doi ";
                fflush(stdin);
                cin >> mb;
                for (int i = 0; i < l.lenght(); i++) {
                    if (mb == l[i].getmb()) l[i].show();
                }
                c = _getch();
            }
            
        }
        else if (t == 0) {
            break;
        }
        else {
            cout << " Ban nhap khong hop le ! ";
        }
    } while (t != 0);
}


//Ham sap xep va ghi du lieu vao lichthidau
void sxbang(Bang& bg,Lichthidau &ltd) {
	int k = bg.lenght();
	int a[10], b[10],c[10];
    int i, j, p, r;
    if (k == 0) {
        cout << "    Hien chua co doi nao trong danh sach!        " << endl;
    }
    if (k == 1) {
        cout << "    Trong danh sach chi co mot doi nen chua the xep lich!    " << endl;
    }
    if (k > 1)
    {
        for (int i = 0; i < k; i++) {
            a[i]= b[i] = c[i] = i;
        }
        if (k % 2 == 1) {
            for (i = 0; i < k; i++) {
                j = 1;
                p = k - 1;
                while (j < p) {
                    int suat = 1;
                    string matran = bg.gettb();
                    matran = matran + std::to_string(b[j]) + std::to_string(b[p]);
                    TD* td = new TD(matran, bg.getmb(), bg.getmd(b[j]), bg.getmd(b[p]), suat % 2 + 1, i + 1);
                    ltd.add(*td);
                    j++; p--;
                    suat++;
                }
                cout << endl;
                for (r = 0; r < k - 1; r++) {
                    b[r] = b[r + 1];
                }
                b[k - 1] = a[i];
            }
            for (i = 0; i < k; i++) {
                j = 1;
                p = k - 1;
                while (j < p) {
                    int suat = 1;
                    string matran = bg.gettb();
                    matran = matran + std::to_string(c[p]) + std::to_string(c[j]);
                    TD* td = new TD(matran,bg.getmb(), bg.getmd(c[p]), bg.getmd(c[j]), ((suat + 1) % 2 + 1), i + 1);
                    ltd.add(*td);
                    j++; p--;
                    suat++;
                }
                cout << endl;
                for (r = 0; r < k - 1; r++) {
                    c[r] = c[r + 1];
                }
                c[k - 1] = a[i];
            }
        }
        else {
            for (i = 0; i < k - 1; i++) {
                j = 1;
                p = k - 2;
                while (j < p) {
                    int suat = 1;
                    string matran = bg.gettb();
                    matran = matran + std::to_string(b[j]) + std::to_string(b[p]);
                    TD* td = new TD(matran, bg.getmb(), bg.getmd(b[j]), bg.getmd(b[p]), suat % 2 + 1, i + 1);
                    ltd.add(*td);
                    j++; p--;
                    suat++;
                }
                string matran = bg.gettb();
                matran = matran + std::to_string(b[0]) + std::to_string(b[k-1]);
                TD* td = new TD(matran, bg.getmb(), bg.getmd(b[0]), bg.getmd(b[k-1]), 1, i + 1);
                ltd.add(*td);
                for (r = 0; r < k - 2; r++) {
                    b[r] = b[r + 1];
                }
                b[k - 2] = a[i];
            }
            for (i = 0; i < k - 1; i++) {
                j = 1;
                p = k - 2;
                while (j < p) {
                    int suat = 1;
                    string matran = bg.gettb();
                    matran = matran + std::to_string(c[p]) + std::to_string(c[j]);
                    TD* td = new TD(matran, bg.getmb(), bg.getmd(c[p]), bg.getmd(c[j]), ((suat + 1) % 2 + 1), i + 1);
                    ltd.add(*td);
                    j++;
                    p--;
                    suat++;
                }
                string matran = bg.gettb();
                matran = matran + std::to_string(c[k-1]) + std::to_string(c[0]);
                TD* td = new TD(matran, bg.getmb(), bg.getmd(c[k-1]), bg.getmd(c[0]), 2, i + 1);
                ltd.add(*td);
                for (r = 0; r < k - 2; r++) {
                    c[r] = c[r + 1];
                }
                c[k - 2] = a[i];
            }
        }
        cout << " Da sap xep lich thi dau thanh cong cho bang "<< bg.gettb() << endl;
    }
}

// Ham lap lich 
void laplich(Ketnoi database ,ListBang& l, Lichthidau& ltd) {
    char c;
    int luachon;
    system("cls");
    for (int i = 0; i < l.lenght(); i++) {
        if (l[i].lenght() != 0) sxbang(l[i], ltd);
    }
    system("pause");
    do {
        system("cls");
        cout << "==================== Lich thi dau ====================" << endl;
        cout << " 1. Dong bo lich thi dau vao lai SQL " << endl;
        cout << " 2. Ghi lich thi dau ra ma hinh " << endl;
        cout << " 0. Thoat!" << endl;
        cout << " Lua chon cua ban: ";
        cin >> luachon;
        if (luachon == 1) {
            database.InsertLTD(ltd);
            c = _getch();
        }
        else if(luachon == 2){
            ltd.show(l);
            c = _getch();
        }
        else if (luachon == 0) {
            break;
        }
        else {
            cout << " Ban nhap khong hop le ! ";
        }
    } while (luachon != 0);
}

// Ham ghi ket qua cho cac tran dau
void ghikq(KQ& kq, Lichthidau ltd,ListBang &l) {
    char c;
    string matran;
    int b1, b2,i;
    do {
        system("cls");
        cout << " Nhap ma tran ban muon nhap ket qua : ";
        cin >> matran;
        for (i = 0; i < ltd.lenght(); i++) {
            if (matran == ltd.getmt(i)) break;
        }
        if (i == ltd.lenght()) {
            cout << " Ma tran ban nhap vao khong hop le! " << endl;
        }
        else
        {
            cout << ltd[i].gettd1(l) << "  : ";
            cin >> b1;
            cout << ltd[i].gettd2(l) << "  : ";
            cin >> b2;
            KQTD* kqtd = new KQTD(matran,ltd.getmb(i), ltd.getmd1(i), ltd.getmd2(i), b1, b2);
            kq.add(*kqtd);
        }
        cout << " Ban co muon tiep tuc khong?(c/k) " << endl;
        c = _getch();
    } while ( c == 'c'|| c == 'C');
}
// Ham ket qua
void ketqua(Ketnoi database, KQ& kq, Lichthidau ltd, ListBang& l) {
    int t;
    char xc;
    do {
        system("cls");
        cout << "==================== Ket qua ====================" << endl;
        cout << " 1. Nhap ket qua cho cac tran dau" << endl;
        cout << " 2. Dong bo ket qua vao lai SQL " << endl;
        cout << " 3. Ghi ket qua ra ma hinh " << endl;
        cout << " 0. Thoat!" << endl;
        cout << " Lua chon cua ban: ";
        cin >> t;
        if (t == 1) {
            ghikq(kq, ltd, l);
        }
        else if (t == 2) {
            database.UpdateLTD(kq);
            xc = _getch();
        }
        else if (t == 3) {
            
            kq.show(l);
            xc = _getch();
        }
        else if (t == 0) {
            break;
        }
        else {
            cout << " Ban nhap khong hop le ! ";
        }
    } while (t != 0);
}
// Ham menu

void menu(Ketnoi database,ListBang &l,Lichthidau &ltd,KQ &kq){
    char c;
    int d = 8;
    int k = 8;
    int p = 8;
    HANDLE mau;
    mau = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(mau, 7);
    int luachon;
    do {

        system("cls");
        cout << "=============================== DO AN LAP TRINH =============================" << endl;
        cout << "===================== Quan ly va lap lich thi dau the thao ==================" << endl;
        cout << "====================================Menu=====================================" << endl;
        cout << " 1 . Quan ly danh sach bang " << endl;
        SetConsoleTextAttribute(mau, d);
        cout << " 2 . Quan ly danh sach doi " << endl;
        SetConsoleTextAttribute(mau, k);
        cout << " 3 . Lap lich thi dau cho cac doi trong cac bang" << endl;
        SetConsoleTextAttribute(mau, p);
        cout << " 4 . Ghi ket qua cho cac tran dau " << endl;
        SetConsoleTextAttribute(mau, 7);
        cout << " 0 . Thoat!" << endl;
        cout << " Lua chon cua ban : ";
        cin >> luachon;
        if (luachon == 1) {
            d = 7;
            qlbang(database,l);
        }
        else if (luachon == 2) {
            if (d == 8) {
                cout << " Ban phai thuc hien cac chuc nang truoc!" << endl;
                c = _getch();
            }
            else {
                k = 7;
                qldoi(database, l);
            }
        }
        else if (luachon == 3) {
            if (k == 8) {
                cout << " Ban phai thuc hien cac chuc nang truoc!" << endl;
                c = _getch();
            }
            else {
                p = 7;
                laplich(database, l, ltd);
            }
        }
        else if (luachon == 4) {
            if (p == 8) {
                cout << " Ban phai thuc hien cac chuc nang truoc!" << endl;
                c = _getch();
            }
            else {
                ketqua(database, kq, ltd, l);
            }
        }
        else if (luachon == 0) {
            break;
        }
        else {
            cout << " Ban nhap ko hop le, moi nhap lai! " << endl;
            c = _getch();
        }
    } while (luachon != 0);
}
int main()
{
	
	Ketnoi database;
	ListBang l;
    Lichthidau ltd;
    KQ kq;
	database.init();
    menu(database, l, ltd, kq);
	database.close();
	return 0;
}