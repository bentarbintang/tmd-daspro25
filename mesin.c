#include "headerTMD.h"

int indeks;
int wlen;
char cw[101];

void start(char pita[]){
    // set index dan panjang kata menjadi 0
    indeks = 0;
    wlen = 0;

    while (pita[indeks] == ' '){ // ignore blank
        indeks++;
    }
    
    // ambil kata masukkan dalam current word
    while ((pita[indeks] != ' ') && (eop(pita) == 0)){
        cw[wlen] = pita[indeks];
        wlen++;
        indeks++;
    }
    cw[wlen] = '\0'; // akhiri dengan null terminator
}

//cek eop
int eop(char pita[]){
    if(pita[indeks] == ';'){ // jika '.' return 1
        return 1;
    } else{
        return 0; // jika bukan '.' kembalikan 0
    }
}

// reset current word
void reset(){
    wlen = 0; // kembalikan panjang kata menjadi 0
    cw[wlen] = '\0'; // set current word menjadi null (siap diisi)
}

// pindah next kata
void inc(char pita[]){
    wlen = 0; // set panjang kata jadi 0 (memastikan)
    while (pita[indeks] == ' '){ // ignore blank
        indeks++;
    }

    // masukkan kata baru
    while ((pita[indeks] != ' ') && pita[indeks] != ';' && (eop(pita) == 0)){
        cw[wlen] = pita[indeks];
        wlen++;
        indeks++;
    }
    cw[wlen] = '\0'; // akhiri lagi
}

// mengembalikan current word
char* getcw(){
    return cw;
}

// mengembalikan panjang current word
int getlen(){
    return wlen;
}


//prosedur membaca datamahasiswa.txt yang berisi foreign key foreign key
void read_mahasiswa(int *indeks, mahasiswa source[]){
    *indeks = 0;
    FILE *ftemp;

    ftemp = fopen("Mahasiswa.txt", "r");

    int returnVal = fscanf(ftemp, "%s %s %s %s %s", source[*indeks].key_nama, source[*indeks].nama, source[*indeks].key_skill, source[*indeks].key_bidang, source[*indeks].key_kota);

    if(strcmp(source[*indeks].key_nama, "####") == 0 || returnVal == EOF){
        printf("FILE KOSONG\n");
    } else{
        while(strcmp(source[*indeks].key_nama, "####") != 0){ // selama bukan data EOF
            *indeks = *indeks + 1; // maju ke indeks penampung berikutnya
            fscanf(ftemp, "%s %s %s %s %s", source[*indeks].key_nama, source[*indeks].nama, source[*indeks].key_skill, source[*indeks].key_bidang, source[*indeks].key_kota);
        }
    }
    fclose(ftemp); // tutup file
}

void read_skill(int *indeks, foreign source[]){
    *indeks = 0;
    FILE *ftemp;

    ftemp = fopen("Skill.txt", "r");

    int returnVal = fscanf(ftemp, "%s %s", source[*indeks].key_nama, source[*indeks].nama);

    if(strcmp(source[*indeks].key_nama, "####") == 0 || returnVal == EOF){
        printf("FIlE KOSONG\n");
    } else{
        while(strcmp(source[*indeks].key_nama, "####") != 0){ // selama bukan data EOF
            *indeks = *indeks + 1; // maju ke indeks penampung berikutnya
            fscanf(ftemp, "%s %s", source[*indeks].key_nama, source[*indeks].nama);
        }
    }
    fclose(ftemp); // tutup file
}

void read_bidang(int *indeks, foreign source[]){
    *indeks = 0;
    FILE *ftemp;

    ftemp = fopen("Bidang.txt", "r");

    int returnVal = fscanf(ftemp, "%s %s", source[*indeks].key_nama, source[*indeks].nama);

    if(strcmp(source[*indeks].key_nama, "####") == 0 || returnVal == EOF){
        printf("FILE KOSONG\n");
    } else{
        while(strcmp(source[*indeks].key_nama, "####") != 0){ // selama bukan data EOF
            *indeks = *indeks + 1; // maju ke indeks penampung berikutnya
            fscanf(ftemp, "%s %s", source[*indeks].key_nama, source[*indeks].nama);
        }
    }
    fclose(ftemp); // tutup file
}

