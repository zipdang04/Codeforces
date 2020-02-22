#include <bits/stdc++.h>
using namespace std;

#define MAX 100001

struct Node{
	int node, len;
	Node(){node = len = 0;}
	Node(int node, int len){this -> node = node, this -> len = len;}
};

int n, m, c;
vector<Node> graph[MAX];
vector<int> rev[MAX];
int s[MAX], ans[MAX];
bool isRoot[MAX], visited[MAX];

void findRoot(int node){
	visited[node] = true;
	if (rev[node].size() == 0) isRoot[node] = true;
	else
		for (int child: rev[node]) 
			if (!visited[child]) findRoot(child);
}

void cal(int node){
	int curr = ans[node];
	for (Node child: graph[node]){
		int day = curr + child.len;
		if (day < ans[child.node]) continue;
		ans[child.node] = day; cal(child.node);
	}
}

main(){
	freopen("timeline.in", "r", stdin);
	freopen("timeline.out", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m >> c;
	for (int i = 1; i <= n; i++) cin >> s[i];
	for (int i = 1; i <= c; i++){
		int a, b, x; cin >> a >> b >> x;
		graph[a].push_back(Node(b, x));
		rev[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) findRoot(i);
	for (int i = 1; i <= n; i++){
		if (isRoot[i])
			ans[i] = s[i], cal(i);
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << '\n';
}

