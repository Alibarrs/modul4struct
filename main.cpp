#include <iostream>
#include <conio.h>

using namespace std;

struct data_pembeli
{
    string kode_pbl;
    string status;
    string nama;
};

struct data_barang
{
    string kode_barang;
    string nama_barang;
    int harga;
};

struct hitung
{
    int juml, total=0;
};
hitung t[5];

int main()
{
    int i, j, juml, diskon, totals=0;
    int subtotal=0, bayar, kembali, jmltrx;
    string kodepem, kodebar;
    string member;

    data_pembeli dp[5];
    dp[0] = {.kode_pbl="P001", .status="M",  .nama="Diana"};
    dp[1] = {.kode_pbl="P002", .status="M",  .nama="Rina"};
    dp[2] = {.kode_pbl="P003", .status="BM", .nama="Lina"};
    dp[3] = {.kode_pbl="P004", .status="BM", .nama="Doni"};
    dp[4] = {.kode_pbl="P005", .status="M",  .nama="Dodi"};

    data_barang db[5];
    db[0] = {.kode_barang="BRG001", .nama_barang="Pensil    ",  .harga=2000};
    db[1] = {.kode_barang="BRG002", .nama_barang="Buku Tulis",  .harga=3500};
    db[2] = {.kode_barang="BRG003", .nama_barang="Penghapus ",  .harga=1000};
    db[3] = {.kode_barang="BRG004", .nama_barang="Penggaris ",  .harga=1500};
    db[4] = {.kode_barang="BRG005", .nama_barang="Ballpoint ",  .harga=2500};

    //input kode pembeli
    cout << "Kode Pembeli   : ";
    cin >> kodepem;
    for (int i=0; i<5; i++)
    {
        if (kodepem == dp[i].kode_pbl)
        {
            cout << "Nama Pembeli   : " << dp[i].nama;
            cout << endl;
            cout << "Status Pembeli : " << dp[i].status;
        }
    }
    //

    // input kode barang
    cout << endl;
    cout << "\n";
    cout << "Jumlah transaksi : ";
    cin >> jmltrx;
        for (int i=0; i<jmltrx; i++)
        {
            cout << "\nKode Barang    : ";
            cin >> kodebar;
            if (kodebar == db[i].kode_barang)
            {
                cout << "Nama Barang    : " << db[i].nama_barang;
                cout << endl;
                cout << "Harga Barang   : " << db[i].harga;
                cout << "\nJumlah Barang  : ";
                cin >> t[i].juml;
                if (t[i].juml >= 3)
                {
                    t[i].total=t[i].juml*(db[i].harga);
                    t[i].total-=300;
                }
                else
                {
                    t[i].total=t[i].juml*db[i].harga;
                }
            }
            cout << "Total          : " << t[i].total << endl;
            subtotal+=t[i].total;
        }
    cout << endl;

    // input diskon otomatis member atau bukan member
    for (int i=0; i<5; i++)
    {
        if (kodepem==dp[i].kode_pbl)
        {
            if (dp[i].status=="M")
            {
                diskon=0.1*subtotal;
            }
            else
            {
                diskon=0;
            }
        }
    }
    totals=subtotal-diskon;

    //output nota pembelian
    cout << endl;
    cout << "========================================================" << endl;
    cout << "                     NOTA PEMBELIAN                     " << endl;
    cout << "                     TOKO INDO APRIL                    " << endl;
    cout << "              Jl. DI Panjaitan 128 Purwokerto           " << endl;
    cout << "========================================================" << endl;
    cout << "Kode Barang || Nama Barang || Jumlah || Harga || Total  " << endl;
    for (int i=0; i<jmltrx; i++)
    {
        cout << db[i].kode_barang << "          ";
        cout << db[i].nama_barang << "      ";
        cout << t[i].juml << "       ";
        cout << db[i].harga << "     ";
        cout << t[i].total << "  ";
        cout << endl;
    }
    cout << "\nSubTotal                                       : " << subtotal;
    cout << "\nDiskon                                         : " << diskon;
    cout << "\nTotal                                          : " << totals;
    cout << "\nJumlah bayar                                   : ";
    cin >> bayar;
    kembali=bayar-totals;
    cout << "Kembali                                        : " << kembali;
    cout << endl;
    cout << "\nData Pembeli     ";
    // mengoutputkan data pembeli
    for (int i=0; i<5; i++)
    {
        if (kodepem==dp[i].kode_pbl)
        {
          cout << "\nKode Pembeli     : " << kodepem;
          cout << "\nNama Pembeli     : " << dp[i].nama;
          // jika M berarti Member else Bukan Member
          if (dp[i].status=="M")
          {
            cout << "\nStatus Pembeli   : Member";
          }
          else
          {
              cout << "\nStatus Pembeli   : Bukan Member";
          }
        }
    }
    getch();

}

