
//THÔNG TIN
/*
	ĐỒ ÁN KỸ THUẬT LẬP TRÌNH: QUẢN LÝ THƯ VIỆN
	NHÓM 5: CA 1 THỨ 6 - 10DHBM
		- Lâm Nhật Ánh (NT)
		- Lý Uyễn Nhi 
		- Đỗ Duy Phương
		- Nguyễn Hữu Đông Khanh
*/
//--------------------------------
//Khai báo thư viện
#include <stdio.h>
#include <conio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#include<fstream> 

using namespace std;
#define _CRT_SECURE_NO_WARNINGS
#define MAXSIZE 100

//-------------------------------------
//Khai báo constant va struct
struct SACH
{
	char maSach[11];
	char tenSach[200];
	char tacgia[50];
	char nhaXB[50];
	int namXB;
};

//------------------------------
//Khai báo hàm con - prototype
void hienThiMenu();
void thucThiChuongTrinh();

void docFileSach(SACH dssach[], int &n);
void ghiFileSach(SACH dssach[], int n);
void xuatDSSACH(SACH dssach[], int n);
void xuatThongTinSach(SACH s);
void NhapThongTinSach(SACH &s);
void nhapDSSach(SACH dssach[], int &n);

int kiemTraMaSach(SACH dssach[], int n, char masach[]);
void ThongTinSachThem(SACH dssach[], int n, SACH &s);
void ThemSach(SACH dssach[], int &n, int vt, SACH s);
void ThemSachCuoi(SACH dssach[], int &n, SACH s);
void XoaSach(SACH dssach[], int &n, int vt);
void SuaSach(SACH dssach[], char ms[], int n);

int binarySearchMaSach_DeQuy(SACH dssach[], int Left, int Right, char masach[]);
int binarySearchTenSach_DeQuy(SACH dssach[], int Left, int Right, char tensach[]);
int binarySearchTacGia_DeQuy(SACH dssach[], int Left, int Right, char tacgia[]);
int binarySearchNhaXB_DeQuy(SACH dssach[], int Left, int Right, char nhaxb[]);
int binarySearchNamXB_DeQuy(SACH dssach[], int Left, int Right, int namxb);

int binarySearchMaSach_KhuDeQuy(SACH dssach[], int n, char masach[]);
int binarySearchTenSach_KhuDeQuy(SACH dssach[], int n, char tensach[]);
int binarySearchTacGia_KhuDeQuy(SACH dssach[], int n, char tacgia[]);
int binarySearchNhaXB_KhuDeQuy(SACH dssach[], int n, char nhaxb[]);
int binarySearchNamXB_KhuDeQuy(SACH dssach[], int n, int namxb);

void InterchangeSort_TangTenSach(SACH dssach[], int n);

void InterchangeSort_TangMaSach(SACH dssach[], int n);
void InterchangeSort_GiamMaSach(SACH dssach[], int n);
void InterchangeSort_TangTenTG(SACH dssach[], int n);
void InterchangeSort_GiamTenTG(SACH dssach[], int n);
void BubbleSort_TangMaSach(SACH dssach[], int n);
void BubbleSort_GiamMaSach(SACH dssach[], int n);
void BubbleSort_TangTenTG(SACH dssach[], int n);
void BubbleSort_GiamTenTG(SACH dssach[], int n);

void SoLuongSach_NhaXB(SACH dssach[], int n);
void SoLuongSach_NamXB(SACH dssach[], int n);
void SoLuongSach_TacGia(SACH dssach[], int n);

void xuatTacGia_MaxSach(SACH dssach[], int n);
void xuatNhaXB_MaxSach(SACH dssach[], int n);
void xuatNamXB_MaxSach(SACH dssach[], int n);
//---------------------------
//Hàm main
void main()
{
	hienThiMenu();
	thucThiChuongTrinh();
	_getch();

}
//-----------------------
//Thân hàm con

