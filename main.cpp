#include <iostream>
#include <cstdio>
#include <windows.h>
#include <conio.h>
#include "rental.h"
#define max 10


using namespace std;

struct data_cust
{
    long long no_ktp;
    char nama_cust [50];
    long long no_tlp;
    char alamat [100];
    char gender[15];
    char jenis_mobil[50];
    char merk_mobil[50];
    int tahun_keluar;
    char warna[50];
    float tarif_harian;
}data[max];

void tampil(int nilai)
{
 cout << "Nomor Induk Kependudukan (NIK): " << data[nilai].no_ktp << endl;
 cout << "Nama Customer                 : " << data[nilai].nama_cust << endl;
 cout << "No Telepon                    : " << data[nilai].no_tlp << endl;
 cout << "Alamat Customer               : " << data[nilai].alamat << endl;
 cout << "Jenis Kelamin                 : " << data[nilai].gender << endl;
 cout << "Jenis Mobil                   : " << data[nilai].jenis_mobil << endl;
 cout << "Merk Mobil                    : " << data[nilai].merk_mobil << endl;
 cout << "Tahun Keluar                  : " << data[nilai].tahun_keluar << endl;
 cout << "Warna Mobil                   : " << data[nilai].warna << endl;
 cout << "Tarif Sewa Harian             : " << data[nilai].tarif_harian << endl;
 cout << endl;
 cout << "Tekan Any Key untuk Kembali.";
}

    int id = -1;

int main()
{
int pil,i,j;
long long cari, ganti;

awal:
system("cls");
cout << "======================================" << endl;
cout << "SELAMAT DATANG DI PROGRAM RENTAL MOBIL" << endl;
cout << "======================================" << endl;
cout << "Menu : " << endl;
cout << "1. Penambahan Data Customer" << endl;
cout << "2. Penghapusan Data Customer" << endl;
cout << "3. Tampil Data Customer" << endl;
cout << "4. Pencarian Data Customer" << endl;
cout << "5. Edit Data Customer" << endl;
cout << "6. Keluar" << endl;
cout << "Masukan Pilihan Anda : " << endl;
cin >> pil;

    switch(pil)
    {
        case 1:
            if(id == max)
            {
                cout << "Data KTP Sudah Penuh.";
                Sleep(2000);
                Sleep(1000);
                cout << ".";
                Sleep(1000);
                cout << ".";
                Sleep(1000);
                goto awal;
            }
            else
                id++;
                cout <<"Penambahan Data" << endl;
                cout <<"Masukan No KTP        : "; cin >> data[id].no_ktp;
                cout <<"Masukan Nama          : "; fflush(stdin); gets(data[id].nama_cust);
                cout <<"Masukan No telepon    : "; cin >> data[id].no_tlp;
                cout <<"Masukan Alamat        : "; fflush(stdin); gets(data[id].alamat);
                cout <<"Masukan Jenis Kelamin : "; fflush(stdin); gets(data[id].gender);
                cout <<"Masukan Jenis Mobil   : "; fflush(stdin); gets(data[id].jenis_mobil);
                cout <<"Masukan Merk Mobil    : "; fflush(stdin); gets(data[id].merk_mobil);
                cout <<"Masukan Tahun keluar  : "; cin >> data[id].tahun_keluar;
                cout <<"Masukan Warna Mobil   : "; fflush(stdin); gets(data[id].warna);
                cout <<"Masukan Tarif Harian  : "; cin >> data[id].tarif_harian;
                cout << endl;
                Sleep(1000);
                cout << "Data yang Anda Masukan Berhasil Tersimpan.";
                Sleep(1000);
                cout << ".";
                Sleep(1000);
                goto awal;
                break;

        case 2:
            if(id == -1)
            {
                cout << "Data Customer Masih Kosong";
                Sleep(1000);
                cout << ".";
                Sleep(1000);
                cout << ".";
                Sleep(1000);
                goto awal;

            }
            else
            {
                cout << "Masukan NIK yang ingin dihapus : ";
                cin >> cari;
                for(i=0;i<id+1;i++)
                {
                    if(data[i].no_ktp == cari)
                    {
                    id -- ;
                    for(j=i;j<id+1;j++)
                    {
                    data[j].no_ktp = data[j+1].no_ktp;
                    }
                    cout << "Data Berhasil Dihapus.";
                    }
                }
                Sleep(1000);
                cout << ".";
                Sleep(1000);
                cout << ".";
                Sleep(1000);
                goto awal;
            }
            break;

        case 3:
            if(id == -1)
            {
            cout << "Data Customer Masih Kosong.";
            Sleep(1000);
            cout << ".";
            Sleep(1000);
            cout << ".";
            Sleep(1000);
            goto awal;
            }
            else
            {
            for(i=0;i<=id;i++)
            {
            cout << "| Data Ke-" << i+1 << " |" << endl;
            tampil(i);
            }
            getch();
            goto awal;
            }
            break;
        case 4:
            if(id == -1)
            {
             cout << "Data Customer Masih Kosong";
            Sleep(1000);
            cout << ".";
            Sleep(1000);
            cout << ".";
            Sleep(1000);
            goto awal;
            }
            else
            {
            printf("Masukan No KTP yang ingin dicari : ");
            cin >> cari;
            for(i=0;i<id+1;i++)
            {
                if(data[i].no_ktp == cari)
                {
                    cout << "==============================" << endl;
                    cout << "Berikut Data Customer yang ada" << endl;
                    cout << "==============================" << endl;
                    tampil(i);
                    getch();
                    goto awal;
                }
                else
                {
                    cout << "Hasil Tidak Ditemukan.";
                    getch();
                    goto awal;
                }
            }
            }
            break ;
        case 5:
            if(id == -1)
            {
             cout << "Data Customer Masih Kosong";
            Sleep(1000);
            cout << ".";
            Sleep(1000);
            cout << ".";
            Sleep(1000);
            goto awal;
            }
            else
            {
            cout << "Masukan NIK yang ingin diubah : ";
            cin >> ganti;
            for(i=0;i<id+1;i++)
            {
            if(data[i].no_ktp == ganti)
            {
            cout << "Masukan Data Baru : " << endl;
            cout <<"Masukan No KTP        : "; cin >> data[id].no_ktp;
            cout <<"Masukan Nama          : "; fflush(stdin); gets(data[id].nama_cust);
            cout <<"Masukan No telepom    : "; cin >> data[id].no_tlp;
            cout <<"Masukan Alamat        : "; fflush(stdin); gets(data[id].alamat);
            cout <<"Masukan Jenis Kelamin : "; fflush(stdin); gets(data[id].gender);
            cout <<"Masukan Jenis Mobil   : "; fflush(stdin); gets(data[id].jenis_mobil);
            cout <<"Masukan Merk Mobil    : "; fflush(stdin); gets(data[id].merk_mobil);
            cout <<"Masukan Tahun keluar  : "; cin >> data[id].tahun_keluar;
            cout <<"Masukan Warna Mobil   : "; fflush(stdin); gets(data[id].warna);
            cout <<"Masukan Tarif Harian  : "; cin >> data[id].tarif_harian;
            cout << endl;
            Sleep(1000);
            cout << "Data yang Anda Masukan Berhasil Tersimpan.";
            Sleep(1000);
            cout << ".";
            Sleep(1000);
            goto awal;
            }
            }
}
    }
}
