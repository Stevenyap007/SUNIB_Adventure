#include <stdio.h>
#include <string.h>

int main() {

    int T;
    char kata[1000];

    scanf("%d", &T);
    
    for (int i = 0; i < T; i++)
    {
        scanf("%s", &kata);

        int pk = strlen(kata);

        for (int j = 0; j < pk; j++)
        {
            if (kata[j] >= 'a' && kata[j] <= 'z'){
				kata[j] -= 32;
			} else if (kata[j] >= 'A' && kata[j] <= 'Z'){
				kata[j] += 32;
			}
        }

        printf("Case #%d: ",i+1);

        for(int k = 0 ; k < pk ; k++){
            printf("%c",kata[pk - 1 - k]);
        }
        printf("\n");
        
        
    }
    







    return 0;
}