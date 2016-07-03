// server_socket.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "1412532_Server.h"
#include "afxsock.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif
using namespace std;

// The one and only application object
CWinApp theApp;



bool KiemTraChuoi(char x[],char arr_nickName [][100],int n);
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
			
			CSocket server;   // Khai Báo SocKet Server và Client
			CSocket arr_client[MAX_N];
			int n_client;// Số lượng client do người dùng nhập

			ThongTin TTNguoiChoi[MAX_N];
			int n_ThongTin = 0; // Số lượng tên client đang có.

			char s_str[1000], r_str[1000];

			OCHU arr_OChu[100];

			printf("Nhap vao so luong Client: ");
			scanf_s("%d", &n_client);
			
			AfxSocketInit();// Khởi tạo cái gì đó = NULL
			server.Create(1234);  // Tạo SocKet là gì?????
			//lang nghe ket noi
			server.Listen();
			// phần kết nối các client vào server.
			for (int i = 0; i<n_client; i++)
			{
				printf("Dang cho mot ket noi...");
				if (server.Accept(arr_client[i]))// Nếu đã kết nối thì ...
				{
					int len = 0;
					len= arr_client[i].Receive(r_str, 100, 0);	// Nhận thông tin từ clint gửi lên
					r_str[len] = '\0';
					while (KiemTraChuoi(r_str, TTNguoiChoi, n_ThongTin))
					{
						arr_client[i].Send("sai", strlen("sai"), 0);
						len = arr_client[i].Receive(r_str, 100, 0);	// Nhận thông tin từ clint gửi lên
						r_str[len] = '\0';
					}
					printf("\nDa nhan ket noi tu client %s.\n", r_str); // In ra thông báo kết nối.
					strcat(TTNguoiChoi[n_ThongTin].nick, r_str);  //đưa vào
					TTNguoiChoi[n_ThongTin].diemSo = 0;// khởi tạo điểm số = 0 cho các người chơi
					n_ThongTin++;// Tăng
					// Gửi thông tin kết quả người chơi về client
					arr_client[i].Send("dung", strlen("dung"), 0);// gửi cho client biết là đúng rồi.
					
				}

				//arr_client[i].Close();// Phải nhập tên đúng thì mới đóng lại
			}
			/////////////////////////////////////////////////////////////////////////////////
			fstream fp;
			int n_OChu = DocTapTin(fp, arr_OChu);
			OCHU OChuDuocChon = LayNgauNhienOChu(arr_OChu, n_OChu);	// lấy ngẫu nhiên 1 ô chữ
			printf("o chu duoc chon: %s", OChuDuocChon.oChu);

			for (int i = 0; i < n_client; i++)
			{
				char tam[10];
				int len = strlen(_itoa(n_client, tam, 10));
				arr_client[i].Send(_itoa(n_client,tam, 10), len, 0);// số lượng người chơi

				len = strlen(OChuDuocChon.oChu);
				arr_client[i].Send(_itoa(len, tam, 10), len, 0);	//số ký tự của ô chữ

				len = strlen(OChuDuocChon.goiY);
				arr_client[i].Send(OChuDuocChon.goiY, len, 0);// gợi ý.
			}
			

			server.Close();
			DuyetThongTin(TTNguoiChoi, n_ThongTin);
			_getch();
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

