#include <bits/stdc++.h>
using namespace std;

#define MAX 25
#define NON 0
#define MOD 1000000007

typedef unsigned long long ll;

ll all[MAX];
ll state[MAX][MAX * 6];

void init(){
    all[1] = 6;
    for (ll i = 2; i < MAX; i++)
        all[i] = all[i - 1] * 6;
    for (ll i = 1; i <= 6; i++) state[1][i] = 1;
    for (ll i = 2; i < MAX; i++)
        for (ll sum = i; sum <= i * 6; sum++){
            for (ll dice = 1; dice <= 6; dice++)
                if (dice == sum) break;
                else state[i][sum] += state[i - 1][sum - dice];
        }    
}

main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    ll n, x;
    while (cin >> n >> x)
    {
        if (n == 0) break;
        ll total = all[n], satisfy = 0;
        for (ll i = x; i <= n * 6; i++) satisfy += state[n][i];
        if (satisfy == 0) cout << "0\n";
        else if (total == satisfy) cout << "1\n";
        else {
            ll g = __gcd(total, satisfy);
            total /= g, satisfy /= g;
            cout << satisfy << '/' << total << '\n';
        }
    }
    
}
