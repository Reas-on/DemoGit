#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct SinhVien {
    int maSinhVien;
    char hoTen[50];
    char ngaySinh[20];
    char gioiTinh[10];
    float diem;
};

void nhapDanhSachSinhVien(struct SinhVien danhSach[], int *soLuong) {
    int i = 0;
    while (1) {
        printf("Nhap ma sinh vien (nhap 0 de ket thuc): ");
        scanf("%d", &danhSach[i].maSinhVien);
        if (danhSach[i].maSinhVien == 0) {
            break;
        }
        printf("Nhap ho ten: ");
        scanf(" %[^\n]s", danhSach[i].hoTen);
        printf("Nhap ngay sinh: ");
        scanf(" %[^\n]s", danhSach[i].ngaySinh);
        printf("Nhap gioi tinh: ");
        scanf(" %[^\n]s", danhSach[i].gioiTinh);
        printf("Nhap diem: ");
        scanf("%f", &danhSach[i].diem);
        i++;
    }
    *soLuong = i;
}

void sapXepTheoDiem(struct SinhVien danhSach[], int soLuong) {
    struct SinhVien temp;
    for (int i = 0; i < soLuong - 1; i++) {
        for (int j = i + 1; j < soLuong; j++) {
            if (danhSach[i].diem > danhSach[j].diem) {
                temp = danhSach[i];
                danhSach[i] = danhSach[j];
                danhSach[j] = temp;
            }
        }
    }
}

void chenSinhVien(struct SinhVien danhSach[], int *soLuong) {
    struct SinhVien sv;
    printf("Nhap ma sinh vien: ");
    scanf("%d", &sv.maSinhVien);
    printf("Nhap ho ten: ");
    scanf(" %[^\n]s", sv.hoTen);
    printf("Nhap ngay sinh: ");
    scanf(" %[^\n]s", sv.ngaySinh);
    printf("Nhap gioi tinh: ");
    scanf(" %[^\n]s", sv.gioiTinh);
    printf("Nhap diem: ");
    scanf("%f", &sv.diem);

    danhSach[*soLuong] = sv;
    (*soLuong)++;
}

void loaiSinhVienKem(struct SinhVien danhSach[], int *soLuong) {
    int i = 0;
    while (i < *soLuong) {
        if (danhSach[i].diem < 4) {
            for (int j = i; j < *soLuong - 1; j++) {
                danhSach[j] = danhSach[j + 1];
            }
            (*soLuong)--;
        } else {
            i++;
        }
    }
}

void congDiemXuatSac(struct SinhVien danhSach[], int soLuong) {
    for (int i = 0; i < soLuong; i++) {
        if (danhSach[i].diem > 8.6) {
            danhSach[i].diem += 0.5;
        }
    }
}

int main() {
    struct SinhVien danhSach[100];
    int soLuong = 0;
    int luaChon;

    while (1) {
        printf("1. Nhap danh sach sinh vien\n");
        printf("2. Sap xep danh sach theo diem\n");
        printf("3. Chen sinh vien\n");
        printf("4. Loai sinh vien kem\n");
        printf("5. Cong diem cho sinh vien xuat sac\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                nhapDanhSachSinhVien(danhSach, &soLuong);
                break;
            case 2:
                sapXepTheoDiem(danhSach, soLuong);
                break;
            case 3:
                chenSinhVien(danhSach, &soLuong);
                break;
            case 4:
                loaiSinhVienKem(danhSach, &soLuong);
                break;
            case 5:
                congDiemXuatSac(danhSach, soLuong);
                break;
            case 0:
                exit(0);
            default:
                printf("Lua chon khong hop le!\n");
                break;
        }
    }

    return 0;
}

