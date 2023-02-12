#include <bits/stdc++.h>
using namespace std;

int mp[16][16], ans =0, flag =0;
int nx[4][2]= {0, -1, -1, 0, 0, 1, 1, 0};

int check(){
    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if(mp[i][j]!=i*4+j+1 && mp[i][j]){
                sum+=abs((mp[i][j]-1)/4-i)+abs((mp[i][j]-1)%4-j);
            }
        } 
    }
    return sum;
}

void dfs(int x, int y, int res, int prev){
    if(res+check() > ans || flag){
        return;
    }
    if(check()==0){
        flag=1;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int tx = x+nx[i][0];
        int ty = y+nx[i][1];
        if(tx<0 || tx>=4 || ty<0 || ty>=4 || abs(prev-i)==2){
            continue;
        }
        swap(mp[x][y],mp[tx][ty]);
        dfs(tx,ty,res+1,i);
        swap(mp[x][y],mp[tx][ty]);
    }
    
}

int main(){
    int x=0, y=0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> mp[i][j];
            if(!mp[i][j]){
                x=i;
                y=j;
            }
        }    
    }
    ans = check();
    flag = 0;
    while (1)
    {
        dfs(x,y,0,-100);
        if(flag){
            cout << ans << endl;
            break;
        }
        ans++;
    }
    return 0;



}