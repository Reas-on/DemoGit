#include <stdio.h>
typedef struct {
    int tuSo;
    int mauSo;
} PhanSo;
void nhapPhanSo(PhanSo *ps) {
    printf("Nhap tu so: ");
    scanf("%d", &(ps->tuSo));
    printf("Nhap mau so: ");
    scanf("%d", &(ps->mauSo));
}
void xuatPhanSo(PhanSo ps) {
    printf("%d/%d", ps.tuSo, ps.mauSo);
}
PhanSo congPhanSo(PhanSo ps1, PhanSo ps2) {
    PhanSo ketQua;
    ketQua.tuSo = ps1.tuSo * ps2.mauSo + ps2.tuSo * ps1.mauSo;
    ketQua.mauSo = ps1.mauSo * ps2.mauSo;
    return ketQua;
}

PhanSo truPhanSo(PhanSo ps1, PhanSo ps2) {
    PhanSo ketQua;
    ketQua.tuSo = ps1.tuSo * ps2.mauSo - ps2.tuSo * ps1.mauSo;
    ketQua.mauSo = ps1.mauSo * ps2.mauSo;
    return ketQua;
}

PhanSo nhanPhanSo(PhanSo ps1, PhanSo ps2) {
    PhanSo ketQua;
    ketQua.tuSo = ps1.tuSo * ps2.tuSo;
    ketQua.mauSo = ps1.mauSo * ps2.mauSo;
    return ketQua;
}

PhanSo chiaPhanSo(PhanSo ps1, PhanSo ps2) {
    PhanSo ketQua;
    ketQua.tuSo = ps1.tuSo * ps2.mauSo;
    ketQua.mauSo = ps1.mauSo * ps2.tuSo;
    return ketQua;
}

int main() {
    int n;
    printf("Nhap so luong phan so: ");
    scanf("%d", &n);

    PhanSo danhSachPhanSo[n];

    for (int i = 0; i < n; i++) {
        printf("Nhap phan so thu %d:\n", i + 1);
        nhapPhanSo(&danhSachPhanSo[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((float)danhSachPhanSo[i].tuSo / danhSachPhanSo[i].mauSo > (float)danhSachPhanSo[j].tuSo / danhSachPhanSo[j].mauSo) {
                PhanSo temp = danhSachPhanSo[i];
                danhSachPhanSo[i] = danhSachPhanSo[j];
                danhSachPhanSo[j] = temp;
            }
        }
    }

    printf("Danh sach phan so sau khi sap xep tang dan:\n");
    for (int i = 0; i < n; i++) {
        xuatPhanSo(danhSachPhanSo[i]);
        printf("\n");
    }

    return 0;
}

