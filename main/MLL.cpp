#include<iostream>
#include "MLL.h"

using namespace std;

void menu(){
    cout << "\n\n--- Apa yang anda ingin lakukan? ---" << endl;
        cout << "1. Kelola Akun (Registrasi/Update Bio/Update Email/Tambah Status)" << endl;
        cout << "2. Melihat Semua Akun" << endl;
        cout << "3. Mencari Akun" << endl;
        cout << "4. Hapus Akun Berdasarkan Nama" << endl;
        cout << "5. Hapus Bio" << endl;
        cout << "6. Hapus Status" << endl;
        cout << "7. Menampilkan Banyak Akun" << endl;
        cout << "8. Menampilkan Akun yang Diawali Huruf Tertentu beserta Jumlahnya" << endl;
        cout << "9. Menampilkan Akun dengan Jumlah Status Tertentu" << endl;
        cout << "10. Menampilkan Akun dengan Nama Terpanjang" << endl;
        cout << "11. Menampilkan Akun dengan Nama Terpendek" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih Menu: ";

}
void createListAkun(listAkun &L){
    L.first = nullptr;
}

bool isEmptyAkun(listAkun L){
    return (L.first == nullptr);

}

bool isEmptyStatus(adrAkun p){
    return(p->firstStatus == nullptr);
}

adrAkun createElemenAkun(string namaAkun,string bio,string email){
    adrAkun p = new elmAkun;
    p->info.nama = namaAkun;
    p->info.bio = bio;
    p->info.email = email;
    p->next = nullptr;
    p->firstStatus = nullptr;
    return p;
}

adrStatus createElemenStatus(string status){
   adrStatus q = new elmStatus;
   q->info = status;
   q->next = nullptr;
   q->prev = nullptr;
   return q;

}

char lowercase(char c){
    if (c >= 'A' && c <= 'Z'){
        return c + 32;
    }
    return c;
}

bool namaLebihKecil(string a, string b){
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0'){
        char ca = lowercase(a[i]);
        char cb = lowercase(b[i]);

        if (ca < cb){
           return true;
        }else if(ca > cb){
            return false;
        }
        i++;
    }

    return a[i] == '\0' && b[i] != '\0';
}

void insertSortedAkunByNama(listAkun &L, adrAkun p){
    if (L.first == nullptr){
        L.first = p;
    }
    else if (namaLebihKecil(p->info.nama, L.first->info.nama)){
        p->next = L.first;
        L.first = p;
    }
    else{
        adrAkun q = L.first;
        while (q->next != nullptr &&
               namaLebihKecil(q->next->info.nama, p->info.nama)){
            q = q->next;
        }
        p->next = q->next;
        q->next = p;
    }
}


void addStatus(adrAkun p,adrStatus q){
    adrStatus x;

    if(isEmptyStatus(p)){
        p->firstStatus = q;
    }else{
        x = p->firstStatus;
        while(x->next != nullptr){
            x = x->next;
        }
        x->next = q;
        q->prev = x;

    }
}

