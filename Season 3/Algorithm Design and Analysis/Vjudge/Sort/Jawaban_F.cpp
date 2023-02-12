#include<bits/stdc++.h>
using namespace std;

const int MAX = 100;
const int INF = 1 << 30;
int n;
int G[MAX][MAX];
int d[MAX];
int visited[MAX];

int prim(){
    int minw =0;
        for (int i = 0; i < n; i++)
        {
            d[i] = INF;
            visited[i] = 0;
        }

        d[0] = 0;
        visited[0] = 1;
        for (int i = 1; i < n; i++)
        {
            if(d[i] > G[0][i]){
                d[i] = G[0][i];
            }
        }

        for (int i = 1; i < n; i++)
        {
            int min = INF, u;
            for (int j = 1; j < n; j++)
            {
                if(!visited[j] && d[j] < min){
                    min = d[j];
                    u = j;
                }
            }
            visited[u] = 1;
            minw += min;
            for (int j = 1; j < n; j++)
            {
                if(!visited[j] && d[j] > G[u][j]){
                    d[j] = G[u][j];
                }
            }
            
            
        }  
        return minw; 
}

int main(){
    cin >> n;
    int e;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> e;
            G[i][j] = e == -1 ? INF : e;
        }
        
    }
    
    cout << prim() << endl;

    return 0;
}