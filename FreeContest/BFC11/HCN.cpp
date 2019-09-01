#include <bits/stdc++.h>
using namespace std;
#define pair pair<int, int>
pair operator +(pair a, pair b){return pair(a.first + b.first, a.second + b.second);}
bool check(pair x, int n, int m){
    if (x.first >= n) return false;
    if (x.second >= m) return false;
    if (x.first < 0) return false;
    if (x.second < 0) return false;
    return true;
}
pair direc[4] = {pair(-1, 0), pair(0, 1), pair(1, 0), pair(0, -1)};
int main(int argc, char const *argv[])
{
    int n, m; cin >> n >> m;
    int hcn[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> hcn[i][j];

    queue<pair> q; int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (hcn[i][j] == 0) continue;
            if (hcn[i][j] == -1) continue;
            hcn[i][j] = -1; ans++; q.push(pair(i, j));
            while (!q.empty()){
                pair curr = q.front(); q.pop();
                // cout << curr.first << curr.second << endl;
                for (pair huong: direc)
                {
                    pair dest = curr + huong;
                    // cout << "---" << dest.first << dest.second << hcn[dest.first][dest.second] << endl;
                    if (!check(dest, n, m)) continue;
                    // cout << "pass\n";
                    if (hcn[dest.first][dest.second] != 1) continue;
                    hcn[dest.first][dest.second] = -1; q.push(dest);
                }
            }
            // cout << endl;
        }
    cout << ans;
    return 0;
}
