#include <bits/stdc++.h>
using namespace std;
const int N = 9;
int belong[N], counter;
vector<int> lists[N];

void dfs(int id, int vi) {
	if(belong[vi]!=0) return;
	belong[vi] = id;
	for(int i=0; i<lists[vi].size(); i++) 
		dfs(id, lists[vi][i]);
}

int main() {
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		int a, b;
		cin >> a >> b;
		lists[a-1].push_back(b-1);
		lists[b-1].push_back(a-1);
	}
	counter = 1;
	for(int i=0; i<N; i++)
		if(belong[i]==0) {
			dfs(counter, i);
			counter++;
		}
	for(int i=0;i<N; i++) {
		cout << (i+1) << " = " << belong[i] << endl;
	}
	cout << "Connected Component = " << (counter-1) << endl;
	return 0;
}
