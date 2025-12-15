#include<iostream>
#include "MLL.h"

using namespace std;

void menu(){
    cout << "\n\n--- Apa yang anda ingin lakukan? ---" << endl;
        cout << "1. Kelola Akun (Registrasi/Update Bio/Email/Tambah Status)" << endl;
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

adrAkun searchAkunByEmail(listAkun L,string email){
    adrAkun p = L.first;
    while(p!= nullptr){
        if(p->info.email == email){
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

void searchAllAkunByStatus(listAkun L, string status) {
    adrAkun p = L.first;
     bool found = false;
      while (p != nullptr) {
        adrStatus s = p->firstStatus;
        while (s != nullptr) {
            if (s->info == status) {
                cout << "Status \"" << status << "\" ditemukan pada akun: " << p->info.nama << endl;
                cout<<"Email: "<<p->info.email<<endl;
                cout<<"Bio: "<<p->info.bio<<endl;
                cout<<" "<<endl;
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
    }
    else {
        cout << "akun tidak ditemukan";
    }
}


void deleteBio(adrAkun p){
    if (p!= nullptr){
        p->info.bio = "-";
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
            a->next = nullptr;
            a->prev = nullptr;
            break;
        }
        a = a->next;
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
    adrAkun p = L.first;
    int counter = 0;
    while (p != nullptr){
        if (lowercase(p->info.nama[0]) == lowercase(x)){
            cout << p->info.nama<<endl;
            counter = counter+1 ;
        }
        p = p-> next;
        cout << counter;
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
    cout << "-------------------";
    cout << p->info.nama;
    cout << p->info.email;
    cout << p->info.bio;
    cout << "-------------------";
}


void tampilAkunDenganJumlahStatusTertentu(listAkun L,int jStatus){
    adrAkun p = L.first;
    int count;
    bool ketemu = false;
      while(p!=nullptr){
       count = countStatus(p);

       if (count == jStatus){
        cout<<p->info.nama<<endl;
        cout<<p->info.email<<endl;
        cout<<p->info.bio<<endl;

        ketemu = true;
       }
       p = p->next;
      }

      if(!ketemu){
        cout<<"Tidak ada akun dengan jumlah status "<<jStatus<<endl;
      }


}

void viewAllAkun(listAkun L){
    adrAkun p = L.first;


    while(p!=nullptr){
        adrStatus s = p->firstStatus;
        cout<<"Username : " << p->info.nama<<endl;
        cout<<"Email : " << p->info.email<<endl;
        cout<<"Bio : " << p->info.bio<<endl;

        if(s == nullptr){
            cout<<"Status : " << " "<<endl;
        }
        while(s!=nullptr){
            cout <<"Status : " <<s->info<<endl;
            s = s->next;
        }
        cout<< " "<<endl;
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
    int panjang;
    string nama = q->info.nama;
    panjang = nama.length();
    return panjang;
}

adrAkun panjangNama(listAkun L){
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
    adrAkun q = L.first;
    adrAkun p = nullptr;
    int maxx = -1;
    adrAkun z=panjangNama(L);
    int max = lengthAkun(z);


    while (q != nullptr){
        int panjang = lengthAkun(q);
        if (panjang >=maxx){
            maxx = panjang;
            p = q;
            if(maxx == max ){
            cout<<p->info.nama<<endl;
            }
        }
        q = q->next;
    }

//anjan,kakakakng,sana,acengkek
}

void tampilPendekNama(listAkun L){
    adrAkun q = L.first;
    adrAkun p = nullptr;

    adrAkun z = panjangNama(L);
    int minn = lengthAkun(z);
//2,8,14,2,
    while (q != nullptr){
        int pendek = lengthAkun(q);
        if (pendek <= minn ){
            minn = pendek;
            p = q;
            cout<< p->info.nama << endl;
        }

        q = q->next;

    }
//andi,acang,beni


}



