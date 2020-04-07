#include <bits/stdc++.h>
using namespace std;

#define MAX 1001
#define NON 0
#define MOD 1000000007

typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, ll> pii;

struct Data
{
    int node, lvl;
    Data() {node = lvl = 0;}
    Data(int node, int lvl) {this -> node = node, this -> lvl = lvl;}
};

int n, m, s, t;
int rG[MAX][MAX];
int path[MAX], pathLen = 0;
bool visited[MAX]; //FF
int previous[MAX]; //EK

//this is for original Ford-Fulkerson
bool findPath(int node, int end, int len){
    visited[node] = true;
    path[len] = node;
    if (node == end){pathLen = len; return true;}

    for (int child = 1; child <= n; child++)
    {
        if (rG[node][child] == 0) continue;
        if (visited[child]) continue;
        if (findPath(child, end, len + 1)) return true;
    }
    return false;
}

//this is for Edmond-Karp
bool findPath(int node, int end){
    previous[node] = -1;
    queue<Data> q; q.push(Data(node, 1));
    bool found = false;
    while (!q.empty())
    {
        Data curr = q.front(); q.pop();
        for (int child = 1; child <= n; child++)
        {
            if (rG[curr.node][child] == 0) continue;
            if (previous[child]) continue;

            previous[child] = curr.node;
            if (child == end){pathLen = curr.lvl + 1, found = true; break;}
            else q.push(Data(child, curr.lvl + 1));
        }
        if (found) break;
    }
    if (!found) return false;
    for (int i = pathLen; i > 0; i--)
        path[i] = end, end = previous[end];
    return true;
}

int fordFulkerson(int source, int sink){
    int answer = 0;
    // while (findPath(source, sink, 1))
    while (findPath(source, sink))
    {
        int bottleNeck = INT32_MAX;
        for (int i = 2; i <= pathLen; i++)
            bottleNeck = min(bottleNeck, rG[path[i - 1]][path[i]]);
        answer += bottleNeck;
        for (int i = 2; i <= pathLen; i++)
            rG[path[i - 1]][path[i]] -= bottleNeck, 
            rG[path[i]][path[i - 1]] += bottleNeck;

        pathLen = 0;
        // fill(visited, visited + n + 1, false);
        fill(previous, previous + n + 1, 0);
    }
    return answer;
}

main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++)
    {
        int u, v, c; cin >> u >> v >> c;
        rG[u][v] = c;
    }
    cout << fordFulkerson(s, t);
}
