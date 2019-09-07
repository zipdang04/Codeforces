#include <bits/stdc++.h>
using namespace std;

#define MAX 10001
#define NON 0
#define MOD 1000000007

#define long long long

typedef pair<long, long> pii;
typedef pair<long, pii> pipii;

#define w first
#define fath second.first
#define chil second.second

long djs[MAX] = {};
priority_queue<pipii, vector<pipii>, greater<pipii>> pq;
long n, m;
long ans = 0;

long getParent(long vertex){
    if (djs[vertex] == 0) return vertex;
    long answer = getParent(djs[vertex]);
    djs[vertex] = answer; return answer;
}

main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (long i = 0; i < m; i++)
    {
        long u, v, len; cin >> u >> v >> len;
        pq.push(pipii(len, pii(u, v)));
    }
    
    while (!pq.empty()){
        pipii currentEdge = pq.top(); pq.pop();
        long parentU = getParent(currentEdge.fath);
        long parentV = getParent(currentEdge.chil);
        if (parentU == parentV) continue;
        ans += currentEdge.w; djs[parentU] = parentV;
    }
    cout << ans;
}
