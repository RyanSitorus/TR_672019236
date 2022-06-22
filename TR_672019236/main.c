#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

#define ENTER 13
#define TAB 9
#define BKSP 8
#define cls() system("cls")


int n = 0, search();
COORD coord = {0,0};

struct barang
{
    char nama[20];
    char jumlah[20];
    char harga[20];
    char tanggal[20];
struct barang *next;
};

struct barang *head = NULL, *node = NULL, *curr=NULL;

struct hist{
    char aktivitas[100];
    struct hist *next;
};

struct hist *headhist = NULL, *nodehist, *currhist, *datahist;

typedef struct
{
    char nama[20];
    char jumlah[20];
    char harga[20];
    char tanggal[20];
}s_barang;

s_barang s_data[100];
void bsort_nama(s_barang list[], int s);
void bsort_jumlah(s_barang list[], int s);
void bsort_harga(s_barang list[], int s);
void bsort_tanggal(s_barang list[], int s);

    void gotoab(int a, int b){
    coord.X=a;
    coord.Y=b;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void login(){
    char user[10];
    char pass[10];
    int p=0;
    time_t t;
    time(&t);
    gotoab(20,8);printf("<<=========================================================================>>");
    gotoab(20,9);printf("|                     SELAMAT DATANG DI DATABASE TOKO XY                    |");
    gotoab(20,10);printf("|===========================================================================|");
    gotoab(20,18);printf("|===========================================================================|");
    gotoab(45,11);printf("%s",ctime(&t));
    gotoab(20,20);printf("<<=========================================================================>>");
    gotoab(20,12);printf("|===========================================================================|");
    gotoab(20,13);printf("|                                                                           |");
    gotoab(20,14);printf("|                                                                           |");
    gotoab(20,15);printf("|                                                                           |");
    gotoab(20,16);printf("|                                                                           |");
    gotoab(20,17);printf("|                                                                           |");
    system("COLOR F1");
    gotoab(35,14);printf("NIM     \t: ");
    gotoab(35,15);printf("PASSWORD\t: ");

    gotoab(50,14);scanf("%s", &user);

    gotoab(50,15);
    char ch;
    int i = 0;
    while(1){
        ch = getch();

        if(ch == ENTER || ch == TAB){
            pass[i] = '\0';
            break;
        }else if(ch == BKSP){
            if(i>0){
                i--;
                printf("\b \b");
            }
        }else{
            pass[i++] = ch;
            printf("*");
        }
    }

    if(strcmp(user, "672019236") == 0 && strcmp(pass, "123") == 0){
        cls();
        gotoab(5,22);
        system("cls");
        menu();
    }else{
    	gotoab(45,22);printf("NIM / Password Salah");
        login();
    }
}

int main(){
    login();
    return 0;
}

void menu(){
	int pilihan, b = 1;

	do{
	cls();
    system("COLOR B4");
	gotoab(50,5);printf("Program Data Transaksi Toko");

	gotoab(21,4);printf("==================================================================================");
	gotoab(21,6);printf("==================================================================================");
	gotoab(21,7);printf("|                                                                                |");
	gotoab(21,8);printf("|                                                                                |");
	gotoab(21,9);printf("|                                                                                |");
	gotoab(21,10);printf("|                                                                                |");
	gotoab(21,11);printf("|                                                                                |");
	gotoab(21,12);printf("|                                                                                |");
	gotoab(21,13);printf("|                                                                                |");
	gotoab(21,14);printf("|                                                                                |");
	gotoab(21,15);printf("|                                                                                |");
	gotoab(21,16);printf("|                                                                                |");
	gotoab(21,17);printf("|                                                                                |");
	gotoab(21,18);printf("|                                                                                |");
	gotoab(21,19);printf("|+==============================================================================+|");
	gotoab(21,20);printf("|                                                                                |");
	gotoab(21,21);printf("|+==============================================================================+|");

    system("COLOR B4");
	gotoab(30,8);printf("Menu: ");
	gotoab(30,9);printf("1. Memasukkan data transaksi");
	gotoab(30,10);printf("2. Menampilkan data transaksi");
	gotoab(30,11);printf("3. Menambahkan Data transaksi Baru");
	gotoab(30,12);printf("4. Menghapus Data transaksi");
	gotoab(30,13);printf("5. Mengedit Data transaksi");
	gotoab(30,14);printf("6. Mencari Data transaksi");
	gotoab(30,15);printf("7. Melihat Riwayat Aktivitas");
	gotoab(30,16);printf("8. Mengurutkan Data transaksi");
	gotoab(30,17);printf("9. Keluar ");
	gotoab(30,20);printf("Masukkan Pilihan : ");
	gotoab(50,20);scanf("%d", &pilihan);
	cls();

	switch (pilihan)
	{
		case 1:
            insert();
			break;
		case 2:
			display();
			break;
		case 3:
			update();
			break;
		case 4:
			remove_();
			break;
		case 5:
			edit();
			printf("error");
			break;
		case 6:
			searching();
			break;
		case 7:
			 history();
			break;
		case 8:
			sorting();
			break;
		case 9:
		    akhir();
			exit(0);
			break;
		default:
		    printf("Silahkan masukkan pilihan 1-9 :)");
	}
	} while(b == 1);
}

void insert(){
    int i=0;
    int a, max;
    system("COLOR C0");
    gotoab(10,0);printf("+==================================================================================================+");
    gotoab(10,2);printf("+==================================================================================================+");
    gotoab(10,10);printf("+==================================================================================================+");

    gotoab(45,1);printf("Masukkan Data transaksi baru ");
    gotoab(42,4);printf("Batas maksimun input data adalah 5 ");
    gotoab(42,6);printf("Berapa banyak data yang mau diinputkan ? ");
    gotoab(60,8);scanf("%d", &max);
    cls();

    if(max > 5){
        gotoab(10,13);printf("Batas maksimum 5 data ");
        insert();
    }

    headhist = NULL;
    head = NULL;
    for(a=0; a<max; a++){
        node = (struct barang*) malloc(sizeof(struct barang));

        i = 0;

        gotoab(10,0);printf("|================================================================================================|");
        gotoab(10,2);printf("|================================================================================================|");


        gotoab(40,1);printf("                 Masukkan data transaksi                 ");
        gotoab(52,3+(6*a));printf("transaksi ke - %d",a+1);
		gotoab(52,4+(6*a));printf("Nama barang      : ",a+1); scanf(" %[^\n]s", &node->nama);
		gotoab(52,5+(6*a));printf("Kuantitas        : ",a+1); scanf(" %[^\n]s", &node->jumlah);
		gotoab(52,6+(6*a));printf("Harga            : ",a+1); scanf(" %[^\n]s", &node->harga);
		gotoab(52,7+(6*a));printf("Tanggal          : ",a+1); scanf(" %[^\n]s", &node->tanggal);

		if(head == NULL){
			head = node;
			curr = node;
		}

		else{
			curr->next = node;
			curr = node;
		}
    }
    curr->next = NULL;
    i += max+1;
    n += max;

    gotoab(10, (6*a)+3);printf("|================================================================================================|");

    datahist = (struct hist*) malloc(sizeof(struct hist));
    char job[100];
    sprintf(job, "Admin memasukkan %d data baru", max);
    strcpy(datahist->aktivitas, job);

    if(headhist == NULL){
    	headhist = datahist;
    	currhist = datahist;
	}else{
		currhist -> next = datahist;
		currhist = datahist;
	}
	currhist -> next = NULL;
}



void display(){
	struct barang *ct;
	ct = (struct barang*) malloc(sizeof(struct barang));;
	ct = head;
	int i = 5, j;
        system("COLOR C7");
		gotoab(10,0);printf("|================================================================================================|");
        gotoab(0,2);printf("|=====================================================================================================================|");
        gotoab(0,4);printf("|=====================================================================================================================|");


		gotoab(35,1);printf("               Data Transaksi                ");
		gotoab(0,3);printf(" Nama");
		gotoab(24,3);printf("Kuantitas");
		gotoab(47,3);printf("Harga");
		gotoab(76,3);printf("Tanggal");

	while(ct != NULL){
		gotoab(24,i);sscanf(ct->jumlah,"%d",&j);printf ("%d", j);
		gotoab(1,i);printf("%s", ct->nama);
		gotoab(47,i);printf ("%s", ct->harga);
		gotoab(76,i);printf ("%s", ct->tanggal);
		ct = ct->next;
		i++;
	}
	printf("\n");

		gotoab(10,i);printf("+================================================================================================+");

	datahist = (struct hist*) malloc(sizeof(struct hist));
	strcpy(datahist->aktivitas, "Admin melihat database Transaksi");

	if(headhist == NULL){
		headhist = datahist;
		currhist = datahist;
	}else{
		currhist -> next = datahist;
		currhist = datahist;
	}
	currhist -> next = NULL;
	getch();
}




void update(){
	int z = 0;
	int a, b = 0, max;
    system("COLOR A0");
		gotoab(10,0);printf("|================================================================================================|");
        gotoab(10,2);printf("|================================================================================================|");

		gotoab(40,1);printf ("              TAMBAH DATA              ");
		gotoab(40,4);printf ("Berapa Data yang Mau Ditambahkan ? ");
		gotoab(75,4);scanf ("%d", &max);
		cls();

		for(a=z; a<z + max; a++){
			node = (struct barang*) malloc(sizeof(struct barang));

			gotoab(10,0);printf("|================================================================================================|");
        	gotoab(10,2);printf("|================================================================================================|");

			gotoab(40,1);printf("                 TAMBAH DATA                 ");
       		gotoab(52,3+(6*b));printf("Transaksi ke - %d",a+1);
			gotoab(52,4+(6*b));printf("Nama barang            : "); scanf(" %[^\n]s", &node->nama);
			gotoab(52,5+(6*b));printf("Kuantitas              : "); scanf(" %[^\n]s", &node->jumlah);
			gotoab(52,6+(6*b));printf("Harga                  : "); scanf(" %[^\n]s", &node->harga);
			gotoab(52,7+(6*b));printf("Tanggal                : "); scanf(" %[^\n]s", &node->tanggal);

			b++;

		if(head == NULL){
			head = node;
			curr = node;
		}else{
			curr->next = node;
			curr = node;
		}
	}
	curr->next = NULL;
	z += max;
	n += max;

	gotoab(10,(6*b)+3);printf("|================================================================================================|");


	datahist = (struct hist*) malloc(sizeof(struct hist));
	char job[100];
	sprintf(job, "Admin menambahkan %d data baru", max);
	strcpy(datahist->aktivitas, job);

	if(headhist == NULL){
		headhist = datahist;
		currhist = datahist;
	}else{
		currhist -> next = datahist;
		currhist = datahist;
	}
	currhist -> next = NULL;
}


void remove_()
{
    system("COLOR B4");
	char id_dl[30];
    display();
	gotoab(10,8);printf("|================================================================================================|");
    gotoab(10,9);printf("|================================================================================================|");
    gotoab(45,10);printf("Masukkan nama barang yang ingin dihapus : ");
    gotoab(60,11);scanf("%s", &id_dl);

    curr = head;
    struct barang *next;
    int cek = 0;
    while(curr != NULL){
    	next = (struct barang*) malloc(sizeof(struct barang));
    	next = curr->next;

    	int cmp = strcmp(curr->nama, id_dl);
    	int ncmp = 1;

    	if(curr->next != NULL){
    		ncmp = strcmp(next->nama, id_dl);
		}

		if(cmp == 0){
			if(curr->next != NULL){
				head = next;
			}else{
				head = NULL;
			}
			cek = 1;
			break;

		}else if(ncmp == 0){
			curr->next = next->next;
			cek = 1;
			break;
		}

		if(curr->next != NULL){
			curr = curr->next;
		}else{
			break;
		}
	}

	if(cek == 0){
		gotoab(47,13);printf(">> Data tidak ditemukan ! <<\n");
		gotoab(10,14);printf("=================================================================================================");
	}else{
		gotoab(47,16);printf(">> Data berhasil dihapus ! <<\n");
		gotoab(10,14);printf("=================================================================================================");

	}
	getch();


    curr = head;
    while(curr != NULL){
    	if(curr->next != NULL){
    		curr = curr->next;
		}else{
			break;
		}
	}
	n -= 1;

	datahist = (struct hist*) malloc(sizeof(struct hist));
	char job[100];
	sprintf(job, "Admin menghapus data transaksi dengan nama barang = %s ", id_dl);
	strcpy(datahist->aktivitas, job);

	if(headhist == NULL){
		headhist = datahist;
		currhist = datahist;
	}else{
		currhist -> next = datahist;
		currhist = datahist;
	}
	currhist -> next = NULL;
}



void edit(){
	int pilih;
	char cari[10], newval[30], nama[30], jk[30], tci[30], tco[30];
	gotoab(10,0);printf("|================================================================================================|");
    gotoab(10,2);printf("|================================================================================================|");
	gotoab(10,11);printf("|================================================================================================|");

	gotoab(44,1);printf("              EDIT DATA             ");
	gotoab(47,4);printf("Data apa yang ingin anda edit? \n");
	gotoab(47,5);printf("1. Nama");
	gotoab(47,6);printf("2. Kuantitas");
	gotoab(47,7);printf("3. Tanggal");
	gotoab(47,9);printf("Pilihan: ");
	gotoab(56,8);printf("Masukkan harga barang : ");
	gotoab(56,9);scanf("%d", &cari);
	search(cari);
	cls();

	gotoab(10,0);printf("|================================================================================================|");
    gotoab(10,2);printf("|================================================================================================|");

	gotoab(40,1);printf("              EDIT DATA             ");

	if(searchEdit (cari) == 1){

		gotoab(47,4);printf("Masukkan data baru: ");
		scanf(" %[^\n]s", &newval);
		switch(pilih){
		case 1:
			strcpy(curr->nama, newval);
			break;
		case 2:
			strcpy(curr->jumlah, newval);
			break;
		case 3:
			strcpy(curr->harga, newval);
			break;
		case 4:
			strcpy(curr->tanggal, newval);
			break;
		}
	}else{
		gotoab(47,4);printf("Data tidak ditemukan ! \n");
	}

		curr = head;
		while(curr != NULL){
			if(curr->next != NULL){
				curr = curr->next;
			}else{
				break;
			}
		}

	datahist = (struct hist*)malloc(sizeof(struct hist));
	strcpy(datahist->aktivitas, "Admin melakukan edit data");

	if(headhist == NULL){
		headhist = datahist;
		currhist = datahist;
	}else{
		currhist -> next = datahist;
		currhist = datahist;
	}
	currhist -> next = NULL;
}

int searchEdit(char idbu[50]){
	curr = head;
	int cmp;
	while(curr != NULL){
		cmp = strcmp(curr->nama, idbu);
		if(cmp == 0){
			return 1;
		}
		curr = curr->next;
	}
	return 0;
}

int search(char cr[50], int num){
	if(num>5||num<1){
		return 2;
	}

	curr = head;
	int cmp;
	while(curr != NULL){
		switch(num){
			case 1:
				cmp =strcmp(curr->nama, cr);
				break;
			case 2:
				cmp =strcmp(curr->jumlah, cr);
				break;
			case 3:
				cmp =strcmp(curr->harga, cr);
				break;
			case 4:
				cmp =strcmp(curr->tanggal, cr);
				break;
			}

		if(cmp == 0){
			return 1;
		}
		curr = curr->next;
	}
	return 0;
}


void searching(){
	int input;
	char cari[30];

	gotoab(10,0);printf("|================================================================================================|");
    gotoab(10,2);printf("|================================================================================================|");
	gotoab(10,12);printf("|================================================================================================|");

	gotoab(40,1);printf("              CARI DATA             ");
	gotoab(40,4);printf("Pencarian Berdasarkan : ");
	gotoab(40,5);printf("1. Nama");
	gotoab(40,6);printf("2. Kuantitas");
	gotoab(40,7);printf("3. Harga");
	gotoab(40,8);printf("4. Tanggal");
	gotoab(40,10);printf("Masukkan pilihan : ");
	gotoab(59,10);scanf("%d", &input);

	switch(input){
		case 1:
			gotoab(40,11);printf("Masukkan Nama barang yang ingin dicari: ");
			scanf("%s", &cari);
			break;
		case 2:
			gotoab(40,11);printf("Masukkan Kuantitas barang yang ingin dicari: ");
			scanf("%s", &cari);
			break;
		case 3:
			gotoab(40,11);printf("Masukkan Harga barang yang ingin dicari: ");
			scanf("%s", &cari);
			break;
		case 4:
			gotoab(40,11);printf("Masukkan Tanggal barang yang ingin dicari: ");
			scanf("%s", &cari);
			break;

	}
		cls();
	if(search(cari, input)==1){
		prSearch();
	}else if(search(cari,input)==2){
		gotoab(40,12);printf("Input tidak valid");
	}else{
		gotoab(40,12);printf("Data tidak ditemukan");
	}

	while(curr != NULL){
		if(curr->next != NULL){
			curr = curr->next;
		}else{
			break;
		}
	}

	datahist = (struct hist*) malloc(sizeof(struct hist));
	strcpy(datahist->aktivitas, "Admin mencari data");

	if(headhist == NULL){
		headhist = datahist;
		currhist = datahist;
	}else{
		currhist -> next = datahist;
		currhist = datahist;
	}
	currhist -> next = NULL;

}

void prSearch(){
	cls();
	struct barang *ct;
	ct = (struct barang*) malloc(sizeof(struct barang));
	ct = curr;
	int i = 5, j;
		gotoab(10,0);printf("|================================================================================================|");
		gotoab(40,1);printf("|             Hasil Pencarian           |");
		gotoab(0,2);printf("|=====================================================================================================================|");
		gotoab(0,3);printf("Nama");
		gotoab(24,3);printf("Kuantitas");
		gotoab(47,3);printf("Harga");
		gotoab(76,3);printf("Tanggal");
		gotoab(0,4);printf("|=====================================================================================================================|");

		gotoab(24,i);sscanf(ct->harga,"%d",&j);printf ("%03d", j);
		gotoab(1,i);printf("%s", ct->nama);
		gotoab(47,i);printf("%s", ct->jumlah);
		gotoab(76,i);printf ("%s", ct->tanggal);

		i++;


	printf("\n");
	getch();
}

void sorting(){
	int input;

	if(head == NULL){
		insert();
	}else{
	gotoab(10,0);printf("|================================================================================================|");
    gotoab(10,2);printf("|================================================================================================|");
	gotoab(40,1);printf("              Mengurutkan Data             ");
	gotoab(40,3);printf("Urutkan data berdasarkan");
	gotoab(40,4);printf("1. Nama");
	gotoab(40,5);printf("2. Kuantitas");
	gotoab(40,6);printf("3. Harga");
	gotoab(40,7);printf("4. Tanggal");
	gotoab(40,8);printf("Pilihan: ");
	gotoab(50,8);scanf("%d", &input);

	if(input == 1){
		bsort_nama(s_data, n);
	}
	else if(input == 2){
		bsort_jumlah(s_data, n);
	}
	else if(input == 3){
		bsort_harga(s_data, n);
	}
	else if(input == 4){
		bsort_tanggal(s_data, n);
	}else{
		cls();
		sorting();
	}
	}
}

void bsort_nama(s_barang list[100], int s){
	s_barang tmp;
	int j, i;

	for(j = 0; j < n; j++){
		for(i = 0; i < s - 1; i++){
			if (strcmp(list[i].nama, list[i + 1].nama) > 0){
				tmp = list[i];
				list[i] = list[i + 1];
				list[i + 1] = tmp;
			}
		}
	}
	sorting_result();
}

void bsort_jumlah(s_barang list[100], int s){
	s_barang tmp;
	int j, i;

	for(j = 0; j < n; j++){
		for(i = 0; i < s - 1; i++){
			if (strcmp(list[i].jumlah, list[i + 1].jumlah) > 0){
				tmp = list[i];
				list[i] = list[i + 1];
				list[i + 1] = tmp;
			}
		}
	}
	sorting_result();
}

void bsort_harga(s_barang list[100], int s){
	s_barang tmp;
	int j, i;

	for(j = 0; j < n; j++){
		for(i = 0; i < s - 1; i++){
			if (strcmp(list[i].harga, list[i + 1].harga) > 0){
				tmp = list[i];
				list[i] = list[i + 1];
				list[i + 1] = tmp;
			}
		}
	}
	sorting_result();
}

void bsort_tanggal(s_barang list[100], int s){
	s_barang tmp;
	int j, i;

	for(j = 0; j < n; j++){
		for(i = 0; i < s - 1; i++){
			if (strcmp(list[i].tanggal, list[i + 1].tanggal) > 0){
				tmp = list[i];
				list[i] = list[i + 1];
				list[i + 1] = tmp;
			}
		}
	}
	sorting_result();
}

void sorting_result(){
	cls();
	struct barang *dt;
	dt = (struct barang*) malloc(sizeof(struct barang));;
	dt = head;
		int i, j;

	gotoab(0,0);printf("|=====================================================================================================================|");
	gotoab(0,1);printf("|=====================================================================================================================|");
    gotoab(0,2);printf("|=====================================================================================================================|");
    gotoab(0,4);printf("|=====================================================================================================================|");
	gotoab(40,1);printf("               Hasil Sorting                 ");
	gotoab(2,3);printf("Nama");
	gotoab(30,3);printf("Kuantitas");
	gotoab(60,3);printf("Harga");
	gotoab(100,3);printf("Tanggal");

	for(i = 0; i < n; i++){
		while(dt != NULL){
		gotoab(2,5+i);printf("%s", dt->nama);
		gotoab(30,5+i);printf("%s", dt->jumlah);
		gotoab(60,5+i);printf ("%s", dt->harga);
		gotoab(100,5+i);printf ("%s", dt->tanggal);
		dt = dt->next;
		i++;
		}
	}
	printf("\n");

	getch();
	cls();
	menu();
}



void history()
{
	int i = 5, j = 1;
	struct hist *ct;
	ct = (struct hist*) malloc(sizeof(struct hist));
	ct = headhist;

	gotoab(10,0);printf("|================================================================================================|");
    gotoab(10,2);printf("|================================================================================================|");

	gotoab(40,1);printf("              Riwayat Kegiatan             ");
	gotoab(40,3);printf("                Kegiatan Anda              ");

	while(ct != NULL){
		gotoab(10,i);printf("%d.    %s", j, ct->aktivitas);
		ct = ct->next;
		i++;
		j++;
	}
	printf("\n");

	getch();
}



void printB(){
    int height = 5;
    int width = (2 * height) - 1;

 int i, j, half = (height / 2);
    for (i = 0; i < height; i++) {
        printf("*");
        for (j = 0; j < width; j++) {
            if ((i == 0 || i == height - 1 || i == half)
                && j < (width - 2))
                printf("*");
            else if (j == (width - 2)
                     && !(i == 0 || i == height - 1
                          || i == half))
                printf("*");
            else
                printf(" ");
        }Sleep(500);
        printf("\n");
}printf("\n");
}


void printY()
{
    int height = 5;
    int width = (2 * height) - 1;

int i, j, counter = 0;
    for (i = 0; i < height; i++) {
        for (j = 0; j <= height; j++) {
            if (j == counter
                || j == height - counter
                       && i <= height / 2)
                printf("*");
            else
                printf(" ");
        }Sleep(500);
        printf("\n");
        if (i < height / 2)
            counter++;
    }printf("\n");
}

void printE()
{
    int height = 5;
    int width = (2 * height) - 1;

int i, j;
    for (i = 0; i < height; i++) {
        printf("*");
        for (j = 0; j < height; j++) {
            if ((i == 0 || i == height - 1)
                || (i == height / 2
                    && j <= height / 2))
                printf("*");
            else
                continue;
        }Sleep(500);
        printf("\n");
    }
}



void akhir(){
    printB();
    printY();
    printE();
}
