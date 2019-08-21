#include <bits/stdc++.h>
using namespace std;
#define long long long
#define pair pair<long, long>
#define MAX 1001
#define MOD 1000000007
long fact[1001] = {};
long ifact[1001] = {};

long power(long a, long n){
    if (n == 0) return 1;
    long ans = power(a, n / 2); ans *= ans, ans %= MOD;
    if (n & 1) return (ans * a) % MOD; else return ans;
}

void init(){
    fact[0] = 1;
    for (int i = 1; i < MAX; i++) 
        fact[i] = (fact[i - 1] * i) % MOD;
    ifact[MAX - 1] = power(fact[MAX - 1], MOD - 2);
    for (int i = MAX - 2; i >= 0; i--)
        ifact[i] = (ifact[i + 1] * (i + 1)) % MOD;
}

long C(long n, long k){
    return ((fact[n] * ifact[k]) % MOD * ifact[n - k]) % MOD;
}

main()
{
    long T; cin >> T; init();
    for (long i = 0; i <= 10; i++)
    {
        cout << fact[i] << ' ' << ifact[i] << endl;
    }
    
    for (long iiii = 0; iiii < T; iiii++)
    {
        long m, n, k; cin >> m >> n >> k;
        if (k < 2){
            cout << "0\n"; continue;
        }
        int ans = 0;
        ans += 2 * C((m - 2) * (n - 2), k - 2), ans %= MOD;
        if (k >= 3){
            long mul = 4 * (m - 2) * (n - 2) + 6 * (2 * m + 2 * n - 4); mul %= MOD;
            ans += mul * C((m - 2) * (n - 2), k - 3), ans %= MOD;
        }
        for (long i = 4; i <= k; i++)
        {
            long mul = C(2 * m + 2 * n - 4, k);
            mul -= 2 * (C(2 * m + n - 4, k) + C(m + 2 * n - 4, k));
            mul += C(2 * m - 4, k) + C(2 * n - 4, k) + 2 * C(m + n - 3, k);
            mul -= 2 * (C(m - 2, k) + C(n - 2, k));
            mul %= MOD; if (mul < 0) mul += MOD;
            ans += (mul * C((m - 2) * (n - 2), k - i)), ans %= MOD;
        }
        
        cout << ans << endl;
    }
    
    return 0;
}
