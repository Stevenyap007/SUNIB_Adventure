#include <stdio.h>

struct Address {
    char street_name[40];
    int number;
    char city[20];
    char province[20];
};

struct Dob{
    int date, month, year;
};

struct Student{
    int student_number;
    char name[20];
    struct Address addr;
    char place[20];
    struct Dob dateofbirth;
};


int main (){

    struct Student daftar[5];
    

    for (int i = 0; i < 1; i++)
    {
        printf("insert student number : \n");
        scanf("%d",&daftar[i].student_number);
        printf("insert student name : \n");
        scanf("%s",&daftar[i].name);
        printf("Insert student address(street name, number, city, province) : \n");
        scanf("%s %d %s %s",&daftar[i].addr.street_name,&daftar[i].addr.number,&daftar[i].addr.city,&daftar[i].addr.province);
        getchar();
        printf("Insert student place : \n");
        scanf("%s",&daftar[i].place);
        printf("Insert Student date of birth(date, month, and year) : \n");
        scanf("%d %d %d",&daftar[i].dateofbirth.date,&daftar[i].dateofbirth.month,&daftar[i].dateofbirth.year);
    }

    // optional
    // for (int j = 0; j < 5; j++)
    // {
    //     printf("%d\n",daftar[j].student_number);
    //     printf("%s\n",daftar[j].name);
    //     printf("%s %d %s %s\n",daftar[j].addr.street_name,daftar[j].addr.number,daftar[j].addr.city,daftar[j].addr.province);
    //     printf("%s\n",daftar[j].place);
    //     printf("%d %d %d\n",daftar[j].dateofbirth.date,daftar[j].dateofbirth.month,daftar[j].dateofbirth.year);
    
    // }
    
       
    
    




    return 0;
}