// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // some CString constructors will be explicit
#define _AFX_NO_MFC_CONTROLS_IN_DIALOGS         // remove support for MFC controls in dialogs

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // Exclude rarely-used stuff from Windows headers
#endif

#include <afx.h>
#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // MFC support for Internet Explorer 4 Common Controls
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>                     // MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <iostream>
using namespace std;
#include<string.h>
#include<conio.h>
#include<fstream>
#define MAX_N 100


// TODO: reference additional headers your program requires here
struct ThongTin
{
	char nick[MAX_N];
	int diemSo;
};
struct OCHU
{
	char oChu[100];
	char goiY[200];
	int lanDoan;
};


bool KiemTraChuoi(char x[], ThongTin ThongTin[], int n);
void DuyetThongTin(ThongTin thongtin[], int n);
int DocTapTin(fstream &fp, OCHU ochu[]);
OCHU LayNgauNhienOChu(OCHU oChu[], int n);