void read_kota(int *indeks, foreign source[]){
    *indeks = 0;
    FILE *ftemp;

    ftemp = fopen("Kota.txt", "r");

    int returnVal = fscanf(ftemp, "%s %s", source[*indeks].key_nama, source[*indeks].nama);

    if(strcmp(source[*indeks].key_nama, "####") == 0 || returnVal == EOF){
        printf("FILE KOSONG\n");
    } else{
        while(strcmp(source[*indeks].key_nama, "####") != 0){ // selama bukan data EOF
            *indeks = *indeks + 1; // maju ke indeks penampung berikutnya
            fscanf(ftemp, "%s %s", source[*indeks].key_nama, source[*indeks].nama);
        }
    }
    fclose(ftemp); // tutup file
}


//prosedur write menulis suatu data ke file
void write_mahasiswa(int indeks, mahasiswa source[]){
    FILE *ftemp;
    ftemp = fopen("Mahasiswa.txt", "w");

    for(int i = 0; i < indeks; i++){
        fprintf(ftemp, "%s %s %s %s %s\n", source[i].key_nama, source[i].nama, source[i].key_skill, source[i].key_bidang, source[i].key_kota);
    }
    fprintf(ftemp, "%s %s %s %s %s\n", "####", "####", "####", "####", "####");
    fclose(ftemp);
}

void write_mahasiswacomplete(int indeks, mahasiswa source[]){
    FILE *ftemp;
    ftemp = fopen("MahasiswaComplete.txt", "w");

    for(int i = 0; i < indeks; i++){
        fprintf(ftemp, "%s %s %s %s %s\n", source[i].key_nama, source[i].nama, source[i].key_skill, source[i].key_bidang, source[i].key_kota);
    }
    fprintf(ftemp, "%s %s %s %s %s\n", "####", "####", "####", "####", "####");
    fclose(ftemp);
}

void write_skill(int indeks, foreign source[]){
    FILE *ftemp;
    ftemp = fopen("Skill.txt", "w");

    for(int i = 0; i < indeks; i++){
        fprintf(ftemp, "%s %s\n", source[i].key_nama, source[i].nama);
    }
    fprintf(ftemp, "%s %s\n", "####", "####");
    fclose(ftemp);
}

void write_bidang(int indeks, foreign source[]){
    FILE *ftemp;
    ftemp = fopen("Bidang.txt", "w");

    for(int i = 0; i < indeks; i++){
        fprintf(ftemp, "%s %s\n", source[i].key_nama, source[i].nama);
    }
    fprintf(ftemp, "%s %s\n", "####", "####");
    fclose(ftemp);
}

void write_kota(int indeks, foreign source[]){
    FILE *ftemp;
    ftemp = fopen("Kota.txt", "w");

    for(int i = 0; i < indeks; i++){
        fprintf(ftemp, "%s %s\n", source[i].key_nama, source[i].nama);
    }
    fprintf(ftemp, "%s %s\n", "####", "####");
    fclose(ftemp);
}


//prosedur menambhkan data ke tabelnya masing masing
void insert_mahasiswa(int indeks, mahasiswa source[]){
    int i = 0;
    int ketemu = 0;
    int sudah_ada = 0;
    
    mahasiswa temp = source[indeks - 1]; //meletakkan pita masukan ke indeks terakhir string indeks otomatis bertambah 1    

    //loop pertama mencari posisi sesuai dengan key dengan membandingkan key dari pita dengan key yang di data
    while(strcmp(temp.key_nama, source[i].key_nama) > 0 && strcmp(source[i].nama, "####") != 0){ 
        i++; //indeks akan naik 1 sampai key temp(key pita) sama dengan key pita yang ada di data 
    } //setelah loop ini selesai indeks akan berhenti sebelum Key pitanya dan indeksnya di simpan

    // loop kedua bertugas untuk menggerser data 
    for(int j = indeks - 1; j > i; j--){ //loop di mulai dari indeks terakhir hingga indeks terakhir dari loop pertama 
        source[j] = source[j-1]; //bergerak terus menerus mengisi j indeks sekarang dengan j indeks sebelumnya logikanya seperti memundurkan kata
    }
        source[i] = temp; //ketika loop sudah selesai menggeser, indeks yang kosong akan di isi dengan inputan yang di simpan di string sementara
        ketemu = 1; //set ketemu jadi true;

    if(ketemu == 1){
        printf(GREEN "\nSUCCESS : Data Berhasil di Tambahkan\n" RESET);
    } else{
        printf(RED "\nERROR : Data Gagal di Tambahkan\n" RESET);
    }
}

