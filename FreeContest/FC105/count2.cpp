#include <bits/stdc++.h>
using namespace std;
#define long long long
#define pair pair<long, long>
#define MAX 1000000
#define MOD 1000000007
vector<long> curr;
vector<vector<long>> record;
long n, k;
void test(long remain){
    if(remain == 0){
        record.push_back(curr);
        return;
    }
    for (long i = 0; i < n; i++)
        for (long j = 0; j < n; j++)
        {
            if (i == j) continue;
            curr[i]++, curr[j] += 2;
            test(remain - 1);
            curr[i]--, curr[j] -= 2;
        }
}
bool same(long i, long j){
    for (long index = 0; index < n; index++)
    {
        if (record[i][index] != record[j][index]) return false;
    }
    return true;
}
main()
{
    cin >> n >> k;
    curr.resize(n);
    fill(curr.begin(), curr.end(), 0);
    test(k);
    long all = record.size();
    for (long i = 0; i < all - 1; i++)
    {
        // cout << i << endl;
        for (long j = i + 1; j < all; j++)
        {
            if (!same(i, j)) continue;
            record.erase(record.begin() + j); j--; all--;
        }
    }
    cout << all;
    return 0;
}
