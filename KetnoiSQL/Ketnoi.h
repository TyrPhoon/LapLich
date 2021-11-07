#pragma once

#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>
#include<stdlib.h>
#include "Doi.h"
#include "Bang.h"
#include "ListBang.h"
#include "Lichthidau.h"
#include "KQ.h"
class Ketnoi
{

#define SQL_RESULT_LEN 240
#define SQL_RETURN_CODE_LEN 1024
    //define handles and variables
    SQLHANDLE sqlConnHandle;
    SQLHANDLE sqlStmtHandle;
    SQLHANDLE sqlEnvHandle;
    SQLWCHAR retconstring[SQL_RETURN_CODE_LEN];

public:
    void init();
    void InsertLTD(Lichthidau &);
    void SelectDoi(ListBang &);
    void SelectBang(ListBang &);
    void UpdateLTD(KQ &);
    void Delete();
    void close();
};