void insert_foreign(int indeks, foreign source[]){
    int i = 0;
    int ketemu = 0;
    foreign temp = source[indeks - 1]; //meletakkan pita sekarang ke indeks terakhir string indeks otomatis bertambah 1
    
    //loop mencari posisi sesuai dengan key dengan membandingkan key dari pita dengan key yang di data
        while(strcmp(temp.key_nama, source[i].key_nama) > 0 && strcmp(source[i].nama, "####") != 0) {
            i++; //indeks akan naik 1 sampai key temp(key pita) sama dengan key pita yang ada di data 
        }
        for(int j = indeks - 1; j > i; j--){ //loop di mulai dari indeks terakhir sampai indeks awal
            source[j] = source[j - 1]; //bergerak terus menerus mengisi j indeks sekarang dengan j indeks sebelumnya
        }
        source[i] = temp; //ketika data sudah selesai menggeser data i di isi dengan temp 
        ketemu = 1; //set ketemu jadi true;

    if(ketemu == 1){
        printf(GREEN "\nSUCCESS : Data Berhasil di Tambahkan\n" RESET);
    } else{
        printf(GREEN "\nERROR : Data Gagal di Tambahkan\n" RESET);
    }
}


//prosedur memperbarui data 
//membuat variabel temp untuk mengcopy data 
void update_mahasiswa(int indeks, mahasiswa source[], char carikey[], char nama[], char key_skill[], char key_bidang[], char key_kota[]){ 
    int i = 0;        //indeks data di mulai dari 0
    int ketemu = 0;   //set ketemu jadi false;

    while(ketemu == 0 && i < indeks){ //mencari key inputan pita pada data loop while selama ketemu belum true 
        if(strcmp(source[i].key_nama, carikey) == 0){ //jika key ketemu
            strcpy(source[i].nama, nama);             //copy foreign key dan atribut lainnya yang ada di array yang sesuai dengan key
            strcpy(source[i].key_skill, key_skill);   //variabel temp untuk menyimpan masukan pita
            strcpy(source[i].key_bidang, key_bidang); //fungsi data temp ini untuk menyimpan pita inputan
            strcpy(source[i].key_kota, key_kota);
            ketemu = 1;
        }
        i++; //i bertambah hingga i lebih kecil indeks
    }

    if(ketemu == 1){
        printf(GREEN "\nSUCCESS : Data Telah di Update\n" RESET);
    } else{
        printf(RED "\nERROR : Data Tidak Berhasil di Update\n" RESET);
    }
}

//membuat variabel temp untuk mengcopy data 
void update_foreign(int indeks, foreign source[], char carikey[], char nama[]){
    int i = 0;
    int ketemu = 0;

    while(ketemu == 0 && i < indeks){ //mencari key masukan pita pada data loop while selama ketemu belum true 
        if(strcmp(source[i].key_nama, carikey) == 0){ //jika key ketemu 
            strcpy(source[i].nama, nama);             //copy foreign key dan atribut lainnya yang ada di array
            ketemu = 1;
        }
        i++; //i bertambah hingga i lebih kecil dari indeks
    }

    if(ketemu == 1){
        printf(GREEN "\nSUCCES : Data Berhasil di Perbarui\n" RESET);
    } else{
        printf(RED "\nERROR : Data Tidak Berhasil di Perbarui\n" RESET);
    }
}


// prosedur menghapus data 
void delete_mahasiswa(int *indeks, mahasiswa source[], char carikey[]){
    int j;
    int ketemu = 0;

    for(int i = 0; i < *indeks; i++){                   //loop mencari primary keynya yang sama
        if(strcmp(source[i].key_nama, carikey) == 0){   //kalo primary key ketemu yang sama masuk ke loop while
            ketemu = 1;                                 //penanda ketika ketemu bernilai true yang artinya key sama

            j = i; //mengisi indeks 
            while(j < *indeks - 1){         //menggunakan loop menggunakan while karena nanti akan di break, loop ketika primary key ketemu dan loop selama j lebih kecil dari indeks terakhir
                source[j] = source[j + 1];  //data indeks ke i sekarang di isi dengan array data setelahnya atau bisa di bilang memajukan indeks 
                j++;                        //increment maju ke indeks selanjutnya
            }
            //menggunakan (*indeks)-- karena ketika data sudah di delete kita harus mengurangi indeks arraynya juga jadi harus menggunakan pointer ke indeks arraynya
            (*indeks)--; //ketika indeks sudah di naikkan kurangi indeks sekarang agar datanya juga berkurang m
            break;       //break ketika indeks usdah berkurang 1
        }
    }

    if(ketemu == 1){ //ketemu sudah true print
        printf(GREEN "\nSUCCESS : Data Berhasil di Hapus\n" RESET);
    } else{
        printf(RED "\nERROR : Data Tidak Bisa di Hapus\n" RESET);
    }  
}

