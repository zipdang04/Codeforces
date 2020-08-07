#include <bits/stdc++.h>
using namespace std;

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

// struct Node
// {
// 	int node, len;
// 	Node() {node = len = 0;}
// 	Node(int node, int len) {this -> node = node, this -> len = len;}
// };
// typedef vector<Node> vg;

#define MAX 1000001
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

struct Matrix{ll mat[2][2] = {};};
ll n, m;

Matrix operator * (Matrix &a, Matrix &b){
	Matrix ans;
	FOR(ll, k, 0, 1)
		FOR(ll, i, 0, 1)
			FOR(ll, j, 0, 1)
				ans.mat[i][j] += a.mat[i][k] * b.mat[k][j],
				ans.mat[i][j] &= m;
	return ans;
}

Matrix operator ^ (Matrix a, ll n){
	Matrix ans;
	ans.mat[0][0] = 1;
	ans.mat[0][1] = 0;
	ans.mat[1][0] = 0;
	ans.mat[1][1] = 1;
	while (n){
		if (n & 1) ans = ans * a;
		n >>= 1, a = a * a;
	}
	return ans;
}

main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	Matrix a;
	a.mat[0][0] = 0;
	a.mat[0][1] = 1;
	a.mat[1][0] = 1;
	a.mat[1][1] = 1;
	while (cin >> n >> m){ 
		m = (1 << m) - 1;
		cout << (a ^ n).mat[0][1] << '\n';
	}
} 
