#include <stdio.h>
#include <time.h>
#include "thongTinThucung.h"
#include "tinhTong.h"   
#include "thongTinCuaHang.h"    



int main() {
    int chon;
    do {
        printf("MENU\n");
        printf("1. Thong tin thu cung\n");
        printf("2. Tinh tong\n");
        printf("3. Thong tin cua hang\n");
        printf("0. Thoat\n");
        printf("Moi chon: ");
        scanf("%d", &chon);

        switch (chon) {
        case 1:
            thongTinThuCung();
            break;
        case 2:
            tinhTong();
            break;
        case 3:
            thongTinCuaHang();
            break;
        case 0:
            printf("Da thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le!\n");
        }
    } while (chon != 0);

    return 0;
}
