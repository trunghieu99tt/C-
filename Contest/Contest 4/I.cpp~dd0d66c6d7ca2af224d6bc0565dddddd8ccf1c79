#include<bits/stdc++.h>

using namespace std;

#define gi greater<int>

string toStr(int n)
{
    string ans;
    stringstream str;
    str << n;
    str >> ans;
    return ans;
}

map<int,int,gi> res;

void convert(string s)
{
    string token;
    stringstream ss(s);
    while(ss>>token)
    {
        if(token!="+")
        {
            int heso = atoll(token.substr(0,token.find('*')).c_str()),
                mu = atoll(token.substr(token.find('^') + 1).c_str());
            res[mu]+=heso;
        }
    }
}

void solve()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        res.clear();
        string a, b;
        getline(cin,a);getline(cin,b);
        convert(a);convert(b);
        string ans = "";
        map<int,int, gi>::iterator it;
        for(it = res.begin();it!=res.end();it++)
            ans+= toStr(it->second) + "*x^" + toStr(it->first) + " + ";
        cout<<ans.substr(0,ans.size() - 3)<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    solve();
    return 0;
}