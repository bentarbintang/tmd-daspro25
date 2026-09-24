# tmd-daspro25

# Database Management System Minimalis (TMD Daspro)

Sistem DBMS berbasis antarmuka baris perintah (*Command Line Interface* / CLI) yang dibangun menggunakan bahasa C. Proyek ini dikembangkan sebagai evaluasi **Tugas Masa Depan (TMD)** untuk mata kuliah **Dasar-Dasar Pemrograman**.

Program ini mengimplementasikan pemrosesan pita kata (mesin kata), pengolahan data terstruktur (*struct*), relasi basis data (*primary key & foreign key*), penyimpaan berbasis berkas teks (DBMS berbasis `.txt`), serta pembentukan tabel otomatis secara dinamis.

---

## 🌟 Fitur Utama

- **Mesin Kata / Pita Kata Custom**: Menguraikan masukan *query* berbasis tanda titik koma (`;`) secara sekuensial.
- **Operasi CRUD (Create, Read, Update, Delete)**:
  - `INSERT`: Menambahkan data mahasiswa atau relasi referensi baru secara terurut (*insertion sort* otomatis berdasarkan *Primary Key*).
  - `UPDATE`: Memperbarui data yang tersimpan berdasarkan *Primary Key*.
  - `DELETE`: Menghapus data secara permanen dari array dan berkas teks.
  - `SELECT`: Menampilkan data berbentuk tabel dinamis yang lebar kolomnya menyesuaikan string terpanjang.
- **Relasi & JOIN Table**:
  - `JOIN All;`: Menghubungkan tabel `Mahasiswa` dengan tabel referensi (`Skill`, `Bidang`, `Kota`) menggunakan penyelarasan *Foreign Key*.
- **Penyimpanan Permanen (File I/O)**: Data dibaca dan ditulis secara otomatis dari/ke berkas `.txt` dengan penanda akhiran berkas `####`.
- **Warna Teks Terminal**: Menggunakan *ANSI Escape Codes* untuk memberikan indikasi status operasi (`SUCCESS`, `ERROR`, menu panduan, dll.).

---

## 📁 Struktur Direktori & Berkas

```text
.
├── headerTMD.h            # Header file: Deklarasi struct, variabel global, dan prototype fungsi/prosedur
├── mesin.c                # Implementasi mesin kata, pemrosesan file, CRUD, serta logika JOIN
├── main.c                 # Program utama, parser query, dan loop interaksi pengguna
├── Mahasiswa.txt          # File data utama Mahasiswa (PKey, Nama, FKey_Skill, FKey_Bidang, FKey_Kota)
├── MahasiswaComplete.txt  # File hasil gabungan (JOIN) dengan data deskriptif
├── Skill.txt              # File referensi/foreign table Skill
├── Bidang.txt             # File referensi/foreign table Bidang
└── Kota.txt               # File referensi/foreign table Kota
```

---

## 🛠️ Persyaratan & Kompilasi

### Persyaratan
- Compiler C (GCC disarankan)

### Cara Kompilasi
Buka terminal/command prompt pada direktori proyek, lalu jalankan perintah berikut:

```bash
gcc main.c mesin.c -o tmd_daspro
```

### Cara Menjalankan
```bash
./tmd_daspro
```

---

## 📖 Panduan Penggunaan Query

Setiap *query* **WAJIB** diakhiri dengan tanda titik koma (`;`).

### 1. Menampilkan Data (`SELECT`)
Menampilkan data dari salah satu tabel (`Mahasiswa`, `Skill`, `Bidang`, atau `Kota`).

```sql
SELECT Mahasiswa;
SELECT Skill;
SELECT Bidang;
SELECT Kota;
```

### 2. Menambah Data (`INSERT`)
Menambahkan baris baru. Data akan otomatis disisipkan sesuai urutan *Primary Key*.

```sql
INSERT Mahasiswa M006 Budi S001 B003 K1;
INSERT Skill S007 Expert_C;
INSERT Bidang B007 AI_Research;
INSERT Kota K7 Bandung;
```

### 3. Memperbarui Data (`UPDATE`)
Mengubah isi data berdasarkan *Primary Key* yang dikirimkan.

```sql
UPDATE Mahasiswa M001 Umeir_New S003 B002 K5;
UPDATE Skill S001 Master_CSPC;
UPDATE Bidang B002 UI_UX_Design;
UPDATE Kota K1 Pangkalpinang;
```

### 4. Menghapus Data (`DELETE`)
Menghapus baris data berdasarkan *Primary Key*.

```sql
DELETE Mahasiswa M001;
DELETE Skill S001;
DELETE Bidang B001;
DELETE Kota K1;
```

### 5. Menggabungkan Data (`JOIN`)
Menghubungkan *Foreign Key* pada tabel `Mahasiswa` dengan nama deskriptif dari tabel `Skill`, `Bidang`, dan `Kota`, lalu menyimpannya ke `MahasiswaComplete.txt`.

```sql
JOIN All;
```

### 6. Menampilkan Bantuan (`HELP`)
```sql
HELP;
-- atau cukup ketik
1;
```

### 7. Keluar Program (`EXIT`)
```sql
EXIT;
-- atau
exit;
-- atau
Semoga Daspro A;
```

---

## 📝 Format Berkas Data (`.txt`)

Data disimpan dengan pembatas spasi/newline dan diakhiri penanda baris `####` sebagai *End of File* penanda mesin pembaca data.

Contoh `Mahasiswa.txt`:
```text
M001 Umeir S002 B004 K2
M002 Bentar S001 B002 K1
#### #### #### #### ####
```

Contoh `Skill.txt`:
```text
S001 Top1_CSPC
S002 Top2_CSPC
#### ####
```

---

## 👨‍💻 Pembuat

- **Nama**: Bentar Bintang Umeir  
- **Mata Kuliah**: Dasar-Dasar Pemrograman  

> *"Saya Bentar Bintang Umeir mengerjakan evaluasi Tugas Masa Depan dalam mata kuliah Dasar-dasar Pemrograman untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin."*
