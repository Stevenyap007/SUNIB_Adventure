#include <bits/stdc++.h>

const int N = 5;



int board[N][N];

bool fcol[N], fver1[N*2], fver2[N*2], found;



void backtrack(int row, int col) {

if(row == N) found = true;

if(found) return;

if(fcol[col] || fver1[row+col] || fver2[row-col+N]) return;

printf("%d, %d\n", row+1, col+1);

board[row][col] = 1;

fver1[row+col] = true; fver2[row-col+N] = true; fcol[col] = true;

for(int i=0; i<N; i++) 

backtrack(row+1, i);

if(found) return;

board[row][col] = 0;

fcol[col] = false; fver1[row+col] = false; fver2[row-col+N] = false;

}



int main()

{

while(!found)

for(int i=0;i<N;i++)

backtrack(0, i);

if(found) {

for(int i=0; i < N ;i++) {

for(int j=0;j<N;j++)

printf("%2d", board[i][j]);

puts("");

}

}

return 0;

}

