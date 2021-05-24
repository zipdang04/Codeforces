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
#define MOD 1000008277

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

const ll filler = 314159265;

ll f(ll a, ll b){
	a += filler, b += filler;
	a %= MOD, b %= MOD;
	ll ans = 1;
	while (b){
		ans *= (b & 1) ? a : 1; ans %= MOD;
		a *= a, a %= MOD;
		b >>= 1;
	}
	return ans;
}

string int2str(ll num){
	string s = "";
	while (num)
		s = char(num % 10 + '0') + s,
		num /= 10;
	return s;
}
ll str2int(string s){
	ll num = 0;
	for (char c: s)
		num *= 10, num += c - '0';
	return num;
}

ll xuly(string s){
	vector<string> tokens;
	int len = s.length(), ptr = 0;
	while (ptr < len){
		if (isalnum(s[ptr])){
			ll num = 0;
			while (isalnum(s[ptr])){
				num *= 10; num += s[ptr++] - '0';
				num %= MOD;
			}
			tokens.push_back(int2str(num));
		} else {
			string tmp = ""; tmp += s[ptr]; ptr++;
			tokens.push_back(tmp);
		}
	}

	stack<string> st;
	for (string token: tokens){
		if (token == ")"){
			string s2 = st.top(); st.pop();
			string ope = st.top(); st.pop();
			string s1 = st.top(); st.pop();
			st.pop();
			ll n1 = str2int(s1), n2 = str2int(s2);

			ll num;

			if (ope == "+") num = (n1 + n2) % MOD;
			else if (ope == "*") num = (n1 * n2) % MOD;
			else num = f(n1, n2);
			

			st.push(int2str(num));
		} else
			st.push(token);
	}
	return str2int(st.top());
}

ll num[MAX];
main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	FOR(int, _, 1, t){
		cout << "Case #" << _ << ": ";
		int n; cin >> n;
		FOR(int, i, 1, n){
			string s; cin >> s;
			num[i] = xuly(s);
		}
		int group = 0; mll save;
		FOR(int, i, 1, n){
			ll cur = num[i];
			if (save[cur]) cout << save[cur] << ' ';
			else {
				save[cur] = ++group;
				cout << group << ' ';
			}
		}
		cout << '\n';
	}
}