void delete_foreign(int *indeks, foreign source[], char carikey[]){
    int j;
    int ketemu = 0;

    for(int i = 0; i < *indeks; i++){ //loop mencari primary keynya yang sama
        if(strcmp(source[i].key_nama, carikey) == 0){ //kalo primary key ketemu yang sama masuk ke loop while
            ketemu = 1;

            j = i; //mengcopy indeks ketika ketemu
            while(j < *indeks - 1){        //menggunakan loop menggunakan while karena nanti akan di break, loop ketika primary key ketemu dan loop selama j lebih kecil dari indeks terakhir
                source[j] = source[j + 1]; //array indeks ke i sekarang
                j++;
            }
            //menggunakan (*indeks)-- karena ketika data sudah di delete kita harus mengurangi indeks arraynya juga jadi harus menggunakan pointer ke indeks arraynya
            (*indeks)--; //ketika indeks sudah di naikkan kurangi indeks sekarang agar datanya juga berkurang
            break;       //break ketika indeks sudah berkurang 1
        }
    }

    if(ketemu == 1){
        printf(GREEN "\nSUCCESS : Data Berhasil di Hapus\n" RESET);
    } else{
        printf(RED "\nERROR : Yahh Data Tidak Bisa di Hapus\n" RESET);
    }  
}

