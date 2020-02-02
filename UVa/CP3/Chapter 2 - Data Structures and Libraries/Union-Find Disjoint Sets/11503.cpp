#include <bits/stdc++.h>
using namespace std;


int dsu[1000001] = {};
int quantity = 0;

int getRoot(int node){
    if (dsu[node] < 0) return node;
    dsu[node] = getRoot(dsu[node]);
    return dsu[node];
}

void join(int u, int v){
    if (u == v) return;
    if (dsu[u] > dsu[v]) swap(u, v);
    dsu[u] += dsu[v], dsu[v] = u;
}

int getKey(map<string, int> &m, string &s){
    if (m[s] == 0)
        m[s] = ++quantity;
    return m[s];
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    for (int iiii = 0; iiii < t; iiii++)
    {
        map<string, int> m; quantity = 0;
        int n; cin >> n;
        fill(dsu, dsu + n + 1, -1);
        for (int i = 0; i < n; i++)
        {
            string s1, s2; cin >> s1 >> s2;
            int f1 = getRoot(getKey(m, s1)), f2 = getRoot(getKey(m, s2));
            join(f1, f2);
            cout << -min(dsu[f1], dsu[f2]) << '\n';
        }
        
    }
    return 0;
}
