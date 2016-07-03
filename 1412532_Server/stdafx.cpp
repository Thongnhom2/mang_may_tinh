// stdafx.cpp : source file that includes just the standard includes
// 1412532_Server.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

// TODO: reference any additional headers you need in STDAFX.H
// and not in this file

bool KiemTraChuoi(char x[], ThongTin thongtin[], int n)
{
	if (n == 0) return 0;
	for (int j = 0; j < n; j++)
	{
		if (strcmp(x, thongtin[j].nick) == 0) return 1;
		else return 0;
	}
}
void DuyetThongTin(ThongTin thongtin[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d. %s\n", i, thongtin[i].nick);
}

int DocTapTin(fstream &fp,OCHU ochu[])
{

	fp.open("ochu.txt", ios_base::in);// đọc tập tin
	int soluong = 0;
	fp >> soluong;
	for (int i = 0; i < soluong; i++)
	{
		fp.getline(ochu[i].oChu, 100);
		fp.getline(ochu[i].goiY, 200);
		fp >> ochu[i].lanDoan;
	}
	fp.close();
	return soluong;
}
OCHU LayNgauNhienOChu(OCHU oChu[],int n)
{
	//printf("o chu duoc chon: %s", oChu[oChu[rand() % n])
	return (oChu[rand() % n]);
}