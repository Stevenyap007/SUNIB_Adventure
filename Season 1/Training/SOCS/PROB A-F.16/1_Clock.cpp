#include <stdio.h>
#include <string.h>

int main(){

    int T;
    
    
    scanf("%d",&T);

    for (int i = 0; i < T; i++)
    {
        int jam;
        char menit[T][3];
        char waktu[T][3];
        scanf("%d:%s %s",&jam,&menit,&waktu[i]);
        
        printf("Case #%d: ",i+1);

        for (int j = 0; j < T; j++)
        {
            if(strcmp(waktu[i], "am") == 0){
                if(jam == 12){
                    jam = 0;
                    printf("%d0:%s\n", jam, menit);
                    break;
                } else if(jam < 10){
                    printf("0%d:%s\n", jam, menit);
                    break;
                } else{
                    printf("%d:%s\n", jam, menit);
                    break;
                }
            } else{
                if(jam == 12){
                    jam = 12;
                    printf("%d:%s\n", jam, menit);
                    break;
                } else{
                    jam += 12;
                    printf("%d:%s\n", jam, menit);
                    break;
                }
            }
        }
    }
            
        
    


    return 0;
}