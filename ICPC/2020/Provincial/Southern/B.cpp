#include <bits/stdc++.h>
using namespace std;
#define MAX 1001
int a[MAX];
int ans[MAX][MAX];
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int n; cin >> n; int sum;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i]; sum += a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (i == 1){
                ans[j][i] = a[j]; 
                if (a[j] & 1 == 0) ans[j][i] /= 2;
                cerr << ans[j][i] << ' ';continue;
            }
            int curr = ans[j - 1][i - 1];
            int blockAns = curr + a[j];
            if (abs(blockAns) > abs(curr - a[j])) blockAns = curr - a[j];
            if (a[j] & 1 == 0)
                if (abs(blockAns) > abs(curr)) blockAns = curr;
            ans[j][i] = blockAns;
            cerr << ans[j][i] << ' ';
        }
        cerr << '\n';
    }
    cout << ans[n][n];
    return 0;
}
