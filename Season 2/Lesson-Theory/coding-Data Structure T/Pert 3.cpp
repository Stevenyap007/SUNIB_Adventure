//single Linked list
#include<stdio.h>
#include<stdlib.h>

struct node{
	int number;
	struct node *next;
}*head=NULL, *tail=NULL;

void pushHead(int a){
	struct node *newNode;
	newNode=(struct node *)malloc(sizeof(struct node));
	newNode->number=a;
	newNode->next=NULL;
	
	if (head==NULL){
		head=tail=newNode;
	}else{
		newNode->next=head;
		head=newNode;
	}
}

void pushTail(int a){
	struct node *newNode;
	newNode=(struct node*)malloc(sizeof(struct node));
	newNode->number=a;
	newNode->next=NULL;
	if (head==NULL){
		head=tail=newNode;
	}else{
		tail->next=newNode;
		tail=newNode;
	}
}

void pushMid(int a,int b){		//"a" adalah angka yang mau ditambahkan, "b" adalah angka penanda kalau node baru akan ditambahan seletah angka tersebut
	struct node *newNode, *ptr=head;
	newNode=(struct node *)malloc (sizeof(struct node));
	newNode->number=a;
	newNode->next=NULL;
	if (head==NULL){
		head=tail=newNode;
	}else{
		while (ptr != NULL && ptr->number != b){
			ptr=ptr->next;
		}if(ptr==NULL){
			printf("Node not Found..\n");
		}else if(ptr==tail){
			pushTail(a);
		}else{
			newNode->next=ptr->next;
			ptr->next=newNode;
		}
	}
}

void popHead(){
	struct node *ptr=head;
	if(head==tail){
		free(ptr);
		head=tail=NULL;
	}else{
		head=head->next;
		free(ptr);
	}
}

void popTail(){
	struct node *ptr=head;
	if (head==tail){
		free(ptr);
		head=tail=NULL;
	}else{
		while (ptr->next != tail){
			ptr=ptr->next;
		}ptr->next=NULL;
		free(tail);
		tail=ptr;
	}
}

void popNode(int a){
	struct node *ptr=head, *prePtr=head;
	while (ptr != NULL && ptr->number != a){
		prePtr=ptr;
		ptr=ptr->next;
	}if (ptr==NULL){
		printf("Number not Found..\n");
	}else if (ptr==head){
		popHead();
	}else if (ptr==tail){
		popTail();
	}else{
		prePtr->next=ptr->next;
		free(ptr);
	}

}

void display(){
	struct node *ptr=head;
	if (head==NULL){
		printf("Linked list is Empyt..\n");
	}else{
		while(ptr != NULL){
			printf("%d -> ",ptr->number);
			ptr=ptr->next;
		}printf("NULL\n");
	}
}

int main(){
	pushHead(30);
	pushHead(40);
	pushHead(50);
	pushHead(60);
	display();
	
	pushTail(20);
	pushTail(10);
	display();
	
	pushMid(30,40);
	display();

	popHead();
	display();
	
	popTail();
	display();
	
	popNode(30);
	display();
	
	return 0;
}
