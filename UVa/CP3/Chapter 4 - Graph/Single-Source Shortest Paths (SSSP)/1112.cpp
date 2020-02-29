#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Node{
    ll node, len;
    Node(){node = len = 0;}
    Node(ll node, ll len){
        this -> node = node; 
        this -> len = len;
    }
};

struct Data{
    ll node, time;
    Data(){node = time = 0;}
    Data(ll node, ll time){
        this -> node = node; 
        this -> time = time;
    }
};

vector<Node> graph[101];
ll n, e, t;

bool operator > (Data a, Data b){
    return a.time > b.time;
}

bool Dijkstra(ll st, ll fi){
    priority_queue<Data, vector<Data>, greater<Data> > pq;
    ll ans[n + 1] = {}; fill(ans, ans + n + 1, INT64_MAX);
    ans[st] = 0; pq.push(Data(st, 0));
    while (!pq.empty()){
        Data curr = pq.top(); pq.pop();
        if (curr.time != ans[curr.node]) continue;
        if (curr.node == fi) break;

        for (Node child: graph[curr.node]){
            Data now(child.node, curr.time + child.len);
            if (ans[now.node] > now.time){
                pq.push(now), ans[now.node] = now.time;
            }
        }
    }
    return ans[fi] <= t;
}

void refresh(){
    for (int i = 1; i <= n; i++) graph[i].clear();
}

main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("1112.inp", "r", stdin);
    ll test; cin >> test;
    for (ll iiii = 0; iiii < test; iiii++)
    {
        ll m; cin >> n >> e >> t >> m;
        for (ll i = 0; i < m; i++)
        {
            ll u, v, len; cin >> u >> v >> len;
            graph[u].push_back(Node(v, len));
            // graph[v].push_back(Node(u, len));
        }
        ll answer = 0;
        for (ll i = 1; i <= n; i++)
            answer += Dijkstra(i, e);
        cout << answer << "\n\n";
        refresh();
    }
    
    return 0;
}