//Hàm hiện thị Menu chương trình
void hienThiMenu()
{
	printf("\n**************************************************************");
	printf("\n********************QUAN LY THU VIEN**************************");
	printf("\n*1. Danh sach quan ly sach (Doc File)                        *");
	printf("\n*2. Them Sach                                                *");
	printf("\n*3. Them Sach (vi tri bat ky)                                *");
	printf("\n*4. Xoa Sach                                                 *");
	printf("\n*5. Sua Sach                                                 *");
	printf("\n*6. Tim kiem Sach (Binary Search) - de quy - MaSach          *");
	printf("\n*7. Tim kiem Sach (Binary Search) - de quy - TenSach         *");
	printf("\n*8. Tim kiem Sach (Binary Search) - khu de quy - MaSach      *");
	printf("\n*9. Tim kiem Sach (Binary Search) - khu de quy - TenSach     *");
	printf("\n*10. Sap xep tang/giam theo ma sach Interchange Sort         *");
	printf("\n*11. Sap xep tang/giam theo ma sach Bubble Sort              *");
	printf("\n*12. Sap xep tang/giam theo ten tac gia Interchange Sort     *");
	printf("\n*13. Sap xep tang/giam theo ten tac gia Bubble Sort          *");
	printf("\n*14. Thong ke so luong sach theo NXB, NamXB, TacGia          *");
	printf("\n*15. TacGia, NhaXuatBan, NamXB co nhieu sach nhat            *");
	printf("\n*16. Xuat Danh Sach Sach Thu Vien (ghi file)                 *");
	printf("\n*0. Thoat                                                    *");
	printf("\n**************************************************************");
	printf("\n**************************************************************");

}

