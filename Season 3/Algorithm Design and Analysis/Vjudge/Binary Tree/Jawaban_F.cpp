#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n,m,v,u; cin >> n >> m;

    vector < int > c[n], p(n), ans;
    vector < bool > visited(n);

    while (m--){
        cin >> v >> u; v--, u--;

        c[v].push_back(u);
        p[u]++;
    }

    set < int > s;

    for (v = 0; v < n; v++)
        if (p[v] == 0)
            s.insert(v);


    while (!s.empty()){
        v = *s.begin(); s.erase(s.begin());

        ans.push_back(v+1), visited[v] = true;

        for(auto u : c[v]){
            p[u]--;

            if(p[u] == 0)
                s.insert(u);
        }
    }

    for (v = 0; v < n; v++)
        if(!visited[v]){
            cout << -1;return 0;
        }

    for (auto v : ans) cout << v << ' ';
}