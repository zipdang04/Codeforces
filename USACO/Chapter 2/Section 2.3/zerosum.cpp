/*
PROB: zerosum
LANG: C++11
*/


#include <bits/stdc++.h>
using namespace std;

int n;

string save[50000] = {}; 
int len = 0;

void generate(int index, int currNum, int pow10, int sum, string s){
    if (index == 1){
        sum += currNum;
        if (sum == 0){
            save[len++] = s;
        }
        return;
    }
    generate(index - 1, index - 1, 10, sum + currNum, '+' + s);
    generate(index - 1, index - 1, 10, sum - currNum, '-' + s);
    generate(index - 1, currNum + (index - 1) * pow10, pow10 * 10, sum, ' ' + s);
}

int main(int argc, char const *argv[])
{
    freopen("zerosum.in", "r", stdin);
    freopen("zerosum.out", "w", stdout);
    cin >> n;
    generate(n, n, 10, 0, "");
    sort(save, save + len);
    for (int i = 0; i < len; i++)
    {
        cout << 1;
        for (int num = 2; num <= n; num++)
        {
            cout << save[i][num - 2] << num;
        }
        cout << '\n';
    }
    
    return 0;
}
