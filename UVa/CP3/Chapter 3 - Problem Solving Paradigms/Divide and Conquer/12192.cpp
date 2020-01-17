#include <bits/stdc++.h>
using namespace std;

#define MAX 501

int n, m;
int grape[MAX][MAX];

bool check(int side, int lVal, int rVal){
    for (int i = 1; i <= n - side + 1; i++)
    {
        int left = 1, right = m - side + 1;
        while (left <= right){
            int mid = (left + right) >> 1;
            
            int smallest = grape[i][mid];
            int biggest = grape[i + side - 1][mid + side - 1];

            if (smallest < lVal) left = mid + 1;
            else if (smallest > rVal) right = mid - 1;
            else if (biggest > rVal) right = mid - 1;
            else return true;
        }
    }
    return false;
}

int cal(int lVal, int rVal){
    int left = 1, right = min(n, m), ans = 0;

    while (left <= right){
        int mid = (left + right) >> 1;
        
        if (check(mid, lVal, rVal)) ans = mid, left = mid + 1;
        else right = mid - 1;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    while (true)
    {
        cin >> n >> m;
        if (n == m && m == 0) return 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> grape[i][j];
        int q; cin >> q;
        for (int iii = 0; iii < q; iii++)
        {
            int l, r; cin >> l >> r;
            cout << cal(l, r) << '\n';
        }
        cout << "-\n";
    }
    
    return 0;
}
