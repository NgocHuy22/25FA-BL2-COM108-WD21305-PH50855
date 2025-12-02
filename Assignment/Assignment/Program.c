#include <stdio.h>
#include <errno.h> 
#include <math.h> 
#include <ctype.h>
void kiemTraSoNguyen()
{
	printf("Kiem Tra So Nguyen");
	printf("\n");
}
void timUochungvaboiSoChung()
{
	int x, y;
	printf("Nhap 2 so nguyen (x y): ");
	scanf_s("%d %d", &x, &y);

	int a = x, b = y;

	// Tính GCD bằng thuật toán Euclid
	while (b != 0) {
		int temp = a % b;
		a = b;
		b = temp;
	}

	int gcd = a;
	int lcm = (x * y) / gcd;

	printf("Uoc so chung lon nhat (GCD) = %d\n", gcd);
	printf("Boi so chung nho nhat (LCM) = %d\n", lcm);
}
void xoaDuLieuNhapConLai() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

void tinhTienKaraoke()
{
	int start, end;
	const int OPEN = 12;
	const int CLOSE = 23;
	const long long PRICE_3H = 150000LL;       
	const long long PRICE_PER_HOUR = PRICE_3H / 3; 
	const long long PRICE_AFTER_3 = PRICE_PER_HOUR * 70 / 100; 

	printf("Nhap gio bat dau (so nguyen 24h): ");
	if (scanf_s("%d", &start) != 1) { printf("Nhap khong hop le.\n"); xoaDuLieuNhapConLai(); return; }
	printf("Nhap gio ket thuc (so nguyen 24h): ");
	if (scanf_s("%d", &end) != 1) { printf("Nhap khong hop le.\n"); xoaDuLieuNhapConLai(); return; }
	xoaDuLieuNhapConLai();

	
	if (start < OPEN || start >= CLOSE) {
		printf("Gio bat dau phai nam trong [%d, %d).\n", OPEN, CLOSE);
		return;
	}
	if (end <= OPEN || end > CLOSE) {
		printf("Gio ket thuc phai nam trong (%d, %d].\n", OPEN, CLOSE);
		return;
	}
	if (end <= start) {
		printf("Gio ket thuc phai lon hon gio bat dau.\n");
		return;
	}

	int hours = end - start;
	long long total;
	if (hours <= 3) total = PRICE_3H;
	else total = PRICE_3H + (long long)(hours - 3) * PRICE_AFTER_3;

	printf("\n--- Hoa don tam tinh ---\n");
	printf("Gio bat dau: %d, Gio ket thuc: %d\n", start, end);
	printf("So gio su dung: %d\n", hours);
	if (hours <= 3) {
		printf("Phi: %lld VND (<=3 gio)\n", total);
	}
	else {
		printf("Phi: %lld VND = %lld (3 gio dau) + %d * %lld (tu gio 4 tro di)\n",
			total, PRICE_3H, hours - 3, PRICE_AFTER_3);
	}

	long long finalTotal = total;
	if (start >= 14 && start <= 17) {
		finalTotal = (total * 90 + 50) / 100; 
		printf("Ap dung giam 10%% vi gio bat dau nam trong [14,17].\n");
	}
	else {
		printf("Khong ap dung giam them 10%%.\n");
	}

	printf("Tong tien phai thanh toan: %lld VND\n", finalTotal);
	printf("\n");
}
void clear_stdin()
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}
void tinhTienDien()
{
	long long kwh;
	
	const long long rate1 = 1678;
	const long long rate2 = 1734; 
	const long long rate3 = 2014; 
	const long long rate4 = 2536; 
	const long long rate5 = 2834; 
	const long long rate6 = 2927; 

	printf("\n--- Tinh tien dien theo bac thang ---\n");
	printf("Nhap so kWh da su dung (so nguyen >= 0): ");
	if (scanf_s("%lld", &kwh) != 1) {
		printf("Nhap khong hop le.\n");
		clear_stdin();
		return;
	}
	clear_stdin();

	if (kwh < 0) {
		printf("So kWh phai la so nguyen duong hoac 0.\n");
		return;
	}

	long long remaining = kwh;
	long long total = 0;

	
	long long use = (remaining > 50) ? 50 : remaining;
	total += use * rate1;
	remaining -= use;

	
	if (remaining > 0) {
		use = (remaining > 50) ? 50 : remaining;
		total += use * rate2;
		remaining -= use;
	}

	
	if (remaining > 0) {
		use = (remaining > 100) ? 100 : remaining;
		total += use * rate3;
		remaining -= use;
	}

	
	if (remaining > 0) {
		use = (remaining > 100) ? 100 : remaining;
		total += use * rate4;
		remaining -= use;
	}

	
	if (remaining > 0) {
		use = (remaining > 100) ? 100 : remaining;
		total += use * rate5;
		remaining -= use;
	}

	
	if (remaining > 0) {
		total += remaining * rate6;
		remaining = 0;
	}

	
	printf("\nSo kWh: %lld kWh\n", kwh);
	printf("Tong tien dien (chua VAT/phi khac) = %lld VND\n", total);
	printf("\n");
}
void doiTien()
{
	long long money;
	const int menhGia[] = { 500, 200, 100, 50, 20, 10, 5, 2, 1 };
	int soTo[9] = { 0 };

	printf("\n Chuong nang doi tien\n");
	printf("Nhap so tien can doi: ");

	if (scanf_s("%lld", &money) != 1) 
	{
		printf("Nhap khong hop le.\n");
		clear_stdin();
		return;
	}
	clear_stdin();

	if (money <= 0) {
		printf("So tien phai lon hon 0.\n");
		return;
	}

	long long remaining = money;

	for (int i = 0; i < 9; i++) {
		if (remaining >= menhGia[i]) {
			soTo[i] = remaining / menhGia[i];
			remaining %= menhGia[i];
		}
	}

	
	printf("\nDoi %lld thanh:\n", money);
	for (int i = 0; i < 9; i++) {
		if (soTo[i] > 0) {
			printf("%d to %d\n", soTo[i], menhGia[i]);
		}
	}
	printf("\n");
}
void tinhLaiVay()
{
	long long tienVay;
	const double laiSuat = 0.05;  
	const int soThang = 12;

	printf("\n--- Chuong trinh tinh lai vay ngan hang tra gop ---\n");
	printf("Nhap so tien muon vay: ");

	if (scanf_s("%lld", &tienVay) != 1 || tienVay <= 0) {
		printf("Nhap khong hop le.\n");
		clear_stdin();
		return;
	}
	clear_stdin();

	double gocPhaiTraMoiThang = (double)tienVay / soThang;
	double tienConLai = tienVay;

	printf("\n%-10s %-15s %-15s %-18s %-15s\n",
		"Ky han", "Lai phai tra", "Goc phai tra", "So tien phai tra", "Con lai");

	for (int thang = 1; thang <= soThang; thang++)
	{
		double laiPhaiTra = tienConLai * laiSuat;
		double tongPhaiTra = gocPhaiTraMoiThang + laiPhaiTra;

		
		printf("%-10d %-15.0f %-15.0f %-18.0f %-15.0f\n",
			thang, laiPhaiTra, gocPhaiTraMoiThang, tongPhaiTra,
			tienConLai - gocPhaiTraMoiThang);

		tienConLai -= gocPhaiTraMoiThang;
	}

	printf("\n");
}
void tinhVayTienMuaXe()
{
	const long long PRICE = 500000000LL;
	const int YEARS = 24;
	const int MONTHS = YEARS * 12;
	const double ANNUAL_RATE = 7.2;

	char buf[128];
	long percent;

	printf("Vay tien mua xe\n");
	printf("Gia xe mac dinh: %lld VND\n", PRICE);
	printf("Nhap so phan tram muon vay (0-100). Vi du 80 = vay 80%%, tra truoc 20%%: ");

	clear_stdin();   

	if (!fgets(buf, sizeof(buf), stdin)) 
	{
		printf("Khong doc duoc du lieu.\n");
		return;
	}

	buf[strcspn(buf, "\r\n")] = '\0';

	errno = 0;
	char* endptr;
	percent = strtol(buf, &endptr, 10);

	if (endptr == buf) {
		printf("Nhap khong hop le: khong co so.\n");
		return;
	}

	if (percent < 0 || percent > 100) {
		printf("Nhap phan tram trong khoang 0-100.\n");
		return;
	}

	long long downPayment = PRICE * (100 - percent) / 100;
	long long loanAmount = PRICE - downPayment;

	double monthlyRate = ANNUAL_RATE / 100 / 12.0;
	double monthlyPayment;

	if (monthlyRate == 0)
		monthlyPayment = loanAmount / (double)MONTHS;
	else {
		double r = monthlyRate;
		double pow_r_n = pow(1 + r, MONTHS);
		monthlyPayment = loanAmount * (r * pow_r_n) / (pow_r_n - 1);
	}

	printf("\nTien tra truoc: %lld VND\n", downPayment);
	printf("So tien vay: %lld VND\n", loanAmount);
	printf("Tra moi thang: %.0f VND\n", monthlyPayment);
}
void sapXepThongTinSV() 
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}

