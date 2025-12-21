#include <iostream>
#include"MLL.h"
using namespace std;

int main()
{
    int pilih;
    listAkun L;
    createListAkun(L);
    adrAkun p,n,adk,hasil;
    adrStatus q;
    string username;
    string email;
    string bio;
    string status;


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

    insertSortedAkunByNama(L,s1);
    insertSortedAkunByNama(L,s2);
    insertSortedAkunByNama(L,s3);
    insertSortedAkunByNama(L,s4);
    insertSortedAkunByNama(L,s5);
    insertSortedAkunByNama(L,s6);
    insertSortedAkunByNama(L,s7);
    insertSortedAkunByNama(L,s8);
    insertSortedAkunByNama(L,s9);
    insertSortedAkunByNama(L,s10);

    cout << "========================================" << endl;
    cout << "  SELAMAT DATANG di MANAJEMEN AKUN      " << endl;
    cout << "========================================" << endl;

    while(true){
    menu();
    cin >> pilih;

    if (pilih>=1 && pilih <=11){

      switch(pilih){
        case 1:{
            bool keluar = false;
            while(!keluar){
            int case_1;
            cout<<"\nApa yang akan ingin anda lakukan terhadap pengelolaan akun?"<<endl;
            cout<<"1.Registrasi\n2.Update Bio\n3.Update Email\n4.Tambah Status\n5.Batal"<< endl;
            cout<<"Pilih Menu: ";
            cin>>case_1;

            switch(case_1){
            case 1:{
                bool uservalid = false;
                bool cekNama = false;
                while(!uservalid){
                    cout <<"\n------------------------\n";
                    cout <<"ketentuan registrasi\n";
                    cout <<"------------------------\n";
                    cout <<"Nama akun wajib lebih dari 5 karakter\n";
                    cout <<"Masukkan username(input 'cancel' untuk membatalkan): ";
                    cin>>username;
                    if (username == "cancel"){
                        break;
                    }

                    n = searchAkunByNama(L,username);
                    int c = counterString(username);


                    if(n== nullptr){
                        cekNama = true;
                    }else{
                        cekNama = false;
                    }

                    if (c < 6){
                        cout << "Username yang anda masukkan kurang dari 6 karakter";
                    } else if (cekNama != true){
                        cout <<"ganti nama lain";
                    } else {
                        cout << "masukan email untuk akun anda(input 'cancel' untuk membatalkan): ";
                        cin >> email;
                        if(email == "cancel"){
                            break;
                        }
                        cout << "masukan bio untuk akun anda \n(jika tidak ingin menambahkan, silahkan input '-' dan 'cancel' jika ingin membatalkan.): ";
                        cin >> bio;
                        if(bio == "cancel"){
                            break;
                        }

                        adk = createElemenAkun(username,bio,email);
                        insertSortedAkunByNama(L,adk);

                        cout<<"Akun anda berhasil didaftarkan\n";
                        uservalid = true;
                    }



                }
                break;

            }case 2:
                cout << "Masukkan username(input 'cancel' untuk membatalkan): ";
                cin >> username;
                if(username == "cancel"){
                    break;
                }
                p = searchAkunByNama(L,username);

                if (p!= nullptr){
                    cout<<"Silahkan masukkan bio yang baru: ";
                    cin >> bio;
                    if(bio == "cancel"){
                        break;
                    }
                    updateBio(searchAkunByNama(L, username),bio);
                }else{
                    cout<<"Akun dengan username "<<username<<" tidak ditemukan";
                }
                break;
            case 3:
                cout << "Masukkan username(input 'cancel' untuk membatalkan): ";
                cin >> username;
                if(username == "cancel"){
                    break;
                }
                p = searchAkunByNama(L,username);

                if(p!=nullptr){
                    cout<<"Silahkan masukkan email yang baru: ";
                    cin >> email;
                    if(email == "cancel"){
                        break;
                    }
                    updateEmail(p,email);
                }else{
                    cout<<"Akun dengan username "<<username<<" tidak ditemukan";
                }
                break;
            case 4:
                cout << "Masukkan username(input 'cancel' untuk membatalkan): ";
                cin >> username;
                if(username == "cancel"){
                    break;
                }
                p = searchAkunByNama(L,username);

                if(p!=nullptr){
                    cout<<"Silahkan masukkan status yang baru: ";
                    cin >> status;
                    if(status == "cancel"){
                        break;
                    }
                    q = createElemenStatus(status);
                    addStatus(p,q);
                    cout<<"akun berhasil ditambahkan";
                }else{
                    cout<<"Akun dengan username "<<username<<" tidak ditemukan";
                }
                break;

            case 5:
                keluar = true;
                continue;

            default:
                cout<<"Pilihan tidak valid\n";
                continue;
            }
            char lanjut;
            cout << "\nLanjut kelola akun? (y/n): ";
            cin >> lanjut;

            if (lanjut == 'n' || lanjut == 'N') {
                keluar = true;

            }
            }
            break;

            }
        case 2:
            cout<<"--------------------------------------------"<<endl;
            viewAllAkun(L);
            break;

        case 3:{
            bool keluar = false;
            int nomor;

            while(!keluar){
            cout<<"Mau cari akun berdasarkan apa?\n1.Nama\n2.Email\n3.Status\n4.Batal"<<endl;
            cout << "Silahkan input nomor pilihan: ";
            cin >> nomor;
            switch(nomor){
            case 1:
                cout << "Masukkan nama yang ingin dicari(input 'cancel' untuk membatalkan): ";
                cin >> username;
                if(username == "cancel"){
                    break;
                }
                hasil = searchAkunByNama(L, username);
                if(hasil!=nullptr){
                viewAkunTertentu(L,hasil);
                }else{
                cout<<"Akun tidak ditemukan"<<endl;
                }
                break;
            case 2:
                cout << "Masukkan email yang ingin dicari(input 'cancel' untuk membatalkan): ";
                cin >> email;
                if(email == "cancel"){
                    break;
                }
                searchAkunByEmail(L, email);
                break;

            case 3:
                cout << "Masukkan Status yang ingin dicari(input 'cancel' untuk membatalkan): ";
                cin >> status;
                if(status == "cancel"){
                    break;
                }
                searchAllAkunByStatus(L, status);
                break;
            case 4:
                keluar = true;
                continue;

            default:
                cout<<"Pilihan tidak valid\n";
                continue;
            }
            char lanjut;
            cout << "\nLanjut Searching? (y/n): ";
            cin >> lanjut;

            if (lanjut == 'n' || lanjut == 'N') {
                keluar = true;

            }


        }
        break;
        }
        case 4:
            cout<<"Silahkan Masukkan Nama akun yang ingin dihapus(input 'cancel' untuk membatalkan): ";
            cin >> username;
            if(username == "cancel"){
                break;
            }
            deleteAkunByNama(L, username);

            break;
        case 5:
            cout<<"Silahkan Masukkan Nama akun(input 'cancel' untuk membatalkan): ";
            cin >> username;
            if (username == "cancel"){
                break;
            }
            hasil = searchAkunByNama(L, username);

            if(hasil!=nullptr){
            deleteBio(hasil);

            }else{
                cout<<"Akun tidak ditemukan";
            }

            //menghapus bio

            break;
        case 6:
            cout<<"Silahkan Masukkan Nama akun(input 'cancel' untuk membatalkan): ";
            cin >> username;
            if(username== "cancel"){
                break;
            }
            hasil = searchAkunByNama(L, username);

            if(hasil!=nullptr){
                q = hasil->firstStatus;
                if(q != nullptr){
                    cout<<"Silahkan Masukkan status yang ingin dihapus(input 'cancel' untuk membatalkan): ";
                    cin >> status;
                    if(status == "cancel"){
                        break;
                    }
                    deleteStatusByOption(hasil, status);
                }else{
                    cout<<"Akun ini tidak memiliki status";
                }
            }else{
                cout<<"Akun tidak ditemukan";
            }
            //hapus status
            break;
        case 7:
            int total;
            total = countAkun(L);
            cout<<"Terdapat "<<total<<" Akun pada Manajemen Akun"<<endl;
            //hitung banyak akun

            break;
        case 8:
            char huruf;
            cout<<"input ! untuk membatalkan"<<endl;
            cout<<"Silahkan input huruf pertama: ";
            cin>>huruf;
            if(huruf == '!'){
                break;
            }
            cout<<"\nAkun yang diawali huruf "<<huruf<<endl;
            cout<<"--------------------------------------------"<<endl;
            viewAkunHuruf(L,huruf);

            break;
        case 9:
            int jStatus;
            cout<<"input -1 untuk membatalkan"<<endl;
            cout<<"Silahkan input jumlah status: ";
            cin>>jStatus;
            if(jStatus == -1){
                break;
            }
            tampilAkunDenganJumlahStatusTertentu(L,jStatus);
            break;
        case 10:
            cout<<"Akun dengan Username terpanjang:\n";
            tampilPanjangNama(L);
            break;
        case 11:
            cout<<"Akun dengan Username terpendek:\n";
            tampilPendekNama(L);
            break;
        default:
            break;
      }
    }else if (pilih == 0){
        break;

    }else{
    cout<<"Pilihan tidak valid";
    }

    char lanjut;
    cout << "\nLanjut Eksplorasi? (y/n): ";
    cin >> lanjut;

    if (lanjut == 'n') {
        break;
    }



    }


    return 0;
}
