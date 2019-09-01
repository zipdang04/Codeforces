#include <bits/stdc++.h>
using namespace std;
#define pair pair<long, long>
#define long long long

main()
{
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = n;
    for (int i = 0; i < n - 1; i++)
    {
        int minimum = a[i];
        int end = n; if (n >= 5000) end = min(n, i + 50);
        for (int j = i + 1; j < end; j++)
        {
            minimum = min(minimum, a[j]);
            bool dem[j - i + 1] = {}; int countt = 0;
            for (int k = i; k <= j; k++)
            {
                int num = a[k] - minimum;
                if (dem[num]) break;
                if (num > j - i) break;
                dem[num] = true; countt++;
            }
            if (countt == j - i + 1) {
                ans++;
                // cout << i + 1<< ' ' << j + 1 << endl;
            }
        }
        
    }
    cout << ans;
    
    return 0;
}
