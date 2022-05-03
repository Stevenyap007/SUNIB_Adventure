#include <stdio.h>
#include <string.h>

struct Huruf{
    char huruf[1000];
};

Huruf kata[205];

int main(){

    int baris, word;
    scanf("%d %d", &baris, &word);

    for(int i = 0; i < baris; i++){
        scanf("%s", kata[i].huruf);
    }

    for(int i = 0; i < baris; i++){
        for(int j = 0; j < word; j++){
            for(int k = 0; k < word - j - 1; k++){
                if(kata[i].huruf[k] > kata[i].huruf[k + 1]){
                    char temp = kata[i].huruf[k];
                    kata[i].huruf[k] = kata[i].huruf[k + 1];
                    kata[i].huruf[k + 1] = temp;
                }
            }
        }
    }

    for(int i = 0; i < baris ; i++){
        for(int j = 0; j < baris - i - 1; j++){
            if(strcmp(kata[j].huruf, kata[j + 1].huruf) < 0){
                Huruf temp = kata[j];
                kata[j] = kata[j + 1];
                kata[j + 1] = temp;
            }
        }
    }

    for(int i = 0; i < baris; i++){
        printf("%s\n", kata[i].huruf);
    }

    return 0;
}