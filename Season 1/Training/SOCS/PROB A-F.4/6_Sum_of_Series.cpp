#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (){
    long int A, B, C, hasil=0;

    scanf("%ld %ld", &A, &B);

    for(C= A; C <= B; C++){
        hasil += C;
    }
   
    printf("%ld\n", hasil);


    return 0;
}