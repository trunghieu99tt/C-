#include <bits/stdc++.h>

using namespace std;

map<string, string> var;
string s;
int lim = 1e4;
string get(int l, int r)
{
    if (s[l] == '"')
    {
        return s.substr(l + 1, r - l - 2);
    }
    if (s[l] != '`')
    {
        return var[s.substr(l, r - l)];
    }
    string res;
    for (int i = l + 1; i + 1 < r; ++i)
    {
        if (s[i] != '$' || (s[i] == '$' && s[i + 1] != '{'))
        {
            res.push_back(s[i]);
            if (res.length() > lim)
                return res = "?";
        }
        else
        {
            int sum = 1;
            int j = i + 2;
            for (; sum > 0; ++j)
            {
                if (s[j] == '{')
                    sum++;
                if (s[j] == '}')
                    sum--;
                if (sum == 0)
                    break;
            }
            res += get(i + 2, j);
            if (res.length() > lim || res.back() == '?')
            {
                return res = "?";
            }
            i = j;
        }
    }
    if (res.length() > lim || res.back() == '?')
        return res = "?";
    return res;
}

int main()
{
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for (; getline(cin, s) && s != "end.";)
    {
        if (s[0] == 'e')
            break;
        while (s.back() != ';')
        {
            s.pop_back();
        }
        if (s.front() == 'v')
        {
            string name, val;
            int i = 4;
            for (; s[i] != ' '; ++i)
            {
                name.push_back(s[i]);
            }
            var[name] = get(i + 3, s.size() - 1);
        }
        else
        {
            const string &res = get(6, s.size() - 1);
            lim -= res.size();
            cout << res << '\n';
            assert(lim >= 0);
        }
    }
    return 0;
}