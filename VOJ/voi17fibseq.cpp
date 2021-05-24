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

ll n, start, mod;
struct Matrix{
    ll mat[2][2] = {};
    ll* operator [](ll pos){
        return mat[pos];
    }
};
Matrix operator * (Matrix a, Matrix b){
    Matrix ans;
    FOR(int, k, 0, 1)
        FOR(int, i, 0, 1)
            FOR(int, j, 0, 1)
                ans[i][j] += a[i][k] * b[k][j] % mod,
                ans[i][j] %= mod;
    return ans;
}
Matrix operator ^ (Matrix a, ll n){
    Matrix ans; FOR(int, i, 0, 1) ans[i][i] = 1;
    while (n){
        if (n & 1) ans = ans * a;
        n >>= 1, a = a * a;
    }
    return ans;
}

Matrix base;
void init(){
    base[0][0] = 0;
    base[0][1] = 1;
    base[1][0] = 1;
    base[1][1] = 1;
}

ll arr[MAX];
ll sum[MAX];
void build(ll start, ll len){
    Matrix tmp = base ^ start;
    arr[1] = tmp[1][0], arr[2] = tmp[1][1];
    FOR(int, i, 3, len)
        arr[i] = (arr[i - 2] + arr[i - 1]) % mod;
    FOR(int, i, 1, len)
        sum[i] = (sum[i - 1] + arr[i]) % mod;
}

ll modPos[MAX];
void clear(){
    FOR(int, i, 1, n)
        modPos[sum[i]] = 0;
}

main()
{
    init();
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    FOR(int, _, 1, t){
        cin >> n >> start >> mod;
        build(start, n);

        int b = 0, e = 0;
        FOR(int, i, 1, n){
            ll curVal = sum[i];
            if (curVal == 0){
                b = 1, e = i; break;
            } else if (modPos[curVal]){
                b = modPos[curVal] + 1, e = i; break;
            } else modPos[curVal] = i;
        }
        cout << e - b + 1 << ' ';
        FOR(int, i, b, e) cout << start + i - 1 << ' '; cout << '\n';
        clear();
    }
}