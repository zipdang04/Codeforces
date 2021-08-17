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
template <class T1, class T2>
void maximize(T1 &a, T2 b){
    if (b > a) a = b;
}
template <class T1, class T2>
void minimize(T1 &a, T2 b){
    if (b < a) a = b;
}
template <class T>
void read(T &number)
{
    bool negative = false;
    register int c;
    number = 0;
    c = getchar();
    while (c != '-' && !isalnum(c)) c = getchar();
    if (c=='-'){
        negative = true;
        c = getchar();
    }
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
    if (negative)
        number *= -1;
}
template <class T, class ...Ts>
void read(T &a, Ts& ... args){
    read(a);
    read(args...);
}

/*
struct Node
{
    int node, len;
    Node() {node = len = 0;}
    Node(int node, int len) {this -> node = node, this -> len = len;}
};
typedef vector<Node> vg;
*/

const int MAX = 2e5 + 1;
const int MOD = 1e9 + 7;

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

int it[MAX * 4];
class SegTree{
    private:
        int len;
        void update(int idx, int lo, int hi, int pos, int val){
            if (lo == hi){
                it[idx] = val; return;
            }

            int y = idx << 1, mid = (lo + hi) >> 1;
            if (pos <= mid) update(y, lo, mid, pos, val);
            else update(y + 1, mid + 1, hi, pos, val);
            it[idx] = max(it[y], it[y + 1]);
        }
        int get(int idx, int lo, int hi, int posL, int posR){
            if (hi <posL || posR < lo) return 0;
            if (posL <= lo && hi <= posR) return it[idx];

            int y = idx <<1 , mid = (lo + hi) >> 1;
            return max(
                get(y, lo, mid, posL, posR),
                get(y + 1, mid + 1, hi, posL, posR)
            );
        }
    public:
        SegTree(){}
        void init(int len){
            this -> len = len;
            memset(it, false, sizeof(it));
        }
        void update(int pos, int val){update(1, 1, len, pos, val);}
        int get(int posL, int posR){return get(1, 1, len, posL, posR);}
};

int n, q;
int v[MAX];
vector<int> graph[MAX];

int par[MAX], lvl[MAX], cntCh[MAX];
void dfs(int node, int parent){
    par[node] = parent, lvl[node] = lvl[parent] + 1; cntCh[node] = 1;
    for (int child: graph[node])
        if (child != parent)
            dfs(child, node),
            cntCh[node] += cntCh[child];
}

int chain[MAX], cRoot[MAX];
int pos[MAX], idx = 0;
void hld(int node, int parent, bool start){
    chain[++idx] = node; pos[node] = idx;
    cRoot[node] = start ? node : cRoot[parent];

    int bigChild = 0;
    for (int child: graph[node])
        if (child != parent && cntCh[child] > cntCh[bigChild])
            bigChild = child;
        
    if (bigChild) hld(bigChild, node, false);
    for (int child: graph[node])
        if (child != parent && child != bigChild)
            hld(child, node, true);
}

const int BIT = 17;
int rmq[BIT + 1][MAX];
struct LCA{
    LCA(){}
    void init(){
        FOR(int, i, 1, n) rmq[0][i] = par[i];
        FOR(int, bit, 1, BIT)
            FOR(int, node, 1, n)
                rmq[bit][node] = rmq[bit - 1][rmq[bit - 1][node]];
    }
    int jump(int node, int dist){
        for (int bit = 0; dist; bit++)
            node = (dist & 1) ? rmq[bit][node] : node,
            dist >>= 1;
        return node;
    }
    int lca(int u, int v){
        if (lvl[u] > lvl[v]) swap(u, v);
        v = jump(v, lvl[v] - lvl[u]);
        if (u == v) return u;

        FORD(int, bit, BIT, 0)
            if (rmq[bit][u] != rmq[bit][v])
                u = rmq[bit][u], v = rmq[bit][v];
        return par[u];
    }
};

SegTree seg;
LCA lca;
int hldGet(int u, int v){
    if (lvl[u] > lvl[v]) swap(u, v);

    int ans = 0;
    while (lvl[v] >= lvl[u]){
        int root = cRoot[v];
        if (lvl[root] < lvl[u]) root = u;
        int posL = pos[root], posR = pos[v];
        maximize(ans, seg.get(posL, posR));
        v = par[root];
    }
    return ans;
}

void update(int node, int x){
    seg.update(pos[node], x);
}
int query(int u, int v){
    int w = lca.lca(u, v);
    return max(
        hldGet(w, u),
        hldGet(w, v)
    );
}

main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    FOR(int, i ,1, n) cin >> v[i];
    FOR(int, i, 1, n - 1){
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1, 0); hld(1, 0, true);
    lca.init();
    seg.init(n); FOR(int, i, 1, n) update(i, v[i]);

    FOR(int, _, 1, q){
        int type, a, b; cin >> type >> a >> b;
        if (type == 1) update(a, b);
        else cout << query(a, b) << ' ';
    }

}