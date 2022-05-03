#include <stdio.h>
#include <stdlib.h>
int main (){

   long int d, s, t;
    scanf("%ld %ld %ld", &d, &s, &t);

    if(d > t && d > s && t > s){
        printf("Daging\n");
        printf("Telur\n");
        printf("Sayur\n");
    } else if(d > t && d > s && s > t){
        printf("Daging\n");
        printf("Sayur\n");
        printf("Telur\n");
    } else if(t > d && t > s && d > s){
        printf("Telur\n");
        printf("Daging\n");
        printf("Sayur\n");
    } else if(t > d && t > s && s > d){
        printf("Telur\n");
        printf("Sayur\n");
        printf("Daging\n");
    } else if(s > d && s > t && t > d){
        printf("Sayur\n");
        printf("Telur\n");
        printf("Daging\n");
    } else if(s > d && s > t && d > t){
        printf("Sayur\n");
        printf("Daging\n");
        printf("Telur\n");
    }


   
   
    





    return 0;
}