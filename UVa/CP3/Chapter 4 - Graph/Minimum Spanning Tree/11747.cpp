#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
typedef pair<ll, ll> pll;
typedef map<int, int> mii;
typedef unordered_map<int, int> umii;
typedef map<ll, ll> mll;
typedef unordered_map<ll, ll> umll;

// struct Node
// {
// 	int node, len;
// 	Node() {node = len = 0;}
// 	Node(int node, int len) {this -> node = node, this -> len = len;}
// };
// typedef vector<Node> vg;

#define MAX 25001
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

int dsu[MAX];
int ans[MAX], cnt;
pipii edge[MAX];
int n, m;

int findRoot(int node){
	if (dsu[node] < 0) return node;
	dsu[node] = findRoot(dsu[node]);
	return dsu[node];
}

bool join(int u, int v){
	// cerr << "join: " << u << ' ' << v << '\n';
	u = findRoot(u), v = findRoot(v);
	if (u == v) return false;
	// cerr << "hmm... not same, okay.\n";
	
	if (dsu[u] > dsu[v]) swap(u, v);
	dsu[u] += dsu[v], dsu[v] = u;

	return true;
}

main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	while (cin >> n >> m){
		if (n == 0) return 0;

		FOR(int, i, 0, n - 1)
			dsu[i] = -1;
		FOR(int, i, 1, m)
			cin >> edge[i].se.fi >> edge[i].se.se >> edge[i].fi;
		sort(edge + 1, edge + 1 + m);
		
		cnt = 0;
		FOR(int, i, 1, m){
			// cerr << "///" << i << '\n';
			int w = edge[i].fi, u = edge[i].se.fi, v = edge[i].se.se;
			if (!join(u, v)) {
				ans[cnt++] = w;
			}
		}
		if (!cnt) cout << "forest";
		else {
			sort(ans, ans + cnt);
			cout << ans[0];
			FOR(int, i, 1, cnt - 1) cout << ' ' << ans[i];
		}
		cout << "\n";
	}
}