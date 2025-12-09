#include<iostream>
#include "MLL.h"

using namespace std;

void menu(){
    cout << "\n--- Apa yang anda ingin lakukan? ---" << endl;
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
        cout << "Pilih Menu : ";



        }
void createListAkun(ListAkun &L){
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
    p->info.namaAkun = namaAkun;
    p->info.bio = bio;
    p->info.email = email;
    p->next = nullptr;
    p->firstStatus = nullptr;
    return p;
}

adrStatus createElemenStatus(string status){
    adrStatus q = new elmStatus;
   // q->info.status =
   q->next = nullptr;
   q->prev = nullptr;
   return q;

}

void addAkun(listAkun &L,adrAkun p){
    adrAkun x;

    if(isEmptyAkun(L)){
        L.first = p;
    }else{
        x = L.first;
        while(current ->next!= nullptr){
            x = x->next;
        }
        x->next = p
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
        if(p->info.namaAkun == namaAkun){
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

//searchAkunByStatus

void deleteBio(adrAkun p){
    if (p!= nullptr){
        p->info.bio = nullptr;

    }

}

//delete status


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

