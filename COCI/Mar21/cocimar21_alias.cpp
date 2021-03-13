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


struct Node
{
    int node, len;
    Node() {node = len = 0;}
    Node(int node, int len) {this -> node = node, this -> len = len;}
};
typedef vector<Node> vg;


#define MAX 1003
#define MOD 1000000007

#define fi first
#define se second
#define pf push_front
#define pb push_back

#define FOR(type, i, a, b) for(type i = (a); i <= (b); i++)
#define FORR(type, i, b, a) for(type i = (b); i >= (a); i--)

#define testBit(n, bit) ((n >> bit) & 1)
#define flipBit(n, bit) (n ^ (1ll << bit))
#define cntBit(n) __builtin_popcount(n)
#define cntBitll(n) __builtin_popcountll(n)
#define randomize mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
int n, m;
map<string, int> msi;
int cnt = 0;

int get(string &s){
    int ans = msi[s];
    return ans ? ans : (msi[s] = ++cnt);
}

vg graph[MAX];

ll ans[MAX][MAX];
const ll oo = 1e15;

void dijkstra(int s){
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    ans[s][s] = 0, pq.push({0, s});
    while (!pq.empty()){
        pii curr = pq.top(); pq.pop();
        if (ans[s][curr.se] != curr.fi) continue;

        for (Node child: graph[curr.se]){
            ll newLen = curr.fi + child.len;
            if (newLen < ans[s][child.node])
                ans[s][child.node] = newLen,
                pq.push({newLen, child.node});
        }
    }
}

main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    FOR(int, _, 1, m){
        string s1, s2; int w; cin >> s1 >> s2 >> w;
        int u = get(s1), v = get(s2);
        graph[u].push_back({v, w});
    }

    FOR(int, i, 1, n){
        FOR(int, j, 1, n) ans[i][j] = oo;
        dijkstra(i);
    }

    int q; cin >> q;
    FOR(int, i, 1, q){
        string s1, s2; cin >> s1 >> s2;
        int u = get(s1), v = get(s2);
        if (u > n || v > n || ans[u][v] == oo) cout << "Roger\n";
        else cout << ans[u][v] << '\n';
    }
}
