#include <bits/stdc++.h>
using namespace std;
#define MAX 201

vector<int> graph[MAX];
int n, m;
int state[MAX];

bool test(int node, int color){
	int other = 3 - color;
	for (int child: graph[node]){
		if (state[child]){
			if (state[child] == color) return false;
			continue;
		}
		state[child] = other; 
		if (!test(child, other)) return false;
	}
	return true;
}

void refresh(){
	for (int i = 1; i < MAX; i++) graph[i].clear();
	memset(state, 0, sizeof(state));
}

main(){
	while (true){
		cin >> n; if (n == 0) break; cin >> m;
		for (int i = 1; i <= m; i++){
			int u, v; cin >> u >> v; u++, v++;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		state[1] = 1;
		if (!test(1, 1)) cout << "NOT ";
		cout << "BICOLORABLE.\n";
		refresh();
	}
}
