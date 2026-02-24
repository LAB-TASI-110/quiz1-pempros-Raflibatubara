#include <stdio.h>
#include <string.h>

#define MAX_LAUNDRY 100

typedef struct {
    char nim[15];
    char nama[50];
    char asrama[20];
    char jenisPakaian[30];
    char pesan[100]; // FITUR BARU: Pesan/Saran dari Mahasiswa
    float berat;
    int status; 
} Laundry;

const char* cetakStatus(int s) {
    switch(s) {
        case 0: return "Antre";
        case 1: return "Cuci";
        case 2: return "Setrika";
        case 3: return "Selesai";
        default: return "Unknown";
    }
}

int main() {
    Laundry daftar[MAX_LAUNDRY];
    int jumlah = 0;
    int pilihan;

    printf("==== DEL-LAUNDRY MANAGEMENT SYSTEM ====\n");
    printf("        Institut Teknologi Del\n");

    do {
        printf("\n--- Menu Utama ---\n");
        printf("1. Tambah Antrean Laundry\n");
        printf("2. Lihat List Laundry & Pesan\n");
        printf("3. Update Status Cucian\n");
        printf("4. Keluar\n");
        printf("Pilih menu (1-4): ");
        scanf("%d", &pilihan);
        getchar(); 

        switch(pilihan) {
            case 1: 
                if (jumlah < MAX_LAUNDRY) {
                    printf("\n--- Form Input Laundry ---\n");
                    printf("NIM           : "); scanf("%s", daftar[jumlah].nim);
                    getchar();
                    printf("Nama          : "); fgets(daftar[jumlah].nama, 50, stdin);
                    daftar[jumlah].nama[strcspn(daftar[jumlah].nama, "\n")] = 0; 
                    
                    printf("Asrama        : "); scanf("%s", daftar[jumlah].asrama);
                    getchar();
                    
                    printf("Jenis Pakaian : "); fgets(daftar[jumlah].jenisPakaian, 30, stdin);
                    daftar[jumlah].jenisPakaian[strcspn(daftar[jumlah].jenisPakaian, "\n")] = 0;
                    
                    // INPUT FITUR BARU: PESAN/SARAN
                    printf("Pesan/Saran   : "); fgets(daftar[jumlah].pesan, 100, stdin);
                    daftar[jumlah].pesan[strcspn(daftar[jumlah].pesan, "\n")] = 0;

                    printf("Berat (kg)    : "); scanf("%f", &daftar[jumlah].berat);
                    
                    daftar[jumlah].status = 0; 
                    jumlah++;
                    printf(">> Data Berhasil Masuk ke Antrean!\n");
                }
                break;

            case 2: 
                printf("\n--- DAFTAR CUCIAN & INSTRUKSI ---\n");
                printf("---------------------------------------------------------------------------------------------------\n");
                printf("%-3s | %-12s | %-15s | %-15s | %-5s | %-15s\n", 
                       "ID", "NIM", "Nama", "Jenis", "Berat", "Status");
                printf("---------------------------------------------------------------------------------------------------\n");
                for(int i = 0; i < jumlah; i++) {
                    printf("%-3d | %-12s | %-15.15s | %-15.15s | %-3.1fkg | %-10s\n", 
                            i+1, daftar[i].nim, daftar[i].nama, 
                            daftar[i].jenisPakaian, daftar[i].berat, cetakStatus(daftar[i].status));
                    // Menampilkan pesan di baris bawahnya agar rapi
                    printf("    [PESAN]: %s\n", (strlen(daftar[i].pesan) > 0) ? daftar[i].pesan : "Tidak ada pesan khusus.");
                    printf("---------------------------------------------------------------------------------------------------\n");
                }
                break;

            case 3: 
                if (jumlah > 0) {
                    int idUpdate;
                    printf("\nMasukkan ID (Nomor) untuk Update Status: ");
                    scanf("%d", &idUpdate);
                    if(idUpdate > 0 && idUpdate <= jumlah) {
                        if(daftar[idUpdate-1].status < 3) {
                            daftar[idUpdate-1].status++;
                            printf(">> Status %s Diperbarui!\n", daftar[idUpdate-1].nama);
                        } else {
                            printf(">> Cucian sudah Selesai.\n");
                        }
                    }
                }
                break;
        }
    } while (pilihan != 4);

    return 0;
}