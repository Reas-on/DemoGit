#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct XeMay {
    char soXe[20];
    char loaiXe[20];
    int giaXe;
    int namSanXuat;
    char chuXe[50];
};

void nhapDanhSachXeMay(struct XeMay danhSachXeMay[], int *soLuongXeMay) {
    int i = 0;
    while (1) {
        printf("Nhap thong tin xe may thu %d:\n", i + 1);
        
        printf("So xe: ");
        scanf("%s", danhSachXeMay[i].soXe);
        
        if (strcmp(danhSachXeMay[i].soXe, "") == 0) {
            break;
        }
        
        printf("Loai xe: ");
        scanf("%s", danhSachXeMay[i].loaiXe);
        
        printf("Gia xe: ");
        scanf("%d", &danhSachXeMay[i].giaXe);
        
        printf("Nam san xuat: ");
        scanf("%d", &danhSachXeMay[i].namSanXuat);
        
        printf("Chu xe: ");
        scanf("%s", danhSachXeMay[i].chuXe);
        
        i++;
    }
    
    *soLuongXeMay = i;
}

void sapXepDanhSachXeMay(struct XeMay danhSachXeMay[], int soLuongXeMay) {
    int i, j;
    struct XeMay temp;
    
    for (i = 0; i < soLuongXeMay - 1; i++) {
        for (j = i + 1; j < soLuongXeMay; j++) {
            if (danhSachXeMay[i].giaXe > danhSachXeMay[j].giaXe) {
                temp = danhSachXeMay[i];
                danhSachXeMay[i] = danhSachXeMay[j];
                danhSachXeMay[j] = temp;
            } else if (danhSachXeMay[i].giaXe == danhSachXeMay[j].giaXe) {
                if (danhSachXeMay[i].namSanXuat > danhSachXeMay[j].namSanXuat) {
                    temp = danhSachXeMay[i];
                    danhSachXeMay[i] = danhSachXeMay[j];
                    danhSachXeMay[j] = temp;
                }
            }
        }
    }
}

void chenXeMay(struct XeMay danhSachXeMay[], int *soLuongXeMay) {
    struct XeMay xeMoi;
    
    printf("Nh?ap thong tin xe may moi:\n");
    
    printf("So xe: ");
    scanf("%s", xeMoi.soXe);
    
    printf("Loai xe: ");
    scanf("%s", xeMoi.loaiXe);
    
    printf("Gia xe: ");
    scanf("%d", &xeMoi.giaXe);
    
    printf("Nam san xuat: ");
    scanf("%d", &xeMoi.namSanXuat);
    
    printf("Chu xe: ");
    scanf("%s", xeMoi.chuXe);
    
    danhSachXeMay[*soLuongXeMay] = xeMoi;
    (*soLuongXeMay)++;
    
    sapXepDanhSachXeMay(danhSachXeMay, *soLuongXeMay);
}

void loaiXeSuDungTren20Nam(struct XeMay danhSachXeMay[], int soLuongXeMay) {
    int i;
    int namHienTai = 2022;
    
    printf("Cac xe may su dung tren 20 nam:\n");
    
    for (i = 0; i < soLuongXeMay; i++) {
        if (namHienTai - danhSachXeMay[i].namSanXuat > 20) {
            printf("So xe: %s\n", danhSachXeMay[i].soXe);
            printf("Loai xe: %s\n", danhSachXeMay[i].loaiXe);
            printf("Gia xe: %d\n", danhSachXeMay[i].giaXe);
            printf("Nam san xuat: %d\n", danhSachXeMay[i].namSanXuat);
            printf("Chu xe: %s\n", danhSachXeMay[i].chuXe);
            printf("\n");
        }
    }
}

void xuatDanhSachXeMay(struct XeMay danhSachXeMay[], int soLuongXeMay) {
    int i;
    
    printf("Danh sach xe may:\n");
    
    for (i = 0; i < soLuongXeMay; i++) {
        printf("So xe: %s\n", danhSachXeMay[i].soXe);
        printf("Loai xe: %s\n", danhSachXeMay[i].loaiXe);
        printf("Gia xe: %d\n", danhSachXeMay[i].giaXe);
        printf("Nam san xuat: %d\n", danhSachXeMay[i].namSanXuat);
        printf("Chu xe: %s\n", danhSachXeMay[i].chuXe);
        printf("\n");
    }
}

int main() {
    struct XeMay danhSachXeMay[100];
    int soLuongXeMay = 0;
    int luaChon;
    
    while (1) {
        printf("----- Quan ly danh sach xe may -----\n");
        printf("1. Nhap danh sach xe may\n");
        printf("2. Sap xep danh sach xe may\n");
        printf("3. Chen xe may\n");
        printf("4. Hien thi danh sach xe may\n");
        printf("5. Hien thi cac xe may su dung tren 20 nam\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &luaChon);
        
        switch (luaChon) {
            case 1:
                nhapDanhSachXeMay(danhSachXeMay, &soLuongXeMay);
                break;
            case 2:
                sapXepDanhSachXeMay(danhSachXeMay, soLuongXeMay);
                break;
            case 3:
                chenXeMay(danhSachXeMay, &soLuongXeMay);
                break;
            case 4:
                xuatDanhSachXeMay(danhSachXeMay, soLuongXeMay);
                break;
            case 5:
                loaiXeSuDungTren20Nam(danhSachXeMay, soLuongXeMay);
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

