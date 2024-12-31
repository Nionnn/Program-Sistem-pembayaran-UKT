#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    int nim;
    double ukt;        
    double pembayaran;
};

void Tampilkandata(const Mahasiswa & data) {
    cout << "\n===== Data Mahasiswa =====" << endl;
    cout << "Nama       : " << data.nama << endl;
    cout << "NIM        : " << data.nim << endl;
    cout << "UKT Total  : Rp" << data.ukt << endl;
    cout << "Pembayaran : Rp" << data.pembayaran << endl;
    cout << "Sisa UKT   : Rp" << (data.ukt - data.pembayaran) << endl;
}

int main() {
    Mahasiswa data;
    cout<< " nama mahasiswa: ";
    getline(cin, data.nama);
    cout<< " nim mahasiswa: ";
    cin>> data.nim;
    cout<< "total UKT: ";
    cin>> data.ukt;
    cout<< " pembayaran awal: ";
    cin>> data.pembayaran;

if (data.pembayaran > data.ukt) {
        cout << "\n error: pembayaran tidak boleh lebih dari total UKT. \n ";
        return 1;
}

Tampilkandata(data);

double tambahan;
    while (data.pembayaran < data.ukt) {
        cout << "\nSisa UKT yang perlu dibayar: Rp" << (data.ukt - data.pembayaran) << endl;
        cout << "Tambahkan pembayaran (Rp): ";
        cin >> tambahan;

 if (data.pembayaran + tambahan > data.ukt) {
            cout << "\n error: total pembayaran melebihi UKT.\n";
        } else {
            data.pembayaran += tambahan;
            cout << "\n pembayaran berhasil ditambahkan.\n";
            Tampilkandata(data);
        }

        // Mengecek apakah pembayaran sudah mencukupi
        if (data.pembayaran == data.ukt) {
            cout << "\n pembayaran selesai. UKT telah lunas.\n";
            break;
        }
    }

    char pilihan;
    cout << "\nApakah Anda ingin menampilkan data mahasiswa lagi? (iya/tidak): ";
    cin >> pilihan;

    if (pilihan == 'iya' || pilihan == 'IYA') {
        Tampilkandata(data);
    }

    return 0;
}
  

        




