#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED
#include<iostream>
using namespace std;

typedef struct elmAkun *adrAkun;
typedef struct elmStatus *adrStatus;

struct akun{
    string nama;
    string bio;
    string email;
    string status;

};
struct listAkun{
    adrAkun first;

};

struct elmAkun{
    akun info;
    adrAkun next;
    adrStatus firstStatus;
};

struct elmStatus{
    string info;
    adrStatus next;
    adrStatus prev;
};


void menu();
void createListAkun(listAkun &L);
bool isEmptyAkun(listAkun L);
bool isEmptyStatus(adrAkun p);
adrAkun createElemenAkun(string namaAkun,string bio,string email);
adrStatus createElemenStatus(string status);
void addAkun(listAkun &L,adrAkun p);
void addStatus(adrAkun p,adrStatus q);
adrAkun searchAkunByNama(listAkun L,string namaAkun);
adrAkun searchAkunByEmail(listAkun L,string email);
void searchAllAkunByStatus(listAkun L, string status);
void deleteFirstAkun(listAkun &L, adrAkun &p);
void deleteAfterAkun(adrAkun prec, adrAkun &p);
void deleteLastAkun(listAkun &L, adrAkun &p);
void deleteAkunByNama(listAkun &L,string x);
void deleteBio(adrAkun p);
void deleteStatusByOption(adrAkun &p, string &x);
int countAkun(listAkun L);
void viewAkunHuruf(listAkun L, string x);
int countStatus(adrAkun p);
void tampilAkunDenganJumlahStatusTertentu(listAkun L,int jStatus);
void viewAllAkun(listAkun L);
int lengthAkun(adrAkun q);
adrAkun panjangNama();
void pendekNama();





#endif // MLL_H_INCLUDED
