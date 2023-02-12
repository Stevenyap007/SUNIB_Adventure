#include <stdio.h>
#include <math.h>

bool check( int num){
    if( num <= 1){
        return false;
    }
    for( int i = 2; i <= sqrt(num); i++){
        if( num % i == 0){
            return false;
        }
    }
    return true;
}
int main(){
    int tc;
    
    scanf("%d", &tc); getchar();
    
    for( int k = 1; k <= tc; k++){
        int N;
    
        scanf("%d", &N);  getchar();
        
        int count = 0;
            
        if( check(N) == false){
            printf("-1\n");
        }else{
            for( int i=2, k=2; i<=N, k<=N; i++, k++){
                int flag = 1;
                
                for( int j=2; j<=sqrt(i); j++){
                    if( i%j == 0){
                        flag = -1;
                        break;
                    }
                }
                if( flag == 1){
                    count++;    
                }    
            }
        }
            if( count != 0){
                printf("%d\n", count);
            }        
        }
    return 0;
}