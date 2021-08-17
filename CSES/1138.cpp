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

#define MAX 200001
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

ll it[MAX * 4];
class SegTree{
    private:
        int len;
        void update(int idx, int lo, int hi, int pos, int val){
            if (lo == hi){it[idx] = val; return;}
            int y = idx << 1, mid = (lo + hi) >> 1;
            if (pos <= mid) 
                update(y, lo, mid, pos, val);
            else 
                update(y + 1, mid + 1, hi, pos, val);
            it[idx] = it[y] + it[y + 1];
        }
        ll get(int idx, int lo, int hi, int posL, int posR){
            if (hi < posL || posR < lo) return 0;
            if (posL <= lo && hi <= posR) return it[idx];
            
            int y = idx << 1, mid = (lo + hi) >> 1;
            return get(y, lo, mid, posL, posR)
                +  get(y + 1, mid + 1, hi, posL, posR);
        }
    public:
        SegTree(){}
        SegTree(int len): len(len){
            memset(it, false, sizeof(it));
        }
        void update(int pos, int val){update(1, 1, len, pos, val);}
        ll get(int posL, int posR){return get(1, 1, len, posL, posR);}
};

int n, q;
int v[MAX];
vi graph[MAX];

const int root = 1;
int par[MAX], lvl[MAX], cntCh[MAX];
void dfs(int node, int parent){
    par[node] = parent; 
    lvl[node] = lvl[parent] + 1; 
    cntCh[node] = 1;
    for (int child: graph[node])
        if (child != parent)
            dfs(child, node),
            cntCh[node] += cntCh[child];
}

int chain[MAX], cRoot[MAX];
int pos[MAX], idx = 0;
void hld(int node, int parent, bool start){
    chain[++idx] = node; pos[node] = idx;
    if (start)
        cRoot[node] = node;
    else
        cRoot[node] = cRoot[parent];
    
    int bigChild = 0;
    for (int child: graph[node])
        if (child != parent && cntCh[child] > cntCh[bigChild]) bigChild = child;
    
    if (bigChild) hld(bigChild, node, false);
    for (int child: graph[node])
        if (child != parent && child != bigChild) hld(child, node, true);
}

SegTree seg;
ll get(ll node){
    ll ans = 0;
    while (node){
        int root = cRoot[node];
        int posL = pos[root], posR = pos[node];

        ans += seg.get(posL, posR);
        node = par[root];
    }
    return ans;
}

main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q; seg = SegTree(n);
    FOR(int, i, 1, n) cin >> v[i];
    FOR(int, i, 1, n - 1){
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(root, 0);
    hld(root, 0, true);
    FOR(int, i, 1, n) seg.update(pos[i], v[i]);
    FOR(int, _, 1, q){
        int type, a, b; cin >> type >> a;
        if (type == 1){
            cin >> b; v[a] = b;
            seg.update(pos[a], b);
        } else cout << get(a) << '\n';
    }
}