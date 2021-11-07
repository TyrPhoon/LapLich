#include "Ketnoi.h"
#include "Doi.h"
#include <iostream>
#include<iomanip>
#include<conio.h>
#include<string.h>
#include<string>
#include<ctime>
using namespace std;

int len(char s[50]) {
    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return i;

}
void Ketnoi::init()
{
    //initializations --- Khoi tao
    sqlConnHandle = NULL;
    sqlStmtHandle = NULL;
    //allocations --- sự phân bổ
    if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &sqlEnvHandle))
        close();

    if (SQL_SUCCESS != SQLSetEnvAttr(sqlEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0))
        close();

    if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, sqlEnvHandle, &sqlConnHandle))
        close();

    //output
    cout << "Attempting connection to SQL Server...";
    cout << "\n";
    switch (SQLDriverConnect(sqlConnHandle, NULL, (SQLWCHAR*)L"DRIVER={SQL Server};SERVER=TYR-PHOON;DATABASE=PBL2",
        SQL_NTS,
        retconstring,
        1024,
        NULL,
        SQL_DRIVER_NOPROMPT)) {

    case SQL_SUCCESS:
        cout << "Successfully connected to SQL Server";
        cout << "\n";
        break;

    case SQL_SUCCESS_WITH_INFO:
        cout << "Successfully connected to SQL Server";
        cout << "\n";
        break;

    case SQL_INVALID_HANDLE:
        cout << "Could not connect to SQL Server";
        cout << "\n";
        close();
        break;

    case SQL_ERROR:
        cout << "Could not connect to SQL Server";
        cout << "\n";
        close();
        break;

    default:
        break;
    }
    //if there is a problem connecting then exit application
    if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle))
        close();
}

void Ketnoi::InsertLTD(Lichthidau &ltd) {
    string s, s4, s5, s6, s7, s8, s9;
    string s1, mb, s2, s3; int su, n;
    string insert;
    bool kq = true;
    s = "INSERT INTO Lichthidau VALUES";
    s4 = "'";
    s5 = "("; s6 = ",NULL,NULL,NULL,NULL,'0')";
    s7 = ",";
    int i;
    for (i = 0; i < ltd.lenght(); i++) {
        s1= ltd.getmt(i);
        mb = ltd.getmb(i);
        s2 = ltd.getmd1(i);
        s3 = ltd.getmd2(i);
        su = ltd.getsuat(i);
        n = ltd.getngay(i);


        if (su == 1) {
            s8 = "16:00:00','19:00:00";
        }
        else
        {
            s8 = "19:00:00','22:00:00";
        }
        time_t baygio = time(0);
        tm now;
        localtime_s(&now, &baygio);
        string year, mon, day, kc;
        kc = "/";
        year = std::to_string(1900 + now.tm_year);
        mon = std::to_string(now.tm_mon);
        day = std::to_string(now.tm_mday + n);
        s9 = mon + kc + day + kc + year;
        insert = s + s5 + s4 + s1 + s4 + s7 + s4 + mb + s4 + s7 + s4 + s2 + s4 + s7 + s4 + s3 + s4 + s7 + s4 + s9 + s4 + s7 + s4 + s8 + s4 + s6;
        char* c = new char[insert.size() + 1];
        copy(insert.begin(), insert.end(), c);
        c[insert.size()] = '\0';
        if (SQL_SUCCESS != SQLExecDirectA(sqlStmtHandle, (SQLCHAR*)c, SQL_NTS)) {
            kq = kq * false;
            cout << "\n";
            cout << "Error querying SQL Server";
            cout << "\n";
            close();
        }
        else {
            kq = kq * true;
        }
    }
    if (kq == true) {
        cout << " INSERT SUCESS! " << endl;
        return;
    }
}

void Ketnoi::SelectDoi(ListBang &l) {
    //output
    cout << "\n";
    cout << "Dang thuc hien truy van SQL...";
    cout << "\n";
    char c[] = "SELECT * FROM doi";
    if (SQL_SUCCESS != SQLExecDirectA(sqlStmtHandle, (SQLCHAR*)c, SQL_NTS)) {
        cout << "Error querying SQL Server";
        cout << "\n";
        close();
    }
    else {
        
        SQLINTEGER ptrSqlVersion;
        char madoi[50];
        char name[50];
        char mabang[50];
        float nhom;
        int i = 0;
        while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {
            SQLGetData(sqlStmtHandle, 1, SQL_CHAR, madoi, SQL_RESULT_LEN, &ptrSqlVersion);
            SQLGetData(sqlStmtHandle, 2, SQL_CHAR, name, SQL_RESULT_LEN, &ptrSqlVersion);
            SQLGetData(sqlStmtHandle, 3, SQL_CHAR, mabang, SQL_RESULT_LEN, &ptrSqlVersion);
            SQLGetData(sqlStmtHandle, 4, SQL_C_FLOAT, &nhom, 1, &ptrSqlVersion);
            std::string myString;
            string md,nm,mb;
            md = myString.assign(madoi, len(madoi));
            nm = myString.assign(name, len(name));
            mb = myString.assign(mabang, len(mabang));
            Doi *d = new Doi(md,nm,nhom,mb);
            for (int j = 0; j < l.lenght(); j++) {
                if (l[j].getmb() == mb) l[j].add(*d);
            }
        }
        cout << " Da lay du lieu thanh cong! " << endl;
    }
    SQLCancel(sqlStmtHandle);
}

