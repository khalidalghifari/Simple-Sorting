#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

/*
 * FUNCTION: createFolder
 *
 * DESCRIPTION:
 * Fungsi ini digunakan untuk membuat folder jika folder tersebut belum ada.
 *
 * PARAMETERS:
 * - folder: String yang menyimpan nama folder yang ingin dibuat.
 *
 * ALGORITHM:
 * - Jika sistem operasi yang digunakan adalah Windows (_WIN32), maka gunakan fungsi mkdir tanpa argumen tambahan.
 * - Jika sistem operasi yang digunakan bukan Windows, maka gunakan fungsi mkdir dengan mode 0777 untuk memberikan hak akses penuh pada folder yang dibuat.
 */
void createFolder(const char *folder)
{
#ifdef _WIN32
    mkdir(folder);
#else
    mkdir(folder, 0777);
#endif
}

/*
 * FUNCTION: saveToFile
 *
 * DESCRIPTION:
 * Fungsi ini digunakan untuk menyimpan isi dari array ke dalam sebuah file teks (.txt).
 *
 * PARAMETERS:
 * - arr: Array yang akan disimpan ke dalam file.
 * - n: Jumlah elemen dalam array.
 * - filename: Nama file teks yang akan digunakan untuk menyimpan array.
 *
 * ALGORITHM:
 * - Buka file dengan mode "w" (write) menggunakan fungsi fopen. Jika gagal membuka file, keluarkan pesan kesalahan dan keluar dari program.
 * - Gunakan loop untuk menuliskan setiap elemen array ke dalam file menggunakan fprintf.
 * - Tutup file yang telah ditulis menggunakan fclose.
 */
void saveToFile(int arr[], int n, const char *filename)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        fprintf(stderr, "Gagal membuka file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++)
    {
        fprintf(file, "%d\n", arr[i]);
    }

    fclose(file);
}

/*
 * FUNCTION: bubbleSort
 *
 * DESCRIPTION:
 * Fungsi ini mengimplementasikan algoritma bubble sort untuk mengurutkan array integer secara ascending.
 *
 * PARAMETERS:
 * - arr: Array integer yang akan diurutkan.
 * - n: Jumlah elemen dalam array.
 * - filename: Nama file teks yang akan digunakan untuk menyimpan array setelah diurutkan.
 *
 * ALGORITHM:
 * - Lakukan pengurutan menggunakan algoritma bubble sort:
 *   - Iterasi dimulai dari elemen pertama hingga elemen sebelum elemen terakhir.
 *   - Bandingkan dua elemen yang bersebelahan dan tukar jika tidak terurut.
 * - Panggil fungsi saveToFile untuk menyimpan array yang telah diurutkan ke dalam file teks.
 */
void bubbleSort(int arr[], int n, const char *filename)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
            {
                // Swap bilangan jika tidak terurut
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
    saveToFile(arr, n, filename);
}

/*
 * FUNCTION: selectionSort
 *
 * DESCRIPTION:
 * Fungsi ini mengimplementasikan algoritma selection sort untuk mengurutkan array integer secara ascending.
 *
 * PARAMETERS:
 * - arr: Array integer yang akan diurutkan.
 * - n: Jumlah elemen dalam array.
 * - filename: Nama file teks yang akan digunakan untuk menyimpan array setelah diurutkan.
 *
 * ALGORITHM:
 * - Lakukan pengurutan menggunakan algoritma selection sort:
 *   - Iterasi dimulai dari elemen pertama hingga elemen sebelum elemen terakhir.
 *   - Pilih elemen minimum dari sisa array yang belum diurutkan dan tukar dengan elemen pertama dari array tersebut.
 * - Panggil fungsi saveToFile untuk menyimpan array yang telah diurutkan ke dalam file teks.
 */
void selectionSort(int arr[], int n, const char *filename)
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Swap bilangan jika tidak terurut
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
    saveToFile(arr, n, filename);
}

/*
 * FUNCTION: insertionSort
 *
 * DESCRIPTION:
 * Fungsi ini mengimplementasikan algoritma insertion sort untuk mengurutkan array integer secara ascending.
 *
 * PARAMETERS:
 * - arr: Array integer yang akan diurutkan.
 * - n: Jumlah elemen dalam array.
 * - filename: Nama file teks yang akan digunakan untuk menyimpan array setelah diurutkan.
 *
 * ALGORITHM:
 * - Lakukan pengurutan menggunakan algoritma insertion sort:
 *   - Iterasi dimulai dari elemen kedua hingga elemen terakhir.
 *   - Untuk setiap elemen, bandingkan dengan elemen-elemen sebelumnya dan pindahkan elemen-elemen yang lebih besar ke posisi yang sesuai.
 * - Panggil fungsi saveToFile untuk menyimpan array yang telah diurutkan ke dalam file teks.
 */
