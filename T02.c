#include <stdio.h>

int main() {
    int N;
    int i;
    int kode;
    int total = 0;

    printf("Masukkan jumlah data: ");
    scanf("%d", &N);

    int nilai[N];

    printf("Masukkan %d nilai:\n", N);
    for(i = 0; i < N; i++) {
        scanf("%d", &nilai[i]);
    }

    printf("Masukkan kode kelompok (1 atau 2): ");
    scanf("%d", &kode);

    // Proses penjumlahan sesuai kelompok
    for(i = 0; i < N; i++) {
        if(kode == 1 && i % 2 == 0) {
            total += nilai[i];
        }
        else if(kode == 2 && i % 2 == 1) {
            total += nilai[i];
        }
    }

    printf("Total nilai kelompok %d adalah: %d\n", kode, total);

    return 0;
}