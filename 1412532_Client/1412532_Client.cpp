// Client_socket.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "1412532_Client.h"
#include "afxSock.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// The one and only application object

CWinApp theApp;

using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	HMODULE hModule = ::GetModuleHandle(NULL);

	if (hModule != NULL)
	{
		// initialize MFC and print and error on failure
		if (!AfxWinInit(hModule, NULL, ::GetCommandLine(), 0))
		{
			// TODO: change error code to suit your needs
			_tprintf(_T("Fatal Error: MFC initialization failed\n"));
			nRetCode = 1;
		}
		else
		{
			// TODO: code your application's behavior here.
			struct NguoiChoi
			{
				char nick[100];
				int diemSo;
				char goiY[200];
			};
			CSocket client;
			NguoiChoi nc_Client;
			char r_str[1000], s_str[1000];

			AfxSocketInit();
			client.Create();
			if (client.Connect(_T("127.0.0.1"), 1234))
			{
				printf("Da ket noi den server!");
				// Đoạn nhập tên và gửi lên Server kiểm tra.
				do
				{
					printf("Nhap vao ten: ");
					gets_s(nc_Client.nick);  // Nhập tên vào.
					//printf("Ten do client nhap: %s", nc_Client.nick);
					client.Send(nc_Client.nick, strlen(nc_Client.nick), 0);   // Gửi tên lên cho server.
					int len = client.Receive(r_str, 100, 0);
					r_str[len] = '\0';
					printf("sever: %s\n\n", r_str);
				} while (strcmp(r_str, "sai")==0);
				nc_Client.diemSo = 0;// Gán điểm số của người chơi = 0
				int soKiTu = 0;// số lượng ký tự trong ô Chữ
				int nguoiChoi = 0;// số lượng người chơi
				int len = client.Receive(r_str, 100, 0);
				r_str[len] = '\0';
				nguoiChoi = atoi(r_str);  //Lấy vào số lượng người chơi

				len = client.Receive(r_str, 100, 0);
				r_str[len] = '\0';
				soKiTu = atoi(r_str);

				len = client.Receive(r_str, 100, 0);
				r_str[len] = '\0';
				strcat(nc_Client.goiY, r_str);	// lấy vào gợi ý ô chữ
				
				printf("so nguoi choi: %d\n", nguoiChoi);
				printf("So ki tu: %d\n", soKiTu);
				printf("goi y: %s\n", nc_Client.goiY);



				client.Close();// đóng kết nối.
			}
			else printf("Khong the ket noi toi Server.\n");
		}
	}
	else
	{
		// TODO: change error code to suit your needs
		_tprintf(_T("Fatal Error: GetModuleHandle failed\n"));
		nRetCode = 1;
	}

	return nRetCode;
}