void Ketnoi::SelectBang(ListBang &l) {
    //output
    cout << "\n";
    cout << "Dang thuc hien truy van SQL...";
    cout << "\n";
    
    char c[] = "SELECT * FROM Bang";
    if (SQL_SUCCESS != SQLExecDirectA(sqlStmtHandle, (SQLCHAR*)c, SQL_NTS)) {
        cout << "Error querying SQL Server";
        cout << "\n";
        close();
    }
    else {
        //d-eclare output variable and pointer
        SQLINTEGER ptrSqlVersion;
        char mabang[50];
        char tenbang[50];
        int i = 0;
        while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {
            SQLGetData(sqlStmtHandle, 1, SQL_CHAR, mabang, SQL_RESULT_LEN, &ptrSqlVersion);
            SQLGetData(sqlStmtHandle, 2, SQL_CHAR, tenbang, SQL_RESULT_LEN, &ptrSqlVersion);
            //display query result
            //cout << "\nquery result: " << madoi << " " << name << " " << mabang << " " << nhom << endl;
            std::string myString;
            string mb, tb;
            mb = myString.assign(mabang, len(mabang));
            tb = myString.assign(tenbang, len(tenbang));
            Bang* b = new Bang(mb, tb);
            l.add(*b);
        }
        cout << " Da lay du lieu thanh cong! " << endl;
    }
    SQLCancel(sqlStmtHandle);
}

void Ketnoi::UpdateLTD(KQ &k) {
    int b1, b2 , d1, d2;
    string  s, s1, s2, s3,matran, update;
    s = "UPDATE Lichthidau SET ";
    s1 = "'"; s2 = "trangthai = '1' WHERE matran =";
    s3 = ",";
    bool kq = true;
    for (int i = 0; i < k.lenght(); i++) {
        matran = k.getmt(i);
        b1 = k.getb1(i);
        b2 = k.getb2(i);
        if (b1 > b2) {
            d1 = 3; d2 = 0;
        }
        else if (b1 == b2) {
            d1 = 1; d2 = 1;
        }
        else {
            d1 = 0; d2 = 3;
        }
        string bt1, bt2, di1, di2;
        bt1 = "banthang1 = ";
        bt1 = bt1 + s1 + std::to_string(b1) + s1;
        bt2 = "banthang2 = ";
        bt2 = bt2 + s1 + std::to_string(b2) + s1;
        di1 = "sodiem1 = ";
        di1 = di1 + s1 + std::to_string(d1) + s1;
        di2 = "sodiem2 = ";
        di2 = di2 + s1 + std::to_string(d2) + s1;
        update = s + bt1 + s3 + bt2 + s3 + di1 + s3 + di2 + s3 + s2 + s1 + matran + s1;
        //cout << s << endl;
        char* c = new char[update.size() + 1];
        copy(update.begin(), update.end(), c);
        c[update.size()] = '\0';
        if (SQL_SUCCESS != SQLExecDirectA(sqlStmtHandle, (SQLCHAR*)c, SQL_NTS)) {
            kq = kq* false;
            cout << "\n";
            cout << "Error querying SQL Server";
            cout << "\n";
            close();
        }
        else
        {
            kq = kq * true;
            
        }
    }
    if (kq == true) {
        cout << "\nUPDATE SUCCESS";
        return;
    }
}

void Ketnoi::Delete() {
    string s0, s, s1, s2, s3, s4, s5, s6, s7;
    s = "DELETE";
    s4 = "'"; s5 = " "; s6 = "WHERE";
    //s5="(";s6=")";
    s7 = ",";
    cout << "Nhap table can xoa : ";
    fflush(stdin);
    getline(cin, s1);
    cout << "Nhap dieu kien xoa (Dung cu phap SQL) : ";
    fflush(stdin);
    getline(cin, s2);
    s = s + s5 + s1 + s5 + s6 + s5 + s2;
    //cout << s << endl;
    char* c = new char[s.size() + 1];
    copy(s.begin(), s.end(), c);
    c[s.size()] = '\0';
    if (SQL_SUCCESS != SQLExecDirectA(sqlStmtHandle, (SQLCHAR*)c, SQL_NTS)) {
        cout << "\n";
        cout << "Error querying SQL Server";
        cout << "\n";
        close();
    }
    else
    {
        cout << "\nUPDATE SUCCESS";
        return;
    }
}

void Ketnoi::close() {
    SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
    SQLDisconnect(sqlConnHandle);
    SQLFreeHandle(SQL_HANDLE_DBC, sqlConnHandle);
    SQLFreeHandle(SQL_HANDLE_ENV, sqlEnvHandle);
    system("pause");
    exit(0);
}