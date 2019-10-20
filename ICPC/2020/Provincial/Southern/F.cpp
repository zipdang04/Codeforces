#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
bool cmp (pii a, pii b){
    if (a.second - a.first > b.second - b.first) return true;
    if (a.second - a.first < b.second - b.first) return false;
    if (a.first < b.first) return true;
    if (a.first > b.first) return false;
    if (a.second > b.second) return true;
    return false;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    pii a[n];
    pii sav[n << 1];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        sav[i << 1] = pii(a[i].first, i << 1);
        cin >> a[i].second;
        sav[(i << 1) + 1] = pii(a[i].second, (i << 1) + 1);
    }
    sort(sav, sav + (n << 1));
    int val = 1;
    for (int i = 0; i < (n << 1); i++)
    {
        if (i != 0 && sav[i].first != sav[i - 1].first) val++;
        if (sav[i].second % 2) a[sav[i].second / 2].second = val;
        else a[sav[i].second / 2].first = val;
    }
    sort(a, a + n, cmp);
    int color[val + 1] = {}, dem[val + 1] = {};
    for (int i = 0; i < n; i++)
    {
        for (int j = a[i].first; j <= a[i].second; j++)
        {
            color[j] = i;
        }
    }
    int ans = 0;
    for (int i = 1; i <= val; i++)
    {
        if (color[i] == 0) continue;
        if (dem[color[i]] == 0) ans++;
        dem[color[i]]++;
    }
    cout << ans;
    return 0;
}
