#include <iostream>
using namespace std;

int main() {
int pilih;
double L, P, E, b, h, I, defleksi, izin;

do {
cout << "\n=== MENU UTAMA ===\n";
cout << "1. Kasus 1 (L/240)\n";
cout << "2. Kasus 2 (L/480)\n";
cout << "3. Keluar\n";
cout << "Pilih menu: ";
cin >> pilih;
      
if (pilih == 1 || pilih == 2) {

cout << "Masukkan panjang L (mm): ";
cin >> L;

cout << "Masukkan beban P (N): ";
cin >> P;

cout << "Masukkan E (N/mm2): ";
cin >> E;

cout << "Masukkan lebar b (mm): ";
cin >> b;

if (pilih == 1)
izin = L / 240;
else
izin = L / 480;

h = 1;

do {
I = b * h * h * h / 12;
defleksi = P * L * L * L / (48 * E * I);
h++;
} while (defleksi > izin);

h--;

cout << "\n=== HASIL ===\n";
cout << "h_min = " << h << " mm\n";
cout << "Defleksi = " << defleksi << " mm\n";
cout << "Batas izin = " << izin << " mm\n";

if (defleksi <= izin)
cout << "Status = AMAN\n";
}
} while (pilih != 3);
cout << "\nProgram selesai.\n";

return 0;
}