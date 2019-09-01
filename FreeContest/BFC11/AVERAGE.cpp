#include <bits/stdc++.h>
using namespace std;

#define pair pair<long, long>
#define long long long

long n, a; 
long arr[200];
long ans = 0;
void test(long index, long sum, long chosen){
    // cout << index << ' ' << sum << ' ' << chosen << endl;
    if (index == n){
        // cout << sum << ' ' << chosen;
        if (chosen == 0) return;
        if (sum % chosen) return;
        if (sum / chosen == a) ans++;
        return;
    }
    if (chosen){
        if ((sum % chosen) && (sum / chosen >= a)) return;
    }
    test(index + 1, sum, chosen); test(index + 1, sum + arr[index], chosen + 1);
}
main()
{
    ios_base::sync_with_stdio(0);
    long q; cin >> q;
    for (long ii = 0; ii < q; ii++)
    {
        cin >> n >> a;
        for (long i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr, arr + n);
        // cout << "ok";
        ans = 0; test(0, 0, 0);
        cout << ans << '\n';
    }
    
    return 0;
}
