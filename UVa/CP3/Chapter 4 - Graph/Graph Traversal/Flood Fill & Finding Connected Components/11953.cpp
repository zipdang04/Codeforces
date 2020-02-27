#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int x, y;
    Node(){x = y = 0;}
    Node(int x, int y){
        this -> x = x, this -> y = y;
    }
};

char ship[102][102];
int n;

const Node direc[4] = {Node(1, 0), Node(0, 1), Node(-1, 0), Node(0, -1)};

Node operator + (Node a, Node b){
    return Node(a.x + b.x, a.y + b.y);
}

bool check(Node a){
    if (a.x < 1 || a.y < 1) return false;
    if (a.x > n || a.y > n) return false;
    return true;
}

bool dfs(Node pos, int cnt){
    // cerr << pos.x << '/' << pos.y << '\n';
    if (ship[pos.x][pos.y] == 'x') cnt++;
    ship[pos.x][pos.y] = '.';
    for (Node d: direc){
        Node now = pos + d;
        if (!check(now)) continue;
        if (ship[now.x][now.y] == '.') continue;
        return dfs(now, cnt);
    }
    return cnt;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    for (int iii = 1; iii <= t; iii++)
    {
        cout << "Case " << iii << ": ";
        cin >> n;
        int answer = 0;
        for (int i = 1; i <= n; i++) cin >> ship[i] + 1;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++){
                if (ship[i][j] == '.') continue;
                answer += dfs(Node(i, j), 0);
            }
        cout << answer << '\n';
    }
    
    return 0;
}
