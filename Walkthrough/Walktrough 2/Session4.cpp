#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define SIZE 100
// Declare size untuk si hash table
// untuk ngasi tau sizenya kita kan menggunakan variable
//  variablenya harus const / kita define
// const int Size = 100;
struct Mahasiswa{
    char nama[255];
    Mahasiswa* next;
}*head[SIZE],*tail[SIZE];

Mahasiswa* createNode(const char* nama){
    Mahasiswa* temp = (Mahasiswa*)malloc(sizeof(Mahasiswa));
    strcpy(temp->nama,nama);
    temp->next = NULL;

    return temp;
}

//  kita perlu bikin suatu hash function untuk kita menggenerate indexnya
int hashFunction(char nama[]){
    //  penjumlahan ASCII dari seluruh string
    int index = 0;
    int stringlength = strlen(nama);

    for (int i = 0; i < stringlength; i++)
    {
        index += nama[i];
    }
    
    return index % SIZE;
}

void pushHashTable(char nama[]){
    Mahasiswa* node = createNode(nama);
    int index = hashFunction(nama);
    printf("%s %d\n", nama , index);

    // validasi klo ternyata
    if (!head[index]){
        head[index] = tail[index] = node;
    }else{
        //  kalau sudah ada, maka terjadi collision
        //  1 chaining
        //  push tail
        tail[index]->next = node;
        tail[index] = node;
    }
}

void printAll(){
    //  buat liat semua
    //  loop untuk semua index array hash tablenya
    for (int i = 0; i < SIZE; i++)
    {
        //  cek apakah di index tersebut ada suatu SLL
        if(head[i]){
            //  Looping dari head -> akhir untuk print datanya
            Mahasiswa* curr = head[i];
            // selama nilai curr ada
            while(curr){
                printf("%s\n", curr->nama);
                curr = curr->next;
            }
        }
    }
    
}

// untuk pop ->  bakalan sama seperti pop mid / search pop
// jadi dia bakalan cari baru bakalan pop
// step" buat popnya
// 1-> masuikin string yang mau di pop
// 2-> generate index berdasarkan string tersebut
// 3-> cari string tersebut di index yang sudah ditembak
// 4 -> kalau ketemu maka kita pop aja

void popHashTable(char nama[]){
    int index = hashFunction(nama);
    // tinggal cari di index
    // kita bakal validasi validasi

    //  kalau di index benar benar ada data
    if(head[index]){
    // yang pertama di SLL nya cuma  ada 1 data dan 1 datanta itu adalah data yang kita cari

    if(strcmp(nama,head[index]->nama) && head[index] == tail[index]){
        free(head[index]);
        head[index] = NULL;
        tail[index] = NULL;
    }
    // kalau misalnya datanya ada di head
    else if(strcmp(nama,head[index]->nama) == 0){
        // pop head
        Mahasiswa* temp = head[index];
        // pindahin head
        head[index]= head[index]->next;
        free(temp);
        temp = NULL;
    }
    // jika datanya ada di tail maka kita pop tail
    else if(strcmp(nama,tail[index]->nama) == 0){
        // karena SLL maka kita loopoing dari node 1 sebelum tail
        Mahasiswa* curr = head[index];
        while (curr->next != tail[index])
        {
            curr = curr->next;
        }
        free(curr->next);
        curr->next = NULL;
        tail[index] = curr;
        
    }
    else{
        //  kita cari kalau dia di tengah- tengah
        Mahasiswa* curr = head[index];
        while (curr && curr->next)
        {
            if(strcmp(curr->next->nama, nama )==0){
                break;
            }



            curr = curr->next;
        }
        //  kalau misalnya curr == tail maka dia sudah dia akhir node dan tidak ketemu
        if(!curr->next){
            puts("Data tidak ketemu");
            return;
        }
        

        Mahasiswa* temp = curr->next;
       
        curr->next = curr->next->next;

        free(temp);
        temp = NULL;

        }
    }


}



/*
    Hash Table
    1. Masukkan data
    2. generate index berdasarkan algoritma / hash function kita tersendiri
    3. masukkin data ke index yang kita sudah generate

    Collision 
    1. Ketika datanya bertabrakan (index 1 sudah diisi, tapi ketika ingin masukkan data, datanya  harus masuk ke index 1)

    Collision Handling
    1. Linear Probing - > coba masukkin datanya ke index disebelahnya
    2. Chaining -> Push tail ( Cuma berlaku untuk linked list)
*/


/*
    Searching
    ===========


    1. Loop dari index array 1 - akhir, trus di setiap indexnya klo ada head
    di looping dari awal sampe akhir, tpi klo stringnya sama maka bru print

    cara yang lebih efisien 
    ========================
    1. generate index dari string yang diberikan untuk dicari, lalu tembak
    index tersebut didalam arranya, dan looping dari awal sampe akhir buat cari

*/

void searching(char nama[]){
    // generate index untuk ditembak
    int index = hashFunction(nama);

    if(head[index] != NULL){
        // tinggal looping dari data awal ampe akhir
        Mahasiswa* curr = head[index];
        while(curr){
            if(strcmp(curr->nama, nama) == 0){
                printf("Data ketemu di index ke %d", index);
                return;
            }
            curr = curr->next;
        }
        if(!curr){
            puts("Tidak ketemu");
        }  
    }
    else{
        puts("tidak ketemu");
    }
}

int main(){
    pushHashTable("ayam");
    pushHashTable("yama");
    pushHashTable("maya");
    popHashTable("yama");
    searching("yama");
    // harusnya ketiga diatas memiliki index yang sama karena total nilai asciinya
    // sama
    printAll();





    return 0;
}