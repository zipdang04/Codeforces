#include <bits/stdc++.h>
using namespace std;

#define MAX 200001

struct Edge
{
    int u, v, len;
    Edge(){u = v = len = 0;}
    Edge(int u, int v, int len){
        this -> u = u,
        this -> v = v,
        this -> len = len;
    }
};

bool operator > (Edge a, Edge b){return a.len > b.len;}

priority_queue<Edge, vector<Edge>, greater<Edge> > pq;
int m, n;
int dsu[MAX];

void refresh(){
    while (!pq.empty()) pq.pop();
    memset(dsu, -1, sizeof(dsu));
}

int getRoot(int node){
    if (dsu[node] < 0) return node;
    return dsu[node] = getRoot(dsu[node]);
}

void join(int u, int v){
    if (dsu[u] < dsu[v]) swap(u, v);
    dsu[u] += dsu[v];
    dsu[v] = u;
}

int MST(int total){
    int part = n;
    while (!pq.empty() && part > 1){
        // cerr << total << '\n';
        Edge curr = pq.top(); pq.pop();
        int u = curr.u, v = curr.v;
        curr.u = getRoot(curr.u), curr.v = getRoot(curr.v);
        if (curr.u == curr.v) continue;
        // cerr << u << ' ' << v << ' ' << curr.len << '\n';
        part--, total -= curr.len, join(curr.u, curr.v);
    }
    return total;
}

int main(int argc, char const *argv[])
{
    while (cin >> n >> m){
        if (n == 0 && m == 0) break;
        refresh();
        int total = 0;
        for (int i = 0; i < m; i++)
        {
            int u, v, len; cin >> u >> v >> len;
            u++, v++;
            total += len; pq.push(Edge(u, v, len));
        }
        cout << MST(total) << '\n';
    }
    return 0;
}
