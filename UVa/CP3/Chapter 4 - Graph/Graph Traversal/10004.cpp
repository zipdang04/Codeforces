#include <bits/stdc++.h>
using namespace std;

#define MAX 201

int n, m;
vector<int> graph[MAX];
int color[MAX] = {};

void refresh(){
	for (int i = 1; i <= MAX; i++){
		graph[i].clear();
	}
	memset(color, 0, sizeof(color));
}

bool test(int node, int color){
	int newColor = 3 - color;
	for (int child: graph[node]){
		if (color[child]){
//			if (color[child] == color) return false;
//			continue;
		}
//		color[child] = newColor;
//		if (!test(child, newColor)) return false;
	}
	return true;
}

main(){
	while (true){
		cin >> n; if (n == 0) break; cin >> m;
		for (int i = 0; i < m; i++){
			int u, v; cin >> u >> v; u++, v++;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		color[1] = 1;
		if (!test(1, 1)) cout << "NOT ";
		cout << "BICOLORABLE.\n";
	}
}
