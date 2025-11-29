#include <stdio.h>

void kiemTraSoNguyen()
{
	printf("Kiem Tra So Nguyen");
	printf("\n");
}

void sapXepPhanTuMang()
{
	void sapXepPhanTuMang(); 
	{
		int integerarray[4];
		int leng = 4;

		printf("Nhap 4 phan tu cua mang:\n");
		for (int i = 0; i < leng; i++) {
			printf("mang[%d] = ", i);
			scanf_s("%d", &integerarray[i]); 
		}

		
		for (int i = 0; i < leng - 1; i++) {
			for (int j = i + 1; j < leng; j++) {
				if (integerarray[i] > integerarray[j]) {
					int temp = integerarray[i];
					integerarray[i] = integerarray[j];
					integerarray[j] = temp;
				}
			}
		}

		printf("\nMang sau khi sap xep tang dan:\n");
		for (int i = 0; i < leng; i++) {
			printf("%d ", integerarray[i]);
		}
		printf("\n");
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
		printf("2. Sap xep phan tu mang");
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

