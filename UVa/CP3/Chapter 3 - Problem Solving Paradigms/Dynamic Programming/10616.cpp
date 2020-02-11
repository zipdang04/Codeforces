#include <bits/stdc++.h>
using namespace std;

int n, q;

string add(string a, string b)
{
    string res="";
    while(a.length() < b.length()) a="0"+a;
    while(b.length() < a.length()) b="0"+b;
    int carry=0;
    for(int i=a.length()-1;i>=0;i--)
    {
        int tmp=a[i]-48 + b[i]-48 + carry;
        carry=tmp/10;
        tmp=tmp%10;
        res=(char)(tmp+48)+res;
    }
    if(carry>0) res="1"+res;
    return res;
}

string convert(int num){
    string ans = "";
    while (num > 0){
        ans = char(num % 10 + '0') + ans, num /= 10;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    for (int iiiii = 1; ; iiiii++)
    {
        cin >> n >> q;
        if (n == 0 && q == 0){return 0;}
        cout << "SET " << iiiii << ":\n";
        int arr[n + 1] = {};
        for (int i = 1; i <= n; i++) cin >> arr[i];
        for (int iii = 0; iii < q; iii++)
        {
            cout << "QUERY " << iii + 1 << ": ";
            int d, m; cin >> d >> m;
            string ans[11][21] = {};
            /**/
            for (int j = 1; j <= m; j++)
                for (int r = 0; r < d; r++)
                    ans[j][r] = "0";
            /**/
            for (int i = 1; i <= n; i++)
            {
                string now[11][21] = {};
                int currentRemain = arr[i] % d;
                now[1][currentRemain] = "1";
                for (int j = 2; j <= min(i, m); j++)
                    for (int r = 0; r < d; r++)
                        now[j][r] = ans[j - 1][(r + d - currentRemain) % d];
                for (int j = 1; j <= m; j++)
                    for (int r = 0; r < d; r++)
                        ans[j][r] = add(ans[j][r], now[j][r]);
            }
            cout << ans[m][0] << '\n';
        }
        
    }
    
    return 0;
}
