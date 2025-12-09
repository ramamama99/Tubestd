#include <iostream>
#include"MLL.h"
using namespace std;

int main()
{
    int pilih;
    listAkun L;
    createListAkun(L);
    adrAkun p;
    adrStatus q;


    adrAkun s1 = createElemenAkun("Andi_01","Suka Belajar","Andiandiandi@gmail.com");
    adrAkun s2 = createElemenAkun("Beni_02","Suka Musik","MasBeni@gmail.com");
    adrAkun s3 = createElemenAkun("Cahya_03","Atlet Renang","Cahyaswimmer@gmail.com");
    adrAkun s4 = createElemenAkun("Dodi_04","Investor","Dodyku@gmail.com");
    adrAkun s5 = createElemenAkun("Endang_05","Long life learner","Endang115@gmail.com");
    adrAkun s6 = createElemenAkun("Farhani_06","Pecinta Kopi","NurFarhani@gmail.com");
    adrAkun s7 = createElemenAkun("GugumGumilar_07","Yapyap","Gugumku@gmail.com");
    adrAkun s8 = createElemenAkun("Hariss_08","Sleeping","Harissucipto@gmail.com");
    adrAkun s9 = createElemenAkun("indriw_09",".","Indriri@gmail.com");
    adrAkun s10 = createElemenAkun("JokoSucipto_10","Kosong","Jokjoko@gmail.com");

    addAkun(L,s1);
    addAkun(L,s2);
    addAkun(L,s3;
    addAkun(L,s4);
    addAkun(L,s5);
    addAkun(L,s6);
    addAkun(L,s7);
    addAkun(L,s8);
    addAkun(L,s9);
    addAkun(L,s10);

    cout << "========================================" << endl;
    cout << "  SELAMAT DATANG di MANAJEMEN AKUN      " << endl;
    cout << "========================================" << endl;

    while(true){
    menu();
    cin >> pilih;

    if (pilih>=1 && pilih <=11){

      switch(pilih){
        case 1:
            int case_1;
            cout<<"Apa yang akan ingin anda lakukan terhadap pengelolaan akun?"<<endl;
            cout<<"1.Registrasi\n2.Update Bio\n3.Update Email\n4.Tambah Status\n5.Batal"<< endl;
            cin>>case_1;

            switch(case_1){
            case 1:
                cout<<"Program masih dalam tahap pengembangan #1";
                break;
            case 2:
                cout<<"kembang #2";
            case 3:
                cout<<"Kembang #3";
            case 4:
                cout<<"kembang #5";
            case 5:
                cout<<"Batal";

            default:
                cout<<"silahkan input kembali\n";

            break;
            }
            break;
        case 2:
            cout<<"Show ALL";
            break;

        case 3:
            cout<<"Search";
            break;
        case 4:
            cout<<"Silahkan Masukkan Nama: ";

            // kalo ada namanya nanti bisa diapus
            // kalo ga ada output nama tidak ada dalam data manajemen akun

            break;
        case 5:
            //menghapus bio

            break;
        case 6:
            //hapus status
            break;
        case 7:
            //hitung banyak akun
            break;
        case 8:
            //tampilin akun yg diawali huruf tertentu
            break;
        case 9:
            //menampilkan akun dengan jumlah status tertentu
            break;
        case 10:
            //menampilkan akun dengan nama akun terpanjang
            break;
        case 11:
            //menampilkan akun dengan nama akun terpendek
            break;
        default:
            break;
      }
    }else if (pilih == 0){
        break;

    }else{
    cout<<"Pilihan tidak valid";
    }

    }


    return 0;
}
