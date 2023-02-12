package com.Testing;
import java.util.Scanner;

public class prob_G {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);                 // Membuat objek untuk input
        long totalRound = input.nextLong();                     // Menginput test case
        long totalPoint = input.nextLong(); input.nextLine();   // Menginput nilai awal
        long max_point = totalPoint;                            // Menginisialisasi nilai max dan min awal sama dengan nilai awal
        long min_point = totalPoint;
        for(int i = 0; i < totalRound; i++){
            char operator1 = '0';
            char operator2 = '0';
            long num1 = 0;
            long num2 = 0;
            operator1 = input.next().charAt(0);                 // Menginput operator 1
            num1 = input.nextLong();                            // Menginput nilai 1
            operator2 = input.next().charAt(0);                 // Menginput operator 2
            num2 = input.nextLong(); input.nextLine();          // Menginput nilai 2
            long max_round = max_point;
            long min_round = min_point;
            if(operator1 == '+') {                              // Jika operator 1 plus maka akan dijalankan operasi plus dan ditentukan nilai min&max
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
            }else{                                              // Jika operator 1 times maka akan dijalankan operasi times dan ditentukan nilai min&max
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
            if(operator2 == '+') {                              // Jika operator 2 plus maka akan dijalankan operasi plus dan ditentukan nilai min&max
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
            }else{                                              // Jika operator 2 times maka akan dijalankan operasi times dan ditentukan nilai min&max
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
            }                                                   // Setelah seleasi maka nilai min&max akan diperbarui untuk query selanjutnya
            min_point = min_round;
            max_point = max_round;
        }
        System.out.println(max_point);                          // Print nilai tertinggi dari seluruh query
    }
}
