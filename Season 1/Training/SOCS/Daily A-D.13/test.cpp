#include <stdio.h>
  
int main()
{
    int i;
  
    // Lets say we have 3 words
    int n = 2;
  
    // Declaration of 2-D char array
    char array[n][20];
  
    // Initialization of 2-D char array
    for (i = 0; i < 2; i++)
        scanf("%s", array[i]);
  
    // print the words
    for (i = 0; i < 2; i++)
        printf("%s\n", array[i]);
  
    return 0;
}

/*
COMP6047
COMP6056
*/
