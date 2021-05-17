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

struct DSU{
    int dsu[MAX] = {};
    
    void clear(int len){
        fill(dsu, dsu + len + 1, -1);
    }

    int findRoot(int node){
        return (dsu[node] < 0 ? node : dsu[node] = findRoot(dsu[node]));
    }

    bool join(int u, int v){
        u = findRoot(u), v = findRoot(v);
        if (u == v) return false;

        if (dsu[u] > dsu[v]) swap(u, v);
        dsu[u] += dsu[v], dsu[v] = u;
        return true;
    }

} dsu;

int n, m;
int a[MAX], b[MAX];

int eA[MAX], eB[MAX];
int cntA, cntB;
pii edges[MAX];

const int oo = 1e9;
int eUsed[MAX], cntE = 0;
int kruskal(int *edgeIdx, int numOfEdges, int lim){
    if (lim == 0) return 0;

    int cntUsed = 0;
    FOR(int, i, 1, numOfEdges){
        int idx = edgeIdx[i];
        pii edge = edges[idx];
        int u = edge.fi, v = edge.se;

        if (dsu.join(u, v)){
            eUsed[++cntE] = idx;
            cntUsed++; if (cntUsed == lim) break;
        }
    }
    return cntUsed;
}

void clear(){
    cntA = cntB = 0;
}

main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    FOR(int, _, 1, t){
        cin >> n >> m; clear();
        FOR(int, i, 1, n - 1) cin >> a[i];
        FOR(int, i, 1, n - 1) cin >> b[i];
        FOR(int, i, 1, m){
            int u, v, c; cin >> u >> v >> c;
            edges[i] = {u, v};
            if (c == 1) 
                eA[++cntA] = i;
            else
                eB[++cntB] = i;
        }

        cntE = 0; dsu.clear(n);
        int maxA = kruskal(eA, cntA, oo); 
        cntE = 0; dsu.clear(n);
        int maxB = kruskal(eB, cntB, oo);

        int ansA = -1, value = oo + oo;
        FORD(int, i, maxA, 0){
            if (n - 1 - i > maxB) continue;
            int cur = a[i] + b[n - 1 - i];
            if (cur < value)
                value = cur, ansA = i;
        }
        int ansB = n - 1 - ansA;

        cntE = 0; dsu.clear(n);
        kruskal(eB, cntB, ansB);
        cntE = 0;
        int aUsed = kruskal(eA, cntA, ansA);
        
        dsu.clear(n);
        FOR(int, i, 1, aUsed){
            pii e = edges[eUsed[i]];
            dsu.join(e.fi, e.se);
        }
        
        aUsed += kruskal(eA, cntA, ansA - aUsed);
        int save = kruskal(eB, cntB, ansB);
        assert(a[aUsed] + b[save] == value);
        
        FOR(int, i, 1, n - 1) cout << eUsed[i] << ' '; cout << '\n';
    }
}