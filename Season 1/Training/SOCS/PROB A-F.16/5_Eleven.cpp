#include <stdio.h>

int main(){
int T;
scanf("%d", &T);
char num[100001];

for(int i=0; i<T; i++){
scanf("%s",&num);
long long int ganjil_Sum = 0,Genap_Sum = 0;
    for(int j = 0; num[j] !='\0'; j++){
        if(j%2 == 0){
            ganjil_Sum = ganjil_Sum + (num[j] - '0');
        }else{
            Genap_Sum = Genap_Sum + (num[j] - '0');
        }
    num[j] = 0;
    }


    if( (ganjil_Sum-Genap_Sum) % 11 == 0 ){
        printf("Case #%d: Yeah\n",i+1);
    }else{
        printf("Case #%d: Nah\n",i+1);
    }
}




return 0;
}