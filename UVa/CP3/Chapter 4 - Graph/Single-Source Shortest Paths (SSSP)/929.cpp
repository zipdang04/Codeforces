#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Point{
	ll row, col;
	Point(){row = col = 0;}
	Point(ll row, ll col){
		this -> row = row, this -> col = col;
	}
};

struct Data{
	Point p; ll val;
	Data(){val = 0;}
	Data(Point p, ll val){
		this -> p = p, this -> val = val;
	}
};

const Point direction[4] = {Point(-1, 0), Point(1, 0), Point(0, -1), Point(0, 1)};
ll arr[1000][1000] = {};
ll ans[1000][1000] = {};
ll n, m;

Point operator + (Point a, Point b){return Point(a.row + b.row, a.col + b.col);}
bool operator > (Data a, Data b) {return a.val > b.val;}
bool check(Point p){
	if (p.row < 1 || p.col < 1) return false;
	if (p.row > n || p.col > m) return false;
	return true;
}

ll Dijkstra(){
	priority_queue<Data, vector<Data>, greater<Data> > pq;
	ans[1][1] = arr[1][1]; pq.push(Data(Point(1, 1), arr[1][1]));
	while (!pq.empty()){
		Data curr = pq.top(); pq.pop();
		if (curr.val != ans[curr.p.row][curr.p.col]) continue;
		
		for (Point d: direction){
			Point now = curr.p + d;
			if (!check(now)) continue;
			
			ll value = curr.val + arr[now.row][now.col];
			if (ans[now.row][now.col] > value){
				ans[now.row][now.col] = value;
				pq.push(Data(now, value));
			}
		}
	}
	return ans[n][m];
}

void reset(){
	for(int i = 1; i <= n; i++)
		fill(ans[i], ans[i] + m + 1, 314159265358979323);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	ll t; cin >> t;
	for (ll ii = 0; ii < t; ii++){
		cin >> n >> m;
		reset();
		for (ll i = 1; i <= n; i++)
			for (ll j = 1; j <= m; j++) cin >> arr[i][j];
		cout << Dijkstra() << '\n';
	}
}
