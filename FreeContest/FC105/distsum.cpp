#include <bits/stdc++.h>
using namespace std;
#define long long long
#define pair pair<long, long>
main()
{
    long n; cin >> n;
    int a[n], b[n];
    for (long i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    long ans = 0; sort(a, a + n); sort(b, b + n);
    long plu = 0, minus = n - 1;
    for (long i = 0; i < n; i++)
    {
        ans += (a[i] + b[i]) * (plu - minus);
        minus--, plu++;
    }
    cout << ans;
    return 0;
}
