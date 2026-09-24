/*Saya Bentar Bintang Umeir sebagai manusia yang berTuhan, saya mengerjakan evaluasi 
Tugas Masa Depan dalam mata kuliah Dasar-dasar Pemrograman untuk keberkahanNya maka
saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include <stdio.h>
#include <string.h>

//warna text
#define RESET  "\033[0m"
#define RED    "\033[31m"
#define GREEN  "\033[32m"
#define YELLOW "\033[33m"
#define CYAN   "\033[36m"
#define BLUE   "\033[34m"

typedef struct { //struck untuk tabel data utama 
    char key_nama[301];       //primary key
    char nama[301];           //nama mahasiswa
    char key_skill[301];      //foreign key
    char key_bidang[301];     //foreign key
    char key_kota[301];       //foreign key
} mahasiswa;

typedef struct { //struck untuk table foreign
    char key_nama[301];  //foreign key
    char nama[301];      //nama pada foreign
} foreign;

//VARIABEL GLOBAL untuk mesin kata
extern int indeks;
extern int wlen;
extern char cw[101];

//MESIN KATA
void start(char pita[]);
int eop(char pita[]);
void inc(char pita[]);
void reset();
char* getcw(); 
int getlen();

//READ FILE
void read_mahasiswa(int *indeks, mahasiswa source[]);
void read_skill(int *indeks, foreign source[]);
void read_bidang(int *indeks, foreign sourcce[]);
void read_kota(int *indeks,foreign source[]);

//WRITE FILE
void write_mahasiswa(int indeks, mahasiswa source[]);
void write_mahasiswacomplete(int indeks, mahasiswa source[]);
void write_skill(int indeks, foreign source[]);
void write_bidang(int indeks, foreign source[]);
void write_kota(int indeks, foreign source[]);

//INSERT
void insert_mahasiswa(int indeks, mahasiswa source[]);  
void insert_foreign(int indeks, foreign source[]);

//UPDATE
void update_mahasiswa(int indeks, mahasiswa source[], char carikode[], char nama[], char kode_skill[], char kode_bidang[], char kode_kota[]);
void update_foreign(int indeks, foreign source[], char carikode[], char nama[]);

//DELETE
void delete_mahasiswa(int *indeks, mahasiswa source[], char carikey[]);  
void delete_foreign(int *indeks, foreign source[], char carikey[]);

//SELECT
void tabelmahasiswa(int indeks, mahasiswa source[]);
void tabelskill(int indeks, foreign source[]);
void tabelbidang(int indeks, foreign source[]);
void tabelkota(int indeks, foreign source[]);

//JOIN
void join(mahasiswa a[], foreign b[], foreign c[], foreign d[]);

//PRINT
void intro();
void guide();
void outro();