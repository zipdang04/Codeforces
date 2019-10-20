#include <bits/stdc++.h>
using namespace std;
#define MAX 1001
string sub(string a, string b)
{
    string res="";
    while(a.length() < b.length()) a="0"+a;
    while(b.length() < a.length()) b="0"+b;
    bool neg=false;
    if(a<b)
    {
        swap(a,b);
        neg=true;
    }
    int borrow=0;
    for(int i=a.length()-1; i>=0;i--)
    {
        int tmp=a[i]-b[i]-borrow;
        if(tmp<0)
        {
            tmp+=10;
            borrow=1;
        }
        else borrow=0;
        res=(char)(tmp%10 + 48) + res;
    }
    while(res.length()>1 && res[0]=='0') res.erase(0,1);
    if(neg) res="-"+res;
    return res;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    string s, t; cin >> s >> t;
    if (s.length() < t.length()) swap(s, t);
    int lenS = s.length(); int lenT = t.length();
    string numS[lenS];
    string numT[lenT];
    for (int i = 0; i < lenS; i++)
    {
        numS[i] = "";
        for (int j = 0; j < lenS; j++)
            numS[i] += s[(i + j) % lenS];
    }
    for (int i = 0; i < lenT; i++)
    {
        numT[i] = "";
        for (int j = 0; j < lenT; j++)
            numT[i] += t[(i + j) % lenT];
    }
    string maxS = "", minS = "";
    for (int i = 0; i < lenS; i++)
    {
        if (numS[i][0] == '0') continue;
        if (maxS == ""){
            maxS = minS = numS[i];
        }
        maxS = max(maxS, numS[i]);
        minS = min(minS, numS[i]);
    }
    string maxT = numT[0], minT = maxT;
    for (int i = 0; i < lenT; i++)
    {
        if (numT[i][0] == '0') continue;
        if (maxT == ""){
            maxT = minT = numT[i];
        }
        maxT = max(maxT, numT[i]);
        minT = min(minT, numT[i]);
    }
    // cerr << maxS << ' ' << maxT << ' ' << minS << ' ' << minT << endl;
    string ans = max(sub(maxS, minT), sub(maxT, minS));
    cout << ans;
    return 0;
}
