#include <bits/stdc++.h>
using namespace std;
const int N = 8;
vector<int> lists[N];
int lowestAncestor[N], index[N], belong[N];
bool isInStack[N];
int counter, ctr;
stack<int> cstack;

void scc(int u) {
	cstack.push(u);	isInStack[u] = true;
	lowestAncestor[u] = index[u] = counter ++;
	
	for(int i=0;i < lists[u].size(); i++) {
		int ni = lists[u][i];
		if(index[ni]==-1) {
			scc(ni);
			if(lowestAncestor[u] > lowestAncestor[ni])
				lowestAncestor[u] = lowestAncestor[ni];
		} else if(isInStack[ni]) {
			if(lowestAncestor[u] > lowestAncestor[ni])
				lowestAncestor[u] = lowestAncestor[ni];
		}
	}
	if(index[u] == lowestAncestor[u]) {
		cout << "Component " << (++ctr) << ":" << endl;
		while(true) {
			int t = cstack.top(); cstack.pop();
			isInStack[t] = false;
			belong[t] = ctr;
			cout << " " << (t+1) << " ";
			if(t == u) break;
		}
		cout << endl;
	}
}

int main() {
	int n, a, b;
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> a >> b;
		lists[a-1].push_back(b-1);
	}
	for(int i=0;i<N;i++) {
		lowestAncestor[i]=0;
		index[i]=-1;
	}
	for(int i=0;i<N;i++)
		if(index[i]==-1)
			scc(i);
			
	for(int i=0;i<N; i++) {
		cout << (i+1) << " = " << belong[i] << endl;
	}
	cout << "Strongly Connected Component = " << ctr << endl;
	return 0;
}
