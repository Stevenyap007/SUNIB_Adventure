#include <stdio.h>
#include <stdlib.h>

struct node{
	int number;
	struct node *next;
	struct node *prev;
}*head=NULL, *tail=NULL;

void pushHead(int a){
	struct node *newNode;
	newNode=(struct node *)malloc (sizeof(struct node));
	newNode->number=a;
	newNode->next=NULL;
	newNode->prev=NULL;
	
	if (head == NULL){
		head=tail=newNode;
	}else{
		newNode->next=head;
		head->prev=newNode;
		head=newNode;
	}
}

void pushTail(int a){
	struct node *newNode;
	newNode=(struct node *)malloc (sizeof(struct node));
	newNode->number=a;
	newNode->next=NULL;
	newNode->prev=NULL;
	
	if (head == NULL){
		head=tail=newNode;
	}else{
		tail->next=newNode;
		newNode->prev=tail;
		tail=newNode;
	}
}

void popHead(){
	struct node *ptr=head;
	if(head==tail){
		free(ptr);
		head=tail=NULL;
	}else{
		head=head->next;
		head->prev=NULL;
		free (ptr);
	}
}

void popTail(){
	struct node *ptr=tail;
	if(head==tail){
		free(ptr);
		head=tail=NULL;
	}else{
		tail=tail->prev;
		tail->next=NULL;
		free (ptr);
	}	
}

void display(){
	struct node *ptr=head;
	if (head==NULL){
		printf("Linked list is Empty..\n");
	}else{
		printf("NULL ->");
		while (ptr != NULL){
			printf("%d ->",ptr->number);
			ptr=ptr->next;
		}printf("NULL\n");
	}
}

int main (){
	pushHead(30);
	pushHead(40);
	display();
	
	pushTail(20);
	pushTail(10);
	display();
	
	popHead();
	display();
	
	popTail();
	display();
	
	return 0;
}
