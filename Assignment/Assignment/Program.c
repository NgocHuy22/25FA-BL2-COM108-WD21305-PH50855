
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <math.h>
#include <limits.h>


void clear_stdin(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

static void trim_newline(char* s) {
    if (!s) return;
    size_t i = strlen(s);
    while (i > 0 && (s[i - 1] == '\n' || s[i - 1] == '\r' || isspace((unsigned char)s[i - 1]))) {
        s[--i] = '\0';
    }
}


typedef struct {
    char name[128];
    double score;
    char hocLuc[32];
} Student;

static void getHocLuc(double score, char* out, size_t out_sz) {
    if (!out || out_sz == 0) return;
    if (score >= 9.0) strcpy_s(out, out_sz, "Xuat sac");
    else if (score >= 8.0) strcpy_s(out, out_sz, "Gioi");
    else if (score >= 6.5) strcpy_s(out, out_sz, "Kha");
    else if (score >= 5.0) strcpy_s(out, out_sz, "Trung binh");
    else strcpy_s(out, out_sz, "Yeu");
}

static int cmp_desc(const void* a, const void* b) {
    const Student* sa = (const Student*)a;
    const Student* sb = (const Student*)b;
    if (sa->score < sb->score) return 1;
    if (sa->score > sb->score) return -1;
    return 0;
}


void kiemTraSoNguyen()
{
    {
        char buf[128];
        long long x;

        printf("\n=== Chuong nang 1: Kiem tra so nguyen ===\n");

        
        while (1)
        {
            printf("Nhap 1 so nguyen x: ");
            if (!fgets(buf, sizeof(buf), stdin)) return;
            buf[strcspn(buf, "\r\n")] = '\0';

            if (buf[0] == '\0') {
                printf("Vui long nhap mot so.\n");
                continue;
            }

            char* endptr;
            x = strtoll(buf, &endptr, 10);
            while (*endptr && isspace((unsigned char)*endptr)) endptr++;

            if (*endptr != '\0') {
                printf("Nhap khong hop le. Vui long nhap lai.\n");
                continue;
            }
            break;
        }

        printf("\nBan da nhap: %lld\n", x);

      
        printf("- %lld la mot so nguyen.\n", x);

      
        int isPrime = 1;
        if (x < 2) isPrime = 0;
        else {
            for (long long i = 2; i * i <= x; i++) {
                if (x % i == 0) {
                    isPrime = 0;
                    break;
                }
            }
        }
        if (isPrime)
            printf("- %lld la so nguyen to.\n", x);
        else
            printf("- %lld KHONG phai la so nguyen to.\n", x);

        /* 3. Kiểm tra số chính phương */
        long long r = (long long)sqrt((double)x);
        if (r * r == x)
            printf("- %lld la so chinh phuong.\n", x);
        else
            printf("- %lld KHONG phai la so chinh phuong.\n", x);

        printf("\n");
    }
}

void timUochungvaboiSoChung()
{
    int x, y;
    printf("Nhap 2 so nguyen (x y): ");
    if (scanf_s("%d %d", &x, &y) != 2) { printf("Nhap khong hop le.\n"); clear_stdin(); return; }
    clear_stdin();

    int a = x, b = y;
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    int gcd = a;
    long long lcm = 0;
    if (gcd != 0) lcm = ((long long)x / gcd) * (long long)y;
    printf("Uoc so chung lon nhat (GCD) = %d\n", gcd);
    printf("Boi so chung nho nhat (LCM) = %lld\n", lcm);
}

void tinhTienKaraoke()
{
    int start, end;
    const int OPEN = 12, CLOSE = 23;
    const long long PRICE_3H = 150000LL;
    const long long PRICE_PER_HOUR = PRICE_3H / 3;
    const long long PRICE_AFTER_3 = PRICE_PER_HOUR * 70 / 100;

    printf("Nhap gio bat dau (so nguyen 24h): ");
    if (scanf_s("%d", &start) != 1) { printf("Nhap khong hop le.\n"); clear_stdin(); return; }
    printf("Nhap gio ket thuc (so nguyen 24h): ");
    if (scanf_s("%d", &end) != 1) { printf("Nhap khong hop le.\n"); clear_stdin(); return; }
    clear_stdin();

    if (start < OPEN || start >= CLOSE) { printf("Gio bat dau phai nam trong [%d, %d).\n", OPEN, CLOSE); return; }
    if (end <= OPEN || end > CLOSE) { printf("Gio ket thuc phai nam trong (%d, %d].\n", OPEN, CLOSE); return; }
    if (end <= start) { printf("Gio ket thuc phai lon hon gio bat dau.\n"); return; }

    int hours = end - start;
    long long total;
    if (hours <= 3) total = PRICE_3H;
    else total = PRICE_3H + (long long)(hours - 3) * PRICE_AFTER_3;

    printf("\n--- Hoa don tam tinh ---\nGio bat dau: %d, Gio ket thuc: %d\nSo gio su dung: %d\n", start, end, hours);
    if (hours <= 3) printf("Phi: %lld VND (<=3 gio)\n", total);
    else printf("Phi: %lld VND = %lld (3 gio dau) + %d * %lld (tu gio 4 tro di)\n", total, PRICE_3H, hours - 3, PRICE_AFTER_3);

    long long finalTotal = total;
    if (start >= 14 && start <= 17) { finalTotal = (total * 90 + 50) / 100; printf("Ap dung giam 10%%.\n"); }
    printf("Tong tien phai thanh toan: %lld VND\n\n", finalTotal);
}

void tinhTienDien()
{
    long long kwh;
    const long long rate1 = 1678, rate2 = 1734, rate3 = 2014, rate4 = 2536, rate5 = 2834, rate6 = 2927;

    printf("\n--- Tinh tien dien theo bac thang ---\nNhap so kWh da su dung (so nguyen >= 0): ");
    if (scanf_s("%lld", &kwh) != 1) { printf("Nhap khong hop le.\n"); clear_stdin(); return; }
    clear_stdin();
    if (kwh < 0) { printf("So kWh phai la so nguyen duong hoac 0.\n"); return; }

    long long remaining = kwh, total = 0, use;
    use = (remaining > 50) ? 50 : remaining; total += use * rate1; remaining -= use;
    if (remaining > 0) { use = (remaining > 50) ? 50 : remaining; total += use * rate2; remaining -= use; }
    if (remaining > 0) { use = (remaining > 100) ? 100 : remaining; total += use * rate3; remaining -= use; }
    if (remaining > 0) { use = (remaining > 100) ? 100 : remaining; total += use * rate4; remaining -= use; }
    if (remaining > 0) { use = (remaining > 100) ? 100 : remaining; total += use * rate5; remaining -= use; }
    if (remaining > 0) { total += remaining * rate6; remaining = 0; }

    printf("\nSo kWh: %lld kWh\nTong tien dien (chua VAT/phi khac) = %lld VND\n\n", kwh, total);
}

void doiTien()
{
    long long money;
    const int menhGia[] = { 500,200,100,50,20,10,5,2,1 };
    int soTo[9] = { 0 };

    printf("\n Chuong nang doi tien\nNhap so tien can doi: ");
    if (scanf_s("%lld", &money) != 1) { printf("Nhap khong hop le.\n"); clear_stdin(); return; }
    clear_stdin();
    if (money <= 0) { printf("So tien phai lon hon 0.\n"); return; }

    long long remaining = money;
    for (int i = 0; i < 9; ++i) {
        if (remaining >= menhGia[i]) { soTo[i] = (int)(remaining / menhGia[i]); remaining %= menhGia[i]; }
    }
    printf("\nDoi %lld thanh:\n", money);
    for (int i = 0; i < 9; ++i) if (soTo[i] > 0) printf("%d to %d\n", soTo[i], menhGia[i]);
    printf("\n");
}

void tinhLaiVay()
{
    long long tienVay;
    const double laiSuat = 0.05;
    const int soThang = 12;

    printf("\n--- Chuong trinh tinh lai vay ngan hang tra gop ---\nNhap so tien muon vay: ");
    if (scanf_s("%lld", &tienVay) != 1 || tienVay <= 0) { printf("Nhap khong hop le.\n"); clear_stdin(); return; }
    clear_stdin();

    double gocPhaiTraMoiThang = (double)tienVay / soThang;
    double tienConLai = tienVay;
    printf("\n%-10s %-15s %-15s %-18s %-15s\n", "Ky han", "Lai phai tra", "Goc phai tra", "So tien phai tra", "Con lai");
    for (int thang = 1; thang <= soThang; ++thang) {
        double laiPhaiTra = tienConLai * laiSuat;
        double tongPhaiTra = gocPhaiTraMoiThang + laiPhaiTra;
        printf("%-10d %-15.0f %-15.0f %-18.0f %-15.0f\n", thang, laiPhaiTra, gocPhaiTraMoiThang, tongPhaiTra, tienConLai - gocPhaiTraMoiThang);
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

    printf("Vay tien mua xe\nGia xe mac dinh: %lld VND\nNhap so phan tram muon vay (0-100): ", PRICE);
    if (!fgets(buf, sizeof buf, stdin)) { printf("Khong doc duoc du lieu.\n"); return; }
    trim_newline(buf);
    if (buf[0] == '\0') { printf("Nhap khong hop le.\n"); return; }

    errno = 0;
    char* endptr;
    percent = (long)strtol(buf, &endptr, 10);
    if (endptr == buf || *endptr != '\0') { printf("Nhap khong hop le.\n"); return; }
    if (percent < 0 || percent > 100) { printf("Nhap phan tram trong khoang 0-100.\n"); return; }

    long long downPayment = PRICE * (100 - percent) / 100;
    long long loanAmount = PRICE - downPayment;
    double monthlyRate = ANNUAL_RATE / 100.0 / 12.0;
    double monthlyPayment;
    if (monthlyRate == 0) monthlyPayment = loanAmount / (double)MONTHS;
    else {
        double r = monthlyRate;
        double pow_r_n = pow(1 + r, MONTHS);
        monthlyPayment = loanAmount * (r * pow_r_n) / (pow_r_n - 1);
    }

    printf("\nTien tra truoc: %lld VND\nSo tien vay: %lld VND\nTra moi thang: %.0f VND\n\n", downPayment, loanAmount, monthlyPayment);
}


void sapXepThongTinSV(void)
{
    char buf[256];
    long n = 0;

    printf("\n--- Nhap danh sach sinh vien ---\n");

   
    do {
        printf("Nhap so luong sinh vien: ");
        if (!fgets(buf, sizeof(buf), stdin)) { printf("Doc du lieu that bai.\n"); return; }
        trim_newline(buf);
        if (buf[0] == '\0') { printf("Vui long nhap mot so.\n"); continue; }

        char* endptr = NULL;
        long temp = strtol(buf, &endptr, 10);
        while (endptr && *endptr && isspace((unsigned char)*endptr)) endptr++;
        if (endptr && *endptr != '\0') { printf("Nhap khong hop le. Vui long nhap lai.\n"); n = 0; continue; }
        if (temp <= 0) { printf("So luong phai la so nguyen duong.\n"); n = 0; continue; }
        if (temp > 10000) { printf("So luong qua lon (toi da 10000). Vui long nhap lai.\n"); n = 0; continue; }
        n = temp;
    } while (n <= 0);

    Student* arr = (Student*)calloc((size_t)n, sizeof(Student));
    if (!arr) { printf("Cap phat bo nho that bai.\n"); return; }

    for (long i = 0; i < n; ++i) {
        printf("\nSinh vien %ld:\n", i + 1);

       
        printf("  Ho va ten: ");
        if (!fgets(arr[i].name, (int)sizeof(arr[i].name), stdin)) {
            
            strcpy_s(arr[i].name, sizeof arr[i].name, "(Khong ro)");
        }
        else {
           
            arr[i].name[strcspn(arr[i].name, "\r\n")] = '\0';
            if (arr[i].name[0] == '\0') {
               
                strcpy_s(arr[i].name, sizeof arr[i].name, "(Khong ro)");
            }
        }

        
        while (1) {
            printf("  Diem (vd: 7.5): ");
            if (!fgets(buf, sizeof(buf), stdin)) { arr[i].score = 0.0; break; }
            trim_newline(buf);
            if (buf[0] == '\0') { arr[i].score = 0.0; break; }

            char* p = NULL;
            double val = strtod(buf, &p);
            while (p && *p && isspace((unsigned char)*p)) p++;
            if (p == buf || (p && *p != '\0')) {
                printf("  Nhap diem khong hop le. Vui long nhap lai.\n");
                continue;
            }
            arr[i].score = val;
            break;
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
void gameFPOLY_LOTT()
{
    char buf[64];
    int so1, so2;

    printf("\n=== Game FPOLY-LOTT ===\n");
    printf("Nhap 2 so tu 1-15\n");

    
    while (1) {
        printf("Nhap so thu 1 (1-15): ");
        if (!fgets(buf, sizeof(buf), stdin)) return;
        so1 = (int)strtol(buf, NULL, 10);
        if (so1 >= 1 && so1 <= 15) break;
        printf("So khong hop le. Vui long nhap lai.\n");
    }

 
    while (1) {
        printf("Nhap so thu 2 (1-15): ");
        if (!fgets(buf, sizeof(buf), stdin)) return;
        so2 = (int)strtol(buf, NULL, 10);
        if (so2 >= 1 && so2 <= 15) break;
        printf("So khong hop le. Vui long nhap lai.\n");
    }

    
    srand((unsigned int)time(NULL));
    int r1 = rand() % 15 + 1;
    int r2;
    do {
        r2 = rand() % 15 + 1;
    } while (r2 == r1);

    printf("\nSo cua ban: %d - %d\n", so1, so2);
    printf("So cua he thong: %d - %d\n", r1, r2);

 
    int count = 0;
    if (so1 == r1 || so1 == r2) count++;
    if (so2 == r1 || so2 == r2) count++;

    printf("\n=== Ket qua ===\n");
    if (count == 2)
        printf("Chuc mung ban da trung GIAI NHAT!\n");
    else if (count == 1)
        printf("Chuc mung ban da trung GIAI NHI!\n");
    else
        printf("Chuc ban may man lan sau!\n");

    printf("\n");
}
static long long ll_gcd(long long a, long long b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    if (b == 0) return a;
    while (b) {
        long long t = a % b;
        a = b;
        b = t;
    }
    return a;
}


static void simplify_frac(long long* num, long long* den) {
    if (*den == 0) return; 
    if (*den < 0) { *den = -(*den); *num = -(*num); }
    long long g = ll_gcd(*num, *den);
    if (g > 0) { *num /= g; *den /= g; }
}


static int parse_fraction(const char* s, long long* num, long long* den) {
    if (!s) return 0;
    
    while (isspace((unsigned char)*s)) s++;
    if (*s == '\0') return 0;

    char tmp[128];
    strncpy_s(tmp, sizeof(tmp), s, _TRUNCATE);
    tmp[sizeof(tmp) - 1] = '\0';
    
    tmp[strcspn(tmp, "\r\n")] = '\0';

    char* slash = strchr(tmp, '/');
    if (!slash) {
        
        char* endptr;
        errno = 0;
        long long a = strtoll(tmp, &endptr, 10);
        if (endptr == tmp || *endptr != '\0') return 0;
        *num = a; *den = 1;
        simplify_frac(num, den);
        return 1;
    }
    else {
        *slash = '\0';
        char* left = tmp;
        char* right = slash + 1;
        
        while (left && isspace((unsigned char)*left)) left++;
        char* lend = left + strlen(left) - 1;
        while (lend > left && isspace((unsigned char)*lend)) { *lend = '\0'; lend--; }
        while (right && isspace((unsigned char)*right)) right++;
        char* rend = right + strlen(right) - 1;
        while (rend > right && isspace((unsigned char)*rend)) { *rend = '\0'; rend--; }

        char* endptr;
        errno = 0;
        long long a = strtoll(left, &endptr, 10);
        if (endptr == left || *endptr != '\0') return 0;
        errno = 0;
        long long b = strtoll(right, &endptr, 10);
        if (endptr == right || *endptr != '\0') return 0;
        if (b == 0) return 0; 
        *num = a; *den = b;
        simplify_frac(num, den);
        return 1;
    }
}


static void print_frac(long long num, long long den) {
    if (den == 0) {
        printf("Invalid(den=0)");
        return;
    }
    if (den == 1) printf("%lld", num);
    else printf("%lld/%lld", num, den);
}
void tinhToanPhanSo(void)
{
    char buf[256];
    long long a_num = 0, a_den = 1, b_num = 0, b_den = 1;

    printf("\n--- Chuong trinh tinh toan phan so ---\n");
    /* read first fraction */
    while (1) {
        printf("Nhap phan so thu 1 (dang a/b hoac so nguyen): ");
        if (!fgets(buf, sizeof(buf), stdin)) return;
        trim_newline(buf);
        if (buf[0] == '\0') { printf("Vui long nhap mot phan so.\n"); continue; }
        if (!parse_fraction(buf, &a_num, &a_den)) { printf("Nhap khong hop le. Vui long nhap lai.\n"); continue; }
        break;
    }

    /* read second fraction */
    while (1) {
        printf("Nhap phan so thu 2 (dang a/b hoac so nguyen): ");
        if (!fgets(buf, sizeof(buf), stdin)) return;
        trim_newline(buf);
        if (buf[0] == '\0') { printf("Vui long nhap mot phan so.\n"); continue; }
        if (!parse_fraction(buf, &b_num, &b_den)) { printf("Nhap khong hop le (hoac 0 la mau so). Vui long nhap lai.\n"); continue; }
        break;
    }

    printf("\nPhan so 1: ");
    print_frac(a_num, a_den);
    printf("\nPhan so 2: ");
    print_frac(b_num, b_den);
    printf("\n\n");

    /* sum: a/b + c/d = (ad + bc) / bd */
    long long sum_num = a_num * b_den + b_num * a_den;
    long long sum_den = a_den * b_den;
    simplify_frac(&sum_num, &sum_den);

    /* diff: a/b - c/d = (ad - bc) / bd */
    long long diff_num = a_num * b_den - b_num * a_den;
    long long diff_den = a_den * b_den;
    simplify_frac(&diff_num, &diff_den);

    /* prod: (a*c) / (b*d) */
    long long prod_num = a_num * b_num;
    long long prod_den = a_den * b_den;
    simplify_frac(&prod_num, &prod_den);

    /* quotient: (a/b) / (c/d) = (a*d) / (b*c) ; check division by zero */
    int can_divide = 1;
    long long quot_num = 0, quot_den = 1;
    if (b_num == 0) {
        can_divide = 0;
    }
    else {
        quot_num = a_num * b_den;
        quot_den = a_den * b_num;
        if (quot_den == 0) can_divide = 0;
        else simplify_frac(&quot_num, &quot_den);
    }

    /* print results */
    printf("Ket qua:\n");
    printf("Tong:    "); print_frac(sum_num, sum_den); printf(" = %.6f\n", (double)sum_num / (double)sum_den);
    printf("Hieu:    "); print_frac(diff_num, diff_den); printf(" = %.6f\n", (double)diff_num / (double)diff_den);
    printf("Tich:    "); print_frac(prod_num, prod_den); printf(" = %.6f\n", (double)prod_num / (double)prod_den);
    if (can_divide) {
        printf("Thuong:  "); print_frac(quot_num, quot_den); printf(" = %.6f\n", (double)quot_num / (double)quot_den);
    }
    else {
        printf("Thuong:  Khong the thuc hien (chia cho 0)\n");
    }

    printf("\n");
}





void lapChucNang(int chonChucNang)
{
    char buf[32];
    int tiepTuc = 1;

    while (tiepTuc == 1) {
        switch (chonChucNang) {
        case 1: kiemTraSoNguyen();
            break;
        case 2: timUochungvaboiSoChung();
            break;
        case 3: tinhTienKaraoke();
            break;
        case 4: tinhTienDien(); 
            break;
        case 5: doiTien();
            break;
        case 6: tinhLaiVay(); 
            break;
        case 7: tinhVayTienMuaXe();
            break;
        case 8: sapXepThongTinSV(); 
            break;
        case 9: gameFPOLY_LOTT(); 
            break;
        case 10: tinhToanPhanSo(); 
            break;
        default: printf("Chon sai. Chuc nang hop le [0-10]\n"); 
            break;
        }

       
        printf("Tiep tuc thuc hien chuc nang nay? [1=Co | 0=Khong]: ");
        if (!fgets(buf, sizeof(buf), stdin)) { tiepTuc = 0; break; }
        trim_newline(buf);
        if (buf[0] == '\0') { tiepTuc = 0; break; }
        char* endptr = NULL;
        long val = strtol(buf, &endptr, 10);
        if (endptr == buf || (endptr && *endptr != '\0')) { tiepTuc = 0; break; }
        tiepTuc = (val == 1) ? 1 : 0;
    }
}


int main(void)
{
    char buf[64];
    int chonChucNang = -1;

    for (;;) {
        printf("Menu\n");
        printf("1. Kiem Tra So Nguyen\n");
        printf("2. Tim uoc so chung va boi so chung cua 2 so\n");
        printf("3. Chuong trinh tinh tien cho quan Karaoke\n");
        printf("4. Tinh tien dien\n");
        printf("5. Chuc nang doi tien\n");
        printf("6. Chuc nang tinh lai suat vay ngan hang vat tra gop\n");
        printf("7. Chuong trinh vay tien mua xe\n");
        printf("8. Sap xep thong tin sinh vien\n");
        printf("9. Game FPOLY-LOTT\n");
        printf("10.Chuong trinh tinh toan phan so\n");
        printf("0. Thoat\n");
        printf("Hay chon chuc nang [0-10]: ");

        if (!fgets(buf, sizeof(buf), stdin)) break;
        trim_newline(buf);
        if (buf[0] == '\0') continue;
        char* endptr = NULL;
        long tmp = strtol(buf, &endptr, 10);
        if (endptr == buf || (endptr && *endptr != '\0')) {
            printf("Nhap khong hop le. Vui long nhap so.\n");
            continue;
        }
        chonChucNang = (int)tmp;
        if (chonChucNang == 0) break;
        if (chonChucNang < 0 || chonChucNang > 10) {
            printf("Chuc nang hop le [0-10]. Vui long chon lai.\n");
            continue;
        }

        lapChucNang(chonChucNang);
    }

    printf("Thoat chuong trinh. Tam biet!\n");
    return 0;
} 