typedef struct {
	char name[128];
	double score;
	char hocLuc[32];
} Student;


void trim_newline(char* s) {
	size_t i = strlen(s);
	while (i > 0 && (s[i - 1] == '\n' || s[i - 1] == '\r' || isspace((unsigned char)s[i - 1]))) {
		s[--i] = '\0';
	}
}


void getHocLuc(double score, char* out, size_t out_sz) {
	if (score >= 9.0) strncpy(out, "Xuat sac", out_sz);
	else if (score >= 8.0) strncpy(out, "Gioi", out_sz);
	else if (score >= 6.5) strncpy(out, "Kha", out_sz);
	else if (score >= 5.0) strncpy(out, "Trung binh", out_sz);
	else strncpy(out, "Yeu", out_sz);
	out[out_sz - 1] = '\0';
}


int cmp_desc(const void* a, const void* b) {
	const Student* sa = (const Student*)a;
	const Student* sb = (const Student*)b;
	if (sa->score < sb->score) return 1;
	if (sa->score > sb->score) return -1;
	return 0;
}


void sapXepSinhVien()
{
	char buf[256];
	long n;

	printf("\n--- Nhap danh sach sinh vien ---\n");
	printf("Nhap so luong sinh vien: ");
	if (!fgets(buf, sizeof(buf), stdin)) {
		printf("Doc du lieu that bai.\n");
		return;
	}
	
	n = strtol(buf, NULL, 10);
	if (n <= 0) {
		printf("So luong phai la so nguyen duong.\n");
		return;
	}

	Student* arr = (Student*)malloc(sizeof(Student) * n);
	if (!arr) {
		printf("Cap phat bo nho that bai.\n");
		return;
	}

	for (long i = 0; i < n; ++i) {
		printf("\nSinh vien %ld:\n", i + 1);

		
		printf("  Ho va ten: ");
		if (!fgets(arr[i].name, sizeof(arr[i].name), stdin)) {
			printf("  Doc ten that bai.\n");
			arr[i].name[0] = '\0';
		}
		trim_newline(arr[i].name);
		if (arr[i].name[0] == '\0') {
		
			strcpy(arr[i].name, "(Khong ro)");
		}

		
		printf("  Diem (vd: 7.5): ");
		if (!fgets(buf, sizeof(buf), stdin)) {
			printf("  Doc diem that bai.\n");
			arr[i].score = 0.0;
		}
		else {
			
			char* p = NULL;
			double val = strtod(buf, &p);
			
			while (*p != '\0' && isspace((unsigned char)*p)) p++;
			if (p == buf || (*p != '\0' && *p != '\n' && *p != '\r')) {
				printf("  Nhap diem khong hop le. Dat diem = 0.\n");
				arr[i].score = 0.0;
			}
			else {
				arr[i].score = val;
			}
		}

		getHocLuc(arr[i].score, arr[i].hocLuc, sizeof(arr[i].hocLuc));
	}


	qsort(arr, (size_t)n, sizeof(Student), cmp_desc);

	
	printf("\n--- Danh sach sau khi sap xep (giam dan theo diem) ---\n");
	printf("%-4s %-30s %-8s %-12s\n", "STT", "Ho va ten", "Diem", "Hoc luc");
	for (long i = 0; i < n; ++i) {
		printf("%-4ld %-30s %-8.2f %-12s\n", i + 1, arr[i].name, arr[i].score, arr[i].hocLuc);
	}

	free(arr);
	printf("\n");
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
			timUochungvaboiSoChung();
			break;
		case 3:
			tinhTienKaraoke();
			break;
		case 4:
			tinhTienDien();
			break;
		case 5:
			doiTien();
			break;
		case 6:
			tinhLaiVay();
			break;
		case 7:
			tinhVayTienMuaXe();	
			break;
		case 8:
			sapXepThongTinSV();
			break;
		case 9:
			// ham goi chuc nang 3
			break;
		case 10:
			// ham goi chuc nang 3
			break;
		default:
			printf("Chon sai. Chuc nang hop le [1-10]");
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
		printf("2. Tim uoc so chung va boi so chung cua 2 so");
		printf("\n");
		printf("3. Chuong trinh tinh tien cho quan Karaoke");
		printf("\n");
		printf("4. Tinh tien dien");
		printf("\n");
		printf("5. Chuc nang doi tien");
		printf("\n");
		printf("6. Chuc nang tinh lai suat vay ngan hang vat tra gop");
		printf("\n");
		printf("7. Chuong trinh vay tien mua xe");
		printf("\n");
		printf("8. Sap xep thong tin sinh vien ");
		printf("\n");
		printf("9.Game FPOLY-LOTT");
		printf("\n");
		printf("Chuong trinh tinh toan phan so ");
		printf("\n");

		printf("0. Thoat");
		printf("\n");
		printf("Hay chon chuc nang [1-10]: ");
		scanf_s("%d", &chonChucNang);
		lapChucNang(chonChucNang);
	} while (chonChucNang != 0);
}
