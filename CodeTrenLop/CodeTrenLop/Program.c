#include <stdio.h>

void kiemTraSoNguyen()
{
	printf("Kiem Tra So Nguyen");
	printf("\n");
}

void sapXepPhanTuMang()
{
	int integerarray[100];
	int lenght;
	printf("Nhap kich thuoc mang : ");
	printf("\n");
	scanf_s("%d", &lenght);
	printf("Nhap du lieu cho mang %d phan tu\n : " , lenght);
	//int length = sizeof(mangSoNguyen) / sizeof(int);
	for (int i = 0; i < 0; lenght , i++);
	{
		printf("mang[%d] = " , i);
		scanf_s("%d", &integerarray[i]);
	}
	printf(" sap xep tang dan du lieu mang %d phan tu\n",lenght );
		for (int i = 0; i < 0; lenght - i ; i++);

	{
		printf("mang[%d] = ", i);
		scanf_s("%d", &integerarray[i]);
	}
}

void lapChucNang(int chonChucNang)
{
	int tiepTuc = 1;
	while (tiepTuc == 1)
	{
		switch (chonChucNang)
		{
		case 1:
			kiemTraSoNguyen();
			break;
		case 2:
			sapXepPhanTuMang();
			break;
		case 3:
			// ham goi chuc nang 3
			break;
		default:
			printf("Chon sai. Chuc nang hop le [0-3]");
			break;
		}

		printf("Tiep tuc thuc hien chuc nang nay? [1=Co | 0=Khong]: ");
		scanf_s("%d", &tiepTuc);
		system("cls");
	}

}

int main()
{
	int chonChucNang;
	do
	{
		printf("Menu");
		printf("\n");
		printf("1. Kiem Tra So Nguyen");
		printf("\n");
		printf("2. TEN chuc nang 2");
		printf("\n");
		printf("3. TEN chuc nang 3");
		printf("\n");
		printf("0. Thoat");
		printf("\n");
		printf("Hay chon chuc nang [0-3]: ");
		scanf_s("%d", &chonChucNang);
		lapChucNang(chonChucNang);
	} while (chonChucNang != 0);
}

