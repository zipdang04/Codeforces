#include <bits/stdc++.h>
using namespace std;
#define long long long
#define pair pair<long, long>
#define MAX 1001
#define MOD 1000000007
main()
{
    long n, k; cin >> n >> k; 
    long a[n], hieu[n] = {}; 
    for (long i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i > 0) hieu[i] = abs(a[i] - a[i - 1]);
    }
    srand(time(NULL));
    if (rand() % 2){
        for (long ii = 0; ii < k; ii++)
        {
            long vitri = 0;
            for (long i = 0; i < n; i++)
                if (hieu[vitri] < hieu[i]) vitri = i;
            if (vitri == 0) break;
            // cout << vitri << "/\n";
            if (vitri == n - 1){
                // cout << vitri - 1 << a[vitri - 1] << "////\n";
                a[vitri] = a[vitri - 1]; hieu[vitri] = 0;
                continue;
            }
            a[vitri] = (a[vitri - 1] + a[vitri + 1]) / 2;
            hieu[vitri] = a[vitri] - a[vitri - 1];
            hieu[vitri + 1] = a[vitri + 1] - a[vitri + 1 - 1];
        }
        long ans = 0;
        for (long i = 0; i < n; i++)
        {
            ans = max(ans, hieu[i]);
            // cout << a[i] << ' ' << hieu[i] << endl;
        }
        cout << ans;
    }
    else {
        sort(hieu, hieu + n);
        cout << hieu[n - k - 1] << '\n';
    }
    return 0;
}
