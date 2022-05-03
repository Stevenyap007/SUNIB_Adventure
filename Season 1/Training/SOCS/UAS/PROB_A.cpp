#include<stdio.h>
#include<string.h>

//membuat function untuk menukar character menjadi integer
int swap (char a){
    if (a>='A'&&a<='Z'){
        return a-'A'+1;
    }else if (a>='a'&&a<='z'){
    return a-'a'+1;
    }

    return 0;
}

int main(){
    int jam,mm;
    char kata[100005],menit[4];
    scanf("%d:%[^>]>%[^\n]",&jam,menit,kata);
    //mengscan input dari user
    int j=0,A=0,B=0,x=menit[0]-48,y=menit[1]-48;
    for (int i=0;i<strlen(kata);i++){
        if (kata[i]==' '){
            j++;
        }
        if (j==x){
            A+=swap(kata[i]);
        }
        if (j==y){
            A+=swap(kata[i]);
        }
    }
    
    if(A>180){
        A = A%180;
    }else{
        A = A;
    }
    
    int total=(x*10)+y+(jam*60);    
    if (total>720) A*=-1;
    
    scanf("%d:%[^>]>%[^\n]",&jam,menit,kata);
    j=0;x=menit[0]-48;y=menit[1]-48;
    for (int i=0;i<strlen(kata);i++){
        if (kata[i]==' '){
            j++;
        }
        if (j==x){
            B+=swap(kata[i]);
        }
        if (j==y){
            B+=swap(kata[i]);
        }
    }

    if(B>180){
        B = B%180;
    }else{
        B = B;
    }


    int total1=(x*10)+y+(jam*60);
    if (total1>720){
        B*=-1;
    } 
    
    printf("Case #1: %d,%d\n",A,B);
    return 0;
}
