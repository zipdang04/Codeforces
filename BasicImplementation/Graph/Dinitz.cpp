#include <bits/stdc++.h>
using namespace std;
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
*/

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef map<int, int> mii;
typedef unordered_map<int, int> umii;
typedef map<ll, ll> mll;
typedef unordered_map<ll, ll> umll;

/*
struct Node
{
    int node, len;
    Node() {node = len = 0;}
    Node(int node, int len) {this -> node = node, this -> len = len;}
};
typedef vector<Node> vg;
*/

#define MAX 1000001
#define MOD 1000000007

#define fi first
#define se second
#define pf push_front
#define pb push_back

#define FOR(type, i, a, b) for(type i = (a); i <= (b); i++)
#define FORD(type, i, b, a) for(type i = (b); i >= (a); i--)

#define testBit(n, bit) ((n >> bit) & 1)
#define flipBit(n, bit) (n ^ (1ll << bit))
#define cntBit(n) __builtin_popcount(n)
#define cntBitll(n) __builtin_popcountll(n)
#define randomize mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());

class Flow{
    struct Edge{int from, dest, oppo; ll capa;};
    private:
        const ll oo = 1ll << 60;
        vector<Edge> edges, resi;
        vector<vector<int>> graph;
        int n, m, s, t;

        const int NaN = -1;
        vector<int> level;
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

            for (int idx: graph[node]){
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