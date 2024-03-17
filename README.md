# Simple Sorting Algorithm

## Deskripsi
Repository ini merupakan implementasi dari tiga algoritma simple sorting: Bubble Sort, Selection Sort, dan Insertion Sort dalam bahasa C. Pada program ini akan dilakukan proses generate bilangan secara acak sebanyak 1 juta bilangan integer. Bilangan tersebut diurutkan secara bubble sort, selection sort dan insertion sort dan  bilangan yang belum terurut dan yang sudah terurut akan disimpan ke dalam file .txt.

## Cara Menjalankan Kode Program

1. Pastikan Anda telah menginstal compiler C pada sistem Anda.
2. Clone repositori ini atau download file 
3. Kompilasi kode menggunakan perintah berikut:
   ```bash
   gcc 2208107010044_Simple_Sorting.c -o sorting
   ```
4. Jalankan hasil yang telah dikompilasi:
   ```bash
   ./sorting
   ```
5. Program akan menghasilkan file output dalam folder `output` yang berisi bilangan yang sudah diurutkan berdasarkan jenis algoritma dan jumlah bilangan.

## Fungsi-fungsi dalam Kode Program

### 1. `saveToFile`
   - Fungsi untuk menyimpan array ke dalam file teks.
   - Parameter:
     - `arr`: Array bilangan integer yang akan disimpan.
     - `n`: Jumlah elemen dalam array.
     - `filename`: Nama file tujuan.

### 2. `bubbleSort`
   - Fungsi untuk melakukan Bubble Sort pada array.
   - Parameter:
     - `arr`: Array bilangan integer yang akan diurutkan.
     - `n`: Jumlah elemen dalam array.
     - `filename`: Nama file untuk menyimpan hasil pengurutan.

### 3. `selectionSort`
   - Fungsi untuk melakukan Selection Sort pada array.
   - Parameter:
     - `arr`: Array bilangan integer yang akan diurutkan.
     - `n`: Jumlah elemen dalam array.
     - `filename`: Nama file untuk menyimpan hasil pengurutan.

### 4. `insertionSort`
   - Fungsi untuk melakukan Insertion Sort pada array.
   - Parameter:
     - `arr`: Array bilangan integer yang akan diurutkan.
     - `n`: Jumlah elemen dalam array.
     - `filename`: Nama file untuk menyimpan hasil pengurutan.

### 5. `printTableBorder`
   - Fungsi untuk mencetak garis tepi tabel pada output.

### 6. `main`
   - Fungsi utama yang menginisialisasi variabel, menghasilkan bilangan acak, menyimpan ke file input, melakukan pengurutan, dan mencetak hasil waktu eksekusi pada tabel.

## Video menjalankan program
(https://youtu.be/zBETZBZkH7o).