//Posedur menampilkan data
void tabelmahasiswa(int indeks_data, mahasiswa source[]){
    //deklarasi panjang kata judulnya
    int Pkey = 11;    
    int Pnama = 4;     
    int Pskill = 5;     
    int Pbidang = 6;    
    int Pkota = 4;       

    //deklarasi nilai awal untuk menyimpan kata terpanjang
    int makskey = 0;
    int maksnama = 0;
    int maksskill = 0;
    int maksbidang = 0;
    int makskota = 0; 

    //mencari kata terpanjang
    for(int i = 0; i < indeks_data; i++){
        int panjangkey = strlen(source[i].key_nama); //mengambil panjang sama sekarang
        if(panjangkey > makskey){ //jika lebih panjang dari maks kata maka di set kata terpanjang
            makskey = panjangkey; //isi kata terpanjang dengan kata terpanjang tadi
        } else if(Pkey > makskey){ //bandingkan lagi dengan judul 
            makskey = Pkey;        //jika judul lebih panjang dari kata dalam data judul jadi kata terpanjang
        }
    } 

    for(int i = 0; i < indeks_data; i++){
        int panjangnama = strlen(source[i].nama);
        if(panjangnama > maksnama){
            maksnama = panjangnama;
        } else if(Pnama > maksnama){
            maksnama = Pnama;
        }
    } 

    for(int i = 0; i < indeks_data; i++){
        int panjangskill = strlen(source[i].key_skill);
        if(panjangskill > maksskill){
            maksskill = panjangskill;
        } else if(Pskill > maksskill){
            maksskill = Pskill;
        }
    } 

    for(int i = 0; i < indeks_data; i++){
        int panjangbidang = strlen(source[i].key_bidang);
        if(panjangbidang > maksbidang){
            maksbidang = panjangbidang;
        } else if(Pbidang > maksbidang){
            maksbidang = Pbidang;
        }
    } 

    for(int i = 0; i < indeks_data; i++){
        int panjangkota = strlen(source[i].key_kota);
        if(panjangkota > makskota){
            makskota = panjangkota;
        } else if(Pkota > makskota){
            makskota = Pkota;
        }
    } 

    //ini tutup atas
    printf("*-");
    for(int i = 0 ; i < 1 ; i++){
        for(int j = 0 ; j < makskey + 1; j++){
            printf("-");
        }
        printf("*-");
        for(int j = 0 ; j < maksnama + 1; j++){
            printf("-");
        }
        printf("*-");
        for(int j = 0 ; j < maksskill + 1 ; j++){
            printf("-");
        }
        printf("*-");
        for(int j = 0 ; j < maksbidang + 1 ; j++){
            printf("-");
        }
        printf("*-");
        for(int j = 0 ; j < makskota + 1 ; j++){
            printf("-");
        }
        printf("*\n");
    }

    //ini Variabel 
    for(int i = 0 ; i < 1 ; i++){
        for(int j = 0 ; j < 1 ; j++){
            printf("| Primary Key ");
        }
        for(int j = 0 ; j < makskey - Pkey ; j++){
            printf(" ");
        }
        for(int j = 0 ; j < 1; j++){
            printf("| Nama ");
        }
        for(int j = 0 ; j < maksnama - Pnama  ; j++){
            printf(" ");
        }
        for(int j = 0 ; j <1; j++){
            printf("| Skill ");
        }
        for(int j = 0 ; j < maksskill - Pskill  ; j++){
            printf(" ");
        }
        for(int j = 0 ; j <1; j++){
            printf("| Bidang ");
        }
        for(int j = 0 ; j < maksbidang - Pbidang ; j++){
            printf(" ");    
        }
        for(int j = 0 ; j <1; j++){
            printf("| Kota ");
        }
        for(int j = 0 ; j < makskota - Pkota ; j++){
            printf(" ");    
        }
        printf("|\n");

    } // ini tutup judul
    printf("*-");
    for(int i = 0 ; i < 1 ; i++){
        for(int j = 0 ; j < makskey + 1; j++){
            printf("-");
        }
        printf("*-");
        for(int j = 0 ; j < maksnama + 1; j++){
            printf("-");
        }
        printf("*-");
        for(int j = 0 ; j < maksskill + 1 ; j++){
            printf("-");
        }
        printf("*-");
        for(int j = 0 ; j < maksbidang + 1 ; j++){
            printf("-");
        }
        printf("*-");
        for(int j = 0 ; j < makskota + 1 ; j++){
            printf("-");
        }
        printf("*\n");
    }
    
    //print nama id klas dan korban
    for(int i = 0 ; i < indeks_data ; i++){
        //print nama untuk mengisi tabel
        int len1 = strlen(source[i].key_nama);
        printf("| %s", source[i].key_nama);
        for(int j = 0 ; j < makskey - len1 ; j++){
            printf(" ");
        }
        //print id
        int len2 = strlen(source[i].nama);
        printf(" | %s", source[i].nama);
        for(int j = 0 ; j < maksnama - len2 ; j++){
            printf(" ");
        }
        //print klasifikasi
        int len3 = strlen(source[i].key_skill);
        printf(" | %s", source[i].key_skill);
        for(int j = 0 ; j < maksskill - len3 ; j++){
            printf(" ");
        }
        //print korban
        int len4 = strlen(source[i].key_bidang);
        printf(" | %s", source[i].key_bidang);
        for(int j = 0 ; j < maksbidang - len4 ; j++){
            printf(" ");
        }
        int len5 = strlen(source[i].key_kota);
        printf(" | %s", source[i].key_kota);
        for(int j = 0 ; j < makskota - len5 ; j++){
            printf(" ");
        }
        printf(" |\n");
    }
    //print penutup tabel
    printf("*-");
    for(int i = 0 ; i < 1 ; i++){
        for(int j = 0 ; j < makskey + 1; j++){
            printf("-");
        }
        printf("*-");
        for(int j = 0 ; j < maksnama + 1; j++){
            printf("-");
        }
        printf("*-");
        for(int j = 0 ; j < maksskill + 1 ; j++){
            printf("-");
        }
        printf("*-");
        for(int j = 0 ; j < maksbidang + 1 ; j++){
            printf("-");
        }
        printf("*-");
        for(int j = 0 ; j < makskota + 1 ; j++){
            printf("-");
        }
        printf("*\n");
    }

}