adrAkun searchAkunByNama(listAkun L,string namaAkun){
    adrAkun p = L.first;
    while(p!= nullptr){
        if(p->info.nama == namaAkun){
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

void searchAkunByEmail(listAkun L,string email){
    adrAkun p = L.first;
    adrStatus s;
    bool ketemu = false;


    while(p!= nullptr){
        s = p->firstStatus;
        if(p->info.email == email){
           cout <<"Username: "<< p->info.nama<<endl;
           cout << "Email: "<<p->info.email<<endl;
           cout << "Bio: "<<p->info.bio<<endl;

            ketemu = true;
        if(s == nullptr){
           cout<<"Status : " << " "<<endl;
        }
        while(s!=nullptr){
          cout <<"Status : " <<s->info<<endl;
          s = s->next;
        }
        cout<<"--------------------------------------------"<<endl;
        }

        p = p->next;
    }
    if(ketemu == false){
        cout<<"Tidak ada akun yang menggunakan email: "<<email;
    }

}

void searchAllAkunByStatus(listAkun L, string status) {
    adrAkun p = L.first;
     bool found = false;
       cout<<"--------------------------------------------"<<endl;
      while (p != nullptr) {
        adrStatus s = p->firstStatus;
        while (s != nullptr) {
            if (s->info == status) {
                cout << "Status \"" << status << "\" ditemukan pada akun: "<< endl;
                cout<<"Username: "<<p->info.nama<<endl;
                cout<<"Email: "<<p->info.email<<endl;
                cout<<"Bio: "<<p->info.bio<<endl;
                adrStatus r = p->firstStatus;
                while(r!=nullptr){
                 cout <<"Status : " <<r->info<<endl;
                 r = r->next;
                }

                cout<<"--------------------------------------------"<<endl;
                found = true;
                break;
            }
            s = s->next;
        }

        p = p->next;

      }
      if(!found){
        cout<<"tidak ada akun yang memiliki status "<<status<<"\n";
      }
}

void deleteFirstAkun(listAkun &L, adrAkun &p){
    if (L.first != nullptr){
        p = L.first;
        L.first = p->next;
        p->next = nullptr;
    }
}

void deleteAfterAkun(adrAkun prec, adrAkun &p){
    if (prec != nullptr && prec->next != nullptr){
        p = prec->next;
        prec->next = p->next;
        p->next = nullptr;
    }
}

void deleteLastAkun(listAkun &L, adrAkun &p){
    if (L.first != nullptr){

        if (L.first->next == nullptr){
            p = L.first;
            L.first = nullptr;
        }

        else {
            adrAkun q = L.first;
            while (q->next->next != nullptr){
                q = q->next;
            }
            p = q->next;
            q->next = nullptr;
        }
    }
}

void deleteAkunByNama(listAkun &L, string x){
    adrAkun p = L.first;
    adrAkun q = nullptr;
    adrAkun del;
    bool found = false;

    while (p != nullptr && !found){
        if (p->info.nama == x){
            found = true;
        } else {
            q = p;
            p = p->next;
        }
    }

    if (found){
        if (p == L.first){
            deleteFirstAkun(L, del);
        }
        else if (p->next == nullptr){
            deleteLastAkun(L, del);
        }
        else {
            deleteAfterAkun(q, del);
        }
        cout<<"Akun berhasil dihapus"<<endl;
    }
    else {
        cout << "akun tidak ditemukan"<<endl;
    }
}


void deleteBio(adrAkun p){
    if (p!= nullptr && p->info.bio != "-"){
        p->info.bio = "-";
        cout<<"Bio berhasil dihapus";
    }else if(p!=nullptr && p->info.bio == "-"){
        cout<<"Akun tidak memiliki bio";
    }
}

void updateBio(adrAkun p, string bioBaru) {
    if (p != nullptr) {
        p->info.bio = bioBaru;
    }
}

void updateEmail(adrAkun p, string emailBaru) {
    if (p != nullptr) {
        p->info.email = emailBaru;
    }
}


void deleteStatusByOption(adrAkun p, string x){
    adrStatus a;
    a = p->firstStatus;
    bool ketemu = false;
    while (a != nullptr){
        if (a->info == x){
            if(a == p->firstStatus){
                p->firstStatus = a->next;
                if (a->next != nullptr){
                a->next->prev = nullptr;
                }
            } else {
                a->prev->next = a->next;
                if (a->next != nullptr){
                    a->next->prev = a->prev;
                }
            }

            ketemu = true;
        }
        a = a->next;
    }
    if (a == nullptr && ketemu==false){
        cout<<"Status tidak ditemukan";
    }else{
        cout<<"Status berhasil dihapus";
    }

}



int countAkun(listAkun L){
    int count;
    adrAkun p;

    count = 0;
    p = L.first;

    while(p!= nullptr){
        count++;
        p = p->next;
    }
    return count;

}

void viewAkunHuruf(listAkun L, char x){
    if(L.first == nullptr){
        cout<<"List Akun Kosong"<<endl;
    }else{
    adrAkun p = L.first;
    adrStatus s;
    int counter = 0;

    while (p != nullptr){
        if (lowercase(p->info.nama[0]) == lowercase(x)){
            s = p->firstStatus;
              cout<<"Username: "<<p->info.nama<<endl;
              cout<<"Email: "<<p->info.email<<endl;
            if(p->info.bio == "-"){
               cout<<"Bio : " << " "<<endl;
            }else{
               cout<<"Bio : " << p->info.bio<<endl;
            }
            if(s == nullptr){
               cout<<"Status : " << " "<<endl;
            }
            while(s!=nullptr){
               cout <<"Status : " <<s->info<<endl;
               s = s->next;
            }
            counter = counter+1 ;
            cout<<"--------------------------------------------"<<endl;
        }
        p = p-> next;

    }
    if (counter == 0){
        cout<<"Tidak ada akun yang diawali huruf "<<x<<endl;
    }else{
      cout <<"Total akun yang diawali huruf "<<x<<" ada "<< counter<<" akun"<<endl;
    }
    }
}

int countStatus(adrAkun p){
    adrStatus s;
    s = p->firstStatus;
    int  count = 0;

    while(s!=nullptr){
        count = count+1;
        s = s->next;
        }
    return count;
    }

void viewAkunTertentu(listAkun L,adrAkun p){
    adrStatus s = p->firstStatus;
    cout<<"--------------------------------------------"<<endl;
    cout <<"Username: "<< p->info.nama<<endl;
    cout << "Email: "<<p->info.email<<endl;
    cout << "Bio: "<<p->info.bio<<endl;
    if(s == nullptr){
        cout<<"Status : " << " "<<endl;
    }
    while(s!=nullptr){
        cout <<"Status : " <<s->info<<endl;
        s = s->next;
    }
     cout<<"--------------------------------------------"<<endl;
}


void tampilAkunDenganJumlahStatusTertentu(listAkun L,int jStatus){
    if(L.first == nullptr){
        cout<<"List Akun Kosong"<<endl;
    }else{



    adrAkun p = L.first;
    int count;
    bool ketemu = false;

      cout<<"--------------------------------------------"<<endl;
      while(p!=nullptr){
       adrStatus s = p->firstStatus;
       count = countStatus(p);

       if (count == jStatus){
        cout<<"Username: "<<p->info.nama<<endl;
        cout<<"Email: "<<p->info.email<<endl;
        if(p->info.bio == "-"){
             cout<<"Bio : " << " "<<endl;
        }else{
            cout<<"Bio : " << p->info.bio<<endl;
        }

        if(s == nullptr){
            cout<<"Status : " << " "<<endl;
        }
        while(s!=nullptr){
            cout <<"Status : " <<s->info<<endl;
            s = s->next;
        }
        cout<<" "<<endl;
        ketemu = true;
        cout<<"--------------------------------------------"<<endl;
       }
       p = p->next;

      }

      if(!ketemu){
        cout<<"Tidak ada akun dengan jumlah status "<<jStatus<<endl;
      }
    }

}

void viewAllAkun(listAkun L){
    adrAkun p = L.first;


    if(p==nullptr){
        cout<<"list akun kosong";
    }

    cout<<" "<<endl;
    while(p!=nullptr){
        adrStatus s = p->firstStatus;
        cout<<"Username : " << p->info.nama<<endl;
        cout<<"Email : " << p->info.email<<endl;
        if(p->info.bio == "-"){
             cout<<"Bio : " << " "<<endl;
        }else{
            cout<<"Bio : " << p->info.bio<<endl;
        }
        if(s == nullptr){
            cout<<"Status : " << " "<<endl;
        }
        while(s!=nullptr){
            cout <<"Status : " <<s->info<<endl;
            s = s->next;
        }
        cout<<"--------------------------------------------"<<endl;
        p = p->next;
    }


}
int counterString(string username){
    int panjang;
    panjang = username.length();
    return panjang;
}

int lengthAkun(adrAkun q){
    if (q == nullptr) {
        return -1;
    }
    return q->info.nama.length();
}

adrAkun panjangNama(listAkun L){
    if (L.first == nullptr){
        return nullptr;
    }

    adrAkun q = L.first;
    adrAkun p = nullptr;
    int maxx = -1;

    while (q != nullptr){
        int panjang = lengthAkun(q);
        if (panjang > maxx){
            maxx = panjang;
            p = q;
        }
        q = q->next;
    }
    return p;
}
void tampilPanjangNama(listAkun L){
    if (L.first == nullptr){
        cout<<"List Akun Kosong"<<endl;
    } else {
        adrAkun q = L.first;
        adrAkun p = nullptr;
        int maxx = -1;
        adrAkun z = panjangNama(L);
        int max = lengthAkun(z);
        adrStatus s;

        cout<<"--------------------------------------------"<<endl;
        while (q != nullptr){
            int panjang = lengthAkun(q);
            if (panjang >= maxx){
                maxx = panjang;
                p = q;
                if (maxx == max){
                    s = p->firstStatus;
                    cout<<"Username: "<<p->info.nama<<endl;
                    cout<<"Email: "<<p->info.email<<endl;
                    if(p->info.bio == "-"){
                        cout<<"Bio : "<<endl;
                    }else{
                        cout<<"Bio : "<<p->info.bio<<endl;
                    }
                    if(s == nullptr){
                        cout<<"Status : "<<endl;
                    }
                    while(s!=nullptr){
                        cout <<"Status : "<<s->info<<endl;
                        s = s->next;
                    }
                    cout<<"--------------------------------------------"<<endl;
                }
            }
            q = q->next;
        }
    }
}

void tampilPendekNama(listAkun L){
    if (L.first == nullptr){
        cout<<"List Akun Kosong"<<endl;
    } else {
        adrAkun q = L.first;
        adrAkun p = nullptr;
        adrStatus s;
        adrAkun z = panjangNama(L);
        int minn = lengthAkun(z);

        cout<<"--------------------------------------------"<<endl;
        while (q != nullptr){
            int pendek = lengthAkun(q);
            if (pendek <= minn){
                minn = pendek;
                p = q;
                s = p->firstStatus;

                cout<<"Username: "<<p->info.nama<<endl;
                cout<<"Email: "<<p->info.email<<endl;
                if(p->info.bio == "-"){
                    cout<<"Bio : "<<endl;
                }else{
                    cout<<"Bio : "<<p->info.bio<<endl;
                }
                if(s == nullptr){
                    cout<<"Status : "<<endl;
                }
                while(s!=nullptr){
                    cout <<"Status : "<<s->info<<endl;
                    s = s->next;
                }
                cout<<"--------------------------------------------"<<endl;
            }
            q = q->next;
        }
    }
}
