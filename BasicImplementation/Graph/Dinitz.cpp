#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define FOR(type, i, a, b) for(type i = (a); i <= (b); i++)
#define FORD(type, i, b, a) for(type i = (b); i >= (a); i--)

class Flow{
    struct Edge{int from, dest, oppo; ll capa;};
    private:
        const ll oo = 1ll << 60;
        vector<Edge> edges, resi;
        vector<vector<int>> graph;
        int n, m, s, t;

        const int NaN = -1;
        vector<int> level;
        vector<int> ptr;

        bool bfs(ll lim){
            level = vector<int>(n, NaN);

            queue<int> q; 
            
            q.push(s); level[s] = 0;
            while (!q.empty()){
                int node = q.front(); q.pop();
                int nodeLvl = level[node];

                for (int idx: graph[node]){
                    Edge e = resi[idx];
                    if (e.capa < lim || level[e.dest] != NaN) continue;
                    
                    q.push(e.dest); level[e.dest] = nodeLvl + 1;
                }
            }

            return level[t] != NaN;
        }
        
        bool dfs(int node, ll lim){
            if (node == t) return true;
            int currLevel = level[node];

            int &i = ptr[node], maxSize = graph[node].size();
            for (; i < maxSize; i++){
                int idx = graph[node][i];
                Edge e = resi[idx];
                if (e.capa < lim || level[e.dest] != currLevel + 1) continue;

                if (dfs(e.dest, lim)){
                    resi[idx].capa -= lim;
                    resi[e.oppo].capa += lim;
                    return true;
                }
            }

            return false;
        }

    public:
        Flow(int n, int s, int t): n(n), s(s), t(t){
            m = 0;
            edges.clear(); 
            graph = vector<vector<int>>(n);
        }

        void addEdge(int from, int dest, ll capa){
            edges.push_back({from, dest, m + 1, capa});
            edges.push_back({dest, from, m    , 0});
            graph[from].push_back(m),
            graph[dest].push_back(m + 1);
            m += 2;
        }

        ll calculate(){
            resi = edges; ll answer = 0;
            ll tmp = oo;
            while (tmp){
                if (!bfs(tmp)){
                    tmp >>= 1; continue;
                }

                ptr = vector<int>(n, 0);
                while (dfs(s, tmp))
                    answer += tmp;
            }
            return answer;
        }
};

Flow *flow;
int n, m;
main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m; 
    flow = new Flow(n + 1, 1, n);
    FOR(int, _, 1, m){
        int u, v, c; cin >> u >> v >> c;
        flow -> addEdge(u, v, c);
        flow -> addEdge(v, u, c);
    }
    cout << flow -> calculate();
}
