#include <stdio.h>
#include <string.h>

int amount[100] = {0};
int lastIndex = 0;
 
int BC = 0;
int MC = 0;
int PC = 0;
int BT = 0;
int CP = 0;
int CC = 0;


void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void upHeap(int index)
{
	if( index==1 )
	{
		return;
	}
	
	int parent = index/2;
	
	if( amount[parent]<amount[index] )
	{
		swap(&amount[parent], &amount[index]);
		upHeap(parent);
	}
}

void insert(int value)
{
	lastIndex++;
	amount[lastIndex] = value;
	upHeap(lastIndex);
}

void printAll()
{
    printf("Top Sales:\n");
    
    char drink_Name[25];
    
    for( int i=1 ; i<=2 ; i++ )
	{
        if( amount[i]==BC )
		{
            strcpy(drink_Name, "Boba Coffee");
        }
        else if( amount[i]==MC )
		{
            strcpy(drink_Name, "Moccapucino");
        }
        else if( amount[i]==PC )
		{
            strcpy(drink_Name, "Pandan Coffee");
        }
        else if( amount[i]==BT )
		{
            strcpy(drink_Name, "Boba Thai");
        }
        else if( amount[i]==CP )
		{
            strcpy(drink_Name, "Choco Pandan");
        }
        else if( amount[i]==CC )
		{
            strcpy(drink_Name, "Cheese Choco");
        }
        
        printf("%d. %s %d\n", i, drink_Name, amount[i]);
    }
}

int main()
{
    int T;
    int N;
    char drink_Code[4];
    
    do
    {
       scanf("%d", &T);
    } while (T<1 || T>100);
    
    for( int i=0 ; i<T ; i++ )
	{
        scanf("%d %s", &N, drink_Code);
        
        if( strcmp(drink_Code, "BC")==0 )
		{
            BC += N;
        }
        else if( strcmp(drink_Code, "MC")==0 )
		{
            MC += N;        
        }
        else if( strcmp(drink_Code, "PC")==0 )
		{
            PC += N;          
        }
        else if( strcmp(drink_Code, "BT")==0 )
		{
            BT += N;           
        }      
        else if( strcmp(drink_Code, "CP")==0 )
		{
            CP += N;            
        }      
        else if( strcmp(drink_Code, "CC")==0 )
		{
            CC += N;          
        }
    }
    
    insert(BC);
    insert(MC);
    insert(PC);
    insert(BT);
    insert(CP);
    insert(CC);
    
    printAll();
    
    return 0;
}