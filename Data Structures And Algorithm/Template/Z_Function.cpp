#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();

    string s;
    cin >> s;

    int n = s.size();
    int L = 0;
    int R = 0;
    vector<int> z(n + 5, 0);
    for (int i = 1; i < n; i++)
    {
        if (i > R)
        {
            L = R = i;
            while (R < n && s[R - L] == s[R])
                R++;
            z[i] = R - L;
            R--;
        }
        else
        {
            int k = i - L;
            if (z[k] < R - i + 1)
                z[i] = z[k];
            else
            {
                L = i;
                while (R < n && s[R - L] == s[R])
                    R++;
                z[i] = R - L;
                R--;
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << z[i] << " ";
}