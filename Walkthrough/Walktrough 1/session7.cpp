#include <stdio.h>
#include <string.h>

int num = 0;
int arr[100000000];

//Create a program using function with parameter called by value & by reference
//Local variable and global variable
//Creating a program using built-in function
//Create a program using recursive concept

// Function : suatu kumpulan prosedur yang bisa dipakai berulang-ulang
// return_type nama_function(paramter) {
	// isi : functionnya ngapain
	// return var
// }

// void : menandakan dia tidak mereturn apapun
// prototype function : define function
void scanAndPrint ();


// Create a program using function with paramater called by value & by reference
// call by value  : menggunakan copy dari variable yang kuta gunakan
// ganti dalam function nilainya : nilai variable aslinya gaakan berubah
// function yg ada parameter
// a + b
int sum (int a,int b,int c){
	num ++;
	c = 5;
	return a + b ;
}
// call by reference : menggunakan variablenya sendiri
// ganti nilai dalam function : nilainta berubah
int sumByRef(int *a,int *b,int *c){
	num++;
	*c = 5;
	return *a + *b ;
}

// ngebedaian berdasarkan parameternya

// tiap function punya scope sendiri
// scope : ruang lingkup suatu variable

// Local variable dan global variable
// tipa function punya scope sendiri : local scope (cuma dalam function) = batasan memorinya lebih kecil
// dibandingkan global scope
// variable yang bisa di detect oleh semua functian : global scope


//Create a program using recursive concept
// recursive function : function yang bisa memanggil diri sendiri
// loop selama n kali
// loop (5) -> loop (4) -> ... _> Loop(0)
int loop(int n){
	
	printf("%d\n",n);
	// kondisi stop : best case
	if(n == 0){
		return 0;
	}
	// memanggil diri sendiri
	return loop(n-1);
}

// dunction factorial
// 5!
// 1 * 2 * 3 * 4 * 5

// 5 * factorial(4)
// 5 * 4 * factorial(3)
// 5 * 4 * 3 * factorial(2)
// 5 * 4 * 3 * 2 * factorial(1)
// 5 * 4 * 3 * 2 * 1 
int factorial (int n){
	// kalau terpenuhi -> return _> bawahnya gak akan jaln
	if ( n == 1 || n == 0 ){
		return 1;
	}
	return(n * factorial(n-1));
}

// deret fibonacci
// 0 1 1 2 3 5 8
// 0 1 2 3 4 5 6

int fibonacci (int n){
	if ( n == 1 || n == 0 ){
		return n;
	}
	return fibonacci(n-2) + fibonacci (n-1);
}

// memoixation : teknik mencatat hasil yang udah dihasilkan
long long int arrFib[100]= {0};

long long int fibonacciMemoized(int n){
	if ( n == 1 || n == 0 ){
		return n;
	}
	// artinya data belum digenerate
	if(arrFib[n] == 0){
		arrFib[n] = fibonacciMemoized(n-2) + fibonacciMemoized(n-1);
	}

	return arrFib[n];
}


// main function
int main(){
//	scanAndPrint();
//	scanAndPrint();
//	scanAndPrint();
int a = 10;
int b = 12;
int c = 0;
// printf("hasil tambah by value : %d", sum(a,b,c));
// printf("nilai a : %d\n",c);
// printf("hasi; tambah by reference : %d\n", sumByRef(&a,&b,&c));
// printf("nilai a : %d\n",c);
// printf("num : %d",num);
// test case yang gede banget, tampung di array


//Creating a program using built-in function
//function yang udah di define
// printf()
// scanf()
// strlen()
// loop(5);
// looping while tanpa kondisi stop

// printf("hasil faktorial : %d\n",factorial(5));
printf("hasil fibonacci : %lld\n",fibonacciMemoized(6));










	return 0;
}

void scanAndPrint () {
	char nama[100];
	scanf("%s",nama);
	printf("Hello, %s\n",nama);
	
	
}
