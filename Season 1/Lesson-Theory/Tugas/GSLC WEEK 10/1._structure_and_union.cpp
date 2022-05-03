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









    return 0;
}