void tabelskill(int indeks_skill, foreign source[]){
    int Pkey = 11;    
    int Pskill = 5;     

    int makskey = 0;
    int maksnama = 0;

    for(int i = 0; i < indeks_skill; i++){
        int panjangkey = strlen(source[i].key_nama);
        if(panjangkey > makskey){
            makskey = panjangkey;
        } else if(Pkey > makskey){
            makskey = Pkey;
        }
    } 

    for(int i = 0; i < indeks_skill; i++){
        int panjangnama = strlen(source[i].nama);
        if(panjangnama > maksnama){
            maksnama = panjangnama;
        } else if(Pskill > maksnama){
            maksnama = Pskill;
        }
    } 

    //ini tutup atas
    printf("*-");
    for(int i = 0 ; i < 1 ; i++){
        for(int j = 0 ; j < makskey + 1; j++){
            printf("-");
        }
        printf("*-");
        for(int j = 0 ; j < maksnama + 1; j++){
            printf("-");
        }
        printf("*\n");
    }

    //ini Variabel 
    for(int i = 0 ; i < 1 ; i++){
        for(int j = 0 ; j < 1 ; j++){
            printf("| Primary Key ");
        }
        for(int j = 0 ; j < makskey - Pkey ; j++){
            printf(" ");
        }
        for(int j = 0 ; j < 1; j++){
            printf("| Skill ");
        }
        for(int j = 0 ; j < maksnama - Pskill  ; j++){
            printf(" ");
        }
        printf("|\n");

    } // ini tutup judul
    printf("*-");
    for(int i = 0 ; i < 1 ; i++){
        for(int j = 0 ; j < makskey + 1; j++){
            printf("-");
        }
        printf("*-");
        for(int j = 0 ; j < maksnama + 1; j++){
            printf("-");
        }
        printf("*\n");
    }
    
    //print nama id klas dan korban
    for(int i = 0 ; i < indeks_skill ; i++){
        //print nama untuk mengisi tabel
        int len1 = strlen(source[i].key_nama);
        printf("| %s", source[i].key_nama);
        for(int j = 0 ; j < makskey - len1 ; j++){
            printf(" ");
        }
        //print id
        int len2 = strlen(source[i].nama);
        printf(" | %s", source[i].nama);
        for(int j = 0 ; j < maksnama - len2 ; j++){
            printf(" ");
        }
        printf(" |\n");
    }
    //print penutup tabel
    printf("*-");
    for(int i = 0 ; i < 1 ; i++){
        for(int j = 0 ; j < makskey + 1; j++){
            printf("-");
        }
        printf("*-");
        for(int j = 0 ; j < maksnama + 1; j++){
            printf("-");
        }
        printf("*\n");
    }
}

void tabelbidang(int indeks_skill, foreign source[]){
    int Pkey = 11;    
    int Pbidang = 6;     

    int makskey = 0;
    int maksnama = 0;

    for(int i = 0; i < indeks_skill; i++){
        int panjangkey = strlen(source[i].key_nama);
        if(panjangkey > makskey){
            makskey = panjangkey;
        } else if(Pkey > makskey){
            makskey = Pkey;
        }
    } 

    for(int i = 0; i < indeks_skill; i++){
        int panjangnama = strlen(source[i].nama);
        if(panjangnama > maksnama){
            maksnama = panjangnama;
        } else if(Pbidang > maksnama){
            maksnama = Pbidang;
        }
    } 

    //ini tutup atas
    printf("*-");
    for(int i = 0 ; i < 1 ; i++){
        for(int j = 0 ; j < makskey + 1; j++){
            printf("-");
        }
        printf("*-");
        for(int j = 0 ; j < maksnama + 1; j++){
            printf("-");
        }
        printf("*\n");
    }

    //ini Variabel 
    for(int i = 0 ; i < 1 ; i++){
        for(int j = 0 ; j < 1 ; j++){
            printf("| Primary Key ");
        }
        for(int j = 0 ; j < makskey - Pkey ; j++){
            printf(" ");
        }
        for(int j = 0 ; j < 1; j++){
            printf("| Bidang ");
        }
        for(int j = 0 ; j < maksnama - Pbidang  ; j++){
            printf(" ");
        }
        printf("|\n");

    } // ini tutup judul
    printf("*-");
    for(int i = 0 ; i < 1 ; i++){
        for(int j = 0 ; j < makskey + 1; j++){
            printf("-");
        }
        printf("*-");
        for(int j = 0 ; j < maksnama + 1; j++){
            printf("-");
        }
        printf("*\n");
    }
    
    //print nama id klas dan korban
    for(int i = 0 ; i < indeks_skill ; i++){
        //print nama untuk mengisi tabel
        int len1 = strlen(source[i].key_nama);
        printf("| %s", source[i].key_nama);
        for(int j = 0 ; j < makskey - len1 ; j++){
            printf(" ");
        }
        //print id
        int len2 = strlen(source[i].nama);
        printf(" | %s", source[i].nama);
        for(int j = 0 ; j < maksnama - len2 ; j++){
            printf(" ");
        }
        printf(" |\n");
    }
    //print penutup tabel
    printf("*-");
    for(int i = 0 ; i < 1 ; i++){
        for(int j = 0 ; j < makskey + 1; j++){
            printf("-");
        }
        printf("*-");
        for(int j = 0 ; j < maksnama + 1; j++){
            printf("-");
        }
        printf("*\n");
    }
}

