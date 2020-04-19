#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<ll, ll> pii;

struct Node
{
    int node, len;
    Node() {node = len = 0;}
    Node(int node, int len) {this -> node = node, this -> len = len;}
};
typedef vector<Node> vg;

#define MAX 101
#define NON 0
#define MOD 1000000007

#define FOR(type, i, a, b) for(type i = a; i < b; i++)
#define FORR(type, i, b, a) for(type i = b; i > a; i--)
#define FORE(type, i, a, b) for(type i = a; i <= b; i++)
#define FORRE(type, i, b, a) for(type i = b; i >= a; i--)

#define testBit(n, bit) ((n >> bit) & 1)
#define flipBit(n, bit) (n ^ (1ll << bit))

ll graph[MAX][MAX];

ld floyd(){
    FORE(int, k, 1, 100)
        FORE(int, i, 1, 100)
            FORE(int, j, 1, 100)
                if (graph[i][j] > graph[i][k] + graph[k][j])
                    graph[i][j] = graph[i][k] + graph[k][j];
    ll sum = 0, cnt = 0;
    FORE(int, i, 1, 100)
        FORE(int, j, 1, 100)
            if (i != j && graph[i][j] != INT32_MAX) sum += graph[i][j], cnt++;
    return sum / ld(cnt);
}

void init(){
    FORE(int, i, 1, 100)
        FORE(int, j, 1, 100) {
            if (i == j) graph[i][j] = 0;
            else graph[i][j] = INT32_MAX;
        }
}

main()
{
    ios_base::sync_with_stdio(0); //cin.tie(0);
    cout << fixed << setprecision(3);
    FORE(int, iiiii, 1, 100000000){
        init();
        int u, v; bool okay = false;
        while (cin >> u >> v){
            if (u == 0) break;
            okay = true; graph[u][v] = 1;
        }
        if (!okay) break;
        // cerr << "ok";
        cout << "Case " << iiiii << ": average length between pages = " << floyd() << " clicks\n";
    }
}
