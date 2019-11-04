#include <iostream>

#include <string.h>

using namespace std;

int main()

{

    ios::sync_with_stdio(false);

    cin.tie();

    string s;

    cin >> s;

    int i, j, n = s.size(), z[n + 1];

    int R = 0, L = 0, res = 0, maxZ = 0;

    for (i = 1; i < n; i++)

    {

        if (i > R)

        {

            R = L = i;

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

        if (z[i] == n - i && maxZ >= n - i)

        {

            cout << s.substr(0, n - i);

            return 0;
        }

        maxZ = max(maxZ, z[i]);
    }

    cout << "Just a legend";
}