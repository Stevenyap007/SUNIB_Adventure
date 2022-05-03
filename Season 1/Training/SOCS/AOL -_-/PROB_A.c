#include <stdio.h>
#include <stdlib.h>

int x,y;
int arr[100][100];
int c1,c2,c3,c4,c5,c6,c7,c8=0;

void cekBottomLeft(int midX, int midY, int target, int *BLX, int *BLY){
	
	if(midX<0 || midX>x || midY<0 || midY>y){
		*BLX = 1000;
		*BLY = 1000;
		return ;
	}else{
		if(arr[midX][midY] == target && c1!=0){
//			printf("(%d,%d) : %d", midX, midY,arr[midX][midY]);
			*BLX = midX;
			*BLY = midY;
			return ;
		}
	}
	c1++;
	cekBottomLeft(midX+1, midY-1,target, BLX,BLY);
}


void cekBottomRight(int midX, int midY, int target, int *BRX, int *BRY){
	if(midX<0 || midX>x ||midY<0 || midY>y){
		*BRX = 1000;
		*BRY = 1000;
		return ;
	}else{
		if(arr[midX][midY]==target && c2!=0){
//			printf("(%d,%d) : %d", midX, midY,arr[midX][midY]);
			*BRX = midX;
			*BRY = midY;
			return ;
		}
	}
	c2++;
	cekBottomRight(midX+1, midY+1,target,BRX,BRY);
}

void cekUpLeft(int midX, int midY, int target, int *ULX, int *ULY){
	if(midX<0 || midX>x ||midY<0 || midY>y){
		*ULX = 1000;
		*ULY = 1000;
		return ;
	}else{
		if(arr[midX][midY]==target && c3!=0){
//			printf("(%d,%d) : %d", midX, midY,arr[midX][midY]);
			*ULX = midX;
			*ULY = midY;
			return ;
		}
	}
	c3++;
	cekUpLeft(midX-1, midY-1,target,ULX,ULY);
}

void cekUpRight(int midX, int midY, int target, int *URX, int *URY){
	if(midX<0 || midX>x ||midY<0 || midY>y){
		*URX = 1000;
		*URY = 1000;
		return ;
	}else{
		if(arr[midX][midY]==target && c4!=0){
//			printf("(%d,%d) : %d", midX, midY,arr[midX][midY]);
			*URX = midX;
			*URY = midY;
			return ;
		}
	}
	c4++;
	cekUpRight(midX-1, midY+1,target,URX,URY);
}


void cekRight(int midX, int midY, int target, int *rightX, int *rightY){
	if(midX<0 || midX>x ||midY<0 || midY>y){
		*rightX = 1000;
		*rightY = 1000;
		return ;
	}else{
		if(arr[midX][midY]==target && c5!=0){
//			printf("(%d,%d) : %d", midX, midY,arr[midX][midY]);
			*rightX = midX;
			*rightY = midY;
			return ;
		}
	}
	c5++;
	cekRight(midX, midY+1,target,rightX, rightY);
}

void cekLeft(int midX, int midY, int target, int *leftX, int *leftY){
	if(midX<0 || midX>x ||midY<0 || midY>y){
		*leftX = 1000;
		*leftY = 1000;
		return ;
	}else{
		if(arr[midX][midY]==target && c6!=0){
//			printf("(%d,%d) : %d", midX, midY,arr[midX][midY]);
			*leftX = midX;
			*leftY = midY;
			return ;
		}
	}
	c6++;
	cekLeft(midX, midY-1,target, leftX, leftY);
}


void cekUp(int midX, int midY, int target, int *upX, int *upY){
	if(midX<0 || midX>x ||midY<0 || midY>y){
		*upX = 1000;
		*upY = -1000;
		return ;
	}else{
		if(arr[midX][midY]==target && c7!=0){
//			printf("(%d,%d) : %d", midX, midY,arr[midX][midY]);
			*upX = midX;
			*upY = midY;
			return ;
		}
	}
	c7++;
	cekUp(midX-1, midY,target,upX, upY);
}


