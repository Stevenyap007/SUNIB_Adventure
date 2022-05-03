#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct customer{
	char nama[50];
    char classPrior[20];
    int prior;
	struct customer *prev, *next;
}*head=NULL, *tail=NULL;

void insertCusQueue(char nama[],char classPrior[],int prior)
{
	struct customer *newCustomer=(struct customer*)malloc(sizeof(struct customer));
	strcpy(newCustomer->nama, nama);
    strcpy(newCustomer->classPrior, classPrior);
	newCustomer->prior=prior;
	newCustomer->prev=newCustomer->next=NULL;
	struct customer *ptr=head;
	if(head==NULL)
	{
		head=tail=newCustomer;
	}
	else if(prior>tail->prior || prior==tail->prior)
	{
		tail->next=newCustomer;
		newCustomer->prev=tail;
		tail=newCustomer;
	}
	else
	{
		while(ptr->next!=NULL && ptr->next->prior<=prior)
		{
			if(ptr->next->prior==prior && strcmp(ptr->next->nama,nama)< 0)
				break;
			ptr=ptr->next;
		}
			
			
		newCustomer->prev=ptr;
		newCustomer->next=ptr->next;
		ptr->next->prev=newCustomer;
		ptr->next=newCustomer;
	}
	
}

void serveOne()
{
	struct customer *ptr=head;
	if(ptr!=NULL)
	{
        printf("Attention! Member [%s] is being served at %s table",ptr->nama,ptr->classPrior);
	}
	else
	{
		printf("Queue is empty\n");
		return;
	}
	
	if(head==tail)
	{
		free(ptr);
		head=tail=NULL;
	}
	else
	{
		head=head->next;
		head->prev=NULL;
		free(ptr);
	}
	
}

void serve_all(){
    customer *curr = head;

    while(curr != NULL){
        if(curr->prior == 1){
        printf("Attention! %s is being served at VVIP table.\n", curr->nama);
        }
        if(curr->prior == 2){
        printf("Attention! %s is being served at VIP table.\n", curr->nama);
        }
        if(curr->prior == 3){
        printf("Attention! %s is being served at Member table.\n", curr->nama);
        }
        if(curr->prior == 4){
        printf("Attention! %s is being served at Guest table.\n", curr->nama);
        }
        if(head == tail) {
            free(curr);
            head = tail = NULL;
        } else {
            head = head->next;
            head->prev = NULL;
            free(curr);
        }

        curr = curr->next;
    }

    if(curr == NULL){
        printf("Queue is empty\n");
        return;
    }
}
int main()
{
	int menu, age, prio;
	char nama[50], condition[20];
	do{
		system("cls");
        printf("================================\n");
		printf("SUNIB Restaurant reservation\n");
		printf("================================\n\n");
        printf("Waiting Line:")
		waitingLine();
		puts("");
		printf("1. Add Customer to Queue\n");
		printf("2. Serve one\n");
		printf("3. Serve All\n");
        printf("4. Dismiss Queue\n");
        printf("5. Exit\n");
		printf("Input menu number: ");
        scanf("%d",&menu); 
        getchar();
		switch(menu)
		{
			case 1:
				gets(condition);
                gets(nama);
				if(strcmp(condition, "VVIP")==0)
				{
					prio=1;
				}
				else if(strcmp(condition, "VIP")==0)
				{
					prio=2;
				}
				else if(strcmp(condition, "Member")==0)
				{
					prio=3;		
                   
				}else if(strcmp(condition, "Guest")==0)
				{
					prio=4;		
				insertCusQueue(nama,condition,prio);
				getchar();
				break;
			case 2:
				serveOne();
				getchar();
				break;
            case 3:
                ServeAll();
                getchar();
            case 4:
                DismissQueue();
		}
	}while(menu<=4 && menu>0);
	return 0;
}


