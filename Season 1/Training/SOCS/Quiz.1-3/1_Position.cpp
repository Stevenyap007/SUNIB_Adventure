#include <stdio.h>

int N, M, A[1000001], Q[1000001], index;

int binSearch(int min, int max, int theOne){
	
	if(min <= max){
		int mid = min + (max - min) / 2;
		
		if(A[mid] == theOne){
            if(mid - 1 >= 0 && A[mid - 1] != theOne){
                return mid + 1;
            } else if(mid - 1 >= 0 && A[mid - 1] == theOne){
                return binSearch(min, mid - 1, theOne);
            } else {
			    return mid + 1;
            }
		}
		
		if(A[mid] < theOne){
			return binSearch(mid + 1, max, theOne);
		}
		return binSearch(min, mid - 1, theOne);
	}
	
	return -1;
}

int main(){

    scanf("%d %d", &N, &M);

    for(int i = 0; i < N; i++){
        scanf("%d", &A[i]);
    }

    for(int i = 0; i < M; i++){
        scanf("%d", &Q[i]);
    }

    for(int i = 0; i < M; i++){
        index = binSearch(0, N - 1, Q[i]);
        printf("%d\n", index);
    }

    return 0;
}
    