//Hàm thực thi chương trình
void thucThiChuongTrinh()
{
	int N, KQ, vt, NAMXB;
	char MS[11], TS[200], TG[50], NHAXB[50];
	int chon = -1;
	SACH DSSACH[MAXSIZE];
	SACH sach;

	while (chon != 0)
	{
		printf("\n\n=================================");
		printf("\nChon chuc nang can thuc thi: ");
		scanf_s("%d", &chon);
		printf("\n");

		switch (chon)
		{
		case 1:
			docFileSach(DSSACH, N);
			xuatDSSACH(DSSACH, N);
			break;

		case 2:
			printf("\nNhap thong tin sach can them:\n");
			ThongTinSachThem(DSSACH, N, sach);
			ThemSachCuoi(DSSACH, N, sach);
			xuatDSSACH(DSSACH, N);
			break;

		case 3:
			printf("\nNhap vi tri can them sach: ");
			scanf_s("%d", &vt);
			printf("\nNhap thong tin sach can them:\n");
			ThongTinSachThem(DSSACH, N, sach);
			ThemSach(DSSACH, N, vt, sach);
			xuatDSSACH(DSSACH, N);
			break;

		case 4:
			printf("\nNhap vi tri muon xoa sach: ");
			scanf_s("%d", &vt);
			XoaSach(DSSACH, N, vt);
			xuatDSSACH(DSSACH, N);
			break;

		case 5:
			printf("\nNhap ma sach muon sua: ");
			fflush(stdin);
			gets_s(MS);
			SuaSach(DSSACH, MS, N);
			xuatDSSACH(DSSACH, N);
			break;

		case 6:
			InterchangeSort_TangMaSach(DSSACH, N);
			printf("Ma Sach muon tim kiem: ");
			fflush(stdin);
			gets_s(MS);
			KQ = binarySearchMaSach_DeQuy(DSSACH, 0, N - 1, MS);
			if (KQ == -1)
				printf("\nKhong tim thay sach co ma sach %s trong danh sach.", MS);
			else
			{
				printf("\nTim thay sach co ma %s trong danh sach tai vi tri %d.\n", MS, KQ);
				printf("\nThong tin sach muon tim la: \n");
				xuatThongTinSach(DSSACH[KQ]);
			}
			break;

		case 7:
			InterchangeSort_TangTenSach(DSSACH, N);
			printf("Ten Sach muon tim kiem: ");
			fflush(stdin);
			gets_s(TS);
			KQ = binarySearchTenSach_DeQuy(DSSACH, 0, N - 1, TS);
			if (KQ == -1)
				printf("\nKhong tim thay sach co ten sach %s trong danh sach.", TS);
			else
			{
				printf("\nTim thay sach co ten %s trong danh sach tai vi tri %d.\n", TS, KQ);
				printf("\nThong tin sach muon tim la: \n");
				xuatThongTinSach(DSSACH[KQ]);
			}
			break;

		case 8:
			InterchangeSort_TangMaSach(DSSACH, N);
			printf("Ma Sach muon tim kiem: ");
			fflush(stdin);
			gets_s(MS);
			KQ = binarySearchMaSach_KhuDeQuy(DSSACH, N, MS);
			if (KQ == -1)
				printf("\nKhong tim thay sach co ma sach %s trong danh sach.", MS);
			else
			{
				printf("\nTim thay sach co ma %s trong danh sach tai vi tri %d.\n", MS, KQ);
				printf("\nThong tin sach muon tim la: \n");
				xuatThongTinSach(DSSACH[KQ]);
			}
			break;

		case 9:
			InterchangeSort_TangTenSach(DSSACH, N);
			printf("Ten Sach muon tim kiem: ");
			fflush(stdin);
			gets_s(TS);
			KQ = binarySearchTenSach_KhuDeQuy(DSSACH, N, TS);
			if (KQ == -1)
				printf("\nKhong tim thay sach co ten sach %s trong danh sach.", TS);
			else
			{
				printf("\nTim thay sach co ten %s trong danh sach tai vi tri %d.\n", TS, KQ);
				printf("\nThong tin sach muon tim la: \n");
				xuatThongTinSach(DSSACH[KQ]);
			}
			break;

		case 10:
			InterchangeSort_TangMaSach(DSSACH, N);
			printf("\nDANH SACH SACH THU VIEN TANG DAN THEO MA SACH (INTERCHANGE SORT)");
			xuatDSSACH(DSSACH, N);
			printf("\n\n\n");

			InterchangeSort_GiamMaSach(DSSACH, N);
			printf("\nDANH SACH SACH THU VIEN GIAM DAN THEO MA SACH (INTERCHANGE SORT)");
			xuatDSSACH(DSSACH, N);
			break;

		case 11:
			BubbleSort_TangMaSach(DSSACH, N);
			printf("\nDANH SACH SACH THU VIEN TANG DAN THEO MA SACH (BUBBLE SORT)");
			xuatDSSACH(DSSACH, N);
			printf("\n\n\n");

			BubbleSort_GiamMaSach(DSSACH, N);
			printf("\nDANH SACH SACH THU VIEN GIAM DAN THEO MA SACH (BUBBLE SORT)");
			xuatDSSACH(DSSACH, N);
			break;

		case 12:
			InterchangeSort_TangTenTG(DSSACH, N);
			printf("\nDANH SACH SACH THU VIEN TANG DAN THEO TEN TAC GIA (INTERCHANGE SORT)");
			xuatDSSACH(DSSACH, N);
			printf("\n\n\n");

			InterchangeSort_GiamTenTG(DSSACH, N);
			printf("\nDANH SACH SACH THU VIEN GIAM DAN THEO TEN TAC GIA (INTERCHANGE SORT)");
			xuatDSSACH(DSSACH, N);
			break;

		case 13:
			BubbleSort_TangTenTG(DSSACH, N);
			printf("\nDANH SACH SACH THU VIEN TANG DAN THEO TEN TAC GIA (BUBBLE SORT)");
			xuatDSSACH(DSSACH, N);
			printf("\n\n\n");

			BubbleSort_GiamTenTG(DSSACH, N);
			printf("\nDANH SACH SACH THU VIEN GIAM DAN THEO TEN TAC GIA (BUBBLE SORT)");
			xuatDSSACH(DSSACH, N);
			break;

		case 14:
			printf("\n==========THONG KE SO LUONG SACH THU VIEN THEO NHA XUAT BAN==========");
			SoLuongSach_NhaXB(DSSACH, N);
			printf("\n\n========THONG KE SO LUONG SACH THU VIEN THEO NAM XUAT BAN==========");
			SoLuongSach_NamXB(DSSACH, N);
			printf("\n\n========THONG KE SO LUONG SACH THU VIEN THEO TAC GIA===============");
			SoLuongSach_TacGia(DSSACH, N);
			break;

		case 15:
			xuatTacGia_MaxSach(DSSACH, N);
			xuatNhaXB_MaxSach(DSSACH, N);
			xuatNamXB_MaxSach(DSSACH, N);
			break;

		case 16:
			ghiFileSach(DSSACH, N);
			break;

		case 0:
			exit(0);

		default:
			printf("\nMoi chon lai chuc nang\n");
			break;
		}
	}
}

