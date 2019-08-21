#include <bits/stdc++.h>
using namespace std;
#define long long long
#define pair pair<long, long>
#define MAX 1001
#define MOD 1000000007

bool khupho[20][20] = {};
long ans = 0;
long m, n, k; 

bool check(){
    bool ok1 = 0, ok2 = 0;
    for (long i = 0; i < n; i++)
    {
        if (khupho[0][i]) ok1 = 1;
        if (khupho[m - 1][i]) ok2 = 1;
    }
    if (!(ok1 && ok2)) return 0;
    ok1 = 0, ok2 = 0;
    for (long i = 0; i < m; i++)
    {
        if (khupho[i][0]) ok1 = 1;
        if (khupho[i][n - 1]) ok2 = 1;
    }
    return ok1 & ok2;
}
void test(long i, long j, long remain){
    if (remain == 0){
        if(!check()) return;
        ans ++, ans %= MOD; return;
    }
    long less = n - j - 1 + n * (m - i - 1);

    if (less <= remain) return;
    for (long ii = i; ii < m; ii++)
    {
        long start = 0;
        if (ii == i) start = j + 1;
        for (long jj = start; jj < n; jj++){
            khupho[ii][jj] = 1;
            test(ii, jj, remain - 1);
            khupho[ii][jj] = 0;
        }
    }
}
main()
{
    long T; cin >> T; //init();
    for (long iiii = 0; iiii < T; iiii++)
    {
        ans = 0;
        cin >> m >> n >> k;
        for (long i = 0; i < m; i++)
        {
            for (long j = 0; j < n; j++)
            {
                test(i, j, k);
            }
            
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}
