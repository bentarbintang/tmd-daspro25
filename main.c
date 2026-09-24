#include "headerTMD.h"

int main(){
    //deklarasi array of string
    mahasiswa data[301];         //meyimpan array dari file mahasiswa.txt
    mahasiswa datacomplete[301]; //menyimpan array dari mahasiswacomplete.txt
    foreign skill[301];          //meyimpan array dari file skill.txt
    foreign bidang[301];         //bidang .txt
    foreign kota[301];           //kota.txt

    //deklarasi indeks data
    int indeks_data = 0;
    int indeks_datacomplete = 0;
    int indeks_skill = 0;
    int indeks_bidang = 0;
    int indeks_kota = 0;
    int ketemu = 0;

    //deklarasi string untuk menyimpan data yang akan di update
    char keycari[51];
    char namabaru[51];
    char skillbaru[51];
    char bidangbaru[51];
    char kotabaru[51];
    char namabaruforeign[51];
    char keycariforeign[51];

    //membaca semua file txt
    read_mahasiswa(&indeks_data, data);
    read_skill(&indeks_skill, skill);
    read_bidang(&indeks_bidang, bidang);
    read_kota(&indeks_kota, kota);

    char pita[301];
    intro(); //panggil void intro yang berisi print kata kata
    guide(); //berisi guide yang akan memandu pengguna memakai program

    printf("Input Query : ");
    scanf(" %300[^\n]s", &pita); //scanf untuk meminta masukan dari user

    start(pita); //mulai memasukkan pita
    while(strcmp(pita, "Semoga Daspro A;") != 0 && strcmp(pita, "EXIT;") != 0 && strcmp(pita, "exit;") != 0){ //jika pita tidak seperti yang di spresifikasikan maka pita akan terus menginput 
        int panjangpita = strlen(pita); //deklarasi panjang pita
        if(strcmp(&pita[panjangpita-1], ";") != 0){ //cek pita apakah ada ; atau tidak jika tidak akan menampilkan eror
            printf(RED "\nEROR : Waduh Kurang ; Nih Coba Lagi Ya\n" RESET); 
        } else{ //jika inputan ada ; maka akan masuk ke kondisi query
            if(strcmp(getcw(), "INSERT") == 0){ //jika kata pertamanya INSERT akan masuk ke kondisi INSERT
                inc(pita); //increment pita untuk inputan 
                if(strcmp(getcw(), "Mahasiswa") == 0){ //jika kata di pita sekarang sesuai dengan masukan inc pita lagi untuk menyimpan data pada array untuk di proses pada void
                    inc(pita);
                    strcpy(data[indeks_data].key_nama, getcw());
                    inc(pita);
                    strcpy(data[indeks_data].nama, getcw());
                    inc(pita);
                    strcpy(data[indeks_data].key_skill, getcw());
                    inc(pita);
                    strcpy(data[indeks_data].key_bidang, getcw());
                    inc(pita);
                    strcpy(data[indeks_data].key_kota, getcw());

                    indeks_data++;
                    
                    insert_mahasiswa(indeks_data, data); //setelah data di simpan akan di proses di void yang telah di panggil
                    write_mahasiswa(indeks_data, data);  //setelah selesai diproses hasil akan di write ke file sesuai dengan data
                    
                } else if(strcmp(getcw(), "Skill") == 0){ //sama juga polanya seperti di atas
                    inc(pita);
                    strcpy(skill[indeks_skill].key_nama, getcw());
                    inc(pita);
                    strcpy(skill[indeks_skill].nama, getcw());
                    
                    indeks_skill++;
                        
                    insert_foreign(indeks_skill, skill);
                    write_skill(indeks_skill, skill);

                } else if(strcmp(getcw(), "Bidang") == 0){
                    inc(pita);
                    strcpy(bidang[indeks_bidang].key_nama, getcw());
                    inc(pita);
                    strcpy(bidang[indeks_bidang].nama, getcw());

                    indeks_bidang++;

                    insert_foreign(indeks_bidang, bidang);
                    write_bidang(indeks_bidang, bidang);

                } else if(strcmp(getcw(), "Kota") == 0){
                    inc(pita);
                    strcpy(kota[indeks_kota].key_nama, getcw());
                    inc(pita);
                    strcpy(kota[indeks_kota].nama, getcw());

                    indeks_kota++;

                    insert_foreign(indeks_kota, kota);
                    write_kota(indeks_kota, kota);
                    
                } else{ //eror handing jika masukkan bukan Mahasiswa, Skill, Bidang, atau Kota 
                    printf(RED "\nERROR : Data Tidak Valid, Awali Dengan Huruf Besar Lalu Huruf Kecil\n" RESET);
                }
            } else if(strcmp(getcw(), "UPDATE") == 0){
                inc(pita);
                if(strcmp(getcw(), "Mahasiswa") == 0){
                    inc(pita);
                    strcpy(keycari, getcw());
                    inc(pita);
                    strcpy(namabaru, getcw());
                    inc(pita);
                    strcpy(skillbaru, getcw());
                    inc(pita);
                    strcpy(bidangbaru, getcw());
                    inc(pita);
                    strcpy(kotabaru, getcw());
                    
                    update_mahasiswa(indeks_data, data, keycari, namabaru, skillbaru, bidangbaru, kotabaru);
                    write_mahasiswa(indeks_data, data);

                } else if(strcmp(getcw(), "Skill") == 0){
                    inc(pita);
                    strcpy(keycariforeign, getcw());
                    inc(pita);
                    strcpy(namabaruforeign, getcw());

                    update_foreign(indeks_skill, skill, keycariforeign, namabaruforeign);
                    write_skill(indeks_skill, skill);

                } else if(strcmp(getcw(), "Bidang") == 0){
                    inc(pita);
                    strcpy(keycariforeign, getcw());
                    inc(pita);
                    strcpy(namabaruforeign, getcw());

                    update_foreign(indeks_bidang, bidang, keycariforeign, namabaruforeign);
                    write_bidang(indeks_bidang, bidang);

                } else if(strcmp(getcw(), "Kota") == 0){
                    inc(pita);
                    strcpy(keycariforeign, getcw());
                    inc(pita);
                    strcpy(namabaruforeign, getcw());

                    update_foreign(indeks_bidang, bidang, keycariforeign, namabaruforeign);
                    write_kota(indeks_kota, kota);

                } else{ //eror handling
                    printf(RED "\nERROR : Data Tidak Valid, Awali Dengan Huruf Besar Lalu Huruf Kecil\n" RESET);
                }
            } else if(strcmp(getcw(), "DELETE") == 0){
                inc(pita);
                char keydelete[51];
                if(strcmp(getcw(), "Mahasiswa") == 0){
                    inc(pita);
                    strcpy(keydelete, getcw());
                    
                    delete_mahasiswa(&indeks_data, data, keydelete);
                    write_mahasiswa(indeks_data, data);

                } else if(strcmp(getcw(), "Skill") == 0){
                    inc(pita);
                    strcpy(keydelete, getcw());

                    delete_foreign(&indeks_skill, skill, keydelete);
                    write_skill(indeks_skill, skill);

                } else if(strcmp(getcw(), "Bidang") == 0){
                    inc(pita);
                    strcpy(keydelete, getcw());

                    delete_foreign(&indeks_bidang, bidang, keydelete);
                    write_bidang(indeks_bidang, bidang);

                } else if(strcmp(getcw(), "Kota") == 0){
                    inc(pita);
                    strcpy(keydelete, getcw());

                    delete_foreign(&indeks_kota, kota, keydelete);
                    write_kota(indeks_kota, kota);

                } else{ //eror handing
                    printf(RED "\nERROR : Data Tidak Valid, Awali Dengan Huruf Besar Lalu Huruf Kecil\n" RESET);
                }
            } else if(strcmp(getcw(), "SELECT") == 0){
                inc(pita);
                if(strcmp(getcw(), "Mahasiswa") == 0){
                    tabelmahasiswa(indeks_data, data);
                } else if(strcmp(getcw(), "Skill") == 0){
                    tabelskill(indeks_skill, skill);
                } else if(strcmp(getcw(), "Bidang") == 0){
                    tabelbidang(indeks_bidang, bidang);
                } else if(strcmp(getcw(), "Kota") == 0){
                    tabelkota(indeks_kota, kota);
                } else{ //eror handing
                    printf(RED "\nERROR : Data Tidak Valid, Awali Dengan Huruf Besar Lalu Huruf Kecil\n" RESET);
                }
            } else if(strcmp(getcw(), "JOIN") == 0){
                inc(pita);

                if(strcmp(getcw(), "All") == 0){

                    join(data, skill, bidang, kota);
                    int n = indeks_data;
                    write_mahasiswacomplete(n, data);
                    tabelmahasiswa(indeks_data, data);
                } else{
                    printf(RED "ERROR : Ketik JOIN All; Aja" RESET);
                }
            } else if(strcmp(getcw(), "1") == 0){
                guide();
            } else if(strcmp(getcw(), "HELP") == 0){
                guide();
            } else{ //eror handling jika masukan pita bukan Query yang benar
                printf(RED "EROR : Query Tidak Valid, Harus Huruf Besar Semua\n" RESET);
                printf(CYAN "Ketik 'HELP;' atau '1;' Jika Bingung\n" RESET);
            }
        }
        reset(); //setelah kondisi if selesai, pita yang telah di isi di reset kembali 
        printf("\nInput Query : ");
        scanf(" %300[^\n]s", &pita);
        start(pita); //setelah kondisi if selesai akan meminta inputan kembali
    }
    outro(); //memamngil prosedur outro untuk menampilkan kata kata
    return 0;
}