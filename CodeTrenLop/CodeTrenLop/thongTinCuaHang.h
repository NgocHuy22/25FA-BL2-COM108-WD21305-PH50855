void thongTinCuaHang() {
    int n;
    float canNang[100];
    float tong = 0;

    printf("Nhap so luong thu cung: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Nhap can nang thu cung thu %d: ", i + 1);
        scanf("%f", &canNang[i]);
        tong += canNang[i];
    }

    float trungBinh = tong / n;
    float min = canNang[0];
    int dem = 0;

    for (int i = 0; i < n; i++) {
        if (canNang[i] < min)
            min = canNang[i];
        if (canNang[i] < trungBinh)
            dem++;
    }

    printf("\nCan nang trung binh: %.2f\n", trungBinh);
    printf("Can nang thap nhat: %.2f\n", min);
    printf("So thu cung duoi muc trung binh: %d\n", dem);
}