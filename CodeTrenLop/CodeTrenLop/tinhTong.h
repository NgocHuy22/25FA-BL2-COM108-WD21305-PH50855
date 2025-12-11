void tinhTong() {
    int n;
    printf("Nhap so nguyen duong n (n > 3): ");
    scanf("%d", &n);

    if (n <= 3) {
        printf("n khong hop le!\n");
        return;
    }

    int tong = 0;
    for (int i = 1; i <= n; i++) {
        if (i % 2 != 0)
            tong += i;
    }

    printf("Tong cac so le tu 1 den %d la: %d\n", n, tong);

    if (n % 5 == 0)
        printf("%d chia het cho 5\n", n);
    else
        printf("%d khong chia het cho 5\n", n);
}
