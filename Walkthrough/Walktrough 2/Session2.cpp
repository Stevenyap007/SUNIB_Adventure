#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Mahasiswa
{
    char nim[20];
    char nama[255];
    int umur;
    Mahasiswa *next;
}*head = NULL,*tail  = NULL;

//bikin head, tail
// Mahasiswa* head = NULL;
// Mahasiswa* tail = NULL;

// bikin mwthod untuk masukin struct ke dalam nodenya
Mahasiswa* newMahasiswa(const char* nim,const char* nama, int umur){
    Mahasiswa* temp = (Mahasiswa*)malloc(sizeof(Mahasiswa));
    // kasi nilai yang di parameter kedalam si tempnya, dimana nanti
    // si temp akan dimasukkan ke dalam linked list
    strcpy(temp->nim, nim);
    strcpy(temp->nama, nama);
    temp->umur= umur;
    temp->next= NULL;


    return temp;
}

void pushHead(const char* nim,const char* nama, int umur){
    // bikin node barunya
    Mahasiswa  *newNode= newMahasiswa(nim,nama,umur);
    
    // validasi kalau linkedListnya kosong
    // kalau linked list kosng maka node yang dimasukkan
    // bakalan jadi head sama tail seklaigus
    if(head == NULL){
        head = tail = newNode;
    }
    else{
        //kalau misalnya sudah ada 
        // step1 kita kasi kalau sebelahnya si newNOde adalah si head
        newNode->next = head;
        // lalu pindahin si headnya
        head = newNode;
    }
}

void pushTail(const char* nim, const char* nama,int umur){
    Mahasiswa* newNode = newMahasiswa(nim,nama,umur);
    // validasi 1 data
    if (head == NULL){
        head = tail = newNode;
    }else{
        tail->next = newNode;
        tail = newNode;
    }
}

void pushMid(const char* nim, const char* nama,int umur){
    Mahasiswa* newNode = newMahasiswa(nim,nama,umur);
    if (!head){
        head = tail = newNode;
    }else if(head->umur > umur){
        pushHead(nim,nama,umur);
    }else if(tail->umur < umur){
        pushTail(nim,nama,umur);
    }else{
        Mahasiswa* curr = head;
        while (curr->next->umur < umur){
            curr = curr->next;
            newNode->next = curr->next;
            curr->next = newNode;
        }
    }
}

void popHead(){
    // validasi misal linekd list harus tidak kosng
    if(head != NULL){

        // calidasi klo misalnya cuma ada 1 node
        if (head==tail){
            free(head);
            head = tail = NULL;
        }else{
            //klo misalnya ada lebih dari 1 node
            Mahasiswa* temp = head;
            // pindahin head ke sebelumnya
            head = head->next;
            free(temp);
            temp = NULL;
        }
    }
}

void popTail(){
    // validasi misal linekd list harus tidak kosng
    if(head){

        // calidasi klo misalnya cuma ada 1 node
        if (head==tail){
            free(head);
            head = tail = NULL;
        }else{
            //klo misalnya ada lebih dari 1 node
            Mahasiswa* current = head;
            // pindahin head ke sebelumnya
            while (current->next != tail){
                current=current->next;
            }
            tail = current;

            free(tail->next);
            tail->next = NULL;
        }
    }
}

void searchPop(const char* nim,int umur){
    if(head){
        if(head->umur == umur && strcmp(head->nim,nim)==0){
            popHead();
        }
        else if(tail->umur == umur && strcmp(tail->nim,nim)==0){
            popTail();
        }else{
            Mahasiswa* curr = head;
            while(curr){
                if(curr->next->umur == 0 && strcmp(curr->next->nim,nim)==0){
                    break;
                }
                curr= curr->next;
            }

            // validasi misalnya gak ketemu

            if(!curr->next){
                puts("tidak ketemu");
                return;
            }

            Mahasiswa* temp = curr->next->next;
            free(curr->next);
            curr->next = NULL;
            curr->next = temp;
        }
    }
}


void printAll(){
    // bikin semacam clonenya
    Mahasiswa* clone = head;
    // tinggal looping dari head -> tail
    while (clone != NULL)
    {
        printf("%s %s %d\n",clone->nim,clone->nama,clone->umur);
        clone = clone->next;
    }
    
}
int main (){

    pushHead("2540125371", "edi",21);
    pushHead("2540125371", "rudi",21);
    pushHead("2540125371", "adi",21);
    pushHead("2540125371", "mili",21);
    pushHead("2540125371", "Johanes",21);
    popHead();
    printAll();




    return 0;
}