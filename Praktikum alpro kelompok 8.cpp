#include <iostream>

using namespace std ;

struct pengguna {
    string nama[4]= {"bayu","haikal","farhan","ipin"};

    int pin[4]= {543210,567890,112345,123456};
    int saldo[4]= {5000000,2000000,3000000,4000000};
};

void tampilan (){
    cout << "================================================\n";
    cout << "|      SELAMAT DATANG CALON PEMGHUNI SURGA     |\n";
    cout << "------------------------------------------------\n";
    cout << "|                     MENU                     |\n";
    cout << "================================================\n";
    cout << "| 1. INFORMASI SALDO                           |\n";
    cout << "| 2. TRANSFER                                  |\n";
    cout << "| 3. GANTI PIN                                 |\n";
    cout << "| 4. TARIK TUNAI                               |\n";
    cout << "================================================\n";
}

void garis (){
    cout << "================================================\n";
}

int main(){
    int pin, transfer, nomor_nama_nasabah, i, index_array, saldo_sumber, saldo_penerima, pin_baru, tarik_tunai;
    int menu, saldonya;
    char pilihan;
    int *poin[4];
 
    string nama_nasabah;
    pengguna penggunanya;
    cout << " " << endl ;
    cout << "====================" << endl ;
    cout << "Masukkan PIN Anda : " ;
    cin >> pin;
    cout << "===================="<< endl;
    cout << " " << endl;
    if (pin == 543210){
        nama_nasabah = penggunanya.nama[0];
        index_array = 0;
    }else if (pin == 567890){
        nama_nasabah = penggunanya.nama[1];
        index_array = 1;
    }else if (pin == 112345){
        nama_nasabah = penggunanya.nama[2];
        index_array = 2;
    }else if (pin == 123456){
        nama_nasabah = penggunanya.nama[3];
        index_array = 3;
    }
        mulai:
    cout << "Pengguna : " << nama_nasabah <<endl  ;
    tampilan();
    cout << "(1-4): ";
    cin >> menu ;
    cout << endl ;
    garis ();

    switch (menu){
    case 1:

        cout <<nama_nasabah<<" Saldo Anda Saat Ini Adalah : Rp."<< penggunanya.saldo[index_array] << endl;
        cout<<"Ingin melakukan transaksi kembali?(Y/N):";
        cin>>pilihan;
        if (pilihan == 'Y' || pilihan == 'y')
        {
            goto mulai;
        } else {
            cout<<"Terima kasih telah melakukan transaksi";
        }
        break;

    case 2:
        for(i=0;i<4;i++){
            if(i == index_array){
                continue;
            } else {
           
            cout<<i<<" ";
            cout<<penggunanya.nama[i]<<" "<< endl;
            
        
            }
        }
        garis ();
        cout<<"Pilih tujuan transfer (Masukkan angka nomor pengguna): ";
        cin>>nomor_nama_nasabah;
        poin[0] = &penggunanya.saldo[index_array];
        poin[1] = &penggunanya.saldo[nomor_nama_nasabah];
        cout<<"Masukkan nominal transfer: ";
        cin>>transfer; cout<<endl;
        *poin[0] = penggunanya.saldo[index_array] - transfer;
        *poin[1] = penggunanya.saldo[nomor_nama_nasabah] + transfer;
        cout<<"Transfer Berhasil... Saldo anda sekarang: "<<penggunanya.saldo[index_array]<<endl;
        cout<<"Ingin melakukan transaksi kembali?(Y/N):";
        cin>>pilihan;
        if (pilihan == 'Y' || pilihan == 'y')
        {
            goto mulai;
        } else {
            cout<<"Terima kasih telah melakukan transaksi";
        }
        
        //*poin = saldonya - transfer;
    break;

    case 3:

        cout <<"Pin Anda saat ini: "<<penggunanya.pin[index_array]<<endl;
        poin[2] = &penggunanya.pin[index_array];
        cout <<"Masukkan pin yang baru: ";
        cin >> pin_baru;
        *poin[2] = pin_baru;
        cout << "Penggantian pin berhasil, pin anda saat ini: "<< penggunanya.pin[index_array]<<endl;
        cout<<"Ingin melakukan transaksi kembali?(Y/N):";
        cin>>pilihan;
        if (pilihan == 'Y' || pilihan == 'y')
        {
            goto mulai;
        } else {
            cout<<"Terima kasih telah melakukan transaksi";
        }
        break;

    case 4:

        cout <<" Saldo Anda Saat Ini Adalah : Rp."<< penggunanya.saldo[index_array] << endl;
        poin[3] = &penggunanya.saldo[index_array];
        cout <<" Masukkan nominal yang ingin ditarik tunai: Rp.";
        cin >> tarik_tunai;
        *poin[3] = penggunanya.saldo[index_array] - tarik_tunai;
        cout << "Tarik tunai berhasil!, sisa saldo anda sekarang adalah : Rp." << penggunanya.saldo[index_array]<<endl;
        cout<<"Ingin melakukan transaksi kembali?(Y/N):";
        cin>>pilihan;
        if (pilihan == 'Y' || pilihan == 'y')
        {
            goto mulai;
        } else {
            cout<<"Terima kasih telah melakukan transaksi";
        }
        break;
    default:
    exit(0);
        break;
    }
}

