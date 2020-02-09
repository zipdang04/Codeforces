#include <bits/stdc++.h>
using namespace std;

#define MAX_N 20001
#define MAX_M 50001

typedef long long ll;

struct Node{
	int node, len;
	Node(){node = len;}
	Node(int node, int len){
		this -> node = node;
		this -> len = len;
	}
};

struct Data{
	int node, ans;
	Data(){node = ans;}
	Data(int node, int ans){
		this -> node = node;
		this -> ans = ans;
	}
};

bool operator > (Data a, Data b){
	return a.ans > b.ans;
}

int n, m, s, t;
vector<Node> graph[MAX_N];
int answer[MAX_N];

void clear(int n){
	for (int i = 1; i <= n; i++)
		graph[i].clear();
}

void Dijkstra(){
	priority_queue<Data, vector<Data>, greater<Data> > pq;
	fill(answer, answer + n + 1, 1000000000);
	answer[s] = 0; pq.push(Data(s, 0));
	while (!pq.empty()){
		Data curr = pq.top(); pq.pop();
		if (curr.ans != answer[curr.node])
			continue;
		
		for (Node child: graph[curr.node]){
			Data now(child.node, curr.ans + child.len);
			if (now.ans < answer[now.node])
				answer[now.node] = now.ans,
				pq.push(now);
		}
	}
}

int main() {
	int test; cin >> test;
	for (int iii = 0; iii < test; iii++){
		cout << "Case #" << iii + 1 << ": ";
		cin >> n >> m >> s >> t; s++, t++;
		clear(n);
		for(int i = 1; i <= m; i++){
			int u, v, len; cin >> u >> v >> len;
			u++, v++;
			graph[u].push_back(Node(v, len));
			graph[v].push_back(Node(u, len));
		}
		Dijkstra();

		if (answer[t] == 1000000000) cout << "unreachable\n";
		else cout << answer[t] << '\n';
	}
}
