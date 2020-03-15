#include <bits/stdc++.h>
using namespace std;

typedef complex<int> Point;

#define cDec cout << fixed << setprecision(2)

int n;
double ans[1 << 8][8];
int trace[1 << 8][8];
Point comp[8];

void init(){
    memset(ans, false, sizeof(ans));
    memset(trace, -1, sizeof(trace));
}

double calLen(Point p){
    int sum = p.real() * p.real() + p.imag() * p.imag();
    return sqrt(double(sum));
}

double f(int state, int node, int cnt){
    if (cnt == 1) return 0;
    if (trace[state][node] != -1) return ans[state][node];
    int newState = state ^ (1 << node);
    for (int prev = 0; prev < n; prev++)
    {
        if (((newState >> prev) & 1) == 0) continue;
        double curr = f(newState, prev, cnt - 1) + calLen(comp[node] - comp[prev]);
        // cerr << curr << '\n';
        if (trace[state][node] == -1 || (ans[state][node] > curr))
            trace[state][node] = prev, ans[state][node] = curr;
    }
    return ans[state][node];
}

void asterisk(int num){
    cout << "**********************************************************\n";
    cout << "Network #" << num << '\n';
}

void printEdge(Point one, Point two){
    // Cable requirement to connect (5,19) to (55,28) is 66.80 feet.
    cout << "Cable requirement to connect " << one << " to " << two << " is ";
    cDec << calLen(one - two) + 16.0;
    cout << " feet.\n";
}

void finalAnnounce(double len){
    cout << "Number of feet of cable required is ";
    cDec << len;
    cout << ".\n";
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int cnt = 0;
    while (cin >> n){
        if (n == 0) break;
        asterisk(++cnt);
        init();
        for (int i = 0; i < n; i++)
        {
            int u, v; cin >> u >> v;
            comp[i] = Point(u, v);
        }
        int bestPlace = 0, sameState = (1 << n) - 1;
        for (int i = 0; i < n; i++)
            if (f(sameState, i, n) < ans[sameState][bestPlace]) bestPlace = i;
        int node = bestPlace, currState = sameState;
        for (int iii = 1; iii < n; iii++)
        {
            int prev = trace[currState][node]; currState ^= 1 << node;
            printEdge(comp[node], comp[prev]);
            node = prev;
        }
        
        // printf("%.2f\n", ans[sameState][bestPlace] + 16.0 * (n - 1));
        // cDec << ans[sameState][bestPlace] + 16.0 * (n - 1) << '\n';
        finalAnnounce(ans[sameState][bestPlace] + 16.0 * (n - 1));
    }
    return 0;
}
