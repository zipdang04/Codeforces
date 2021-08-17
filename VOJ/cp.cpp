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
template <class T1, class T2>
void maximize(T1 &a, T2 b){
    if (b > a) a = b;
}
template <class T1, class T2>
void minimize(T1 &a, T2 b){
    if (b < a) a = b;
}
template <class T>
void read(T &number)
{
    bool negative = false;
    register int c;
    number = 0;
    c = getchar();
    while (c != '-' && !isalnum(c)) c = getchar();
    if (c=='-'){
        negative = true;
        c = getchar();
    }
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
    if (negative)
        number *= -1;
}
template <class T, class ...Ts>
void read(T &a, Ts& ... args){
    read(a);
    read(args...);
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

#define MAX 101
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

bool might[MAX][MAX];
int p10[MAX][MAX];
const int MODSTART = 70, MODEND = 89;
void init(){
    FOR(int, mod, MODSTART, MODEND){
        FOR(int, i, 0, mod - 1)
            might[mod][i * i % mod] = true;
        p10[mod][0] = 1;
        FOR(int, i, 1, mod - 1)
            p10[mod][i] = p10[mod][i - 1] * 10 % mod;
    }
}

string num;
int len;

bool able[MAX][MAX];
bool check(int l, int r){
    FOR(int, mod, MODSTART, MODEND){
        int tmp = 0, cnt = 0;
        FORD(int, i, r, l)
            tmp += (num[i] - '0') * p10[mod][cnt],
            tmp %= mod, cnt++;
        if (!might[mod][tmp]) return false;
    }
    return true;
}

ll f[MAX];

main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    init();

    int t; cin >> t;
    FOR(int, _, 1, t){
        cin >> num; len = num.length();
        FOR(int, l, 0, len - 1)
            FOR(int, r, l, len - 1)
                able[l][r] = check(l, r);
        FOR(int, r, 0, len - 1){
            f[r] = able[0][r];
            FOR(int, l, 1, r)
                if (able[l][r])
                    f[r] += f[l - 1];
        }
        cout << f[len - 1] << '\n';

        memset(able, false, sizeof(able));
        memset(f, false, sizeof(f));
    }
}