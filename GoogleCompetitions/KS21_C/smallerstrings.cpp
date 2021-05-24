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

ll n, k;
string s;
string make(string s){
	FOR(int, i, 1, n / 2)
		s[n - i + 1] = s[i];
	return s;
}
main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	FOR(int, _, 1, t){
		cout << "Case #" << _ << ": ";
		cin >> n >> k; cin >> s; s = ' ' + s;
		bool minus = make(s) >= s;
		ll ans = 0;
		ll root = n / 2 + n % 2;
		FOR(int, i, 1, root){
			ans *= k, ans %= MOD;
			ans += (s[i] - 'a'), ans %= MOD;
		}
		if (!minus) {ans++; ans %= MOD;}
		cout << ans << '\n';
	}
}