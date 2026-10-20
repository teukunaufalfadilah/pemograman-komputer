#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

int getMonth(const string &date) {
    return stoi(date.substr(5, 2));
}

int main() {
   
    ifstream file("data_curah_hujan.csv");
    if (!file.is_open()) {
        cerr << "Gagal membuka file data_curah_hujan.csv!\n";
        return 1;
    }

    string line;
    getline(file, line); 

    vector<vector<double>> data(13); 

   
    while (getline(file, line)) {
        stringstream ss(line);
        string stasiun, tanggal, val_str;
        getline(ss, stasiun, ',');
        getline(ss, tanggal, ',');
        getline(ss, val_str, ',');

        if (val_str.empty()) continue;
        double val = stod(val_str);
        int bulan = getMonth(tanggal);
        data[bulan].push_back(val);
    }
    file.close();

    ofstream outFile("output_curah_hujan.csv");
    if (!outFile.is_open()) {
        cerr << "Gagal membuat file output_curah_hujan.csv!\n";
        return 1;
    }

 
    outFile << fixed << setprecision(2);
    cout << fixed << setprecision(2);

    string header = "Bulan,Total(mm),Rata-rata(mm/hari),Maks(mm/hari)";
    outFile << header << "\n";
    cout << header << "\n";

    for (int m = 1; m <= 12; ++m) {
        if (data[m].empty()) continue;

        double sum = 0, maxv = -1e9;
        for (double v : data[m]) {
            sum += v;
            if (v > maxv) maxv = v;
        }

        double mean = sum / data[m].size();

        string row = to_string(m) + "," + to_string(sum) + "," + to_string(mean) + "," + to_string(maxv);

        outFile << m << "," << sum << "," << mean << "," << maxv << "\n";
        
        cout << m << "," << sum << "," << mean << "," << maxv << "\n";
    }

    outFile.close();
    cout << "\nBerhasil menyimpan ringkasan ke 'output_curah_hujan.csv'!\n";

    return 0;
}