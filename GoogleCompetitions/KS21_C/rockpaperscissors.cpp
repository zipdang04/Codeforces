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

const int ROUND = 60;

ll W, E;

ld f[ROUND + 1][ROUND + 1][ROUND + 1];
string trace[ROUND + 1][ROUND + 1][ROUND + 1];

const int R = 0, P = 1, S = 2;
ld cal(int rock, int paper, int scissors, int mePlay){
	int turn = rock + paper + scissors; ld tmp = f[turn][rock][paper];
	if (turn == 0) return (W + E) / 3.0;
	ld add = 0;
	FOR(int, i, 0, 2){
		ld chance;
		if (i == R) chance = scissors / ld(turn);
		else if (i == P) chance = rock / ld(turn);
		else chance = paper / ld(turn);

		int res = mePlay - i; if (res < 0) res += 3;
		if (res == 1) add += chance * W;
		else if (res == 0) add += chance * E;
	}
	return tmp + add;
}
void calculate(){
	FOR(int, turn, 1, ROUND){
		FOR(int, rock, 0, turn){
			FOR(int, paper, 0, turn - rock){
				int scissors = turn - rock - paper;

				if (rock){
					ld tmp = cal(rock - 1, paper, scissors, R);
					if (tmp > f[turn][rock][paper])
						f[turn][rock][paper] = tmp,
						trace[turn][rock][paper] = trace[turn - 1][rock - 1][paper] + "R";
				}
				if (paper){
					ld tmp = cal(rock, paper - 1, scissors, P);
					if (tmp > f[turn][rock][paper])
						f[turn][rock][paper] = tmp,
						trace[turn][rock][paper] = trace[turn - 1][rock][paper - 1] + "P";
				}
				if (scissors){
					ld tmp = cal(rock, paper, scissors - 1, S);
					if (tmp > f[turn][rock][paper])
						f[turn][rock][paper] = tmp,
						trace[turn][rock][paper] = trace[turn - 1][rock][paper]     + "S";
				}
			}
		}
	}
}
void clear(){
	FOR(int, turn, 1, ROUND)
		FOR(int, rock, 0, turn)
			FOR(int, paper, 0, turn - rock)
				f[turn][rock][paper] = -1,
				trace[turn][rock][paper] = "";
}

main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	int x; cin >> x;
// 	ld shiet = 0;
	FOR(int, _, 1, t){
		cin >> W >> E;
		
		calculate();
		ld ans = 0; string play = "";
		FOR(int, rock, 0, ROUND)
			FOR(int, paper, 0, ROUND - rock){
				ld tmp = f[ROUND][rock][paper];
				if (tmp > ans)
					ans = tmp,
					play = trace[ROUND][rock][paper];
			}
		cout << "Case #" << _ << ": " << play << '\n';
		// cerr << ans << ' ' << x << '\n';
// 		shiet += ans;
		
		clear();
	}
// 	cout << shiet / ld(t);
}