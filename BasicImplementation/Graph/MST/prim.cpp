#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

#define w first
#define ch second
#define fath second.first
#define chil second.second

vector<pii> graph[10001];
bool visited[10001] = {};
int n, m;
int sum = 0;

void buildTree(){
	visited[1] = true;
	priority_queue<pipii, vector<pipii>, greater<pipii>> edgeSave;
	for(pii edge: graph[1]){
		edgeSave.push(pipii(edge.w, pii(1, edge.ch)));
	}

	while (!edgeSave.empty()){
		pipii currEdge = edgeSave.top(); edgeSave.pop();
		// cout << currEdge.w << ' ' << currEdge.fath << ' ' << currEdge.chil << endl;
		if (visited[currEdge.chil]) continue;
		visited[currEdge.chil] = true;
		sum += currEdge.w;

		for(pii edge: graph[currEdge.chil]){
			if (visited[edge.ch]) continue;
			edgeSave.push(pipii(edge.w, pii(currEdge.chil, edge.ch)));
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int u, v, len; cin >> u >> v >> len;
		graph[u].push_back(pii(len, v));
		graph[v].push_back(pii(len, u));
	}
	for (int i = 1; i <= n; i++) sort(graph[i].begin(), graph[i].end());
	cout << endl;
	buildTree();
	cout << sum;
}
