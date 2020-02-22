#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, q;
ll ans[201][11][21], arr[201];

void refresh(){
	memset(ans, 0, sizeof(ans));
}

main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	for (ll iii = 1; ; iii++){
		cin >> n >> q; if (n == 0 && q == 0) break;
		cout << "SET " << iii << ":\n";

		for (ll i = 1; i <= n; i++) cin >> arr[i];
		for (ll ii = 1; ii <= q; ii++){
			cout << "QUERY " << ii << ": ";
			ll d, m; cin >> d >> m;
			ans[0][0][0] = 1;
			ll finalAns = 0;
			for (ll i = 1; i <= n; i++){
				ll r = arr[i] % d;
				
				for (ll j = 0; j <= m; j++)
					for (ll k = 0; k < d; k++) ans[i][j][k] = ans[i - 1][j][k];

				for (ll j = 1; j <= min(i, m); j++){
					for (ll k = 0; k < d; k++){
						ll r2 = (k + r) % d; if (r2 < 0) r2 += d;
						ans[i][j][r2] += ans[i - 1][j - 1][k];
					}
				}
			}
			cout << ans[n][m][0] << '\n';
			refresh();
		}
	}
}
