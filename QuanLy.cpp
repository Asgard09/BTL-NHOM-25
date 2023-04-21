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
void add(Tuthien **head) {
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

    if (*head == NULL) {
        *head = new_tuthien;
        new_tuthien->stt = 1;
    } else {
        Tuthien* node = *head;
        while (node->next != NULL) {
            node = node->next;
        }
        new_tuthien->stt = node->stt + 1;
        node->next = new_tuthien;
    }
    printf("Nhap thanh cong!\n");
}
void edit(Tuthien *head) {
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

void print(Tuthien *head) {
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

void xoa(Tuthien **head) {
    int stt;
    printf("Nhap STT nguoi can xoa: ");
    scanf("%d", &stt);
    if (*head == NULL) {
        printf("Danh sach rong!\n");
        return;
    }
    if ((*head)->stt == stt) {
        Tuthien *temp = *head;
        *head = (*head)->next;
        free(temp);
        printf("Da xoa thanh cong!\n");
        Tuthien *node = *head;
        while (node != NULL) {
            node->stt--;
            node = node->next;
        }
        return;
    }
    Tuthien *node = *head;
    int index = 0;
    while (node->next != NULL) {
        index++;
        if (node->next->stt == stt) {
            Tuthien *temp = node->next;
            node->next = node->next->next;
            free(temp);
            printf("Da xoa thanh cong!\n");
            Tuthien *p = node->next;
            while (p != NULL) {
                p->stt--;
                p = p->next;
            }
            return;
        }
        node = node->next;
    }
    printf("Khong tim thay STT can xoa.\n");
}
void search_stt(Tuthien *head) {
    int stt;
    printf("Nhap STT nguoi can tim kiem: ");
    scanf("%d", &stt);

    Tuthien* node = head;
    while (node != NULL) {
        if (node->stt == stt) {
            printf("Thong tin nguoi co STT %d:\n", stt);
 			printf("+-----+---------------------------+---------------+--------------+------------------+\n");
    		printf("| %-3s | %-25s | %-13s | %-12s | %-16s |\n", "STT", "Ho va ten", "Dia chi", "Ngay ung ho", "So tien");
    		printf("+-----+---------------------------+---------------+--------------+------------------+\n");
    		printf("| %-3d | %-25s | %-13s | %-12s | %-16.2f |\n", node->stt, node->ten, node->diachi, node->ngayungho, node->sotien);
    		printf("+-----+---------------------------+---------------+--------------+------------------+\n");
            return;
        }
        node = node->next;
    }

    printf("Khong tim thay STT can tim kiem.\n");
}
void search_ten(Tuthien *head) {
	char ten[50];
    printf("Nhap ten nguoi can tim kiem: ");
    fflush(stdin);
    gets(ten);
    Tuthien* node = head;
    printf("Danh sach nguoi co ten %s:\n",ten);
	printf("+-----+---------------------------+---------------+--------------+------------------+\n");
   	printf("| %-3s | %-25s | %-13s | %-12s | %-16s |\n", "STT", "Ho va ten", "Dia chi", "Ngay ung ho", "So tien");
	printf("+-----+---------------------------+---------------+--------------+------------------+\n");
	int dem=0;
    while (node != NULL) {
        if (strcmp(node->ten, ten) == 0) {
      		printf("| %-3d | %-25s | %-13s | %-12s | %-16.2f |\n", node->stt, node->ten, node->diachi, node->ngayungho, node->sotien);
      		dem++;
        }
        node = node->next;
    }
    printf("+-----+---------------------------+---------------+--------------+------------------+\n");
	if(dem==0){
    printf("Khong tim thay ten nguoi can tim kiem.\n");
}}

void search_diachi(Tuthien *head) {
	char diachi[50];
    printf("Nhap dia chi nguoi can tim kiem: ");
    fflush(stdin);
    gets(diachi);
    printf("Danh sach nguoi co dia chi %s:\n",diachi);
	printf("+-----+---------------------------+---------------+--------------+------------------+\n");
	printf("| %-3s | %-25s | %-13s | %-12s | %-16s |\n", "STT", "Ho va ten", "Dia chi", "Ngay ung ho", "So tien");
	printf("+-----+---------------------------+---------------+--------------+------------------+\n");
    Tuthien* node = head;
    int dem=0;
    while (node != NULL) {
        if (strcmp(node->diachi, diachi) == 0) {
            printf("| %-3d | %-25s | %-13s | %-12s | %-16.2f |\n", node->stt, node->ten, node->diachi, node->ngayungho, node->sotien);
            dem++;
        }
        node = node->next;
    }
    printf("+-----+---------------------------+---------------+--------------+------------------+\n");
	if(dem==0){
    printf("Khong tim thay dia chi can tim kiem.\n");
}}
void search_sotien(Tuthien *head) {
    float sotien;
    printf("Nhap so tien can tim kiem: ");
    scanf("%f", &sotien);
    printf("Danh sach nguoi co dia chi %f:\n",sotien);
	printf("+-----+---------------------------+---------------+--------------+------------------+\n");
	printf("| %-3s | %-25s | %-13s | %-12s | %-16s |\n", "STT", "Ho va ten", "Dia chi", "Ngay ung ho", "So tien");
	printf("+-----+---------------------------+---------------+--------------+------------------+\n");
    Tuthien* node = head;
    int dem=0;
    while (node != NULL) {
        if (node->sotien == sotien) {
			printf("| %-3d | %-25s | %-13s | %-12s | %-16.2f |\n", node->stt, node->ten, node->diachi, node->ngayungho, node->sotien);
            dem++;
        }
        node = node->next;
    }
    printf("+-----+---------------------------+---------------+--------------+------------------+\n");
	if(dem==0){
    printf("Khong tim thay so tien can tim kiem.\n");
}}
void swap(Tuthien *a, Tuthien *b) {
    int temp_sotien = a->sotien;
    a->sotien = b->sotien;
    b->sotien = temp_sotien;

    int temp_stt = a->stt;
    a->stt = b->stt;
    b->stt = temp_stt;

    char temp_ten[30];
    strcpy(temp_ten, a->ten);
    strcpy(a->ten, b->ten);
    strcpy(b->ten, temp_ten);

    char temp_diachi[30];
    strcpy(temp_diachi, a->diachi);
    strcpy(a->diachi, b->diachi);
    strcpy(b->diachi, temp_diachi);

    char temp_ngayungho[20];
    strcpy(temp_ngayungho, a->ngayungho);
    strcpy(a->ngayungho, b->ngayungho);
    strcpy(b->ngayungho, temp_ngayungho);
}
void sapxepsotien(Tuthien* head) {
    Tuthien *current = head, *index = NULL;
    float temp_sotien;
    char temp_ten[50], temp_diachi[20], temp_ngayungho[20];
    int temp_stt;
    while(current != NULL) {
        index = current->next;
        while(index != NULL) {
            if(current->sotien > index->sotien) {
            	swap(current,index);
            }
            index = index->next;
        }
        current = current->next;
    }
    printf("Danh sach da sap xep theo so tien:\n");
    print(head);
}
void sapxeptheoten(Tuthien* head) {
    Tuthien *current = head, *index = NULL;
    float temp_sotien;
    char temp_ten[50], temp_diachi[20], temp_ngayungho[20];
    int temp_stt;
    while(current != NULL) {
        index = current->next;
        while(index != NULL) {
            if(strcmp(current->ten, index->ten) > 0) {
            	swap(current,index);
            }
            index = index->next;
        }
        current = current->next;
    }
    printf("Danh sach da sap xep theo ten:\n");
    print(head);
}
void sapxepdiachi(Tuthien* head) {
    Tuthien *current = head, *index = NULL;
    float temp_sotien;
    char temp_ten[50], temp_diachi[20], temp_ngayungho[20];
    int temp_stt;
    while(current != NULL) {
        index = current->next;
        while(index != NULL) {
            if(strcmp(current->diachi, index->diachi) > 0) {
                swap(current,index);
            }
            index = index->next;
        }
        current = current->next;
    }
    printf("Danh sach da sap xep theo dia chi:\n");
    print(head);
}
void sapxepSTT(Tuthien* head) {
    Tuthien *current = head, *index = NULL;
    float temp_sotien;
    char temp_ten[50], temp_diachi[20], temp_ngayungho[20];
    int temp_stt;
    while(current != NULL) {
        index = current->next;
        while(index != NULL) {
            if(current->sotien > index->sotien) {
            	swap(current,index);
            }
            index = index->next;
        }
        current = current->next;
    }
}
void thongke(Tuthien* head) {
    if (head == NULL) {
        printf("Danh sach rong.");
        return;
    }

    float tongtien = 0;
    Tuthien* node = head;
    Tuthien* nguoiunghonhieunhat = head;
    Tuthien* nguoiunghoitnhat = head;

    while (node != NULL) {
        tongtien += node->sotien;

        if (node->sotien > nguoiunghonhieunhat->sotien) {
            nguoiunghonhieunhat = node;
        }

        if (node->sotien < nguoiunghoitnhat->sotien) {
            nguoiunghoitnhat = node;
        }

        node = node->next;
    }

    printf("---TONG SO TIEN----: %f\n", tongtien);
    printf("----------------NGUOI UNG HO TIEN NHIEU NHAT-------------------\n") ;
	printf("+-----+---------------------------+---------------+--------------+------------------+\n");
	printf("| %-3s | %-25s | %-13s | %-12s | %-16s |\n", "STT", "Ho va ten", "Dia chi", "Ngay ung ho", "So tien");
	printf("+-----+---------------------------+---------------+--------------+------------------+\n");
	printf("| %-3d | %-25s | %-13s | %-12s | %-16.2f |\n", nguoiunghonhieunhat->stt, nguoiunghonhieunhat->ten, nguoiunghonhieunhat->diachi,nguoiunghonhieunhat->ngayungho, nguoiunghonhieunhat->sotien);
	printf("+-----+---------------------------+---------------+--------------+------------------+\n");
	printf("-----------------NGUOI UNG HO TIEN IT NHAT-----------------\n" );
	printf("+-----+---------------------------+---------------+--------------+------------------+\n\n");
	printf("| %-3s | %-25s | %-13s | %-12s | %-16s |\n", "STT", "Ho va ten", "Dia chi", "Ngay ung ho", "So tien");
	printf("+-----+---------------------------+---------------+--------------+------------------+\n");
	printf("| %-3d | %-25s | %-13s | %-12s | %-16.2f |\n", nguoiunghoitnhat->stt, nguoiunghoitnhat->ten, nguoiunghoitnhat->diachi,nguoiunghonhieunhat->ngayungho, nguoiunghoitnhat->sotien);
	printf("+-----+---------------------------+---------------+--------------+------------------+\n");
}
void docFile(Tuthien** head, char* fileName) {
    FILE* f;
    f = fopen(fileName, "r"); // Use "r" instead of "rt"
    if (f == NULL) {
        printf("Khong the mo file %s", fileName);
        return;
    }
    int stt;
    char ten[50];
    char diachi[20];
    char ngayungho[20];
    float sotien;
    Tuthien* lastNode = NULL; // Initialize to NULL
    while (fscanf(f, "%d,%49[^,],%19[^,],%19[^,],%f\n", &stt, ten, diachi, ngayungho, &sotien) == 5) {
        Tuthien* newNode = (Tuthien*) malloc(sizeof(Tuthien));
        newNode->stt = stt;
        strcpy(newNode->ten, ten);
        strcpy(newNode->diachi, diachi);
        strcpy(newNode->ngayungho, ngayungho);
        newNode->sotien = sotien;
        newNode->next = NULL;
        if (*head == NULL) {
            *head = newNode;
            lastNode = newNode; // Update lastNode
        } else {
            lastNode->next = newNode;
            lastNode = newNode; // Update lastNode
        }
    }
    fclose(f);
}

void ghiFile(Tuthien* head, char* fileName) { // Remove pointer and use head directly
    FILE* f;
    f = fopen(fileName, "w"); // Use "w" instead of "wt"
    Tuthien* node = head;
    while (node != NULL) {
        fprintf(f, "%d,%s,%s,%s,%f\n", node->stt, node->ten, node->diachi, node->ngayungho, node->sotien);
        node = node->next;
    }
    fclose(f);
}
void menu_search(Tuthien* &head){
	clrscr();
	int chon;
	do{
		printf("\n--------TIM KIEM----------\n");
		printf("1. Tim kiem theo stt\n");
		printf("2. Tim kiem theo ten\n");
		printf("3. Tim kiem theo dia chi\n");
		printf("4. Tim kiem theo so tien\n");
		printf("5. Quay lai menu chinh\n");
		printf("Nhap lua chon: ");
		scanf("%d", &chon);

		switch (chon){
			case 1:
				clrscr();
				search_stt(head);
				break;
			case 2:
				clrscr();
				search_ten(head);
				break;
			case 3:
				clrscr();
				search_diachi(head);
				break;
			case 4:
				clrscr();
				search_sotien(head);
				break;
			case 5:
				clrscr();
				return;
			default:
				clrscr();
				printf("Lua chon khong hop le. Chon lai\n");
        }
    } while (1);
		}
void menu_sapxep(Tuthien* &head){
	int chon;
	do {
		printf("\n--------SAP XEP----------\n");
		printf("1. Sap xep theo ten ABC\n");
		printf("2. Sap xep theo dia chi ABC\n");
		printf("3. Sap xep theo so tien\n");
		printf("4. Quay lai menu chinh\n");
  		printf("Nhap lua chon: ");
        scanf("%d", &chon);

        switch (chon){
        	case 1:
        		clrscr();
        		sapxeptheoten(head);
        		break;
       		case 2:
       			clrscr();
       			sapxepdiachi(head);
       			break;
 			case 3:
 				clrscr();
 				sapxepsotien(head);
 				break;
			case 4:
				sapxepSTT(head);
				return;
				break;
			default:
				clrscr();
				printf("Lua chon khong hop le. Chon lai\n");
	}
	}while(1);
}

void menu() {
    int chon;
    char fileName[100];
    do {
        printf("\n-------MENU-------\n");
        printf("1. Them\n");
        printf("2. Sua\n");
        printf("3. In danh sach\n");
        printf("4. Xoa\n");
        printf("5. Tim Kiem\n");
        printf("6. Sap xep\n");
        printf("7. Thong ke\n");
        printf("8. Doc file\n");
        printf("9. Ghi file\n");
        printf("10. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &chon);

        switch (chon) {
            case 1:
            	clrscr();
                add(&head);
                break;
            case 2:
            	clrscr();
                edit(head);
                break;
            case 3:
            	clrscr();
                print(head);
                break;
            case 4:
            	clrscr();
            	xoa(&head);
            	break;
            case 5:
            	clrscr();
            	menu_search(head);
            	break;
            case 6:
            	clrscr();
            	menu_sapxep(head);
            	break;
           	case 7:
           		clrscr();
           		thongke(head);
           		break;
      		case 8:
      			clrscr();
				printf("\n Nhap ten file: ");
				scanf("%s",fileName);
				docFile(&head,fileName);
				printf("Da doc xong du lieu tu file %s\n", fileName);
				break;
			case 9:
				clrscr();
				printf("\n Nhap ten file: ");
				scanf("%s",fileName);
				ghiFile(head,fileName);
				printf("Da ghi xong du lieu tu file %s\n", fileName);
				break;
            case 10:
                printf("Goodbye!\n");
                exit(0);
            default:
            	clrscr();
                printf("Lua chon khong hop le. Chon lai\n");
        }
    } while (1);
}

int main() {
    menu();
    return 0;
}

