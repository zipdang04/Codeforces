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

#define MAX 100001
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

class Math{
	private:
		ll fact[MAX + 1] = {};
		ll ifac[MAX + 1] = {};
	public:
		Math(){
			fact[0] = 1;
			FOR(ll, i, 1, MAX)
				fact[i] = (fact[i - 1] * i) % MOD;
			ifac[MAX] = pow(fact[MAX], MOD - 2);
			FORR(ll, i, MAX - 1, 0)
				ifac[i] = (ifac[i + 1] * (i + 1)) % MOD;
		}

		ll pow(ll a, ll n){
			if (n == 0) return 1;
			ll ans = pow(a, n >> 1);
			ans *= ans, ans %= MOD;
			if (n & 1) return (ans * a) % MOD;
			return ans;
		}

		ll C(ll n, ll k){
			return (((fact[n] * ifac[k]) % MOD) * ifac[n - k]) % MOD;
		}
		
		ll P(ll n, ll k){
			return (fact[n] * ifac[n - k]) % MOD;
		}
		
		ll factorial(ll n){
			return fact[n];
		}
} math;

int n;
int v[MAX];
class SegTree{
	private:
		static const int oo = 1e9;
		int len;
		int it[MAX * 4];
		void buildTree(int ind, int lo, int hi){
			if (lo == hi){
				it[ind] = lo;
				return;
			}

			int mid = (lo + hi) >> 1, y = ind << 1;
			buildTree(y, lo, mid); 
			buildTree(y + 1, mid + 1, hi);
			it[ind] = (v[it[y]] < v[it[y + 1]]) ? it[y] : it[y + 1]; 
		}
		int get(int ind, int lo, int hi, int posL, int posR){
			if (hi < posL || posR < lo) return oo;
			if (posL <= lo && hi <= posR) return it[ind];

			int y = ind << 1, mid = (lo + hi) >> 1;
			int x1 = get(y, lo, mid, posL, posR),
				x2 = get(y + 1, mid + 1, hi, posL, posR);
			
			if (x1 == oo) return x2;
			if (x2 == oo) return x1;
			return (v[x1] < v[x2]) ? x1 : x2;
		}
	public:
		SegTree(int len): len(len){
			buildTree(1, 1, len);
		}
		int get(int posL, int posR){
			return get(1, 1, len, posL, posR);
		}
} *seg;

ll dnc(int lo, int hi){
	if (lo == hi) return 1;
	int len = hi - lo + 1, pos = seg -> get(lo, hi);
	
	ll ans = math.C(len - 1, pos - lo);
	if (lo < pos) ans *= dnc(lo, pos - 1), ans %= MOD;
	if (pos < hi) ans *= dnc(pos + 1, hi), ans %= MOD;
	return ans;
}

bool valid(){
	FOR(int, i, 1, n)
		if (v[i] - v[i - 1] > 1) return false;
	return true;
}

main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	FOR(int, i, 1, t){
		cout << "Case #" << i << ": ";

		cin >> n; FOR(int, i, 1, n) cin >> v[i];
		if (!valid()){cout << 0 << '\n'; continue;}

		seg = new SegTree(n);
		cout << dnc(1, n) << '\n';

		delete seg;
	}
}