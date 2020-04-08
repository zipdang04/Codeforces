#include <bits/stdc++.h>
using namespace std;

#define MAX 10001
#define NON 0
#define MOD 1000000007

typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, ll> pii;

int num;
int cycle[MAX];

main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    while (cin >> num){
        if (num == 0) break;
        cycle[1] = num;
        for (int i = 2; i < MAX; i++)
            cycle[i] = (cycle[i - 1] * cycle[i - 1]) % 1000000 / 100;
        
        int tor = 1, hare = 2;
        while (cycle[tor] != cycle[hare]) tor++, hare += 2;
        hare = 1, tor++;
        while (cycle[tor] != cycle[hare]) tor++, hare++;
        int muy = hare - 1;
        tor = hare + 1;
        while (cycle[tor] != cycle[hare]) tor++;
        int cycle = tor - hare;
        cout << muy + cycle << '\n';
    }
}
