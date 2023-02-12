#include <stdio.h>

int main() {
    long totalRound, totalPoint, max_point, min_point;
    char operator1, operator2;
    long num1, num2;

    scanf("%ld %ld", &totalRound, &totalPoint);

    max_point = totalPoint;
    min_point = totalPoint;

    for(int i = 0; i < totalRound; i++){
        scanf(" %c %ld %c %ld", &operator1, &num1, &operator2, &num2);

        long max_round = max_point;
        long min_round = min_point;

        if(operator1 == '+') {
            long temp = max_point + num1;
            max_round = temp;
            min_round = temp;

            long temp2 = min_point + num1;
            if(temp2 > max_round){
                max_point = temp2;
            }
            if(temp2 < min_round) {
                min_round = temp2;
            }
        } else {
            long temp = max_point * num1;
            max_round = temp;
            min_round = temp;

            long temp2 = min_point * num1;
            if(temp2 > max_round) {
                max_round = temp2;
            }
            if(temp2 < min_round) {
                min_round = temp2;
            }
        }

        if(operator2 == '+') {
            long temp = max_point + num2;
            if(temp > max_round){
                max_round = temp;
            }
            if(temp < min_round){
                min_round = temp;
            }
            long temp2 = min_point + num2;
            if(temp2 > max_round){
                max_round = temp2;
            }
            if(temp2 < min_round){
                min_round = temp2;
            }
        } else {
            long temp = max_point * num2;
            if(temp > max_round){
                max_round = temp;
            }
            if(temp < min_round){
                min_round = temp;
            }
            long temp2 = min_point * num2;
            if(temp2 > max_round){
                max_round = temp2;
            }
            if(temp2 < min_round){
                min_round = temp2;
            }
        }
        min_point = min_round;
        max_point = max_round;
    }
    printf("%ld", max_point);
    return 0;
}
