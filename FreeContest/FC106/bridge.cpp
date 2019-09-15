#include <bits/stdc++.h>
using namespace std;

#define MAX 2001
#define NON 0
#define MOD 1000000007

#define pair pair<long, long>
#define long long long

vector<long> graph[MAX];
bool del[MAX][MAX] = {};
long n, m;
pair edge[MAX] = {};
bool visited[MAX] = {};

long dfs(long node){
	visited[node] = true;
	long ans = 1;
	for(long child: graph[node]){
		if (visited[child]) continue;
		if (del[node][child]) continue;
		ans += dfs(child);
	}
	return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (long i = 0; i < m; i++)
    {
        long u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
		edge[i] = pair(u, v);
    }
	for (long ii = 0; ii < m; ii++){
		pair drop = edge[ii];
		del[drop.first][drop.second] = del[drop.second][drop.first] = true;
		memset(visited, false, sizeof(visited));
		long sum = 0, ans = 0;
		for(long node = 1; node <= n; node++){
			if (visited[node]) continue;
			long get = dfs(node);
			ans += sum * get, sum += get;
		}
		cout << ans << '\n';
	}
}
    
