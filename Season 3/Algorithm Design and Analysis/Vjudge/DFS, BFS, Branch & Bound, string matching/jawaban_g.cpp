#include<bits/stdc++.h>
using namespace std;

const int N = 3;

static const int dx[4] = {-1,0,1,0};
static const int dy[4] = {0,-1,0,1};
static const char dir[4] = {'u','l','d','r'};

string target = "123456780";

int bfs(string str){
    queue<string> Q;
    map<string, int> d;
    Q.push(str);
    d[str] = 0;
    string u,v;
    while (!Q.empty())
    {
        u = Q.front();
        Q.pop();
        if(u == target) return d[u];

        int t = u.find("0");
        int sx = t / N;
        int sy = t % N;

        for (int r = 0; r < 4; r++)
        {
            int tx = sx + dx[r];
            int ty = sy + dy[r];

            if(tx < 0 || ty < 0 || tx >= N || ty >= N)continue;

            int ans = d[u];

            swap(u[t], u[tx * N + ty]);
            if(!d[u]){
                d[u] = ans + 1;
                Q.push(u);
            }
            swap(u[t], u[tx * N + ty]);
        }
        
    }
    
    return 0;
}

int main(){
    string str;
    char ch;
    for (int i = 0; i < N * N; i++)
    {
        cin >> ch;
        str += ch;
    }

    int ans = bfs(str);
    cout << ans << endl;

    return 0;
    
}