void cekBottom(int midX, int midY, int target, int *bottomX, int *bottomY){
	if(midX<0 || midX>x ||midY<0 || midY>y){
		*bottomX = 1000;
		*bottomY = 1000;
		return;
	}else{
		if(arr[midX][midY]==target && c8!=0){
//			printf("(%d,%d) : %d", midX, midY,arr[midX][midY]);
			*bottomX = midX;
			*bottomY = midY;
			return;
		}
	}
	c8++;
	cekBottom(midX+1, midY,target, bottomX, bottomY);
}




int main(){
	int bottomX, bottomY,upX, upY, rightX, rightY, leftX , leftY, URX, URY, ULX, ULY, BLX, BLY, BRX, BRY;
	scanf("%d %d", &x, &y);getchar();
	
	
	for(int i=0;i<x;i++){
		for(int j=0; j<y;j++){
			scanf("%d", &arr[i][j]);
		}
	}
	
	int midX,midY;
	
	midX = x/2;
	midY = y/2;

	int target = arr[midX][midY];
	
	cekBottom(midX, midY, target,&bottomX, &bottomY);
	cekUp(midX, midY, target,&upX, &upY);
	cekLeft(midX, midY, target,&leftX, &leftY);
	cekRight(midX, midY, target,&rightX, &rightY);
	cekUpRight(midX, midY, target, &URX, &URY);
	cekUpLeft(midX, midY, target, &ULX, &ULY);
	cekBottomLeft(midX, midY, target, &BLX, &BLY);
	cekBottomRight(midX, midY, target, &BRX, &BRY);
	
	int Xs[8], Ys[8];
	
	Xs[0] = bottomX;
	Xs[1] = upX;
	Xs[2] = leftX;
	Xs[3] = rightX;
	Xs[4] = URX;
	Xs[5] = ULX;
	Xs[6] = BRX;
	Xs[7] = BLX;
	
	Ys[0] = bottomY;
	Ys[1] = upY;
	Ys[2] = leftY;
	Ys[3] = rightY;
	Ys[4] = URY;
	Ys[5] = ULY;
	Ys[6] = BRY;
	Ys[7] = BLY;
	
	int min = 100000;
	
	for(int i=0; i<8;i++){
		if(abs(midX-Xs[i])<=min && abs(midX-Xs[i])!=0){
			min = abs(midX-Xs[i]);
		}
//		printf("%d : %d\n",i, midX-Xs[i]);
	}
	
//	printf("min : %d, midX : %d\n", min, midX);
//	
//	printf("bottom : %d %d\n",bottomX,bottomY);
//	printf("up : %d %d\n",upX,upY);
//	printf("left : %d %d\n",leftX,leftY);
//	printf("right : %d %d\n",rightX,rightY);
//	printf("UR : %d %d\n",URX,URY);
//	printf("UL : %d %d\n",ULX,ULY);
//	printf("BR : %d %d\n",BRX,BRY);
//	printf("BL : %d %d\n",BLX,BLY);


	printf("The nearest coordinate with same value is : ");

	int cek=0;
	
	if(leftY+min == midY){
		printf("left : (%d,%d) ", leftX, leftY);
		printf("left : (%d,%d) ", leftX, leftY);
		cek++;
	}
	
	if(rightY-min == midY){
		printf("right : (%d,%d) ", rightX, rightY);
		cek++;
	}
	
	if(upX+min == midX){
		printf("up : (%d,%d) ", upX, upY);
		cek++;
	}
	
	if(bottomX-min == midX){
		printf("bottom : (%d,%d) ", bottomX, bottomY);
		cek++;
	}
	
	if(URX+min == midX && URY-min == midY){
		printf("URX : (%d,%d) ", URX, URY);
		cek++;
	}
	
	if(ULX+min == midX && ULY+min == midY){
		printf("ULX : (%d,%d) ", ULX, ULY);
		cek++;
	}
	
	if(BLX-min == midX && BLY+min == midY){
		printf("BLX : (%d,%d) ", BLX, BLY);
		cek++;
	}
	
	if(BRX-min == midX && BRY-min == midY){
		printf("BRX : (%d,%d) ", BRX, BRY);
		cek++;
	}
	
	if(cek == 0){
		printf("There is no coordinate\n");
	}
	
	
	return 0;
}