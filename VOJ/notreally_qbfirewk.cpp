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

#define MAX_PETAL 30
#define MAX_COLOR 32
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

ll n, m, k, c;
ll arr[MAX_PETAL * 2 + 1][MAX_COLOR + 1][MAX_COLOR + 1][MAX_PETAL + 1];
#define f(pos, beginColor, currColor, cnt) arr[pos][beginColor][currColor][cnt]
const int NaN = -1;

ll dp(int pos, int beginColor, int currColor, int cnt){
    if (currColor < 1 || currColor > m || cnt < 0) return 0;

    ll &ans = f(pos, beginColor, currColor, cnt);
    if (ans != NaN) return ans;

    if (pos == n * 2){
        if (abs(beginColor - currColor) != 1 || cnt != int(currColor == c) ) 
            return ans = 0;
        return ans = 1;
    }

    return ans = dp(pos + 1, beginColor, currColor + 1, cnt - (currColor == c))
               + dp(pos + 1, beginColor, currColor - 1, cnt - (currColor == c));
}

main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k >> c;
    FOR(int, pos, 1, n * 2)
        FOR(int, begColor, 1, m)
            FOR(int, curColor, 1, m)
                FOR(int, cnt, 0, n)
                    f(pos, begColor, curColor, cnt) = NaN;
    
    ll answer = 0;
    FOR(int, i, 1, m) {
        answer += dp(1, i, i, k);
    }
    cout << answer << '\n';

}