//==============================================================

//Hàm đọc File DS Sách
void docFileSach(SACH dssach[], int &n)
{
	ifstream in;
	char* filename = "..//QuanLyThuVien//DuLieu//DSSACH.txt";

	in.open(filename);

	if (in)
	{
		in >> n;
		for (int i = 0; i < n; i++)
		{
			in >> dssach[i].maSach;
			in >> dssach[i].tenSach;
			in >> dssach[i].tacgia;
			in >> dssach[i].nhaXB;
			in >> dssach[i].namXB;
		}
	}
	in.close();
}

//Hàm ghi File DS Sách
void ghiFileSach(SACH dssach[], int n)
{
	ofstream out;
	char* filename = "..//QuanLyThuVien//DuLieu//DSSACH_out.txt";
	out.open(filename);

	if (out)
	{
		out << "So luong Sach: " << n << "\n";
		for (int i = 0; i < n; i++)
		{
			out << "Ma Sach: " << dssach[i].maSach << "  " << "Ten sach: " << dssach[i].tenSach << "Ma Sach: " << dssach[i].tacgia << "  " << "Nha xuat ban: " << dssach[i].nhaXB << "Nam xuat ban: " << dssach[i].namXB << "\n";
		}
	}
	out.close();
	printf("\nXuat File thanh cong\n");
}

//Hàm xuất thông tin của DS Sách
void xuatDSSACH(SACH dssach[], int n)
{
	printf("\nSo Sach: %d \n\n DANH SACH SACH \n\n", n);
	printf("\n%-5s%-15s%-25s%-25s%-25s%-15s\n", "STT", "MA SACH", "TEN SACH", "TAC GIA", "NHA XB", "NAMXB");
	for (int i = 0; i < n; i++)
	{
		printf("\n%-5d", i + 1);
		xuatThongTinSach(dssach[i]);
	}
}

//Nhập thông tin Sách ở Thư Viện
void NhapThongTinSach(SACH &s)
{
	printf("\nNhap ma sach: ");
	fflush(stdin);
	gets_s(s.maSach);
	printf("\nNhap ten sach: ");
	fflush(stdin);
	gets_s(s.tenSach);
	printf("\nNhap tac gia: ");
	fflush(stdin);
	gets_s(s.tacgia);
	printf("\nNhap nha xuat ban: ");
	fflush(stdin);
	gets_s(s.nhaXB);
	printf("\nNhap nam xuat ban: ");
	scanf_s("%d", &s.namXB);
		
}

//Xuất thông tin Sách ở Thư viện
void xuatThongTinSach(SACH s)
{
	printf("%-15s%-25s%-25s%-25s%-10d", s.maSach, s.tenSach, s.tacgia, s.nhaXB, s.namXB);
}

//Nhập Danh Sách Sách ở Thư Viện
void nhapDSSach(SACH dssach[], int &n)
{
	do
	{
		printf("\nCho biet so luong sach o thu vien la: ");
		scanf_s("%d", &n);
	} while (n < 0);

	for (int i = 0; i < n; i++)
	{
		NhapThongTinSach(dssach[i]);
	}
}

//=============================================================//

//Hàm kiểm tra mã sách
int kiemTraMaSach(SACH dssach[], int n, char masach[])
{
	for (int i = 0; i < n; i++)
	{
		if (strcmp(masach, dssach[i].maSach) == 0)
		{
			return 0;
		}
	}
	return 1;
}

//Thông Tin Sách được thêm
void ThongTinSachThem(SACH dssach[], int n, SACH &s)
{
	printf("\nNhap ma sach: ");
	fflush(stdin);
	gets_s(s.maSach);
	int kq = kiemTraMaSach(dssach, n, s.maSach);

	if (kq==1)
	{
		printf("\nNhap ten sach: ");
		fflush(stdin);
		gets_s(s.tenSach);
		printf("\nNhap tac gia: ");
		fflush(stdin);
		gets_s(s.tacgia);
		printf("\nNhap nha xuat ban: ");
		fflush(stdin);
		gets_s(s.nhaXB);
		printf("\nNhap nam xuat ban: ");
		scanf_s("%d", &s.namXB);
	}
	else
	{
		printf("\nMa sach da ton tai.\n");
		NhapThongTinSach(s);
	}
}

