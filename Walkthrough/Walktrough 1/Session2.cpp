#include <stdio.h>
#include <string.h> // --> strlen() buat itung panjang kalimat
                    //  strcmp() biasa dipakai buat if else --> return int --> return 0
#include <math.h> 


int main(){
    
    //operator matematiika
    // - + * /
    
    
    // ctrl + shift + arr up/down
    // pindahin line keatas atau bawah
    
    //    ctrl + e
    //    buat copy line kebawah
    
    
/////////////////////////////////////////////////////////////////////////////   
//    int angka2=3;
/*
    int angka1=2, angka2=4;
    int  tambah1= angka1+angka2;
    
    printf("tambah: %d\n", tambah1);
    printf("kurang: %d\n", angka2-angka1);
    printf("kali: %d\n", angka1*angka2);
    printf("bagi: %d\n", angka1/angka2);
    //modulo adalah sisa hasil bagi 5/2-->2
    printf("%d\n", 5%3);
    // cari tau angka ini angka ganjil atau genap
    int angka3 = 11;
    printf("modulo: %d\n", angka2%angka1);
*/  

///////////////////////////////////////////////////////////////////////////// 
  
/*    
	// assigment operator
    // =, +=, -=, *=, /=
 
    int angka1=1;
    angka1+=2; // --> angka1 = angka1+2
    //angka1 = 3  
    
    
    angka1 -=2;
    printf("%d\n", angka1);
    angka1 *= 2;
    printf("%d\n", angka1);
    angka1 /= 3;
    printf("%d\n", angka1);
*/    
    //relational operator
    //    ==, <, >, <=, >=, !=
    // = --> buat assign value ke variable 
    // == --> buat membandingkan value
    
//    if(kondisi){
//        statement jika hasil 'true'
//    } else {
//    statement jika hasil 'false'
// }
/*   
///////////////////////////////////////////////////////////////////////////// 

    int angka1=3;
    
    if(angka1%2==1){
        printf("GANJIL");
    } else {
        printf("GENAP");
    }
*/   

/*
    int angka1=4;
    
    if(angka1>10){
        printf("LEBIH BESAR ATAU SAMA DENGAN 10\n");
    } else {
        printf("LEBIH KECIL ATAU SAMA DENGAN 10\n");
    }
    
    
    if(angka1 != 10){
        printf("TIDAK SAMA\n");
    } else {
        printf("SAMA\n");
    }  
    // ternary operator
    // variable = expression1 ? expression2 : expression3
    angka1 !=10 ? printf("tidak sama\n") : printf("sama\n");
*/    
    
/////////////////////////////////////////////////////////////////////////////   
//pointer
/*
    int angka1=3;
    printf("%d\n", &angka1);
    int *ptr= &angka1;
    printf("%d\n", ptr);
    *ptr=4;
    printf("%d\n", angka1);
*/   

///////////////////////////////////////////////////////////////////////////// 
    // bitwise operator
    // &, /, <<, >>, ^
    // XOR -- > salah satu harus beda --> benar , bener & bener --> salah
    //OR salah 1 benar --> bener, benar & benar --> benar
/* 
    2 = 00000010
    4 = 00000100
    ------------- &
        00000000
        
    2 = 00000010
    4 = 00000100
    ------------- |
        00000110 = 6

    2<<2
    
    2 = 00000010
      = 00001000
    
    
    10000000<<1
    00000000
    
    2 = 00000010
    4 = 00000100
    ------------- ^ --> XOR --> exclusive or, 
*/                        
/*       
    
    printf("and: %d\n", 4&2);
    printf("or: %d\n", 4|2);
    printf("left shift: %d\n",2<<2);
    printf("right shift: %d\n",2>>2);
    printf("XOR: %d\n", 4^2);
*/   

/////////////////////////////////////////////////////////////////////////////

/*  
    char kalimat1[20]="hello world";
    printf("%s", kalimat1);
    
    scanf("%[^\n]", kalimat1); // ambil kalimat sampai ada enter
    scanf("%[^1]", &kalimat1); //ambil kalimat sampai ada angka 1
*/    
    //yang tidak bole 
    // strrev() buat balik kalimat
    // pow() buat pangkat
        
    return 0;
}
