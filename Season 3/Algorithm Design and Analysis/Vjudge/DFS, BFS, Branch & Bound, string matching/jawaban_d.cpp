#include<bits/stdc++.h>
using namespace std;

const int N = 105;
vector <int> g[N];
bool vis[N];
int dis[N];
queue<int>q;

int main(){
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int u,k,in;
        cin>>u>>k;
        for (int j = 0; j < k; j++)
        {
            cin>>in;
            g[u].push_back(in);
        }
        
    }

    q.push(1);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = true;
        for (auto v:g[u])
        {
            if(!vis[v]){
                q.push(v);
                dis[v] = dis[u]+1;
                vis[v] = true;
            }
        }
        
    }
    
    for (int i = 1; i <= n; i++)
    {
        if(i>1 && !dis[i]){
            dis[i] = -1;
        }
        cout<<i<<" "<<dis[i]<<endl;
    }
    


    return 0;
}