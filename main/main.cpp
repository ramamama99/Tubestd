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
        case 1:
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
                    cout <<"Masukkan username: ";
                    cin>>username;
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
                        cout << "masukan email untuk akun anda: ";
                        cin >> email;
                        cout << "masukan bio untuk akun anda (jika tidak ingin menambahkan, silahkan input '-'.): ";
                        cin >> bio;

                        adk = createElemenAkun(username,bio,email);
                        insertSortedAkunByNama(L,adk);

                        cout<<"Akun anda berhasil didaftarkan\n";
                        uservalid = true;
                    }



                }
                break;


            }case 2:
                cout << "Masukkan username: ";
                cin >> username;
                p = searchAkunByNama(L,username);

                if (p!= nullptr){
                    cout<<"Silahkan masukkan bio yang baru: ";
                    cin >> bio;
                    updateBio(searchAkunByNama(L, username),bio);
                }else{
                    cout<<"Akun dengan username "<<username<<" tidak ditemukan";
                }
                break;
            case 3:
                cout << "Masukkan username: ";
                cin >> username;
                p = searchAkunByNama(L,username);

                if(q!=nullptr){
                    cout<<"Silahkan masukkan email yang baru: ";
                    cin >> email;
                    updateEmail(p,email);
                }else{
                    cout<<"Akun dengan username "<<username<<" tidak ditemukan";
                }
                break;
            case 4:
                cout << "Masukkan username: ";
                cin >> username;
                p = searchAkunByNama(L,username);

                if(p!=nullptr){
                    cout<<"Silahkan masukkan status yang baru: ";
                    cin >> status;
                    q = createElemenStatus(status);
                    addStatus(p,q);
                }else{
                    cout<<"Akun dengan username "<<username<<" tidak ditemukan";
                }
                break;


            default:
            break;


            }
            break;
        case 2:
            viewAllAkun(L);
            break;

        case 3:{

            int nomor;
            string nama;
            string Email;
            string Status;

            cout<<"Mau cari akun berdasarkan apa? (1.Nama/2.Email/3.Status)";
            cout << "Silahkan input nomor pilihan: ";
            cin >> nomor;
            switch(nomor){
            case 1:
                cout << "Masukkan nama yang ingin dicari: ";
                cin >> nama;
                hasil = searchAkunByNama(L, nama);
                viewAkunTertentu(L,hasil);
                break;
            case 2:
                cout << "Masukkan email yang ingin dicari: ";
                cin >> Email;
                hasil = searchAkunByEmail(L, Email);
                viewAkunTertentu(L,hasil);
                break;

            case 3:
                cout << "Masukkan Status yang ingin dicari: ";
                cin >> Status;
                searchAllAkunByStatus(L, Status);
                break;
            }

            break;
        }
        case 4:
            cout<<"Silahkan Masukkan Nama akun yang ingin dihapus: ";
            cin >> username;
            deleteAkunByNama(L, username);

            break;
        case 5:
            cout<<"Silahkan Masukkan Nama akun: ";
            cin >> username;
            hasil = searchAkunByNama(L, username);
            deleteBio(hasil);
            cout<<"Bio berhasil dihapus";

            //menghapus bio

            break;
        case 6:
            cout<<"Silahkan Masukkan Nama akun: ";
            cin >> username;
            cout<<"Silahkan Masukkan status yang ingin dihapus: ";
            cin >> status;
            hasil = searchAkunByNama(L, username);
            deleteStatusByOption(hasil, status);

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
            cout<<"Silahkan input huruf pertama: ";
            cin>>huruf;
            viewAkunHuruf(L,huruf);
            break;
        case 9:
            int jStatus;
            cout<<"Silahkan input jumlah status: ";
            cin>>jStatus;
            tampilAkunDenganJumlahStatusTertentu(L,jStatus);
            break;
        case 10:
            cout<<"Akun dengan Username terpanjang:\n";
            tampilPanjangNama(L);
            break;
        case 11:
            cout<<"Akun dengan Username terpendek:\n";
            tampilPendekNama(L);
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
