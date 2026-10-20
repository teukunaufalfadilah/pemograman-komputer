#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string nama, pendidikan, pernah_walikota;
    int umur, pengalaman;

    // Input data kandidat
    cout << "Masukkan nama kandidat: ";
    getline(cin, nama);

    cout << "Apakah pernah menjabat sebagai Walikota? (Ya/Tidak): ";
    cin >> pernah_walikota;

    cout << "Masukkan umur calon: ";
    cin >> umur;

    cout << "Masukkan pendidikan terakhir (SMA/D3/S1/S2/S3): ";
    cin >> pendidikan;

    cout << "Masukkan lama pengalaman kerja (tahun): ";
    cin >> pengalaman;

    // Mengubah huruf menjadi kapital agar tidak terpengaruh huruf besar/kecil
    for (char &c : pernah_walikota) c = toupper(c);
    for (char &c : pendidikan) c = toupper(c);

    string hasil;

    // Logika penyeleksian
    if (pernah_walikota == "YA") {
        hasil = "LOLOS";
    } else {
        // Cek syarat umur >= 40, pendidikan S1/S2/S3, dan pengalaman >= 10 tahun
        if (umur >= 40 && (pendidikan == "S1" || pendidikan == "S2" || pendidikan == "S3") && pengalaman >= 10) {
            hasil = "LOLOS";
        } else {
            hasil = "TIDAK LOLOS";
        }
    }

    // Output hasil seleksi
    cout << "\n========================================" << endl;
    cout << "Hasil Seleksi Bakal Calon Gubernur a.n. " << nama << " : " << hasil << endl;
    cout << "========================================" << endl;

    return 0;
}