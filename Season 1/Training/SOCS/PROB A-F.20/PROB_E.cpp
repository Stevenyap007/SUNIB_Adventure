#include <stdio.h>
#include <string.h>

struct mahasiswa{
    char nama[20];
    int nilai;
};

void Swap( mahasiswa *a, mahasiswa *b){
    mahasiswa temp = *a;
    *a = *b;
    *b = temp;
}
int main(){
    int T;
    scanf("%d", &T);
    
    for( int i = 0; i < T; i++){
        int N;
        scanf("%d", &N);
        mahasiswa data[N];
        
        for(int j = 0; j < N; j++){
            scanf(" %[^#]#%d", &data[j].nama, &data[j].nilai);
        }

        for( int k = 0; k < N; k++){
            for ( int l = 0; l < N - k - 1; l++){
                if(data[l].nilai < data[l+1].nilai){
                    Swap(&data[l], &data[l+1]);
                }else if(data[l].nilai == data[l+1].nilai){
                    if(strcmp(data[l].nama, data[l+1].nama) > 0){
                        Swap( &data[l], &data[l+1]);
                    }
                }
            }
        }
        
        char target[20];
        scanf(" %s", &target);
        for( int m = 0; m < N; m++){
            if(strcmp(target, data[m].nama) == 0){
                printf("Case #%d: %d\n", i+1, m+1);
                break;
            }
        }
    }
    return 0;
}