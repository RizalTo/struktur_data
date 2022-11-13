#include <iostream>
#include<string.h>
using namespace std;

struct queue
{
    char nama[30];
    int nilai;
    queue *next;
};
queue *head, *tail;

void Inqueue()
{
    queue *baru;
    baru = new queue;
    cout << "Masukkan Nama : ";cin>>baru->nama;
    cout << "Masukkan Nilai :";cin>>baru->nilai;
    baru->next=NULL;

    if(head==NULL)
        head=tail=baru;
    else
    {
        tail->next=baru;
        tail=tail->next;
    }
}

void Dequeue()
{
    queue *hapus;
    if (tail!=NULL)
    {
        if(head!=tail)
        {
            hapus=head;
            head=head->next;
            delete hapus;
        }
        else
        {
            head=tail=NULL;
        }
    }
    else
        cout<<"Data Masih kosong\n";
}

void Tampil()
{
    queue *bantu;
    bantu=head;
    cout << "Queue : "<<endl;

    if(bantu==NULL)
        cout<<"Data Queue Masih Kosong";

    while (bantu!=NULL)
    {
        cout<<bantu->nama<<" "<<bantu->nilai<<endl;
        bantu=bantu->next;
    }
    cout << endl;
}

int main()
{
    int pilih;
    do
    {
        Tampil();
        cout<<"1. INQUEUE"<<endl;
        cout<<"2. DEQUEUE"<<endl;
        cout<<"3. Exit"<<endl;
        cout<<"Pilihan Anda [1-3] : ";
        cin>>pilih;
        if(pilih==1)
            /*Menjalankan : Tambah Node di-BELAKANG */
            Inqueue();
        if(pilih==2)
            /*Menjalankan : Hapus Node di-DEPAN*/
            Dequeue();
    }
    while(pilih!=3);
    return 0;
}
