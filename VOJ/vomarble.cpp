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

const ll sz = 62;
struct Matrix{
    ll mat[sz][sz] = {};
    Matrix (){
        memset(mat, false, sizeof(mat));
    }
    ll* operator [](ll pos){
        return mat[pos];
    }
};
Matrix operator * (Matrix a, Matrix b){
    Matrix ans;
    FOR(ll, k, 0, sz - 1)
        FOR(ll, i, 0, sz - 1)
            FOR(ll, j, 0, sz - 1){
                ans[i][j] += a[i][k] * b[k][j] % MOD,
                ans[i][j] %= MOD;
            }
    return ans;
}

ll n, m, k;
Matrix base, ans;
const string allChar = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890";
ll idx[256] = {};
Matrix mul[62];

void init(){
    FOR(ll, i, 0, sz - 1) ans[0][i] = 1;
    FOR(ll, i, 0, sz - 1)
        FOR(ll, j, 0, sz - 1)
            base[i][j] = 1;
    FOR(ll, i, 0, sz - 1)
        idx[allChar[i]] = i;
}
void initP(){
    mul[0] = base;
    FOR(int, i, 1, sz - 1)
        mul[i] = mul[i - 1] * mul[i - 1];
}
void power(Matrix &ans, ll n){
    FOR(int, i, 0, sz - 1){
        if (n & 1) ans = ans * mul[i];
        n >>= 1;
    }
    
}

pair<ll, pair<ll, char>> query[MAX];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    cin >> n >> m >> k;
    FOR(ll, _, 1, m){
        char x, y; cin >> x >> y;
        x = idx[x], y = idx[y];
        base[x][y] = base[y][x] = 0;
    }
    initP();
    
    FOR(ll, i, 1, k){
        ll t, x; char y;  cin >> t >> x >> y;
        query[i] = {x, {t, y}};
    }
    sort(query + 1, query + 1 + k);

    ll curTime = 1;
    FOR(ll, _, 1, k){
        pair<ll, pii> cur = query[_];
        ll t = cur.se.fi, x = cur.fi, y = idx[cur.se.se];
        power(ans, x - curTime); curTime = x;
        if (t == 0) ans[0][y] = 0;
        else
            FOR(ll, i, 0, sz - 1)
                if (i != y)
                    ans[0][i] = 0;
    }
    power(ans, n - curTime);
    ll answer = 0;
    FOR(ll, i, 0, sz - 1)
        answer += ans[0][i], answer %= MOD;
    cout << answer;
}