#include <stdio.h>
#include <string.h>

// Struktur untuk database menu
typedef struct {
    char kode[10];
    char nama[30];
    int harga;
} Menu;

// Struktur untuk menyimpan baris pesanan di struk
typedef struct {
    char nama[30];
    int porsi;
    int harga;
    int total;
} Struk;

int main() {
    // Database Menu sesuai gambar soal
    Menu list_menu[] = {
        {"NGS", "Nasi Goreng Spesial", 15000},
        {"AP", "Ayam Penyet", 20000},
        {"SA", "Sate Ayam (10 Tusuk)", 25000},
        {"BU", "Bakso Urat", 18000},
        {"MAP", "Mie Ayam Pangsit", 15000},
        {"GG", "Gado-Gado", 15000},
        {"SAM", "Soto Ayam", 17000},
        {"RD", "Rendang Daging", 25000},
        {"IB", "Ikan Bakar", 35000},
        {"NUK", "Nasi Uduk Komplit", 20000}
    };

    Struk pesanan[50];
    int count = 0;
    long total_kotor = 0;
    char input_kode[10];
    int porsi_butet;

    // Loop Input: Membaca Kode lalu Porsi Butet
    while (1) {
        if (scanf("%s", input_kode) == EOF || strcmp(input_kode, "END") == 0) {
            break;
        }
        scanf("%d", &porsi_butet);

        for (int i = 0; i < 10; i++) {
            if (strcmp(input_kode, list_menu[i].kode) == 0) {
                // Logika: Ucok (100kg) & Butet (50kg) -> Rasio 2:1
                // Total porsi = 1 (Butet) + 2 (Ucok) = 3 * porsi_butet
                int total_porsi = porsi_butet * 3;
                int subtotal = total_porsi * list_menu[i].harga;

                strcpy(pesanan[count].nama, list_menu[i].nama);
                pesanan[count].porsi = total_porsi;
                pesanan[count].harga = list_menu[i].harga;
                pesanan[count].total = subtotal;

                total_kotor += subtotal;
                count++;
                break;
            }
        }
    }

    // Logika Perhitungan Diskon Kupon
    float diskon = 0;
    if (total_kotor >= 500000) diskon = 0.25;      // Hitam
    else if (total_kotor >= 400000) diskon = 0.20; // Hijau
    else if (total_kotor >= 300000) diskon = 0.15; // Merah
    else if (total_kotor >= 200000) diskon = 0.10; // Kuning
    else if (total_kotor >= 100000) diskon = 0.05; // Biru

    long total_akhir = total_kotor - (total_kotor * diskon);

    // OUTPUT: Sesuai format gambar image_43ae83.png
    printf("\n%-20s %-10s %-10s %-10s\n", "Menu", "Porsi", "Harga", "Total");
    printf("========================================================\n");

    for (int i = 0; i < count; i++) {
        // Menggunakan padding agar kolom sejajar sempurna
        printf("%-20s %-10d %-10d %-10d\n", 
               pesanan[i].nama, 
               pesanan[i].porsi, 
               pesanan[i].harga, 
               pesanan[i].total);
    }

    printf("========================================================\n");
    // "Total Pembayaran" diletakkan di kiri, dan angkanya diratakan ke kanan
    printf("%-20s %35ld\n", "Total Pembayaran", total_akhir);

    return 0;
}