//Hàm thêm Sách ở vị trí bất kỳ
void ThemSach(SACH dssach[], int &n, int vt, SACH s)
{
	for (int i = n-1; i >= vt; i--)
	{
		dssach[i + 1] = dssach[i];
	}
	dssach[vt] = s;
	n++;
}

//Hàm thêm Sách ở cuối DS
void ThemSachCuoi(SACH dssach[], int &n, SACH s)
{
	dssach[n] = s;
	n++;
}

//Hàm xóa Sách ở vị trí bất kỳ
void XoaSach(SACH dssach[], int &n, int vt)
{
	for (int i = vt+1; i < n; i++)
	{
		dssach[i - 1] = dssach[i];
	}
	n--;
}

//Hàm sửa Sách
void capNhatSach(SACH &s)
{
	printf("\nNhap ten sach: ");
	fflush(stdin);
	gets_s(s.tenSach);
	printf("\nNhap tac gia: ");
	fflush(stdin);
	gets_s(s.tacgia);
	printf("\nNhap nha xuat ban: ");
	fflush(stdin);
	gets_s(s.nhaXB);
	printf("\nNhap nam xuat ban: ");
	scanf_s("%d", &s.namXB);
}

void SuaSach(SACH dssach[], char ms[], int n)
{
	int f = 0;
	for (int i = 0; i < n; i++)
	{
		if (strcmp(ms, dssach[i].maSach) == 0)
		{
			f = 1;
			printf("\nCap nhat thong tin Sach co ma sach la: %s", ms);
			capNhatSach(dssach[i]);
			break;
		}
	}

	if (f == 0)
	{
		printf("\n Sach co ma sach la %c khong ton tai.", ms);
	}
}

//=====================================================================//

//Hàm tìm kiếm Sách theo Mã Sách Binary Search - đệ quy
int binarySearchMaSach_DeQuy(SACH dssach[], int Left, int Right, char masach[])
{
	if (Left > Right)
		 return (-1);
	int Mid = (Left + Right) / 2;
	if (strcmp(dssach[Mid].maSach, masach) == 0)
		return Mid;
	else if (strcmp(dssach[Mid].maSach, masach) > 0)
		return binarySearchMaSach_DeQuy(dssach, Left, Mid - 1, masach);
	else
		return binarySearchMaSach_DeQuy(dssach, Mid + 1, Right, masach);
}

//Hàm tìm kiếm Sách theo Mã Sách Binary Search - khử đệ quy
int binarySearchMaSach_KhuDeQuy(SACH dssach[], int n, char masach[])
{
	int Left = 0, Right = n - 1, Mid;
	while (Left <= Right)
	{
		int Mid = (Left + Right) / 2;
		if (strcmp(dssach[Mid].maSach, masach) == 0)
			return Mid;
		else if (strcmp(dssach[Mid].maSach, masach) > 0)
			Right = Mid - 1;
		else
			Left = Mid + 1;
	}
	return -1;
}

//Hàm tìm kiếm Sách theo Tên Sách Binary Search - đệ quy
int binarySearchTenSach_DeQuy(SACH dssach[], int Left, int Right, char tensach[])
{
	if (Left > Right)
		return (-1);
	int Mid = (Left + Right) / 2;
	if (strcmp(dssach[Mid].tenSach, tensach) == 0)
		return Mid;
	else if (strcmp(dssach[Mid].tenSach, tensach) > 0)
		return binarySearchTenSach_DeQuy(dssach, Left, Mid - 1, tensach);
	else
		return binarySearchTenSach_DeQuy(dssach, Mid + 1, Right, tensach);
}

//Hàm tìm kiếm Sách theo Tên Sách Binary Search - khử đệ quy
int binarySearchTenSach_KhuDeQuy(SACH dssach[], int n, char tensach[])
{
	int Left = 0, Right = n - 1, Mid;
	while (Left <= Right)
	{
		int Mid = (Left + Right) / 2;
		if (strcmp(dssach[Mid].tenSach, tensach) == 0)
			return Mid;
		else if (strcmp(dssach[Mid].tenSach, tensach) > 0)
			Right = Mid - 1;
		else
			Left = Mid + 1;
	}
	return -1;
}


