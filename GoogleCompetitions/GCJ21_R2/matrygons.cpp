#include <bits/stdc++.h>
using namespace std;
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
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

template<class T>
void minimize(T &a, T b){
	if (b < a) a = b;
}
template<class T>
void maximize(T &a, T b){
	if (b > a) a = b;
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

#define MAX 1000001
#define MOD 1000000007

#define fi first
#define se second
#define pf push_front
#define pb push_back

#define FOR(type, i, a, b) for(type i = (a); i <= (b); i++)
#define FORR(type, i, b, a) for(type i = (b); i >= (a); i--)

#define testBit(n, bit) (((n) >> (bit)) & 1)
#define flipBit(n, bit) ((n) ^ (1ll << (bit)))
#define cntBit(n) __builtin_popcount(n)
#define cntBitll(n) __builtin_popcountll(n)
#define randomize mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());

ll f[2][MAX];

ll test(ll num, bool allow2){
	if (num == 2) return allow2;
	if (num < 2) return 0;
	ll &ans = f[allow2][num];
	if (ans) return ans;

	ll begin = 3; if (allow2) begin = 2;
	FOR(ll, i, begin, num){
		if (i * i > num) break;
		if (num % i) continue;

		maximize(ans, test(i - 1, true));
		maximize(ans, test(num / i - 1, true));
	}
	ans += 1; return ans;
}

main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll t; cin >> t;
	FOR(ll, _, 1, t){
		ll num; cin >> num;
		cout << "Case #" << _ << ": " << test(num, false) << '\n';
	}
}