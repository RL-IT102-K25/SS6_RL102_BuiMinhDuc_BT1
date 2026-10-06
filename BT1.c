#include <stdio.h>
#include <string.h>

#define MAX_PHIEU 50

int main() {
    char maPhieu[MAX_PHIEU][20] = {
        "PM101",
        "PM102",
        "PM103"
    };
    int ngayQuaHan[MAX_PHIEU] = {0, 3, 5};
    int soLuong = 3;
    int choice;

    do {
        printf("\n--- HE THONG QUAN LY MUON TRA SACH (LIBRARY_WMS) ---\n");
        printf("1. Xem danh sach phieu muon\n");
        printf("2. Them moi phieu muon\n");
        printf("3. Cap nhat so ngay qua han\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Loi nhap lieu!\n");
            while (getchar() != '\n');
            continue;
        }
        
        // Làm sạch bộ đệm sau khi đọc số nguyên lựa chọn menu
        while (getchar() != '\n');

        switch (choice) {
            case 1: {
                printf("\n--- DANH SACH PHIEU MUON SACH ---\n");
                printf("STT | Ma Phieu | So Ngay Qua Han | Tien Phat (VND)\n");
                printf("--------------------------------------------------\n");
                for (int i = 0; i < soLuong; i++) {
                    long long tienPhat = (long long)ngayQuaHan[i] * 5000;
                    printf("%d | %s | %d ngay | %lld VND\n", 
                           i + 1, maPhieu[i], ngayQuaHan[i], tienPhat);
                }
                printf("--------------------------------------------------\n");
                printf("Tong so phieu: %d\n", soLuong);
                break;
            }
            case 2: {
                if (soLuong >= MAX_PHIEU) {
                    printf("Loi: Danh sach phieu muon da day, khong the them!\n");
                } else {
                    printf("Nhap ma phieu muon moi: ");
                    scanf("%19s", maPhieu[soLuong]);
                    while (getchar() != '\n'); // Làm sạch bộ đệm sau khi nhập chuỗi
                    
                    ngayQuaHan[soLuong] = 0; // Mặc định số ngày quá hạn ban đầu = 0
                    soLuong++;
                    printf("Them moi thanh cong!\n");
                }
                break;
            }
            case 3: {
                char searchCode[20];
                printf("Nhap ma phieu muon can cap nhat: ");
                scanf("%19s", searchCode);
                while (getchar() != '\n'); // Làm sạch bộ đệm

                int foundIndex = -1;
                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], searchCode) == 0) {
                        foundIndex = i;
                        break;
                    }
                }

                if (foundIndex != -1) {
                    printf("Tim thay phieu muon '%s' tai vi tri index %d.\n", searchCode, foundIndex);
                    int newDays;
                    do {
                        printf("Nhap so ngay qua han moi: ");
                        if (scanf("%d", &newDays) != 1 || newDays < 0) {
                            printf("So ngay qua han khong hop le! Vui long nhap lai (>= 0).\n");
                            while (getchar() != '\n');
                        } else {
                            while (getchar() != '\n'); // Làm sạch bộ đệm
                            ngayQuaHan[foundIndex] = newDays;
                            printf("Cap nhat thanh cong! So ngay qua han moi cua %s la %d ngay.\n", searchCode, newDays);
                            break;
                        }
                    } while (1);
                } else {
                    printf("Khong tìm thay ma phieu '%s' trong he thong!\n", searchCode);
                }
                break;
            }
            case 0:
                printf("Cam ơn ban da su dung he thong. Tam biet!\n");
                break;
            default:
                printf("Chuc nang khong hop le! Vui long chon lai tu 0 den 3.\n");
        }
    } while (choice != 0);

    return 0;
}