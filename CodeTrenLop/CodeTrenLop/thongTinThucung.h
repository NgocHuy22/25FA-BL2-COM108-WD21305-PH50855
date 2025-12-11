void thongTinThuCung() {
    int maThuCung;
    char tenThuCung[50];
    int namSinh;

    printf("Nhap ma thu cung: ");
    scanf("%d", &maThuCung);

    printf("Nhap ten thu cung: ");
    fflush(stdin);
    gets(tenThuCung);

    printf("Nhap nam sinh: ");
    scanf("%d", &namSinh);


    time_t t = time(NULL);
    struct tm* tm = localtime(&t);
    int namHienTai = tm->tm_year + 1900;

    int tuoi = namHienTai - namSinh;

    printf("\n--- Thong tin thu cung ---\n");
    printf("Ma thu cung: %d\n", maThuCung);
    printf("Ten thu cung: %s\n", tenThuCung);
    printf("Nam sinh: %d\n", namSinh);
    printf("Tuoi: %d\n", tuoi);
}
