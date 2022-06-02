/*
Peserta Kelompok:
1. Ryan Daniel Asatama Sibagariang (NPM:2006574616)
2. Paramarddhika Alfarist Bustaman (NPM:2006465445)
3. Dhandy Radya Prananda (NPM:2006465685)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#define SIZE 10
#include "jumlah.c"
#include "jumlah.h"

struct listNode {	//struct linked list
	char nama[50]; 			
	float ipk;
	struct listNode *nextPtr;
};

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

struct node {		//struct binary tree
	float nilai_akhir;
	char nama[50];
	struct node *left;
	struct node *right;
};

typedef struct node* mynode;

void login();		//deklarasi fungsi
void menu();
void panduan();
void datadiri_nilai();
float IP( int nilai[SIZE][6],  int i, int j );
void sort( float arrMean[], char arrNPM[SIZE][50], float arrSum[], char arrNama[SIZE][50], char arrJurusan[SIZE][50], char arrStatus[SIZE][50], int n );
void swapFloat( float *x, float *y );
void swapChar(char *x, char *y);
void cariPelajar();
int cari(char carinpm[SIZE][50], char npm[][50], int c, int z, char arrNama[SIZE][50], char arrJurusan[SIZE][50], char arrStatus[SIZE][50]);
int akhirProgram(int x);
void linked_list();
void linkedlist_instructions();
void insertNode(ListNodePtr *sPtr, float ipk[], char nama[][50], int x);
void deleteNode(ListNodePtr *sPtr, char nama[]);
int isEmpty(ListNodePtr sPtr);
void printList(ListNodePtr currentPtr);
void binary_tree();
void binarytree_instructions();
mynode create_node (char nama[][50], float nilai_akhir[], int y);
mynode insert(mynode root, char nama[][50], float nilai_akhir[], int y);
void displayIn(mynode node);
void search_node(mynode root, float nilai_akhir);
mynode delete_node(mynode root, float nilai_akhir);

char nama[SIZE][50];	//deklarasi variabel
char npm[SIZE][50];
char jurusan[SIZE][50];
char status_akademis[SIZE][50];
int nilai_semester[SIZE][6];
float ip_semester[SIZE][6];
float sum[SIZE];
float Mean[SIZE];		//IPK
int count, count1;

int main () {
	system("cls");  	  // membersihkan layar
	system("Color 1F");   // memberikan warna pada background dan teks
	
	int i;
	
	printf("\n\n\n\n\n\n\n");
	printf("\n\t\t\t\t\t==========================================");		//mencetak tampilan awal program
	printf("\n\t\t\t\t\t\tBESTIE SCHOLARSHIP SELECTOR\t\t");
    printf("\n\t\t\t\t\t\t  Universitas Indonesia\t\t");
    printf("\n\t\t\t\t\t==========================================");
    printf("\n\t\t\t\t\t\t      Diprogram oleh:\t\t\n");
    printf("\n\t\t\t\t\t\tRyan Daniel Asatama Sibagariang\t\t\n\t\t\t\t\t\tParamarddhika Alfarist Bustaman\t\t\n\t\t\t\t\t\tDhandy Radya Prananda\n");
    printf("\n\t\t\t\t\t------------------------------------------");
    printf("\n\t\t\t\t\t       Tekan 'ENTER' untuk memulai\n");
	getch();
	
	system ("cls");
	printf ("\t\t");
	printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tLoading");		//loading screen
	printf ("\n\n\t\t\t\t      ");
	for(i = 0 ; i < 43 ; i++) {
		printf(".");
		Sleep(10);
	}
	
    system("cls");
    login();
	
	return 0;
}

void login() { //function login
	char username[20]; 				//menyimpan username
	char password[3]; 				//menyimpan password 
	int i; 
	printf("\n\n\n\t\t\t\t\t==========================================");
        printf("\n\t\t\t\t\t\t       SELAMAT DATANG\t\t");
        printf("\n\t\t\t\t\t\t  BESTIE SCHOLARSHIP SELECTOR\t\t");
        printf("\n\t\t\t\t\t==========================================");

	printf("\n\n\t\t\t\t\t\tEnter your username (6 Kata) : "); 
	scanf("%s",username); 										//input username 
	
	printf("\t\t\t\t\t\tEnter your password (6 Kata) : "); 		//input password
   
   	for(i = 0; i < 6; i++){ 									//enkripsi password
   		password[i] = getch(); 
   		printf("*");   	 
	} 
	password[i] = '\0'; 
 

	printf("\n\n\t\t\t\t\t------------------------------------------");
	printf("\n\t\t\t\t\t\tPress any key to continue"); 
  	getch(); 
  
  	if(!strcmp(username,"BESTIE") && !strcmp(password,"BESTIE")) { 		//username and passsword checking
  		printf("\n\t\t\t\t\t\tLogged In Successful");					//username and passsword benar
  		for(i = 0 ; i < 5 ; i++) {
		printf(".");
		Sleep(150);
		}
		
  		system("cls");
  		menu();
  	}
  	else { 
  		printf("\n\t\t\t\t\t\tIncorrect username or password\n");
  		login();    												    //username and passsword salah 
  	} 
}

void menu() { //function untuk menu
	int pil;
	int n;
    int end = 0;
	
    while (end == 0) {
        system("cls");
        printf("\n");
        printf("\n\t\t\t\t\t==========================================");		//menu program
        printf("\n\t\t\t\t\t\t\t    MENU\t\t");
        printf("\n\t\t\t\t\t\t  BESTIE SCHOLARSHIP SELECTOR\t\t");
        printf("\n\t\t\t\t\t==========================================");
        printf("\n\n");
        printf("\t\t\t\t\t\t[0] Panduan Program\n");
		printf("\t\t\t\t\t\t[1] Input Data Diri dan Nilai Pelajar\n");
		printf("\t\t\t\t\t\t[2] Penyeleksian Beasiswa\n");
		printf("\t\t\t\t\t\t[3] Cari Pelajar\n");
		printf("\t\t\t\t\t\t[4] Linked List\n");
		printf("\t\t\t\t\t\t[5] Binary Tree\n");
		printf("\t\t\t\t\t\t[6] Keluar\n");
		printf("\n\t\t\t\t\t------------------------------------------\n");
		do{
			printf("\t\t\t\t\t\tPilihan menu: ");		//input pilihan menu
       		scanf("%d", &n);
       		
       		if(n < 0 || n > 6){
       			printf("\t\t\t\t\t\tInvalid input!\n\n");
			}
		}while(n < 0 || n > 6);
        
          
        switch(n) {										//menjalankan menu program sesuai dengan input pilihan
        	case 0:
                panduan();
                getch();
                break;
            case 1:
                datadiri_nilai();
                getch();
                break;
            case 2:
                sort(Mean, npm, sum, nama, jurusan, status_akademis, count);
                getch();
                break;
            case 3:
                cariPelajar();
                getch();
                break;
            case 4:
            	linked_list();
            	getch();
            	break;
            case 5:
            	binary_tree();
            	getch();
            	break;
            case 6:
				end = akhirProgram(end);
				getch();
                break;		// mengakhiri program
        }
 	}
}

void panduan(){		//function untuk panduan program
	system("cls");
	int i;
	
	printf("\t\t");
	for(i = 0; i < 30; i++){
		printf("==");
		Sleep(30);
	}
		
	printf("\n\t\t\tPanduan Program BESTIE SCHOLARSHIP SELECTOR");
	
	printf("\n\t\t");
	for(i = 0; i < 30; i++){
		printf("==");
		Sleep(30);
	}
	
	printf("\n\n\t1. Program dapat melakukan beberapa kali proses input data dengan menggunakan fitur 'Binary Tree'");
	printf("\n\t2. Program akan menginput data dari mahasiswa berupa Nama, NPM, Jurusan, dan Status Akademis");
	printf("\n\t3. Program juga akan menginput nilai mahasiswa berupa nilai keseluruhan untuk semester 1 sampai 6");
	printf("\n\t4. Program akan melakukan seleksi untuk mencari 3 orang dengan IPK teratas untuk menerima program");
	printf("\n\t   beasiswa BESTIE");
	printf("\n\t5. Program dapat mencari data mahasiswa yang telah mendaftar beasiswa (apakah lolos/tidak lolos)");
	printf("\n\t6. Terdapat beberapa fitur tambahan pada program, yaitu fitur 'Linked List' dan fitur 'Binary Tree'");
	printf("\n\t7. Fitur 'Linked List' mempunyai fungsi dalam Menambahkan, Mengurutkan, serta Menghapus data");
	printf("\n\t   peserta yang mengikuti penyeleksian program beasiswa BESTIE");
	printf("\n\t8. Fitur 'Binary Tree' mempunyai fungsi dalam Menambahkan, Menampilkan, Mengurutkan, Menghapus,");
	printf("\n\t   serta Mencari data peserta yang mengikuti penyeleksian program beasiswa BESTIE");
	printf("\n\t9. Terdapat pilihan menu \"keluar\" pada fitur 'Binary Tree' dan 'Linked List' agar user dapat");
	printf("\n\t   keluar dari fitur tersebut dan masuk ke menu utama pada program");
	printf("\n\t10.Jika program tidak digunakan maka user dapat memilih \"keluar\" pada pilihan menu utama");
	
	printf("\n\n\t\t\t Anda akan kembali ke bagian menu selama 5 detik");	
	for(i = 0; i < 5; i++){
		printf(".");
		Sleep(1000);
	}
	menu();		
}

void datadiri_nilai(){ //fucntion untuk menginput data diri dan nilai mahasiswa
	system("cls");

	int i = 0;
	int j, sentinel1;
	
	printf("\n\t\t\t\t\t==========================================");
    printf("\n\t\t\t\t\t     INPUT DATA DIRI DAN NILAI\t\t");
    printf("\n\t\t\t\t\t    BESTIE SCHOLARSHIP SELECTOR\t\t");
    printf("\n\t\t\t\t\t==========================================");
	
	printf("\n\nSilakan memasukkan input data diri dan nilai mahasiswa");
	do{
		printf("\n\nNama Mahasiswa : ");
		scanf(" %255[^\n]s", nama[i]);
		fflush(stdin);
		
		printf("NPM : ");
		scanf(" %255[^\n]s",npm[i]);
		fflush(stdin);
		
		printf("Jurusan : ");
		scanf(" %255[^\n]s", jurusan[i]);
		fflush(stdin);
		
		do{
			printf("Status Akademis (Wajib Aktif): ");
			scanf(" %255[^\n]s", status_akademis[i]);
			fflush(stdin);
			if(!strcmp(status_akademis[i], "Aktif"))	//error handling
				break;
			else
				printf("\nInput yang dimasukkan tidak sesuai\n");
		}while(1);
		
		printf("\n");
		printf("Masukkan input nilai semester 1 sampai 6 (nilai dalam integer)\n");
		for(j = 0; j < 6; j++) {
			do{
				printf("Nilai Semester %d : ", j+1);
				scanf("%d", &nilai_semester[i][j]);
				if(nilai_semester[i][j] < 0 ||  nilai_semester[i][j] > 100)		//error handling
					printf("Nilai input invalid\n");
			} while(nilai_semester[i][j] < 0 || nilai_semester[i][j] > 100);

			ip_semester[i][j] = IP(nilai_semester, i, j);
			sum[i] = summary(ip_semester, i, 6);
		}
		
		Mean[i] = sum[i] / 6;
		i++;
		count++;
		
		do{
			printf("\ninput data lagi? (0 untuk lanjut, -1 untuk selesai)\n>>");
			scanf("%d", &sentinel1);
			if(sentinel1 != 0 && sentinel1 != -1)	//error Handling
				printf("Nilai input invalid\n");	
		}while(sentinel1 != 0 && sentinel1 != -1);
		
	} while(sentinel1 != -1);
	
	system("cls");
	printf("\n\n\t\t=====Data Sebelum Diseleksi=====\n");	//mencetak data input sebelum sorting
	for(i = 0; i < count; i++) {
		printf("\nNama: %s", nama[i]);
		printf("\nNPM: %s", npm[i]);
		printf("\nJurusan: %s", jurusan[i]);
		printf("\nStatus Akademis: %s\n", status_akademis[i]);
		for(j = 0; j < 6; j++) {
			printf("IP Semester %d: %.2f\n", j+1, ip_semester[i][j]);
		}
		printf("Total IP: %.2f", sum[i]);
		printf("\nIPK: %.2f\n", Mean[i]);
	}
	printf("\n\nPress any key to continue");
	
}

float IP(int nilai[SIZE][6], int i, int j) { //function untuk mengkonversi nilai input ke indeks IP
	int angka;
	
	angka = nilai[i][j];
	
	switch(angka){
		case 85 ... 100:
			return 4.00;
			break;
		case 80 ... 84:
			return 3.70;
			break;
		case 75 ... 79:
			return 3.30;
			break;
		case 70 ... 74:
			return 3.00;
			break;
		case 65 ... 69:
			return 2.70;
			break;
		case 60 ... 64:
			return 2.30;
			break;
		case 55 ... 59:
			return 2.00;
			break;
		case 40 ... 54:
			return 1.00;
			break;
		case 0 ... 39:
			return 0.00;
			break;
	}
}

void sort(float arrMean[], char arrNPM[SIZE][50], float arrSum[], char arrNama[SIZE][50], char arrJurusan[SIZE][50], char arrStatus[SIZE][50], int n) {	//function bubble sort
	int i, j;
	
	for(i = 0; i < n; i++) {
		for(j = 0; j < n - 1; j++) {
			if(arrMean[j+1] > arrMean[j]) {
				swapFloat(&arrMean[j+1], &arrMean[j]);
				swapFloat(&arrSum[j+1], &arrSum[j]);
				swapChar(arrNPM[j+1], arrNPM[j]);
				swapChar(arrNama[j+1], arrNama[j]);
				swapChar(arrJurusan[j+1], arrJurusan[j]);
				swapChar(arrStatus[j+1], arrStatus[j]);
			}
		}
	}
	
	system("cls");
	printf("\n\n\t\t=====Data Setelah Diseleksi=====");	//mencetak data input setelah sorting
	for(i = 0; i < n; i++) {
		printf("\n\n%d. Nama: %s", i+1, arrNama[i]);
		printf("\n   NPM: %s", arrNPM[i]);
		printf("\n   Jurusan: %s", arrJurusan[i]);
		printf("\n   Status Akademis: %s", arrStatus[i]);
		printf("\n   Total IP: %.2f", arrSum[i]);
		printf("\n   IPK: %.2f", arrMean[i] );
	}
	printf("\n\nPress any key to continue");
		
}

void swapFloat(float *x, float *y) {	//function swap untuk float dalam sorting
	float temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void swapChar(char *x, char *y){	//function swap untuk character dalam sorting
	char *temp = (char *)malloc((strlen(x) + 1) * sizeof(char));
	strcpy(temp, x);
	strcpy(x, y);
	strcpy(y, temp);
	free(temp);	//membebaskan ruang memori
}

void cariPelajar() {	//function untuk mencari data input mahasiswa
	
	int sentinel2, z = 0;
	char carinpm[SIZE][50];
	
	do{
		
		system("cls");
		printf("\n\nMasukkan Nilai NPM Mahasiswa yang Ingin Dicari");
		printf("\nNPM mahasiswa : ");
		scanf(" %255[^\n]s", carinpm[z]);
		cari(carinpm, npm, count, z, nama, jurusan, status_akademis);
		z++;
		
		do{
			printf("\n\nIngin mencari lagi? (0 untuk lanjut, -1 untuk selesai)\n>>");
			scanf("%d", &sentinel2);
			if(sentinel2 != 0 && sentinel2 != -1)	//error handling
				printf("Nilai input invalid\n");	
		}while(sentinel2 != 0 && sentinel2 != -1);
		
	} while( sentinel2 != -1 );
	printf("\n\nPress any key to continue");
	
}

int cari(char carinpm[SIZE][50], char npm[][50], int c, int z, char arrNama[SIZE][50], char arrJurusan[SIZE][50], char arrStatus[SIZE][50]) {	//function linear searching
	int i;
    for(i = 0; i < c; i++){
      	if(strcmp(carinpm[z], npm[i]) == 0){
	  		printf("\n\nData ada pada sistem");
	  		printf("\nNama : %s", arrNama[i]);
			printf("\nNPM: %s", npm[i]);
			printf("\nJurusan: %s", arrJurusan[i]);
			printf("\nStatus Akademis: %s\n", arrStatus[i]);
			if(Mean[i] == Mean[0] || Mean[i] == Mean[1] || Mean[i] == Mean[2])	//jika mahasiswa yang dicari lolos
				printf( "\nSELAMAT ANDA LOLOS SELEKSI BESTIE SCHOLARSHIP" );
			else
				printf( "\nMOHON MAAF ANDA TIDAK LOLOS SELEKSI BESTIE SCHOLARSHIP" ); //jika mahasiswa yang dicari tidak lolos
	  		return 0;
		}
	}
	printf("\n\nData tidak ada pada sistem");	
}

int akhirProgram(int x) {	//function untuk mengakhiri program
	x = 1;
	system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n       __________________________________________________________________________________________________________\n");
    printf("\n\t\t\t\t\t\t      Terimakasih\n\n");
    printf("\t\t\t\t\t  -Ryan Daniel, Paramarddhika, Dhandy-\n");
    printf("       __________________________________________________________________________________________________________\n");
    return x;
}

void linked_list() {      // function linked list pada program 
	ListNodePtr startPtr = NULL;
	int choice = 0, i = 0;
	char name[50];
	
	count1 = 0;
	
	linkedlist_instructions();
	do{										  //Error Handling
		printf("\t\t\t\t\t\tPilihan menu: "); // masukkan input untuk memilih menu 
		scanf( "%d", &choice );	
	
		if( choice < 1 || choice > 4 )
		printf("\t\t\t\t\t\tInvalid input!\n\n");
	}while( choice < 1 || choice > 4 );
		
	for(i = 0; i < count + count1; i++){
		insertNode(&startPtr, Mean, &nama[i], i);
	}
					
	while(choice != 4){	   // memilih menu berdasarkan input yang telah dimasukkan user
		switch (choice) {
			case 1:
				system("cls");
				printList(startPtr);  //Memanggil function printlist
				printf("\n\nPress any key to continue"); 
				getch();
				break;
			case 2:
				system("cls");
				printf("\nNama Mahasiswa : ");
				scanf(" %255[^\n]s", nama[count + count1]);
				fflush(stdin);
				
				do{						//Error Handling
					printf("IPK: ");
					scanf("\n%f", &Mean[count + count1]);
					
					if(Mean[count + count1] < 0 || Mean[count + count1] > 4) {
						printf("Input IPK invalid.\n\n");
					}
				}while(Mean[count + count1] < 0 || Mean[count + count1] > 4);			
				
				insertNode(&startPtr, Mean, &nama[count + count1], (count + count1));  //Memanggil function insertNode
				
				count1++;
				printf("\n\nPress any key to continue"); 
				getch();
				break;
			case 3:
				system("cls");
				if (!isEmpty( startPtr )) {
					printf("Nama yang ingin dihapus: ");
					scanf(" %255[^\n]s", name);
					deleteNode (&startPtr, name);	//Memanggil function deleteNode
				}
				else {
					printf("List kosong.\n\n");
				}
				
				printf("\n\nPress any key to continue"); 
				getch();
				break;
			default:
				printf("\t\t\t\t\t\tInvalid input!\n\n");
				break;
		}
		
		linkedlist_instructions();
		do{												//Error Handling
			printf("\t\t\t\t\t\tPilihan menu: ");
			scanf( "%d", &choice );	
		
			if( choice < 1 || choice > 4 ){
				printf("\t\t\t\t\t\tInvalid input!\n\n");
			}		
		}while( choice < 1 || choice > 4 );
	}
}

void linkedlist_instructions() {
	system("cls");
	printf("\n\t\t\t\t\t==========================================");		//menu linked list
        printf("\n\t\t\t\t\t\t\t    MENU\t\t");
        printf("\n\t\t\t\t\t\t\t  LINKED LIST\t\t");
        printf("\n\t\t\t\t\t==========================================");
        printf("\n\n");
        printf("\t\t\t\t\t\t[1] List data\n");
        printf("\t\t\t\t\t\t[2] Insert data\n");
		printf("\t\t\t\t\t\t[3] Delete data\n");
		printf("\t\t\t\t\t\t[4] Keluar\n");
		printf("\n\t\t\t\t\t------------------------------------------\n");
}

void insertNode(ListNodePtr *sPtr, float ipk[], char nama[][50], int x) {  //function pada linked list (untuk menambahkan nama dan IPK)
	ListNodePtr newPtr;
	ListNodePtr previousPtr;
	ListNodePtr currentPtr;
	
	newPtr = malloc( sizeof(ListNode) );
	
	if (newPtr != NULL) {
		strcpy(newPtr->nama, *nama);
		newPtr->ipk = ipk[x];
		newPtr->nextPtr = NULL;
	
		previousPtr = NULL;
		currentPtr = *sPtr;
	
		//sorting data
		while (currentPtr != NULL && ipk[x] < currentPtr->ipk) {  
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}

		if (previousPtr == NULL) {
			newPtr->nextPtr = *sPtr;
			*sPtr = newPtr;
		}
		else {
			previousPtr->nextPtr = newPtr;
			newPtr->nextPtr = currentPtr;
		}
	}
	else {
		printf("%f not inserted. No memory available.\n", ipk[x]);
	}
}

void deleteNode(ListNodePtr *sPtr, char nama[]) {  //function pada linked list (untuk menghapus nama dan IPK)
	ListNodePtr previousPtr;
	ListNodePtr currentPtr;
	ListNodePtr tempPtr;

	if (strcmp( nama, (*sPtr)->nama ) == 0) {  // jika data berada di posisi pertama
		tempPtr = *sPtr;
		*sPtr = ( *sPtr )->nextPtr;
		free( tempPtr );	
		printf( "%s dihapus.\n", nama );
	}	
	
	else { 									// jika data tidak berada di posisi pertama
		previousPtr = *sPtr;
		currentPtr = (*sPtr)->nextPtr;

		while (currentPtr != NULL && strcmp(nama, currentPtr->nama) != 0) {
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}

		if (currentPtr != NULL) {
			tempPtr = currentPtr;
			previousPtr->nextPtr = currentPtr->nextPtr;
			free(tempPtr);
			printf("%s dihapus.\n", nama);
		}
		
		else { 											// jika ada suatu data yang tidak terdaftar
			printf("%s tidak ditemukan.\n\n", nama);	
		}	
	}
}

int isEmpty(ListNodePtr sPtr) {  //function pada linked list (jika tidak ada data sama sekali)
	return sPtr == NULL;	
}

void printList(ListNodePtr currentPtr) {  //function pada linked list (untuk menampilkan nama dan IPK)
	
	if (currentPtr == NULL) {
		printf("\nList kosong.\n\n");
	}
	else {
		printf("\nList Data Mahasiswa:\n");
		
		while (currentPtr != NULL) {
			printf("Nama: %s\n", currentPtr->nama);
			printf("IPK: %.2f\n\n", currentPtr->ipk);
			currentPtr = currentPtr->nextPtr;
		}
	}
}

void binary_tree() {       // function binary tree pada program
	int tree = 0, y = 0;
	float nilai_akhir;
	
	mynode root = NULL;
		
	while (tree != 5){ 		
		binarytree_instructions();
		
		printf("\n\t\t\t\t\t------------------------------------------\n");
		do{														//Error Handling
			printf("\t\t\t\t\t\tMasukkan pilihan menu : ");
			scanf("%d", &tree);
			if(tree < 0 || tree > 5) {
				printf("\t\t\t\t\t\tInvalid input!\n\n");
			}		
		}while(tree < 0 || tree > 5);
		
		switch (tree) {				//Menjalankan menu program sesuai dengan input pilihan
	        case 1:
	        	system("cls");
				printf("\n\nMasukkan input IPK dan nama mahasiswanya \n");
				printf("Nama : ");
				scanf(" %255[^\n]s", nama[y]);
				
				do{										//Error Handling
					printf("IPK: ");
					scanf("\n%f", &Mean[y]);
					
					if(Mean[y] < 0 || Mean[y] > 4) {
						printf("Input IPK invalid.\n\n");
					}
				}while(Mean[y] < 0 || Mean[y] > 4);
								
				root = insert(root, &nama[y] , Mean, y);  //pemanggilan function insert
				printf("\nPress any key to continue");
				getch();
	           	break;
	        case 2:
	        	system("cls");
	            printf("\n\nMasukkan input IPK yang ingin dicari : \n");
	            scanf("%f", &nilai_akhir);
	            search_node(root, nilai_akhir);  //pemanggilan function search_node
	            
	            printf("\nPress any key to continue");
				getch();
	            break;
	        case 3:
	        	system("cls");
	        	printf("\n\nINPUT IPK YANG DIHAPUS TIDAK MERUPAKAN INPUT INSERT YANG PERTAMA KALI");
	        	printf("\n(Jika input delete adalah input pertama maka binary tree kosong)");
	        	
	        	printf("\nMasukkan input IPK yang ingin dihapus : \n");
	        	scanf("%f", &nilai_akhir);
	            delete_node(root, nilai_akhir); //pemanggilan function delete_node
	            printf("\nPress any key to continue"); 
				getch();
	            break;
	        case 4:
	        	system("cls");
	        	printf("\n\n");
	          	displayIn(root); //pemanggilan function displayIn
	          	printf("\nPress any key to continue");
				getch();
	           	break;
	        case 5:				// mengakhiri program
	        	break;
	    }
	}
}

void binarytree_instructions() {
	system("cls");
	printf("\n\t\t\t\t\t==========================================");		//menu binary tree
    printf("\n\t\t\t\t\t\t\t    MENU\t\t");
    printf("\n\t\t\t\t\t\t\t  BINARY TREE \t\t");
    printf("\n\t\t\t\t\t==========================================");
    printf("\n\n");
    printf("\t\t\t\t\t\t[1] Insert data\n");
    printf("\t\t\t\t\t\t[2] Search data\n");
	printf("\t\t\t\t\t\t[3] Delete data\n");
	printf("\t\t\t\t\t\t[4] Display data\n");
	printf("\t\t\t\t\t\t[5] Keluar\n");
}

mynode create_node (char nama[][50], float nilai_akhir[], int y){  // function pada binary tree (membuat node pada tree)
	mynode new_node = (mynode)malloc(sizeof(struct node));
	strcpy(new_node->nama, nama[y]);
	new_node->nilai_akhir = nilai_akhir[y];
	new_node->left = NULL;
	new_node->right = NULL;
	return(new_node);
}

mynode insert(mynode root, char nama[][50], float nilai_akhir[], int y){ // function pada binary tree (memasukkan data pada tree)
	if (root == NULL){									// Jika kondisi tree tidak ada data
		root = create_node(&nama[y], nilai_akhir, y);
		return (root);
	} 
	else { 						// Jika kondisi tree sudah ada data
		int is_left = 0;
		mynode cursor = root;
		mynode prev = NULL;
		
		// sorting data
		while (cursor != NULL){  
			prev = cursor;
			if (nilai_akhir[y] < cursor->nilai_akhir){
				is_left = 1;
				cursor = cursor->left;
			}
			else if (nilai_akhir[y] > cursor->nilai_akhir){
				is_left = 0;
				cursor = cursor->right;
			}
		}
		
		if (is_left == 1){
			prev->left = create_node(&nama[y], nilai_akhir, y);
		}
		else {
			prev->right = create_node(&nama[y], nilai_akhir, y);
		}
		return (root);
	}
};


void displayIn(struct node *noded) {   //function pada binary tree (menampilkan data secara In-order)
	if(noded == NULL){
		return;
	}
	
	displayIn(noded->right);
	printf("IPK : %.2f, Nama mahasiswa : %s \n", noded->nilai_akhir, noded->nama);
	displayIn(noded->left);	
}

void search_node(mynode root, float nilai_akhir){  //function pada binary tree (mencari data)
	mynode cursor = root;
	
	while (cursor->nilai_akhir != nilai_akhir){
		if (cursor != NULL){
			if(nilai_akhir > cursor->nilai_akhir){
				cursor = cursor->right;
			}
			else {
				cursor = cursor->left;
			}
			if (cursor == NULL){
				printf("\nIPK %.2f tidak ditemukan\n", nilai_akhir);
				return;
			}
		}
	}
	printf("\nIPK %.2f ditemukan\n", nilai_akhir);
	return;
}

mynode delete_node(mynode root, float nilai_akhir){  //function pada binary tree (menghapus data)
	if(root == NULL)
		return root;
	
	mynode cursor;
	if(nilai_akhir > root->nilai_akhir){
		root->right = delete_node(root->right, nilai_akhir);	
	}

	else if(nilai_akhir < root->nilai_akhir){
		root->left = delete_node(root->left, nilai_akhir);
	}
	else {
		if(root->left == NULL){
			cursor = root->right;
			free(root);
			printf("\nIPK %.2f dihapus\n", nilai_akhir);
			root = cursor;
		}
		else if(root->right == NULL){
			cursor = root->left;
			free(root);
			printf("\nIPK %.2f dihapus\n", nilai_akhir);
			root = cursor;
		}
		else {
			cursor = root->right;
			while(cursor->left != NULL){
				cursor = cursor->left;
			}
		root->nilai_akhir = cursor->nilai_akhir;
		root->right = delete_node(root->right, cursor->nilai_akhir);
		}
	}
	return (root);
}