void tabelkota(int indeks_skill, foreign source[]){
    int Pkey = 11;    
    int Pkota = 4;     

    int makskey = 0;
    int maksnama = 0;

    for(int i = 0; i < indeks_skill; i++){
        int panjangkey = strlen(source[i].key_nama);
        if(panjangkey > makskey){
            makskey = panjangkey;
        } else if(Pkey > makskey){
            makskey = Pkey;
        }
    } 

    for(int i = 0; i < indeks_skill; i++){
        int panjangnama = strlen(source[i].nama);
        if(panjangnama > maksnama){
            maksnama = panjangnama;
        } else if(Pkota > maksnama){
            maksnama = Pkota;
        }
    } 

    //ini tutup atas
    printf("*-");
    for(int i = 0 ; i < 1 ; i++){
        for(int j = 0 ; j < makskey + 1; j++){
            printf("-");
        }
        printf("*-");
        for(int j = 0 ; j < maksnama + 1; j++){
            printf("-");
        }
        printf("*\n");
    }

    //ini Variabel 
    for(int i = 0 ; i < 1 ; i++){
        for(int j = 0 ; j < 1 ; j++){
            printf("| Primary Key ");
        }
        for(int j = 0 ; j < makskey - Pkey ; j++){
            printf(" ");
        }
        for(int j = 0 ; j < 1; j++){
            printf("| Kota ");
        }
        for(int j = 0 ; j < maksnama - Pkota  ; j++){
            printf(" ");
        }
        printf("|\n");

    } // ini tutup judul
    printf("*-");
    for(int i = 0 ; i < 1 ; i++){
        for(int j = 0 ; j < makskey + 1; j++){
            printf("-");
        }
        printf("*-");
        for(int j = 0 ; j < maksnama + 1; j++){
            printf("-");
        }
        printf("*\n");
    }
    
    //print nama id klas dan korban
    for(int i = 0 ; i < indeks_skill ; i++){
        //print nama untuk mengisi tabel
        int len1 = strlen(source[i].key_nama);
        printf("| %s", source[i].key_nama);
        for(int j = 0 ; j < makskey - len1 ; j++){
            printf(" ");
        }
        //print id
        int len2 = strlen(source[i].nama);
        printf(" | %s", source[i].nama);
        for(int j = 0 ; j < maksnama - len2 ; j++){
            printf(" ");
        }
        printf(" |\n");
    }
    //print penutup tabel
    printf("*-");
    for(int i = 0 ; i < 1 ; i++){
        for(int j = 0 ; j < makskey + 1; j++){
            printf("-");
        }
        printf("*-");
        for(int j = 0 ; j < maksnama + 1; j++){
            printf("-");
        }
        printf("*\n");
    }
}

//Prosedur join
void join(mahasiswa a[], foreign b[], foreign c[], foreign d[]){
    int i=0;
    while(strcmp(a[i].key_nama, "####") != 0) {
        int j = 0, found = 0;
        while(found == 0 && strcmp(b[j].key_nama, "####") != 0){
            if(strcmp(a[i].key_skill, b[j].key_nama) == 0) {
                strcpy(a[i].key_skill, b[j].nama);
                found = 1;
            }
            j++;
        }
        j = 0, found = 0;
        while(found == 0 && strcmp(c[j].key_nama, "####") != 0){
            if(strcmp(a[i].key_bidang, c[j].key_nama) == 0) {
                strcpy(a[i].key_bidang, c[j].nama);
                found = 1;
            }
            j++;
        }
        j = 0, found = 0;
        while(found == 0 && strcmp(d[j].key_nama, "####") != 0){
            if(strcmp(a[i].key_kota, d[j].key_nama) == 0) {
                strcpy(a[i].key_kota, d[j].nama);
                found = 1;
            }
            j++;
        }
        i++;
    }
}

