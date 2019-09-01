#include <bits/stdc++.h>
using namespace std;

#define a first
#define b second

#define pair pair<long, long>
#define long long long

long fenwick[100001] = {};
long get(long index){
    long ans = 0;
    while (index > 0) ans += fenwick[index], index -= index & -index;
    return ans;
}
void update(long index, long amount){
    while (index <= 100000) fenwick[index] += amount, index += index & -index;
}
main()
{
    long q; cin >> q;
    pair command[q];
    for (long i = 0; i < q; i++){
        cin >> command[i].a >> command[i].b;
    }
    sort(command, command + q);
    long num = 0; pair prev;
    pair assign[q];
    for (pair comm: command)
    {
        if (num == 0) num++, assign[num - 1] = pair(num, comm.first);
        else if (comm.first != prev.first) num++, assign[num - 1] = pair(num, comm.first);
        update(num, comm.second); prev = comm;
    }
    long k; cin >> k;
    long left = 1, right = 100000;
    while (left < right)
    {
        // cout << left << '/' << right << endl;
        long mid = (left + right) / 2;
        if (get(mid) >= k) right = mid;
        else left = mid + 1;
    }
    // cout<< le << endl;
    for (pair ass: assign)
    {
        if (ass.first == left){
            cout << ass.second; return 0;
        }
    }
    
    return 0;
}
