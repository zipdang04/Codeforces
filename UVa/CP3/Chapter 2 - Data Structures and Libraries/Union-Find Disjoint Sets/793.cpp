#include <bits/stdc++.h>
using namespace std;

#define loadcannon(s) {getline(cin, s); ss = stringstream(s);}

int dsu[1000001] = {};

int getRoot(int node){
    if (dsu[node] < 0) return node;
    dsu[node] = getRoot(dsu[node]);
    return dsu[node];
}

void join(int u, int v){
    u = getRoot(u), v = getRoot(v);
    if (u == v) return;
    if (dsu[u] > dsu[v]) swap(u, v);
    dsu[u] += dsu[v], dsu[v] = u;
}

bool sameComponent(int u, int v){
    u = getRoot(u), v = getRoot(v);
    return u == v;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    stringstream ss;
    string s; loadcannon(s);
    
    int t; ss >> t;
    getline(cin, s);

    for (int iiii = 0; iiii < t; iiii++)
    {
        int n; loadcannon(s); ss >> n;
        fill(dsu, dsu + n + 1, -1);

        int success = 0, fail = 0;
        while (true)
        {
            loadcannon(s);
            if (s.empty()) break;

            char query; int i, j; ss >> query >> i >> j;
            if (query == 'c') join(i, j);
            else{
                if (sameComponent(i, j)) success++;
                else fail++;
            }
        }
        cout << success << "," << fail;
        if (iiii + 1 < t) cout << "\n\n";
        else cout << "\n";
    }
    return 0;
}
