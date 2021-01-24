#include <bits/stdc++.h>

using namespace std;

int main()
{
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    string x, y;
    cin >> x >> y;
    if (x == "0" || y == "0")
        cout << "0";
    else
    {

        int sA = count(begin(x), end(x), 'S');
        int sB = count(begin(y), end(y), 'S');
        int cnt = sA * sB;
        for (int i = 0; i < cnt; i++)
            cout << "S(";
        cout << "0";
        for (int i = 0; i < cnt; i++)
            cout << ")";
    }

    return 0;
}