//===============================================================//

//Hàm hoán vị
template <typename T>
void hoanVi(T &a, T &b)
{
	T t = a;
	a = b;
	b = t;
}

//Sắp xếp tăng theo tên sách - Interchange Sort
void InterchangeSort_TangTenSach(SACH dssach[], int n)
{
	for (int i = 0; i < n - 1; i++)
	for (int j = i + 1; j < n; j++)
	if (strcmp(dssach[i].tenSach, dssach[j].tenSach) > 0)
		hoanVi(dssach[i], dssach[j]);
}

//Sắp xếp tăng theo mã sách - Interchange Sort
void InterchangeSort_TangMaSach(SACH dssach[], int n)
{
	for (int i = 0; i < n - 1; i++)
	for (int j = i + 1; j < n; j++)
	if (strcmp(dssach[i].maSach, dssach[j].maSach) > 0)
		hoanVi(dssach[i], dssach[j]);
}

//Sắp xếp giảm theo mã sách - Interchange Sort
void InterchangeSort_GiamMaSach(SACH dssach[], int n)
{
	for (int i = 0; i < n - 1; i++)
	for (int j = i + 1; j < n; j++)
	if (strcmp(dssach[i].maSach, dssach[j].maSach) < 0)
		hoanVi(dssach[i], dssach[j]);
}

//Sắp xếp tăng theo tên tác giả - Interchange Sort
void InterchangeSort_TangTenTG(SACH dssach[], int n)
{
	for (int i = 0; i < n - 1; i++)
	for (int j = i + 1; j < n; j++)
	if (strcmp(dssach[i].tacgia, dssach[j].tacgia) > 0)
		hoanVi(dssach[i], dssach[j]);
}

//Sắp xếp giảm theo tên tác giả - Interchange Sort
void InterchangeSort_GiamTenTG(SACH dssach[], int n)
{
	for (int i = 0; i < n - 1; i++)
	for (int j = i + 1; j < n; j++)
	if (strcmp(dssach[i].tacgia, dssach[j].tacgia) < 0)
		hoanVi(dssach[i], dssach[j]);
}

//Sắp xếp tăng theo mã sách - Bubble Sort
void BubbleSort_TangMaSach(SACH dssach[], int n)
{
	for (int i = 0; i < n - 1; i++) 
	for (int j = n - 1; j > i; j--) 
	if (strcmp(dssach[j].maSach, dssach[j - 1].maSach) < 0)
		hoanVi(dssach[j], dssach[j-1]);
}

//Sắp xếp giảm theo mã sách - Bubble Sort
void BubbleSort_GiamMaSach(SACH dssach[], int n)
{
	for (int i = 0; i < n - 1; i++)
	for (int j = n - 1; j > i; j--)
	if (strcmp(dssach[j].maSach, dssach[j - 1].maSach) > 0)
		hoanVi(dssach[j], dssach[j - 1]);
}

//Sắp xếp tăng theo tên tác giả - Bubble Sort
void BubbleSort_TangTenTG(SACH dssach[], int n)
{
	for (int i = 0; i < n - 1; i++)
	for (int j = n - 1; j > i; j--)
	if (strcmp(dssach[j].tacgia, dssach[j - 1].tacgia) < 0)
		hoanVi(dssach[j], dssach[j - 1]);
}

//Sắp xếp tăng theo tên tác giả - Bubble Sort
void BubbleSort_GiamTenTG(SACH dssach[], int n)
{
	for (int i = 0; i < n - 1; i++)
	for (int j = n - 1; j > i; j--)
	if (strcmp(dssach[j].tacgia, dssach[j - 1].tacgia) > 0)
		hoanVi(dssach[j], dssach[j - 1]);
}


//================================================================

