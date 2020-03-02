#include <bits/stdc++.h>
using namespace std;

#define MAX 100001
struct Data{
    bool neg, zero;
    Data(){neg = zero = 0;}
    Data(bool neg, bool zero){
        this -> neg = neg,
        this -> zero = zero;
    }
};

int n, k;
Data it[MAX << 2];

Data join(Data left, Data right){
    return Data(left.neg ^ right.neg, left.zero | right.zero);
}

void buildTree(int index, int left, int right){
    if (left == right){
        int num; cin >> num;
        if (num < 0) it[index] = Data(1, 0);
        else if (num > 0) it[index] = Data();
        else it[index] = Data(0, 1);
        return;
    }

    int y = index << 1, mid = (left + right) >> 1;
    buildTree(y, left, mid); buildTree(y + 1, mid + 1, right);
    it[index] = join(it[y], it[y + 1]);
}

Data get(int index, int left, int right, int begin, int end){
    if (right < begin || end < left) return Data();
    if (begin <= left && right <= end) return it[index];

    int y = index << 1, mid = (left + right) >> 1;
    return join(get(y, left, mid, begin, end), get(y + 1, mid + 1, right, begin, end));
}

void update(int index, int left, int right, int pos, int num){
    if (left == right){
        if (num < 0) it[index] = Data(1, 0);
        else if (num == 0) it[index] = Data(0, 1);
        else it[index] = Data(0, 0);
        return;
    }

    int y = index << 1, mid = (left + right) >> 1;
    if (pos <= mid) update(y, left, mid, pos, num);
    else update(y + 1, mid + 1, right, pos, num);
    it[index] = join(it[y], it[y + 1]);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while (cin >> n >> k){
        buildTree(1, 1, n);
        for (int iii = 0; iii < k; iii++)
        {
            char q; int u, v; cin >> q >> u >> v;
            if (q == 'C')
                update(1, 1, n, u, v);
            else{
                Data ans = get(1, 1, n, u, v);
                if (ans.zero) cout << '0';
                else if (ans.neg) cout << '-';
                else cout << '+';
            }
        }
        cout << '\n';
    }
    return 0;
}
