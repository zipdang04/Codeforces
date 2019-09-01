#include <bits/stdc++.h>
using namespace std;

#define pair pair<long, long>
#define long long long

int main()
{
    ios_base::sync_with_stdio(0);
    long q; cin >> q;
    for (long ii = 0; ii < q; ii++)
    {
        long n, a; cin >> n >> a;
        long daycon[51][5000] = {};
        for (long fdslkf = 0; fdslkf < n; fdslkf++)
        {
            long x; cin >> x;
			long add[51][5000] = {};
            for (long i = 1; i <= n; i++)
            {
                for (long sum = 0; sum <= 2500; sum++)
                {
                    if (daycon[i][sum] == 0) continue;
                    add[i + 1][sum + x]++;
                }
            }
			for (int i = 0; i < 51; i++)
				for(int j = 0; j < 5000; j++) daycon[i][j] = (daycon[i][j] + add[i][j]) % 1000000007;
            daycon[1][x]++; daycon[1][x] %= 1000000007;
        }
        long ans = 0;
        for (long i = 1; i < 51 && a * i <= 5000; i++)
        {
            ans += daycon[i][a * i]; ans %= 1000000007;
        }
        cout << ans << '\n';
    }
    
    return 0;
}
