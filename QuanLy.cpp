#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tuthien {
	int stt;
    char ten[50];
    char diachi [20];
    char ngayungho[20];
    float sotien;
    struct tuthien* next;
} Tuthien;

Tuthien* head = NULL;
void clrscr() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
void add(Tuthien *tuthien) {
    Tuthien* new_tuthien = (Tuthien*)malloc(sizeof(Tuthien));
	new_tuthien->stt = 0;
    printf("Nhap ho va ten: ");
    fflush(stdin);
    gets(new_tuthien->ten);
    printf("Nhap dia chi: ");
    fflush(stdin);
    gets(new_tuthien->diachi);
    printf("Nhap ngay ung ho:(dd/mm/yy) ");
    fflush(stdin);
    gets(new_tuthien->ngayungho);
    printf("Nhap so tien: ");
    scanf("%f", &new_tuthien->sotien);
    new_tuthien->next = NULL;

    if (head == NULL) {
        head = new_tuthien;
        new_tuthien->stt=1;
    } else {
        Tuthien* node = head;
        while (node->next != NULL) {
            node = node->next;
        }
        new_tuthien->stt = node->stt + 1;
        node->next = new_tuthien;
    }
    printf("Nhap thanh cong!\n");
}
void edit(Tuthien *tuthien) {
    int stt;
    printf("Nhap STT nguoi can sua: ");
    scanf("%d", &stt);
    Tuthien* node = head;
    while (node != NULL) {
        if (node->stt == stt) {
            printf("Nhap ho ten thay the: ");
            getchar();
            fflush(stdin);
            gets(node->ten);
            printf("Nhap dia chi: ");
            fflush(stdin);
            gets(node->diachi);
            printf("Nhap ngay ung ho (dd/mm/yy): ");
            fflush(stdin);
            gets(node->ngayungho);
            printf("Nhap so tien: ");
            scanf("%f", &node->sotien);
            printf("Cap nhat thanh cong!\n");
            return;
        }
        node = node->next;
    }
    printf("Khong ton tai.\n");
}
void print(Tuthien *tuthien) {
    printf("-------------------------------DANH SACH TU THIEN--------------------------------\n\n");
    printf("+-----+---------------------------+---------------+--------------+------------------+\n");
    printf("| %-3s | %-25s | %-13s | %-12s | %-16s |\n", "STT", "Ho va ten", "Dia chi", "Ngay ung ho", "So tien");
    printf("+-----+---------------------------+---------------+--------------+------------------+\n");

    Tuthien* node = head;
    while (node != NULL) {
        printf("| %-3d | %-25s | %-13s | %-12s | %-16.2f |\n", node->stt, node->ten, node->diachi, node->ngayungho, node->sotien);
        node = node->next;
    }
    printf("+-----+---------------------------+---------------+--------------+------------------+\n");
}
