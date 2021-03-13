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

#define MAX 200005
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

const int blSize = 450;

int n, q;
int p[MAX];

class SegTree{
    private:
        int len;
        vi it[MAX * 4];

        void join(vi &a, vi &b, vi &ans){
            int aPtr = 0, bPtr = 0;
            int lenA = a.size(), lenB = b.size();
            while (aPtr < lenA && bPtr < lenB)
                if (a[aPtr] < b[bPtr]) 
                    ans.push_back(a[aPtr++]);
                else
                    ans.push_back(b[bPtr++]);
            while (aPtr < lenA)
                ans.push_back(a[aPtr++]);
            while (bPtr < lenB)
                ans.push_back(b[bPtr++]);
            
        }
        
        int get(vi &arr, int value){
            return arr.end() - lower_bound(arr.begin(), arr.end(), value);
        }

        void buildTree(int ind, int left, int right){
            if (left == right){
                it[ind] = vi(1, p[left]);
                return;
            }

            int y = ind << 1, mid = (left + right) >> 1;
            buildTree(y, left, mid), buildTree(y + 1, mid + 1, right);
            join(it[y], it[y + 1], it[ind]);
        }

        int getTree(int ind, int left, int right, int posL, int posR, int value){
            if (right < posL || posR < left) return 0;
            if (posL <= left && right <= posR) return get(it[ind], value);

            int y = ind << 1, mid = (left + right) >> 1;
            return getTree(y, left, mid, posL, posR, value)
                +  getTree(y + 1, mid + 1, right, posL, posR, value);
        }
    
    public:
        SegTree(int len): len(len){
            buildTree(1, 1, len);
        }

        int getAns(int posL, int posR){
            int lo = 1, hi = 200000, ans = 0;
            while (lo <= hi){
                int mid = (lo + hi) >> 1;
                if (getTree(1, 1, len, posL, posR, mid) >= mid) 
                    ans = mid, lo = mid + 1;
                else
                    hi = mid - 1;
            }
            return ans;
        }
} *seg;

main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q; FOR(int, i, 1, n) cin >> p[i];
    seg = new SegTree(n);
    FOR(int, _, 1, q){
        int l, r; cin >> l >> r;
        cout << seg -> getAns(l, r) << '\n';
    }
}