//Thống kê số lượng Sách theo Nhà xuất bản
void SoLuongSach_NhaXB(SACH dssach[], int n)
{ 
	for (int i = 0; i < n; i++)
	{
		bool kt = true; //phần tử phân biệt
		for (int j = i-1; j >= 0; j--)
		{
			if (strcmp(dssach[i].nhaXB, dssach[j].nhaXB) == 0)
			{
				kt = false;
				break;
			}
		}

		if (kt == true)
		{
			int dem = 0;
			//duyệt lại chuỗi ban đầu để đếm số lần xuất hiện
			for (int k = 0; k < n; k++)
			{
				if (strcmp(dssach[i].nhaXB, dssach[k].nhaXB) == 0)
				{
					dem++;
				}
			}
			printf("\nSo luong sach thuoc nha xuat ban %s la: %d", dssach[i].nhaXB, dem);
		}
	}
}

//Thống kê số lượng Sách theo Năm sản xuất
void SoLuongSach_NamXB(SACH dssach[], int n)
{
	for (int i = 0; i < n; i++)
	{
		bool kt = true; //phần tử phân biệt
		for (int j = i - 1; j >= 0; j--)
		{
			if (dssach[i].namXB == dssach[j].namXB)
			{
				kt = false;
				break;
			}
		}

		if (kt == true)
		{
			int dem = 0;
			//duyệt lại chuỗi ban đầu để đếm số lần xuất hiện
			for (int k = 0; k < n; k++)
			{
				if (dssach[i].namXB == dssach[k].namXB)
				{
					dem++;
				}
			}
			printf("\nSo luong sach xuat ban vao nam %d la: %d", dssach[i].namXB, dem);
		}
	}
}

//Thống kê số lượng Sách theo Tác Giả
void SoLuongSach_TacGia(SACH dssach[], int n)
{
	for (int i = 0; i < n; i++)
	{
		bool kt = true; //phần tử phân biệt
		for (int j = i - 1; j >= 0; j--)
		{
			if (strcmp(dssach[i].tacgia, dssach[j].tacgia) == 0)
			{
				kt = false;
				break;
			}
		}

		if (kt == true)
		{
			int dem = 0;
			//duyệt lại chuỗi ban đầu để đếm số lần xuất hiện
			for (int k = 0; k < n; k++)
			{
				if (strcmp(dssach[i].tacgia, dssach[k].tacgia) == 0)
				{
					dem++;
				}
			}
			printf("\nSo luong sach thuoc tac gia %s la: %d", dssach[i].tacgia, dem);
		}
	}
}

//============================================================================

//Đếm số lượng sách mà Tác giả có nhiều sách nhất
void xuatTacGia_MaxSach(SACH dssach[], int n)
{
	int max = 1;
	char tg[50];
	for (int i = 0; i < n; i++)
	{
		int dem = 0;
		for (int j = 0; j < n; j++)
		{
			if (strcmp(dssach[i].tacgia, dssach[j].tacgia) == 0)
				dem++;
		}
		if (max < dem)
		{
			max = dem;
			strcpy_s(tg, dssach[i].tacgia);
		}
	}
	printf("\nTac gia co so luong sach nhieu nhat la: %s voi so luong sach la: %d", tg, max);
}

//Đếm số lượng sách mà nhà xuất bản có nhiều sách nhất
void xuatNhaXB_MaxSach(SACH dssach[], int n)
{
	int max = 1;
	char nhaxb[50];
	for (int i = 0; i < n; i++)
	{
		int dem = 0;
		for (int j = 0; j < n; j++)
		{
			if (strcmp(dssach[i].nhaXB, dssach[j].nhaXB) == 0)
				dem++;
		}
		if (max < dem)
		{
			max = dem;
			strcpy_s(nhaxb, dssach[i].nhaXB);
		}
	}
	printf("\nNha Xuat Ban co so luong sach nhieu nhat la: %s voi so luong sach la: %d", nhaxb, max);
}

//Đếm số lượng sách mà năm có nhiều sách được xuất bản nhất
void xuatNamXB_MaxSach(SACH dssach[], int n)
{
	int max = 1, namxb;
	for (int i = 0; i < n; i++)
	{
		int dem = 0;
		for (int j = 0; j < n; j++)
		{
			if (dssach[i].namXB == dssach[j].namXB)
				dem++;
		}
		if (max < dem)
		{
			max = dem;
			namxb = dssach[i].namXB;
		}
	}
	printf("\nNam xuat ban co so luong sach nhieu nhat la: %d voi so luong sach la: %d", namxb, max);
}

//==============================================