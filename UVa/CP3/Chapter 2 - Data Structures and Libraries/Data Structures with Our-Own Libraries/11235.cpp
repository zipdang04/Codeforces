#include <bits/stdc++.h>
using namespace std;

#define MAX 100001

struct Freq
{
    int num, f;
    Freq(int num, int f){
        this -> num = num, 
        this -> f = f;
    }
};

typedef vector<Freq> vf;

struct Node{
    vf arr; 
    int ans = 0;
};

int n;
Node it[MAX * 4];

void refresh(){
    for (int i = 1; i <= (n << 2); i++)
        it[i].ans = 0, it[i].arr.clear();
}

Node join(Node &left, Node &right){
    Node ans; ans.ans = max(left.ans, right.ans);
    int lLen = left.arr.size(), rLen = right.arr.size();
    int i = 0, j = 0;
    while (i < lLen && j < rLen){
        if (left.arr[i].num < right.arr[i].num){
            ans.ans = max(ans.ans, left.arr[i].f);
            ans.arr.push_back(left.arr[i]);
            i++;
        }
        else if (left.arr[i].num > right.arr[i].num){
            ans.ans = max(ans.ans, right.arr[j].f);
            ans.arr.push_back(right.arr[j]);
            j++;
        }
        else{
            ans.ans = max(ans.ans, left.arr[i].f + right.arr[j].f);
            ans.arr.push_back(Freq(left.arr[i].num, left.arr[i].f + right.arr[i].f));
            i++, j++;
        }
    }
    while (i < lLen){
        ans.ans = max(ans.ans, left.arr[i].f);
        ans.arr.push_back(left.arr[i]);
        i++;
    }
    while (j < rLen){
        ans.ans = max(ans.ans, right.arr[j].f);
        ans.arr.push_back(right.arr[j]);
        j++;
    }
    for (Freq num: ans.arr) cerr << num.num << '/' << num.f << ' '; cerr << '\n';
    return ans;
}

void buildTree(int index, int left, int right){
    if (left == right){
        // cerr << "read:" << '\n';
        int num; cin >> num;
        it[index].ans = 1, it[index].arr.push_back(Freq(num, 1));
        return;
    }
    int y = index << 1, mid = (left + right) >> 1;
    buildTree(y, left, mid); buildTree(y + 1, mid + 1, right);
    it[index] = join(it[y], it[y + 1]);
}

Node get(int index, int left, int right, int l, int r){
    if (l <= left && right <= r) return it[index];
    if (right < l || r < left){
        Node nothing; return nothing;
    }
    int y = index << 1, mid = (left + right) >> 1;
    Node ansLeft = get(y, left, mid, l, r), 
         ansRight = get(y + 1, mid + 1, right, l, r);
    return join(ansLeft, ansRight);
}

main()
{
    while (true){
        cin >> n; if (n == 0) break;
        int q; cin >> q;
        buildTree(1, 1, n);
        for (int iii = 0; iii < q; iii++)
        {
            // cerr << iii << '\n';
            int left, right; cin >> left >> right;
            cout << get(1, 1, n, left, right).ans << '\n';
        }   
    }
    return 0;
}