void insertionSort(int arr[], int n, const char *filename)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        // Pindahkan elemen yang lebih besar dari key ke posisi setelahnya
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    saveToFile(arr, n, filename);
}

/*
 * FUNCTION: printTableBorder
 *
 * DESCRIPTION:
 * Fungsi ini digunakan untuk mencetak garis tepi tabel pada output.
 *
 * PARAMETERS:
 * - width: Jumlah karakter untuk lebar garis tepi.
 */
void printTableBorder(int width)
{
    for (int i = 0; i < width; i++)
    {
        printf("-");
    }
    printf("\n");
}

int main()
{
    // Inisialisasi variabel
    const int maxNumbers = 1000000;      // Jumlah maksimal bilangan
    const int step = 100000;             // Langkah penambahan jumlah bilangan
    const char *inputFolder = "input";   // Nama folder untuk menyimpan file input
    const char *outputFolder = "output"; // Nama folder untuk menyimpan file output

    // Membuat folder input dan output jika belum ada
    createFolder(inputFolder);
    createFolder(outputFolder);

    int *numbers = (int *)malloc(maxNumbers * sizeof(int)); // Mengalokasikan memori untuk array bilangan

    // Generate bilangan secara acak dan menyimpan ke dalam file input
    srand(time(NULL)); // Menggunakan waktu sebagai seed untuk random number generator
    for (int i = 0; i < maxNumbers; i++)
    {
        numbers[i] = rand();
    }

    char inputFilename[50]; // Nama file untuk menyimpan bilangan input
    sprintf(inputFilename, "%s/input.txt", inputFolder);
    saveToFile(numbers, maxNumbers, inputFilename);

    // Melakukan pengurutan dan menyimpan hasil ke dalam file
    printTableBorder(59);                                                                               // Mencetak garis tepi tabel
    printf("| %-15s | %-15s | %-20s |\n", "Jenis Algoritma", "Jumlah Bilangan", "Waktu Eksekusi (ms)"); // Mencetak header tabel
    printTableBorder(59);                                                                               // Mencetak garis tepi tabel
    for (int n = step; n <= maxNumbers; n += step)
    {
        int *copyNumbers = (int *)malloc(n * sizeof(int)); // Mengalokasikan memori untuk array copy bilangan
        for (int i = 0; i < n; i++)
        {
            copyNumbers[i] = numbers[i];
        }

        // Pengukuran waktu eksekusi dilakukan dengan bantuan fungsi `clock()` dari library `time.h`.

        // Bubble Sort
        char bubbleFilename[50]; // Nama file untuk menyimpan hasil bubble sort
        sprintf(bubbleFilename, "%s/%d_bubble.txt", outputFolder, n);
        clock_t start = clock();
        bubbleSort(copyNumbers, n, bubbleFilename);
        clock_t end = clock();
        double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC * 1000; // Waktu eksekusi dalam milidetik
        printf("| %-15s | %-15d | %-20f |\n", "Bubble Sort", n, cpu_time_used);

        // Selection Sort
        char selectionFilename[50]; // Nama file untuk menyimpan hasil selection sort
        sprintf(selectionFilename, "%s/%d_selection.txt", outputFolder, n);
        start = clock();
        selectionSort(copyNumbers, n, selectionFilename);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC * 1000; // Waktu eksekusi dalam milidetik
        printf("| %-15s | %-15d | %-20f |\n", "Selection Sort", n, cpu_time_used);

        // Insertion Sort
        char insertionFilename[50]; // Nama file untuk menyimpan hasil insertion sort
        sprintf(insertionFilename, "%s/%d_insertion.txt", outputFolder, n);
        start = clock();
        insertionSort(copyNumbers, n, insertionFilename);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC * 1000; // Waktu eksekusi dalam milidetik
        printf("| %-15s | %-15d | %-20f |\n", "Insertion Sort", n, cpu_time_used);

        // Mencetak garis tepi antara setiap baris tabel
        printTableBorder(59);

        free(copyNumbers); // Membuang memori yang sudah dialokasikan
    }

    free(numbers); // Membuang memori yang sudah dialokasikan untuk array bilangan

    return 0;
}
