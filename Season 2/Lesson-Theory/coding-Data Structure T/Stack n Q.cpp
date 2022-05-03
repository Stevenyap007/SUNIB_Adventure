/*//Array of Stack
#include <stdio.h>
#include <stdlib.h>
#define max 5

int top=-1;		//inisialisasi top posisinya diluar stack
int stack[max];	//pembuatan variable stack seukuran maximum

int isFull(){
	return (top==max-1) ? 1:0;
}

int isEmpty(){
	return (top==-1) ? 1:0;
}

void push(){
	int number;
	if(!isFull()){		//tampung data baru, geser posisi top, assign nilai ke stack		
		printf("Insert number: ");
		scanf("%d",&number);
		top++;
		stack[top]=number;
	}else{
		printf("Stack is Full..\n");
	}
}

void pop(){
	if (!isEmpty){
		top--;
	}else{
		printf("Stack is Empty..");
	}
}

void display(){
	int i;
	for (i=top;i>=0;i--){
		printf("%d\n",stack[i]);
	}
}

int main (){
	int choice;
	do{
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Display\n");
		printf("4. Exit\n");
		printf("Choose 1 menu: ");
		scanf("%d", &choice);getchar();
		
		switch (choice){
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("Choose the correct menu!\n");
		}
		
	}while (choice != 4);
	
	return 0;
}*/

//Array of Queue
#include <stdio.h>
#include <stdlib.h>
#define max 5

int head=-1, tail=-1;
int queue[max];

int isFull(){
	return(tail==max-1) ? 1:0;
}

int isEmpty(){
	return (tail==-1) ? 1:0;
}

void push(){
	int number;
	if (!isFull()){
		printf("Insert the Number: ");
		scanf("%d",&number);
		tail++;
		queue[tail]=number;
		if (head==-1) head=0;
	}else{
		printf("Queue is Full..\n");
	}
	
}

void pop(){
	if (!isEmpty()){
		if (head==tail){
			head=tail=-1;
		}else{
			head++;
		}
	}else{
		printf("Queue is Empty..\n");
	}
	
}

void display(){
	int i;
	if (head==-1){
		printf("Queue is Empty..\n");
	}else{
		for(i=head;i<=tail;i++){
			printf("%d ",queue[i]);
		}
		printf("Current Head: %d, Current Tail: %d \n\n",queue[head],queue[tail]);
	}
}

int main (){
	int choice;
	do{
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Display\n");
		printf("4. Exit\n");
		printf("Choose 1 menu: ");
		scanf("%d", &choice);getchar();
		
		switch (choice){
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("Choose the correct menu!\n");
		}
		
	}while (choice != 4);
	
	return 0;
}








