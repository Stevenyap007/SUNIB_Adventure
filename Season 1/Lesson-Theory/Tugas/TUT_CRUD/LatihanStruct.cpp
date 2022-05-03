#include <stdio.h>
#include <string.h>

int index = 0, x, idx;

struct library{
	char title[100], author[100];
	int year, id;
};

library book[100];

void create(){
	FILE *create;
	create = fopen("Library.txt", "r");
	
	if(create == NULL){
		create = fopen("Library.txt", "w");
	} else {
		while(!feof(create)){
			fscanf(create, "%d#%[^#]#%[^#]#%d\n", &book[index].id, book[index].title, book[index].author, &book[index].year);
			index++;
		}
	}
	
	fclose(create);
}

void write(){
	FILE *write;
	write = fopen("Library.txt", "w");
	
	for(int i = 0; i < index; i++){
		fprintf(write, "%d#%s#%s#%d\n", book[i].id, book[i].title, book[i].author, book[i].year);
	}
	
	fclose(write);
}

void mainmenu(){
	printf("1. Input book record\n");
	printf("2. Display book record\n");
	printf("3. Update book record\n");
	printf("4. Erase book record\n");
	printf("5. Save and Exit\n");
	printf("Input number [1..5] : ");
	scanf("%d", &x);
	while(x < 1 || x > 5){
		printf("Input number [1..5] : ");
		scanf("%d", &x);
	}
}

void input(){
	if(index < 100){
		printf("Book ID : ");
		scanf("%d", &book[index].id);
		printf("Book Title : ");
		scanf(" %[^\n]", book[index].title);
		printf("Book Author : ");
		scanf(" %[^\n]", book[index].author);
		printf("Year Publish : ");
		scanf("%d", &book[index].year);
		index++;
	} else {
		printf("It's already 100 books !");
	}
}

void merge(int l, int m, int r){
	int N1 = m - l + 1;
	int N2 = r - m;

	char tempTitleLeft[N1][100], tempTitleRight[N2][100], tempAuthorLeft[N1][100], tempAuthorRight[N2][100];
	int tempIdLeft[N1], tempIdRight[N2], tempYearLeft[N1], tempYearRight[N2];

	for(int i = 0; i < N1; i++){
		strcpy(tempTitleLeft[i], book[l + i].title);
		strcpy(tempAuthorLeft[i], book[l + i].author);
		tempIdLeft[i] = book[l + i].id;
		tempYearLeft[i] = book[l + i].year;
	}

	for(int j = 0; j < N2; j++){
		strcpy(tempTitleRight[j], book[m + 1 + j].title);
		strcpy(tempAuthorRight[j], book[m + 1 + j].author);
		tempIdRight[j] = book[m + 1 + j].id;
		tempYearRight[j] = book[m + 1 + j].year;
	}
	
	int i = 0;
	int j = 0;
	int k = l;
		
	while(i < N1 && j < N2){
		if(strcmp(tempTitleLeft[i], tempTitleRight[j]) < 0){
			strcpy(book[k].title, tempTitleLeft[i]);
			strcpy(book[k].author, tempAuthorLeft[i]);
			book[k].id = tempIdLeft[i];
			book[k].year = tempYearLeft[i];
			i++;
		} else {
			strcpy(book[k].title, tempTitleRight[j]);
			strcpy(book[k].author, tempAuthorRight[j]);
			book[k].id = tempIdRight[j];
			book[k].year = tempYearRight[j];
			j++;
		}
		k++;
	}
		
	while(i < N1){
		strcpy(book[k].title, tempTitleLeft[i]);
		strcpy(book[k].author, tempAuthorLeft[i]);
		book[k].id = tempIdLeft[i];
		book[k].year = tempYearLeft[i];
		i++;
		k++;
	}
	
	while(j < N2){
		strcpy(book[k].title, tempTitleRight[j]);
		strcpy(book[k].author, tempAuthorRight[j]);
		book[k].id = tempIdRight[j];
		book[k].year = tempYearRight[j];
		j++;
		k++;
	}
}

void mergesort(int l, int r){
	if(l < r){
		int m = l + (r - l) / 2;
		mergesort(l, m);
		mergesort(m + 1, r);
		
		merge(l, m, r);
	}
}

void printmenu(){
	printf("============================================================\n");
	for(int i = 0; i < index; i++){
		printf("%-5d- %-20s- %-20s- %-5d\n", book[i].id, book[i].title, book[i].author, book[i].year);
	}
	printf("============================================================\n");
}

void update(){
	printf("Input Book Id : ");
	scanf("%d", &idx);
	for(int i = 0; i < index; i++){
		if(idx == book[i].id){
			printf("New Book ID : ");
			scanf("%d", &book[i].id);
			printf("Book Title : ");
			scanf(" %[^\n]", book[i].title);
			printf("Book Author : ");
			scanf(" %[^\n]", book[i].author);
			printf("Year Publish : ");
			scanf("%d", &book[i].year);
		}
	}
}

void erase(){
	printf("Input Book Id : ");
	scanf("%d", &idx);
	for(int i = 0; i < index; i++){
		if(idx == book[i].id){
			for(int j = i; j < index - 1; j++){
				book[j].id = book[j + 1].id;
				strcpy(book[j].title, book[j + 1].title);
				strcpy(book[j].author, book[j + 1].author);
				book[j].year = book[j + 1].year;
			}
			index--;
		}
	}
}

int main(){
	
	create();	
	while(x >= 1 || x <= 5){
		mainmenu();
		if(x == 1){
			printf("\n");
			input();
			getchar(); getchar();
			write();
		}
		
		else if(x == 2){
			printf("\n");
			mergesort(0, index - 1);
			printmenu();
			getchar(); getchar();
		}
		
		else if(x == 3){
			printf("\n");
			printmenu();
			update();
			getchar(); getchar();
			write();
		}
		
		else if(x == 4){
			printf("\n");
			erase();
			printmenu();
			getchar(); getchar();
		}
		
		else if(x == 5){
			printf("Thank you, bye !");
			getchar(); getchar();
			write();
			break;
		}
	}
	
	return 0;
}
