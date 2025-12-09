#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED
#include<iostream>
using namespace std;

typedef struct elmAkun *adrAkun;
typedef struct elmStatus *adrAkun;

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

struct status{

};

struct elmStatus{
    status info;
    adrStatus next;
    adrStatus prev;
};


void menu()
void createListAkun(ListAkun &L)
bool isEmptyAkun(listAkun L)
bool isEmptyStatus(adrAkun p){
adrAkun createElemenAkun(string namaAkun,string bio,string email){
adrStatus createElemenStatus(string status){
void addAkun(listAkun &L,adrAkun p){
void addStatus(adrAkun p,adrStatus q){
adrAkun searchAkunByNama(listAkun L,string namaAkun){
adrAkun searchAkunByEmail(listAkun L,string email){
//searchAkunByStatus
void deleteBio(adrAkun p){
//delete status
int countAkun(listAkun L){



<<<<<<< HEAD
=======
typedef halomok int
test lagi
>>>>>>> d782fa0602907ddb5d173d7fb03db26bd5b1783e

#endif // MLL_H_INCLUDED
