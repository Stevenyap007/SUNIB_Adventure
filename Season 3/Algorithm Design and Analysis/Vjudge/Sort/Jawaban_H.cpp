#include<bits/stdc++.h>
using namespace std;
static const int MAX = 1E4;
static const int INF = 1E9;
vector<pair<int, int> > adj[MAX];

int d[MAX];
int n;
struct Node{
    int v, dist;
    Node(){
    }
    Node(int v, int dist): v(v), dist(dist){
    }

    bool operator<(Node e)const{
        return dist > e.dist;
    }
};

void dijkstra(int k){
    bool visited[MAX];
    priority_queue< Node > PQ;

    for (int i = 0; i < n; i++)
    {
        d[i] = INF;
        visited[i] = false;
    }
    
    d[k] = 0;
    visited[k] = true;
    PQ.push(Node(k, 0));
    while(!PQ.empty()){
        Node p = PQ.top();
        PQ.pop();

        int u = p.v;
        visited[u] = true;

        for(int i = 0; i < adj[u].size(); i++){
                int v = adj[u][i].first;
                if(visited[v]) continue;
                if(d[v] > d[u] + adj[u][i].second){
                    d[v] = d[u] + adj[u][i].second;
                    PQ.push(Node(v, d[v] ));
                }
        }
    }
}

int main(){
    int u, k, v, c;
    cin >> n;


    for (int i = 0; i < n; i++)
    {
        cin >> u >> k;
        for (int j = 0; j < k; j++)
        {
            cin >> v >> c;
            adj[u].push_back(make_pair(v,c));        
        }
        
    }

    dijkstra(0);

    for (int i = 0; i < n; i++)
    {
        cout << i << " " << (d[i] == INF ? 1 : d[i]) << endl;
    }
    return 0;
    
}