void intro(){
    printf(BLUE "\n              WELCOME TO DATABASE MAHASISWA\n" RESET);
    printf(BLUE "\nSEBELUM MEMULAI ALANGKAH BAIKNYA KITA MENGUCAPKAN BISMILLAH\n" RESET);
}

void guide(){
    printf(CYAN "\n                GUIDE BOOK\n\n" RESET);
    printf(CYAN"       BERIKUT BEBERAPA PILIHAN QUERY\n" RESET);

    printf(CYAN"\n      INSERT\n" RESET);
    printf(CYAN"INSERT : Menabahakan Data\n" RESET);
    printf(CYAN"INSERT : Harus Input 5 Data\n" RESET);
    printf(CYAN"INSERT Mahasiswa M??? [NamaMahasiswa] S??? B??? K?; \n" RESET);
    printf(CYAN"INSERT Skill S??? [datayangmauditambah];\n" RESET);
    printf(CYAN"INSERT Bidang B??? [datayangmauditambah];\n" RESET);
    printf(CYAN"INSERT Kota K? [datayangmauditambah];\n" RESET);

    printf(CYAN"\n     UPDATE \n" RESET);
    printf(CYAN"UPDATE : Mengubah Data \n" RESET);
    printf(CYAN"UPDATE : Harus Input 4 Data Juga\n" RESET);
    printf(CYAN"UPDATE Mahasiswa M??? [NamaMahasiswa] S??? B??? K?; \n" RESET);
    printf(CYAN"UPDATE Skill S??? [datayangmaudiubah];\n" RESET);
    printf(CYAN"UPDATE Bidang B??? [datayangmaudiubah];\n" RESET);
    printf(CYAN"UPDATE Kota K? [datayangmaudiubah];\n" RESET);

    printf(CYAN"\n     DELETE \n" RESET);
    printf(CYAN"DELETE : Menghapus Data \n" RESET);
    printf(CYAN"DELETE : Hanya Input 1 Data\n" RESET);
    printf(CYAN"DELETE Mahasiswa M???; \n" RESET);
    printf(CYAN"DELETE Skill S???;\n" RESET);
    printf(CYAN"DELETE Bidang B???;\n" RESET);
    printf(CYAN"DELETE Kota K?;\n" RESET);

    printf(CYAN"\n     SELECT \n" RESET);
    printf(CYAN"SELECT : Menampilkan Data \n" RESET);
    printf(CYAN"SELECT : Ketik Data Yang Ingin di Tampilkan Saja\n" RESET);
    printf(CYAN"SELECT Mahasiswa; \n" RESET);
    printf(CYAN"SELECT Skill;\n" RESET);
    printf(CYAN"SELECT Bidang;\n" RESET);
    printf(CYAN"SELECT Kota;\n" RESET);

    printf(CYAN"\n     JOIN \n" RESET);
    printf(CYAN"JOIN : Mengubah Foreign Key Dengan Data lain Seperti\n" RESET);
    printf(CYAN"Skill, Bidang, dan Kota \n" RESET);
    printf(CYAN"JOIN All; \n" RESET);

    printf(CYAN"\n     EXIT\n" RESET);
    printf(CYAN"EXIT : Keluar Dari Program\n" RESET);
    printf(CYAN"Ketik 'Semoga Daspro A;' \n" RESET);
    printf(CYAN"Atau' \n" RESET);
    printf(CYAN"Ketik 'EXIT;' \n" RESET);
    printf(CYAN"Atau' \n" RESET);
    printf(CYAN"Ketik 'exit;' \n" RESET);

    printf(CYAN"\nJANGAN LUPA ; PADA AKHIR INPUTAN YA\n\n" RESET);
}

void outro(){
    printf(BLUE"\n            Program Selesai\n" RESET);
    printf(BLUE"\n       SAMPAI JUMPA DI SEMESTER 2\n" RESET);
    printf(BLUE"\n     MARI MENGUCAPKAN ALHAMDULILLAH\n" RESET);
}