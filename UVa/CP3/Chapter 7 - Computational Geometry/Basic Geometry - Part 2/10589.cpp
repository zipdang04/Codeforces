#include <bits/stdc++.h>
using namespace std;

#define MAX 1
#define NON 0
#define MOD 1000000007

typedef long long ll;
typedef complex<double> Point;
typedef pair<ll, ll> pii;

bool check(ll x1, ll y1, ll x2, ll y2, ll len){
    // cerr << x1 << ' ' << y1 << ' ' << len * len << '\n';
    x1 -= x2, y1 -= y2;
    x1 *= x1, y1 *= y1, len *= len;
    if (x1 + y1 <= len) return true;
    return false;
}
ll parse(string s){
    ll ans = 0;
    for (char c: s)
    {
        if (c == '.') continue;
        ans *= 10, ans += c - '0';
    }
    return ans;
}
main()
{
    ios_base::sync_with_stdio(0); //cin.tie(0);
    ll n, a;
    while (cin >> n >> a)
    {
        if (n == 0) break;
        a *= 10000000;
        ll cnt = 0;
        for (int i = 0; i < n; i++)
        {
            string x, y; cin >> x >> y;
            ll x1 = parse(x), y1 = parse(y);
            cnt += check(x1, y1, 0, 0, a) 
                && check(x1, y1, 0, a, a)
                && check(x1, y1, a, 0, a)
                && check(x1, y1, a, a, a);
        }
        a /= 10000000;
        // cerr << cnt * a * a / double(n) << '\n';
        // cout << '\n';
        printf("%0.5f\n", (cnt * a * a) / double(n));
    }
}
